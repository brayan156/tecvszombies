#include "game.h"
#include <QGraphicsScene>
#include "browntower.h"
#include "bullet.h"
#include "enemy.h"
#include "buildbrowntowericon.h"
#include "buildgreentowericon.h"
#include "buildredtowericon.h"
#include "buildyellowtowericon.h"
#include "menuview.h"
#include "custombutton.h"
#include "backtracking.h"
#include <QTimer>
#include <QGraphicsLineItem>
#include <QPen>
#include <QGraphicsLineItem>
#include <QDebug>

Game::Game(): QGraphicsView(){
    // create a scene
    srand(time(NULL));
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    QBrush brush(QColor("grey"));
    scene->setBackgroundBrush(brush);

    // set the scene
    setScene(scene);

    // set curosr

    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);

    // alter window

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create enemy
    //Matriz BackTracking
    crearMatrizBack();

    //Matriz PathFinding
    crearCuadricula();


    pointsToFollow << QPointF(800,600);


    crearCuadricula();

    // test code
    BuildBrownTowerIcon * bt = new BuildBrownTowerIcon();
    BuildGreenTowerIcon * gt = new BuildGreenTowerIcon();
    BuildRedTowerIcon * rt = new BuildRedTowerIcon();
    BuildYellowTowerIcon * yt = new BuildYellowTowerIcon();
    CustomButton *button=new CustomButton(this);
    button->setText("estadisticas");

    gt->setPos(x(),y()+50);
    rt->setPos(x(),y()+100);
    yt->setPos(x(),y()+150);
    button->move(x(),y()+200);

    scene->addItem(bt);
    scene->addItem(gt);
    scene->addItem(rt);
    scene->addItem(yt);
    scene->addWidget(button);
    MenuView *menu=new MenuView(this);
    menu->show();



}

void Game::setCursor(QString filename){
    // if there is already a cursor, remove it first
    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event){
    if (cursor){
        //cursor->setPos(event->pos());
        cursor->setPos(checkpos(event->pos()));
    }
}

void Game::mousePressEvent(QMouseEvent *event){
    // if we are building
    if (building){
        // return if the cursor is colliding with a tower
        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++){
            if (dynamic_cast<Tower*>(items[i])){
                return;
            }
        }

        // otherwise, build at the clicked location

        //building->setPos(event->pos());


        building->setPos(checkpos(event->pos()));
        scene->addItem(building);
        this->updateMatrizBack(event->x(),event->y());
        cursor = nullptr;
        building = nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }

}
void Game::crearMatrizBack()
{
    for (int i = 0;i<10;i++) {
        for (int j=0;j<10;j++) {
            MatrizBack[i][j] = 1;
        }
    }

}

void Game::updateMatrizBack(int puntox, int puntoy)
{
    int index_x = (puntox)/80;
    int index_y = (puntoy)/60;

    MatrizBack[index_y][index_x] = 0;
    qDebug()<<QString::number(index_x)+" , "+QString::number(index_y);
    for (int n=0; n<this->enemigos->length();n++){
        Enemy *enemy=this->enemigos->at(n);
        this->track.solveMaze(this->MatrizBack,enemy->coordenada[0],enemy->coordenada[1]);
        enemy->ruta=this->crearuta(enemy->coordenada[0],enemy->coordenada[1]);
        enemy->cambio_ruta=1;
    }

//    for (int i = 0; i < 10; i++){
//    {
//        for (int j = 0; j < 10; j++){
//            printf(" %d ", MatrizBack[i][j]);}
//        printf("\n");

////        qDebug() << MatrizBack[i][j] << "";
//    }
////    qDebug() << endl;
//    }

}

void Game::pasar_generacion()
{
    qDebug()<<"Voy a pasa de generacion";
    if (this->modo.compare("primer_ganador")==0){
        if (this->enemigos_pasados->length()>=1){
            qDebug()<<"Cerrar";
            this->close();
        }else{
        QList<Zombie> *zombies_a_cruzar=new QList<Zombie>;
        for (int i=this->enemigos_eliminados->length()-1; i>=0;i--){
            zombies_a_cruzar->append(this->enemigos_eliminados->at(i));
            if (zombies_a_cruzar->length()==8){break;} }
    qDebug()<<"cruzo enemigos";
    this->zombies=this->cruzador.Combinar(zombies_a_cruzar);
    numero_enemigos = this->zombies->length()-1;
    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumberOfEnemies = 0;
     qDebug()<<"voy a crear nuevos enemigos";
    createEnemies(numero_enemigos);
     }
    }
    else if (this->modo.compare("generacion")==0){
        if (this->cruzador.num_generacion<this->cantidad_oleadas){
            qDebug()<<"Cerrar2";
            this->close();
        }else{
            QList<Zombie> *zombies_a_cruzar=new QList<Zombie>;
            for (int i=0; i<this->enemigos_pasados->length();i++){
                zombies_a_cruzar->append(this->enemigos_pasados->at(i));
                if (zombies_a_cruzar->length()==8){break;}
            }
            qDebug()<<"pase los pasados";
            if (zombies_a_cruzar->length()<8){
                for (int i=this->enemigos_eliminados->length()-1; i>0;i--){
                    zombies_a_cruzar->append(this->enemigos_eliminados->at(i));
                    if (zombies_a_cruzar->length()==8){break;} }
            }
            this->zombies=this->cruzador.Combinar(zombies_a_cruzar);
            numero_enemigos = this->zombies->length()-1;
            spawnTimer = new QTimer(this);
            enemiesSpawned = 0;
            maxNumberOfEnemies = 0;
            createEnemies(numero_enemigos);
        }
    }
    this->enemigos_eliminados->clear();
    this->enemigos_pasados->clear();
}

QList<int> *Game::crearuta(int px, int py)
{
    //1=izq 2=arriba 3=derecha 4=abajo
  int xant=px;
  int yant=py;
  QList<int> *ruta=new QList<int>;
  qDebug() << ("vamos a crear ruta");
//  for (int i = 0; i < 10; i++)
//  {
//      for (int j = 0; j < 10; j++){
//          printf(" %d ", track.solucion[i][j]);}
//      printf("\n");
//  }
  while (py>0 || px!=9){
      if(py>0 && py-1!=yant && track.solucion[py-1][px]==1){
          ruta->append(2);
          yant=py;
          py--;
      }
      else if(py<9 && py+1!=yant && track.solucion[py+1][px]==1){
          ruta->append(4);
          yant=py;
          py++;}
      else if(px>0 && px-1!=xant && track.solucion[py][px-1]==1){
          ruta->append(1);
          xant=px;
          px--;
      }
      else{
          xant=px;
          px++;
          ruta->append(3);}

  }
  for(int i=0; i<ruta->length();i++){
      qDebug()<<ruta->at(i)<<",";
  }
  qDebug()<<"aqui termina ruta";
  return ruta;
}

void Game::createEnemies(int numberOfEnemies){

    enemiesSpawned = 0;
    maxNumberOfEnemies = numberOfEnemies;
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnTimer->start(this->tiempo_spawn);


}

void Game::creatRoad(){
    for (size_t i = 0, n = pointsToFollow.size()-1; i < n; i++){
        // create a line connecting the two points
        QLineF line(pointsToFollow[i],pointsToFollow[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);

        QPen pen;
        pen.setWidth(15);
        pen.setColor(Qt::darkGray);

        lineItem->setPen(pen);
        scene->addItem(lineItem);

    }
}

void Game::crear_poblacion()
{
    int i=0;
    while (i<=this->numero_enemigos){
        Zombie zombie;
        zombie.crear_zombie_ramdon();
        this->zombies->append(zombie);
        i++;
    }

}



void Game::crearCuadricula()
{
    QVector <int> temp;
    temp.append(0);
    temp.append(0);


    int k = 0;
    for (int i = 0;i<100;i++) {
        if(k==10){
            temp[0] += 80;
            temp[1] = 0;
            k = 0;
        }
        cuadricula.append(temp);
        temp[1] += 60;
        k++;

    }



}

void Game::empezar_primer_ganador()
{
    this->modo="primer_ganador";
    numero_enemigos = 10;
    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumberOfEnemies = 0;
    this->crear_poblacion();
    createEnemies(numero_enemigos);
    creatRoad();
}

void Game::empezar_generacion(int n)
{
    this->modo="generacion";
    numero_enemigos = 10;
    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumberOfEnemies = 0;
    this->crear_poblacion();
    createEnemies(numero_enemigos);
    creatRoad();
}

QPointF Game::checkpos(QPoint posicion)
{

    int puntox = 0;
    int puntoy = 0;

    int index = 0;
    for (int i = 0;i<10;i++) {

        if(posicion.x() - cuadricula[i+index][0] < 80){

                puntox = ((i)*80)+15;

                break;


        }
        index += 10;


    }
    index = 0;
    for (int j = 0;j<10;j++) {
        if(posicion.y() - cuadricula[j+index][1] < 60){
                puntoy = ((j)*60)+5;
                break;

        }
    }
    QPointF coords(puntox,puntoy);
//    qDebug() << coords;
    return coords;

}



QList<Enemy *> *Game::getEnemigos() const
{
    return enemigos;
}

void Game::spawnEnemy(){
    // spawn an enemy

    Enemy * enemy = new Enemy(pointsToFollow);

    enemy->zombie=this->zombies->at(this->contador_union_zombie_enemigo);

    //qDebug() << enemy->zombie.tipo << endl;
    if(enemy->zombie.stats[0]==1){
        enemy->setPixmap(QPixmap(":/images/zombie1.png"));

    }else if(enemy->zombie.stats[0]==2){
        enemy->setPixmap(QPixmap(":/images/zombie2.png"));

    }else if(enemy->zombie.stats[0]==3){
        enemy->setPixmap(QPixmap(":/images/zombie3.png"));

    }else{
        enemy->setPixmap(QPixmap(":/images/zombie4.png"));
    }


    this->contador_union_zombie_enemigo++;
    enemy->setPos(0,9*60);
    this->track.solveMaze(this->MatrizBack,0,9);
    enemy->ruta=this->crearuta(0,9);
    scene->addItem(enemy);
    this->enemigos->append(enemy);
    enemy->poner_a_caminar();
    enemiesSpawned += 1;

    if (enemiesSpawned >= maxNumberOfEnemies){

        spawnTimer->disconnect();
    }
}
