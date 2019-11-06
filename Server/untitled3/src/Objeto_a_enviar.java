public class Objeto_a_enviar {
    int stats[]=new int[7];
    int mutaciones=0;
    int prob_mutaciones=2;
    int inversiones=0;
    int prob_inversiones=4;


    public Objeto_a_enviar() {
    }

    public int[] getStats() {
        return stats;
    }

    public void setStats(int[] stats) {
        this.stats = stats;
    }

    public int getMutaciones() {
        return mutaciones;
    }

    public void setMutaciones(int mutaciones) {
        this.mutaciones = mutaciones;
    }

    public int getProb_mutaciones() {
        return prob_mutaciones;
    }

    public void setProb_mutaciones(int prob_mutaciones) {
        this.prob_mutaciones = prob_mutaciones;
    }

    public int getInversiones() {
        return inversiones;
    }

    public void setInversiones(int inversiones) {
        this.inversiones = inversiones;
    }

    public int getProb_inversiones() {
        return prob_inversiones;
    }

    public void setProb_inversiones(int prob_inversiones) {
        this.prob_inversiones = prob_inversiones;
    }
}
