package Dessin.Experts;
import Dessin.Init.InitFrame;

/**
 * Classe experte de dessin (chaine de responsabilité)
 */
public abstract class ExpertDessin
{
    /**
     * Fenêtre de dessin
     *
     * @see InitFrame
     */
    public static InitFrame currentFrame;
    /**
     * Maillon suivant de la chaîne de repsonsabilité
     */
    private ExpertDessin suivant;

    /**
     * Initialise le maillon suivant de la chaine
     * @param psuivant
     *      expert placée sur le prochain maillon
     */
    public void setSuivant(ExpertDessin psuivant)
    {
        suivant = psuivant;
    }

    /**
     * Méthode abstraite de dessin spécifique à chaque expert, qui traitera les requetes et les executera
     * @param req
     *      Requete du client
     * @return booleen, true si la requête a été correctement exécutée ou non par l'expert
     */
    public abstract boolean dessinSpecifique(String req);

    /**
     * Méthode qui gère les experts. Quand un expert n'arrive pas à executer la requete, l'expert suivant s'en charge
     * @param req
     *      Requete du client
     * @return booleen, true si la requête a été correctement exécutée ou non par les experts
     */
    public boolean dessin (String req)
    {
        if(dessinSpecifique(req)) return true;

        if(suivant != null) return suivant.dessin(req);

        return false;

    }
}
