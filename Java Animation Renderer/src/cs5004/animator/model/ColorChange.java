package cs5004.animator.model;

/**
 * a class to change the color of an AnimatedShape.
 */
public class ColorChange extends AbstractMotion implements IMotion {

  private int startX;
  private int startY;
  private int endX;
  private int endY;
  private float oldRed;
  private float oldGreen;
  private float oldBlue;
  private float red;
  private float green;
  private float blue;
  private String id;


  /**
   * A method that allows one to make an identical shape with a different color.
   *
   * @param startTime - starting time when the color change should occur.
   * @param endTime   - Ending time when the animation should be done.
   * @param startX    - Starting x coordinate where the shape is at the time of animation.
   * @param startY    - starting y coordinate where the shape is at the time of animation.
   * @param endX      - ending x coordinate where the shape is at the time of animation.
   * @param endY      - Ending y coordinate where the shape is at the time of animation.
   * @param red       - red integer color for the shape.
   * @param green     -  green integer color for the shape.
   * @param blue      - blue integer color for the shape.
   * @param id        - the String ID for the shape, used in a hashmap elsewhere in program.
   */
  public ColorChange(int startTime, int endTime, int startX, int startY, int endX, int endY,
                     float oldRed, float oldGreen, float oldBlue, float red, float green,
                     float blue,
                     String id) throws IllegalArgumentException {


    super(startTime, endTime, startX, startY, endX, endY);

    if (startTime < 0 || endTime < 0 || red < 0 || green < 0 || blue < 0) {
      throw new IllegalArgumentException("one or more of your parameters cannot be negative");
    }
    this.oldRed = oldRed;
    this.oldBlue = oldBlue;
    this.oldGreen = oldGreen;

    this.red = red;
    this.green = green;
    this.blue = blue;

    this.id = id;
    this.type = MoveTypes.COLORCHANGE;


  }

  /**
   * Changes the color values from the original to the new color values.
   *
   * @param r - red value.
   * @param g green value.
   * @param b - blue value.
   */
  public void colorChange(float r, float g, float b) {
    this.red = r;
    this.green = g;
    this.blue = b;
  }


  @Override
  public String getID() {
    return this.id;
  }

  @Override
  public int compareTo(IMotion o) {
    return this.startTime - o.getStartTime();
  }

  @Override
  public float getRed() {
    return this.red;
  }

  @Override
  public float getBlue() {
    return this.blue;
  }

  @Override
  public float getGreen() {
    return this.green;
  }

  @Override
  public double getNewHeight() {
    return 0;
  }

  @Override
  public double getNewWidth() {
    return 0;
  }

  @Override
  public double getOldWidth() {
    return 0;
  }

  @Override
  public double getOldHeight() {
    return 0;
  }


  /**
   * teturns the old green val.
   *
   * @return old red val. int.
   */
  public float getOldRed() {
    return this.oldRed;
  }

  /**
   * teturns the old green val.
   *
   * @return old blue val. int.
   */
  public float getOldBlue() {
    return this.oldBlue;
  }

  /**
   * teturns the old green val.
   *
   * @return old green val. int.
   */
  public float getOldGreen() {
    return this.oldGreen;
  }

  @Override
  public IShape tween(int tick, IShape shapeToTweeen) {
    IShape shape = shapeToTweeen;
    double newR = tweenHelper(this.getOldRed(), this.getRed(), this.startTime,
            this.endTime, tick);
    double newG = tweenHelper(this.getOldGreen(), this.getGreen(), this.startTime,
            this.endTime, tick);
    double newB = tweenHelper(this.getOldBlue(), this.getBlue(), this.startTime,
            this.endTime, tick);


    shape.setR(newR);
    shape.setG(newG);
    shape.setB(newB);

    return shape;
  }


}



