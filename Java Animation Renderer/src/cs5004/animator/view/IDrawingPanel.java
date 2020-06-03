package cs5004.animator.view;

import java.util.List;

import cs5004.animator.model.ViewShape;

/**
 * Created by vidojemihajlovikj on 7/31/19.
 */
public interface IDrawingPanel {

  /**
   * Draws our shapes iteratively by going over an array of shapes.
   */
  void drawShapes(List<ViewShape> shapesToDraw);
}
