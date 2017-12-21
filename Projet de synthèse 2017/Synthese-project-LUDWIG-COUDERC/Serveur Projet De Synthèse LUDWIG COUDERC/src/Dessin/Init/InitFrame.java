package Dessin.Init;

import Dessin.Experts.*;
import java.awt.*;
import java.awt.geom.Line2D;
import java.awt.image.BufferStrategy;

import static java.awt.Color.*;
import static java.awt.Color.CYAN;
import static java.awt.Color.YELLOW;

/**
 * <b>InitFrame est la classe représentant la fenêtre utilisée et générée par le serveur.</b>
 * Elle dispose de plusieurs paramètres :
 *  - Graph (de la classe Graphic2D) qui servira de pinceau et dessinera les formes sur la fenêtre.
 *  - Un tableau de couleurs.
 *  - Un booleen checkColor.
 *  - Une couleur fixedColor
 * InitFrame sera initialisée grâce à son construteur par défaut, et pourra dessiner grâce à sa procédure dessinerForme
 *
 *
 *
 * @author Ludwig - Couderc
 */
public class InitFrame extends Frame{

    /**
     * Le graphic de la fenêtre, qui dessinera les formes sur cette dernière, qui est de type Graphics2D afin de
     * pouvoir dessiner avec des coordonnées de type double
     */
    private Graphics2D graph;
    /**
     * Tableau de couleur permettant de retourner à la classe setColorFrame d'initialiser la couleur de la fenêtre
     * depuis un entier
     *
     * @see InitFrame#setColorFrame(int)
     */
    private final Color tabColor[] = {RED, GREEN, BLUE, BLACK, YELLOW, CYAN};
    /**
     * Le booleen définit si la couleur est fixée ou non pour les figures prochainement dessinées
     *
     * @see InitFrame#setCheckColor(boolean)
     */
    private static boolean checkColor;
    /**
     * Couleur fixée pour les prochaines figures dessinées
     */
    private static Color fixedColor;


    /**
     * constructeur par défaut:
     *  - supprime les bordures de la fenêtre, car réduire la fenêtre dans la barre de tâches supprime les dessins
     *  - initialise les dimensions
     *  - mets le booleen checkColor à false
     *
     */
    public InitFrame()
    {

        super("Dessin de forme géométrique");

            setUndecorated(true); // empêche de réduire la fenêtre, ce qui provoque des bugs
            setBounds(30, 60, 1000, 1000);
            setIgnoreRepaint(true);
            setVisible(true);
            checkColor = false;


    }

    /**
     * Procédure de dessin de la forme choisie, avec la couleur choisie (avec remplissage)
     * @param s
     *      Forme géométrique à dessiner, de type Line2D, Poly2D, ou Arc2D
     * @param couleur
     *      Couleur choisie
     *      @see InitFrame#setColorFrame(int)
     */
    public void dessinerForme(Shape s, String couleur)
    {
        //Dessine la forme demandée
        createBufferStrategy(1);
        try {
            Thread.sleep(150);
        }
        catch(Exception e)
        {
            System.out.println("Ca marche pas");
        }
        BufferStrategy strategie = getBufferStrategy();
        graph = (Graphics2D) strategie.getDrawGraphics();
        if(!checkColor)
        {
            int couleurint = Integer.parseInt(couleur);
            setColorFrame(couleurint);
        }
        else
        {
            graph.setColor(fixedColor);
        }
        graph.draw(s);
        graph.fill(s);
        strategie.show();
        graph.dispose();

    }

    /**
     * Initialise la couleur de/des forme(s) qui sera/seront dessinée(s)
     * @param i
     *      indice du tableau tabColor
     */
    public void setColorFrame(int i)
    {

        graph.setColor(tabColor[i]);
    }

    /**
     * Modifie la valeur de checkColor
     * @param b
     *      Nouvellevaleur binaire appliqué à checkColor
     */
    public void setCheckColor(boolean b) {checkColor = b;}

    /**
     * Fixe la couleur des prochaines formes à dessiner
     * @param i
     *      chiffre de la couleur (indice du tableau tabColor
     */
    public void setFixedColor(int i)
    {
        fixedColor = tabColor[i];
    }
}
