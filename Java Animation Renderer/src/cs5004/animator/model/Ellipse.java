package cs5004.animator.model;

/**
 * this is a class to encapsulate shapes such as ovals or Circles in our 2D animation.
 */
public class Ellipse extends AbstractShape {

  /**
   * Takes in all of the required data in order to display the kind of ellipse that is specified.
   *
   * @param xValue - top left corner starting x coordinate.
   * @param yValue - top left corner starting y coordinate.
   * @param width  - the width of the rectangle.
   * @param height - the height of the rectangle
   * @param r      - the starting RED color value.
   * @param g      - the starting GREEN color value.
   * @param b      - the starting BLUR color value.
   */
  protected Ellipse(int xValue, int yValue, int width, int height, float r, float g, float b,
                    int start,
                    int end, String id) {
    super(xValue, yValue, width, height, r, g, b, start, end, id);
    this.type = ShapeType.ELLIPSE;
  }

  /**
   * makes a copy of our current Ishape.
   *
   * @return a new IShape copy.
   */
  @Override
  public IShape makeCopy() {
    Ellipse ellipse = new Ellipse(xValue, yValue, (int) width, (int) height, r, g, b, start, end,
            id);
    return ellipse;
  }

  /**
   * A toString to print out the rectangle's data.
   *
   * @return a String that holds all of our rectangle's data in the word format that was specified.
   */
  @Override
  public String toString() {
    // Did't use String.format because it's slow. Concatenating like this looks horrible,
    // would StringBuilder help?
    String returnable = "\nType: Ellipse" +
            "\nCenter at: (" + xValue + "," + yValue + "), Width: " + width + ", Height: " +
            height + ", Color: (" + r + "," + g + "," + b + ")" +
            "\nAppears at: " + "***STARTTIME***" +
            "\nDisappears at: ***ENDTIMR***\n";

    return returnable;
  }

}


