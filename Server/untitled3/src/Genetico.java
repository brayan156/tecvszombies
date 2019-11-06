import java.util.ArrayList;

public class Genetico {
    int prob_mutacion=2;
    int prob_inversion=4;
    int cant_mutaciones=0;
    int cant_inversiones=0;
    int num_generacion=1;

    ArrayList<Zombie> Combinar(ArrayList<Zombie> zombies_a_cruzar)
    {
        ArrayList<Zombie> nuevagen=new ArrayList<Zombie>();
        for (int i=0; i < zombies_a_cruzar.size();i++){

            Zombie zombie1=zombies_a_cruzar.get(i);
            for (int j=i+1; j<zombies_a_cruzar.size();j++){
                Zombie nuevozombie=new Zombie();
                Zombie zombie2=zombies_a_cruzar.get(j);
                int tipo= (int) (Math.random() * 2);
                if (tipo==0){
                    nuevozombie.stats[zombie1.tipo]=zombie1.stats[zombie1.tipo];
                    nuevozombie.stats[zombie1.velocidad]=zombie1.stats[zombie1.velocidad];
                }
                else{
                    nuevozombie.stats[zombie2.tipo]=zombie2.stats[zombie2.tipo];
                    nuevozombie.stats[zombie2.velocidad]=zombie2.stats[zombie2.velocidad];
                }
                int orden=(int) (Math.random() *2);
                if (orden==0){
                    nuevozombie.stats[2]=zombie1.stats[2];
                    nuevozombie.stats[3]=zombie1.stats[3];
                    nuevozombie.stats[4]=zombie2.stats[4];
                    nuevozombie.stats[5]=zombie2.stats[5];
                    nuevozombie.stats[6]=zombie2.stats[6];

                }
                else{
                    nuevozombie.stats[2]=zombie2.stats[2];
                    nuevozombie.stats[3]=zombie2.stats[3];
                    nuevozombie.stats[4]=zombie1.stats[4];
                    nuevozombie.stats[5]=zombie1.stats[5];
                    nuevozombie.stats[6]=zombie1.stats[6];
                }
                int n_inverision=(int) (Math.random() *10);
                if (n_inverision>this.prob_inversion){
                    nuevozombie=this.Inversion(nuevozombie);
                    this.cant_inversiones++;
                }
                for (int m=2;m<7;m++){
                    int n_mutancion=(int) (Math.random() *10);
                    if (n_mutancion>this.prob_mutacion){
                        nuevozombie.stats[m]+=2;
                        this.cant_mutaciones++;
                    }
                }
                nuevozombie.vida_incial=nuevozombie.stats[nuevozombie.vida];
                nuevagen.add(nuevozombie);
            }
        }
        this.num_generacion++;
        return nuevagen;
    }

    Zombie Inversion(Zombie zombie_a_invertir)
    {
        Zombie zombie_invertido=new Zombie();
        int j=6;
        zombie_invertido.stats[zombie_invertido.tipo]=zombie_a_invertir.stats[zombie_a_invertir.tipo];
        zombie_invertido.stats[zombie_invertido.velocidad]=zombie_a_invertir.stats[zombie_a_invertir.velocidad];
        for (int i=2;i<j;i++){
            zombie_invertido.stats[i]=zombie_a_invertir.stats[j];
            zombie_invertido.stats[j]=zombie_a_invertir.stats[i];
            j--;
        }
        zombie_invertido.stats[j]=zombie_a_invertir.stats[j];
        return zombie_invertido;
    }

}
