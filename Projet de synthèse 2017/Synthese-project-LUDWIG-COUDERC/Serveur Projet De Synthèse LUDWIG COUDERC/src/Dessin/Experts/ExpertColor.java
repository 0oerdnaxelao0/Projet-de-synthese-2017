package Dessin.Experts;

/**
 * Indique que la couleur des prochaines figures de la fenêtre n'est plus fixe, si c'était le cas
 */
public class ExpertColor extends ExpertDessin{

    public boolean dessinSpecifique(String req) {
        if (!(req.contains("Color"))) return false;
        else
        {
            currentFrame.setCheckColor(false);
            return true;
        }
    }
}
