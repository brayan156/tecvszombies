//import com.fasterxml.jackson.databind.ObjectMapper;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import java.util.ArrayList;


@Path("zomb")
public class Zomb {
    private Genetico genetico=new Genetico();

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public ArrayList<Objeto_a_enviar> createI(){
        int i=0;
        ArrayList<Objeto_a_enviar> lista_zombies = new ArrayList<Objeto_a_enviar>(10);
        while (i<10){
            Zombie zombie=new Zombie();
            Objeto_a_enviar objeto=new Objeto_a_enviar();
            zombie.crear_zombie_ramdon();
            objeto.stats=zombie.stats;
            lista_zombies.add(objeto);
            i++;
        }
        return lista_zombies;
    }
    @POST
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public ArrayList<Objeto_a_enviar> getI(ArrayList<Objeto_a_recibir> lista_recibida){
        ArrayList<Zombie> lista_zombies = new ArrayList<Zombie>();
        for (int j=0; j<lista_recibida.size();j++){
            Zombie zombie1=new Zombie();
            zombie1.stats=lista_recibida.get(j).stats;
            System.out.println(zombie1.stats[0]);
            lista_zombies.add(zombie1);
        }

        ArrayList<Zombie> lista_zombies_cruzados=this.genetico.Combinar(lista_zombies);

        ArrayList<Objeto_a_enviar> lista_zombies2 = new ArrayList<Objeto_a_enviar>();
        for (int i=0; i<lista_zombies_cruzados.size();i++){
            Zombie zombie=lista_zombies_cruzados.get(i);
            Objeto_a_enviar objeto=new Objeto_a_enviar();
            objeto.stats=zombie.stats;
            System.out.println("zombies cruzados");
            System.out.println(zombie.stats[0]);
            objeto.mutaciones=this.genetico.cant_mutaciones;
            objeto.inversiones=this.genetico.cant_inversiones;
            lista_zombies2.add(objeto);
        }
        return lista_zombies2;
    }
}

