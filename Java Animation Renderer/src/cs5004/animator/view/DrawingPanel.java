package cs5004.animator.view;

import java.awt.*;
import java.util.List;

import javax.swing.*;

import cs5004.animator.model.ViewShape;

/**
 * Created by vidojemihajlovikj on 7/31/19.
 */
public class DrawingPanel extends JPanel implements IDrawingPanel {

  List<ViewShape> shapesToDraw = null;


  /**
   * draws the shapes to our drawing panel.
   *
   * @param argShapesToDraw A list of shapes that we are printing.
   */
  @Override
  public void drawShapes(List<ViewShape> argShapesToDraw) {
    this.shapesToDraw = argShapesToDraw;
    repaint();
  }


  /**
   * preps our shapes to be painted a specific color.
   *
   * @param g the graphic we are going to be rendering.
   */
  @Override
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    if (shapesToDraw != null) {
      for (ViewShape shape : this.shapesToDraw) {

        Color newColor = new Color(shape.getRed(), shape.getG(), shape.getB());


        switch (shape.getShapeType()) {
          case "Rectangle":
            g.setColor(newColor);
            g.fillRect(shape.getX(), shape.getY(), shape.getW(), shape.getH());

            break;
          case "Ellipse":
            g.setColor(newColor);
            g.fillOval(shape.getX(), shape.getY(), shape.getW(), shape.getH());
            break;

          case "pentagon":
            throw new IllegalArgumentException("nope");

          default:
            throw new IllegalArgumentException("No such shape");
        }

      }

    }
  }
}
