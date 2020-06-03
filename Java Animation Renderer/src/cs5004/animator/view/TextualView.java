package cs5004.animator.view;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

import cs5004.animator.model.ViewShape;

/**
 * This is  type of view in our program that can genrate a textual output for the user to see. In
 * our case, this class write's this output from the model into a file.
 */
public class TextualView implements IView {
  private String outputFromModel;
  private String output;
  private String viewType;


  /**
   * The constructor for our view. it takes in the relative speed our animation should play at, and
   * also the output location that it should be writing to.
   *
   * @param tickPerSec - the speed of the animation.
   * @param output     - the output location/name.
   */
  public TextualView(int tickPerSec, String output) {

    /**
     * this class's object is generated by a ViewFactory that determines from console input that we
     * need a textual output. we then send the data from main that was parsed from the console to
     * this class's constructor so it knows what to render. Besides this, all this class is meant
     * to do is write the generated text to a file, which is done in render.
     */

    this.output = output;
    this.outputFromModel = "";
    this.viewType = "text";

  }

  @Override
  public void render(String text) throws FileNotFoundException {

    try {

      FileOutputStream outputStream = new FileOutputStream(this.output);
      byte[] strToBytes = text.getBytes();
      outputStream.write(strToBytes);

      outputStream.close();
    } catch (IOException e) {
      throw new FileNotFoundException("couldn't find that file");
    }

  }

  @Override
  public void setVisible(boolean visibility) {
    /**
     * will be implemented next week.
     */
  }

  @Override
  public String getViewType() {
    return this.viewType;
  }

  @Override
  public void renderList(List<ViewShape> shapes) {
    /**
     * not used.
     */

  }


  /**
   * sets the textFromModel text to be whatever the model generated for us to use.
   *
   * @param outputFromModel String data that the model compiled and sent to be rendered via text.
   */
  public void setText(String outputFromModel) {
    this.outputFromModel = outputFromModel;
  }
}