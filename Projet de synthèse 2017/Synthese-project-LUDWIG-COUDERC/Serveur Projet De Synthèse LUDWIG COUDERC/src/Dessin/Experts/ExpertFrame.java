package Dessin.Experts;

import Dessin.Experts.ExpertDessin;
import Dessin.Init.InitFrame;

import java.awt.*;
import java.awt.geom.Path2D;

/**
 * Créé la fenêtre de dessin et l'initialise
 */
public class ExpertFrame extends ExpertDessin
{
        public boolean dessinSpecifique(String req)
        {
            if (!(req.contains("NewFrame"))) return false;
            else {
                try {
                    currentFrame = new InitFrame();
                    return true;
                }
                catch(Exception e)
                {
                    System.out.println(e.getMessage());
                    return false;
                }

            }
        }
}
