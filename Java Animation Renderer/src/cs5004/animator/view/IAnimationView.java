package cs5004.animator.view;

import cs5004.animator.model.ViewShape;

/**
 * Created by vidojemihajlovikj on 7/31/19.
 */
public interface IAnimationView {

  /**
   * displays our view in a way that allows the user to see it. Can be in multiple formats.
   *
   * @param shapes - an array of shape type objects that will be shown.
   */
  void renderList(java.util.List<ViewShape> shapes);


  /**
   * displays out window if the boolean is true, otherwise it is not visible.
   *
   * @param value - true or false.
   */
  void showWindow(boolean value);
}
