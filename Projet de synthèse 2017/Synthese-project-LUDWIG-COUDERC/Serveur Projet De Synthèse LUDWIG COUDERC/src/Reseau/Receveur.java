package Reseau;

import Dessin.Experts.*;

import java.io.*;
import java.net.Socket;

/**
 * Classe recevant les requêtes envoyées par le client, et les envoie aux experts de dessin
 *
 * @see ExpertDessin
 * @see Receveur#fluxEntrant
 */
public class Receveur extends Thread
{
    /**
     * requêtes envoyées par les clients
     */
    private BufferedReader fluxEntrant;
    /**
     * Numéro de client
     */
    int noClient;

    /**
     * Constructeur initialisant les données membres de la classe
     * @param client
     *      socket du client
     * @param noClient
     *      numero du client
     * @throws IOException
     *      Erreur si le flux entrant ne peut être initialisé
     */
    public Receveur(Socket client, int noClient) throws IOException
    {
        fluxEntrant = new BufferedReader(new InputStreamReader(client.getInputStream()));
        this.noClient = noClient;

    }

    /**
     * Construit la chaine de responsabilité et envoie la requête du client dans cette dernière
     * @param requete
     *      Requete reçue par le flux entrant
     * @see ExpertDessin
     */
    private void expert(String requete)
    {
        System.out.println("Le client a envoyé" + requete);
        ExpertDessin expertComposee = new ExpertComposee();
        ExpertDessin expertFrame = new ExpertFrame();
        ExpertDessin expertCercle = new ExpertCercle();
        ExpertDessin expertPolygone = new ExpertPolygone();
        ExpertDessin expertSegment = new ExpertSegment();
        expertComposee.setSuivant(expertFrame);
        expertFrame.setSuivant(expertCercle);
        expertCercle.setSuivant(expertPolygone);
        expertPolygone.setSuivant(expertSegment);

        expertComposee.dessin(requete);

    }

    /**
     * Lis le flux entrant et envoie les requêtes recues dans la chaine de responsabilité
     *
     * @see Receveur#expert(String)
     */
    public void run()
    {
        try
        {
            while (!this.isInterrupted())
            {
                String requete = fluxEntrant.readLine();
                expert(requete);
            }
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
}
