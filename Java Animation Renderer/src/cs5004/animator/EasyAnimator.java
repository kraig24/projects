package cs5004.animator;

import java.io.FileNotFoundException;

import javax.swing.*;

import cs5004.animator.controller.AnimationController;
import cs5004.animator.controller.Controller;
import cs5004.animator.controller.IController;
import cs5004.animator.model.IModel;
import cs5004.animator.model.Model;
import cs5004.animator.util.AnimationFileReader;
import cs5004.animator.util.TweenModelBuilder;
import cs5004.animator.view.IView;
import cs5004.animator.view.ViewFactory;


/**
 * creates model, view, and controller.
 */
public class EasyAnimator {

  /**
   * our main function. generates a model from data, takes in source code, and makes a controller +
   * view, which is specified from our source code.
   *
   * @param args - the arguments taken in via console commands at compile time.
   * @throws FileNotFoundException - if the specified file can't be found/made, we throw this
   *                               error.
   */
  public static void main(String[] args) throws FileNotFoundException {


    // error pop ups
    JFrame mainFrame;
    IModel model = null;
    mainFrame = new JFrame();


    // parses our console commands.
    AnimationFileReader fileReader = new AnimationFileReader();
    String filename = "";
    String viewType = "";
    String tickSpeed = "1";
    String output = "";
    for (int s = 0; s < args.length; s++) {
      if (args[s].equalsIgnoreCase("-if")) {
        filename = args[s + 1];

      } else if (args[s].equalsIgnoreCase("-iv")) {
        viewType = args[s + 1];


      } else if (args[s].equalsIgnoreCase("-o")) {
        output = args[s + 1];

      } else if (args[s].equalsIgnoreCase("-speed")) {
        tickSpeed = args[s + 1];

      }
      TweenModelBuilder<IModel> builder = Model.getBuilder(Integer.parseInt(tickSpeed));


      // makes our model.
      try {
        model = fileReader.readFile(filename, builder);
      } catch (Exception e) {
        JOptionPane.showMessageDialog(mainFrame, "That file was not found");
        System.err.println("File not found.");
      }

    }

    // makes our view.
    IView view = ViewFactory.makeView(viewType, output, tickSpeed);


    // makes our controller.
    IController controller;
    if (view.getViewType().equalsIgnoreCase("animation")) {
      controller = new AnimationController(view, model);
    } else {
      controller = new Controller(view, model);
    }

    controller.run();


  }
}