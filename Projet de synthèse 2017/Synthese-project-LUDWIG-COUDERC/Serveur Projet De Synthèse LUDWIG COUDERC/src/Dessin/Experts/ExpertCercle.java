package Dessin.Experts;

import java.awt.Graphics2D;
import java.awt.geom.Arc2D;

/**
 * Dessine un cercle à partir des coordonnées de son centre, sa couleur et son diamètre
 */
public class ExpertCercle extends ExpertDessin
{
    public boolean dessinSpecifique(String req)
    {
        if (!(req.contains("Cercle"))) return false;
        else
        {
            System.out.println("Je suis dans l'expert Cercle !");
            try
            {
                String [] requeteSplitee = req.split(";");

                // x = _centre.getX() - rayon;
                //y = _centre.getY() + rayon;
                // largeur = hauteur = 2*rayon;
                //graphics.drawOval(x, y, largeur);
                double x = Double.parseDouble(requeteSplitee[2]);
                double y = Double.parseDouble(requeteSplitee[3]);
                double largeur = Double.parseDouble(requeteSplitee[4]);

                Arc2D.Double a = new Arc2D.Double(Arc2D.PIE);
                a.setFrame(x, y, largeur, largeur);
                a.setAngleStart(0);
                a.setAngleExtent(360);

                System.out.println("x : "+a.getX()+"\n");
                System.out.println("y : "+a.getY()+"\n");
                System.out.println("largeur : "+ a.getWidth());
                System.out.println("hauteur : "+ a.getHeight());
                currentFrame.dessinerForme(a, requeteSplitee[1]);

            }

            catch (Exception e)
            {
                System.out.println(e.getMessage());
                return false;
            }

        }
        return true;

    }

}
