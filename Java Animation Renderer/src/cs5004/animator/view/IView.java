package cs5004.animator.view;

import java.io.FileNotFoundException;

import cs5004.animator.model.ViewShape;


/**
 * an interface to encapsulate all of the functionality a view in our program should be able to do.
 * It should be able to render data from the model in some way, and toggle the visibility of
 * shapes.
 */
public interface IView {
  /**
   * Sends out the view to a specified file location that the user chooses.
   *
   * @param text - the text generated from the model.
   * @throws FileNotFoundException - if we cannot write to the selected file.
   */
  void render(String text) throws FileNotFoundException;


  /**
   * States whether the current shape is visible to the user or not.
   *
   * @param visibility - A boolean stating whether or not the shape is visible.
   */
  void setVisible(boolean visibility);


  /**
   * returns to the user whether the current view is a text view or an SVG view.
   *
   * @return A string that specifies which type the view is.
   */
  String getViewType();


  /**
   * displays our view in a way that allows the user to see it. Can be in multiple formats.
   *
   * @param shapes - an array of shape type objects that will be shown.
   */
  void renderList(java.util.List<ViewShape> shapes);
}

