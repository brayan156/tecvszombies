public class Zombie {
    int tipo=0;
    int velocidad=1;
    int vida=2;
    int vida_incial=3;
    int Res_arquero=3;
    int Res_mago=4;
    int Res_artillero=5;
    int Res_fuego=6;
    int stats[]=new int[7];
    int modo_movimiento=8;
    int backtracking=8;

    public Zombie() {
    }

    void crear_zombie_ramdon()
    {
        int tipo= (int) (Math.random() * 4);

        if (tipo==0){
            crear_Orco();
        }
        else if (tipo==1) {
            crear_Elfo();
        }
        else if (tipo==2) {
            crear_Harpia();
        }
        else {
            crear_Mercenario();
        }
    }





    void crear_Orco()
    {
        stats[this.tipo]=1;
        stats[this.velocidad]=3;
        for (int i=2; i<7;i++){
            if (i==this.Res_arquero){
                stats[i]= (int) (Math.random() * 5) +6;
            }
        else if (i==3) {
                stats[i]= (int) (Math.random() * 10) +1;
            }
            else  {
                stats[i]= (int) (Math.random() * 5) +1;
            }
        }
        this.vida_incial=this.stats[this.vida];
    }

    void crear_Elfo()
    {
        stats[this.tipo]=2;
        stats[this.velocidad]=5;
        for (int i=2; i<7;i++){
            if (i==this.Res_arquero || i== this.Res_mago){
                stats[i]= (int) (Math.random() * 5) +6;
            }
        else if (i==this.Res_artillero || i==this.Res_fuego) {
                stats[i]= (int) (Math.random() * 5) +1;
            }
        else  {
                stats[i]= (int) (Math.random() * 10) +1;
            }
        }
        this.vida_incial=this.stats[this.vida];
    }

    void crear_Harpia()
    {
        stats[this.tipo]=3;
        stats[this.velocidad]=5;
        for (int i=2; i<7;i++){
            stats[i]= (int) (Math.random() * 10) +1;

        }
        this.vida_incial=this.stats[this.vida];
    }

    void crear_Mercenario()
    {
        stats[this.tipo]=4;
        stats[this.velocidad]=7;
        for (int i=2; i<7;i++){
            if (i==this.Res_arquero || i==this.Res_mago || i==this.Res_artillero){
                stats[i]= (int) (Math.random() * 5) +6;
            }
        else if (i==this.Res_fuego) {
                stats[i]= (int) (Math.random() * 5) +1;
            }
        else  {
                stats[i]=(int)Math.random()*10+1;
            }
        }
        this.vida_incial=this.stats[this.vida];
    }



    public int getTipo() {
        return tipo;
    }

    public void setTipo(int tipo) {
        this.tipo = tipo;
    }

    public int getVelocidad() {
        return velocidad;
    }

    public void setVelocidad(int velocidad) {
        this.velocidad = velocidad;
    }

    public int getVida() {
        return vida;
    }

    public void setVida(int vida) {
        this.vida = vida;
    }

    public int getVida_incial() {
        return vida_incial;
    }

    public void setVida_incial(int vida_incial) {
        this.vida_incial = vida_incial;
    }

    public int getRes_arquero() {
        return Res_arquero;
    }

    public void setRes_arquero(int res_arquero) {
        Res_arquero = res_arquero;
    }

    public int getRes_mago() {
        return Res_mago;
    }

    public void setRes_mago(int res_mago) {
        Res_mago = res_mago;
    }

    public int getRes_artillero() {
        return Res_artillero;
    }

    public void setRes_artillero(int res_artillero) {
        Res_artillero = res_artillero;
    }

    public int getRes_fuego() {
        return Res_fuego;
    }

    public void setRes_fuego(int res_fuego) {
        Res_fuego = res_fuego;
    }

    public int[] getStats() {
        return stats;
    }

    public void setStats(int[] stats) {
        this.stats = stats;
    }

    public int getModo_movimiento() {
        return modo_movimiento;
    }

    public void setModo_movimiento(int modo_movimiento) {
        this.modo_movimiento = modo_movimiento;
    }

    public int getBacktracking() {
        return backtracking;
    }

    public void setBacktracking(int backtracking) {
        this.backtracking = backtracking;
    }

    public int getA() {
        return A;
    }

    public void setA(int a) {
        A = a;
    }

    int A=9;

}
