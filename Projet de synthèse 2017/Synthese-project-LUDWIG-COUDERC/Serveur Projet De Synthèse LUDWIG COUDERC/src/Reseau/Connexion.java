package Reseau;

import java.net.ServerSocket;
import java.net.Socket;

/**
 * Classe gérant les connexions et démarre le serveur
 *
 * @author Ludwig - Couderc
 */
public class Connexion
{
    public Connexion ()
    {
        System.out.println("Test");
        try
        {

            int portServeur = 16000;
            ServerSocket serveur = new ServerSocket(portServeur);
            System.out.println("Serveur démarré :" + serveur);
            int noClient = 1;
            while(true)
            {
                Socket client = serveur.accept();
                System.out.println("Connexion reussie numero " + noClient);
                ++noClient;
                Receveur r = new Receveur(client, noClient);
                r.start();
            }
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
}
