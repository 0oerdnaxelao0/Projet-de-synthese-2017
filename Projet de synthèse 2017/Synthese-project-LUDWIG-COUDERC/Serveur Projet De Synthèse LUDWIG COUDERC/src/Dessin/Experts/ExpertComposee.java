package Dessin.Experts;

import java.awt.*;

/**
 * Dessine une forme composée, fixe la couleur de la fenêtre pour que ses formes aient la même couleur
 *
 * @see Dessin.Init.InitFrame#checkColor
 * @see Dessin.Init.InitFrame#fixedColor
 */
public class ExpertComposee extends ExpertDessin
{
    public boolean dessinSpecifique(String request)
    {

        if (!(request.contains("Composee"))) return false;
        else
        {
            String [] tabString = request.split(";");
            currentFrame.setFixedColor(Integer.parseInt(tabString[1]));
            currentFrame.setColorFrame(Integer.parseInt(tabString[1]));
            currentFrame.setCheckColor(true);
            return true;
        }

    }

}
