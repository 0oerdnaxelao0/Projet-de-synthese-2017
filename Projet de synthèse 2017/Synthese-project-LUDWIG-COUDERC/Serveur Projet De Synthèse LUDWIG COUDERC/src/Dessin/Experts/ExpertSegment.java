package Dessin.Experts;

import Dessin.Experts.ExpertDessin;

import java.awt.Graphics2D;
import java.awt.geom.*;

/**
 * Dessine un segment à partir des coordonnées de ses points et sa couleur
 */
public class ExpertSegment extends ExpertDessin
{
    public boolean dessinSpecifique(String req)
    {
        if (!(req.contains("Segment"))) return false;
        else
        {
            System.out.println("Je dessine un Segment");
            String [] requeteSplitee = req.split(";");
            for (int i = 0; i < requeteSplitee.length; i++)
            {
                System.out.println(requeteSplitee[i]);
                System.out.println("\n");
            }
            /*
            if (! currentFrame.getCheckColor()) {
                int couleur = Integer.parseInt(requeteSplitee[1]);
                currentFrame.setColorFrame(couleur);
            }*/

                double x1 = Double.parseDouble(requeteSplitee[2]);
                System.out.println("x1 =" + x1);
                double y1 = Double.parseDouble(requeteSplitee[3]);
                System.out.println("y1 =" + y1);
                double x2 = Double.parseDouble(requeteSplitee[4]);
                System.out.println("x2 =" + x2);
                double y2 = Double.parseDouble(requeteSplitee[5]);
                System.out.println("y2 =" + y2);
                Line2D.Double ligne = new Line2D.Double(x1, y1, x2, y2);
                System.out.println(ligne.getX1());
                currentFrame.dessinerForme(ligne,requeteSplitee[1]);
                //graph.fill(ligne);
                //graph.draw(ligne);
                //currentFrame.getGraphic2D().draw(ligne);
        }
        return true;
    }
}
