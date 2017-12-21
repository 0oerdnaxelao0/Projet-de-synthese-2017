package Dessin.Experts;

import Dessin.Experts.ExpertDessin;
import java.awt.Graphics2D;
import java.awt.geom.Path2D;

/**
 * Dessine un polygone à partir des coordonnées de ses points et sa couleur
 */
public class ExpertPolygone extends ExpertDessin
{
    public boolean dessinSpecifique(String req)
    {
        if (!(req.contains("Polygone"))) return false;
        else
        {
            System.out.println("Je suis dans l'expert Polygone ! \n");
            String [] requeteSplitee = req.split(";");
            for (int i = 0; i < requeteSplitee.length; i++)
            {
                System.out.println(requeteSplitee[i]);
                System.out.println("\n");
            }
            try
            {

                int tailleTab = (requeteSplitee.length - 2) / 2;
                double x[] = new double [tailleTab];
                double y[] = new double [tailleTab];
                int indiceX = 0;
                int indiceY = 0;
                for (int i = 2; i < requeteSplitee.length ; i++)
                {
                    if((i % 2) == 0)
                    {
                        x[indiceX] = Double.parseDouble(requeteSplitee[i]);
                        indiceX++;

                    }

                    else
                    {
                        y[indiceY] = Double.parseDouble(requeteSplitee[i]);
                        indiceY++;
                    }
                }
                System.out.println("Les x : \n");
                for (int i = 0 ; i < x.length; i++ )
                {
                    System.out.println(x[i]);
                    System.out.println("\n");
                }
                System.out.println("Les y : \n");
                for (int i = 0 ; i < y.length; i++ )
                {
                    System.out.println(y[i]);
                    System.out.println("\n");
                }
                Path2D poly = new Path2D.Double();
                poly.moveTo(x[0], y[0]);
                for(int i = 1; i < tailleTab; i++)
                {
                    poly.lineTo(x[i], y[i]);
                }
                poly.closePath();
                currentFrame.dessinerForme(poly,requeteSplitee[1]);



            }
            catch(Exception e)
            {
                System.out.println(e.getMessage());
                return false;
            }

            return true;

        }
    }
}
