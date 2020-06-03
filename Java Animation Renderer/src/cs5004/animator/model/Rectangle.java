package cs5004.animator.model;

/**
 * This is a class to represent a rectangle. it is made inside of the model class, and specified in
 * a switch statement there.
 */
public class Rectangle extends AbstractShape {
  /**
   * has specified values to encapsulate the needed data to draw a rectangle.
   *
   * @param xValue - top left corner starting x coordinate.
   * @param yValue - top left corner starting y coordinate.
   * @param width  - the width of the rectangle.
   * @param height - the height of the rectangle
   * @param r      - the starting RED color value.
   * @param g      - the starting GREEN color value.
   * @param b      - the starting BLUR color value.
   */
  protected Rectangle(int xValue, int yValue, int width, int height, float r, float g, float b,
                      int start, int end, String id) {
    super(xValue, yValue, width, height, r, g, b, start, end, id);
    this.type = ShapeType.RECTANGLE;
  }

  @Override
  public IShape makeCopy() {
    Rectangle rec = new Rectangle(xValue, yValue, (int) width, (int) height, r, g, b, start, end,
            id);
    return rec;
  }

  /**
   * A toString to print out the rectangle's data.
   *
   * @return a String that holds all of our rectangle's data in the word format that was specified.
   */
  @Override
  public String toString() {
    //TODO: Finished the outline, but we need to figure out how to get time here - KJ
    String returnable = "\nType: rectangle" +
            "\nMin Corner: (" + xValue + "," + yValue + "), Width: " + width + ", Height: " +
            height + ", Color: (" + r + "," + g + "," + b + ")" +
            "\nAppears at: " + "***STARTTIME***" +
            "\nDisappears at: ***ENDTIMR***\n";


    return returnable;


  }
}
