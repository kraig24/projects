package cs5004.animator.controller;

import java.io.FileNotFoundException;

/**
 * An interface to encapsulate all basic functions that a controller will be able to do in this
 * program.
 */
public interface IController {


  /**
   * launches the controller. calls the view to display the content that the model produces.
   *
   * @throws FileNotFoundException - if the model did not have viable output or the file missing.
   */
  void run() throws FileNotFoundException;


  /**
   * A getter in case we need our controlelr to go to new programs later on.
   *
   * @return our controller.
   */
  Controller setController();
}
