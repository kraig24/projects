package cs5004.animator.controller;

import java.io.FileNotFoundException;

import cs5004.animator.model.IModel;
import cs5004.animator.view.IView;

/**
 * The controller is a class to facilitate data between the model and the view.
 */
public class Controller implements IController {
  private IView view;
  private IModel model;
  //private Readable rd;
  private Appendable ap;

  /**
   * Our constructor to make a controlle.r IT is the last of the three modules to be created, and
   * takes in the view and model so that it can communicate with both.
   *
   * @param view  - our view that we ar working with, made by a factory.
   * @param model - our model, which was built by our model builder.
   */
  public Controller(IView view, IModel model) {
    this.view = view;
    this.model = model;
  }

  /**
   * Checks to see what type of view we are working with, and then calls the model to retrieve the
   * corresponding data.
   *
   * @throws FileNotFoundException - If we cannot find the specified data we are looking for.
   */
  @Override
  public void run() throws FileNotFoundException {

    if (view.getViewType().equals("text")) {
      String temp = this.model.getState();
      this.view.render(temp);
    }
    if (view.getViewType().equals("svg")) {
      String temp = this.model.svgState();
      this.view.render(temp);
    }

    // model.addShape( );
  }

  /**
   * sets the controller to be whatever it currently is. acts as a getter.
   *
   * @return our current controller.
   */
  @Override
  public Controller setController() {
    return this;
  }
}
