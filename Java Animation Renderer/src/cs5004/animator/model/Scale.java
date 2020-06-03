package cs5004.animator.model;

/**
 * a class to represent changing a shape's size. inherits IMotion.
 */
public class Scale extends AbstractMotion implements IMotion {
  private final IShape shape;
  private final double oldHeight;
  private final double oldWidth;
  private double newHeight;
  private double newWidth;

  /**
   * A type of motion that represents either increasing or decreasing the size of a shape.
   *
   * @param startTime - the start time for the motion to occur.
   * @param endTime   - the the end time for th emotion to occur
   * @param startX    - the starting x coordinate.
   * @param startY    - the starting y coordinate.
   * @param endX      - the ending x coordinate.
   * @param endY      - the ending y coordinate.
   * @param id        - the string ID to find the shape in a hashmap.
   */
  protected Scale(int startTime, int endTime, int startX, int startY, int endX, int endY,
                  IShape id) {
    super(startTime, endTime, startX, startY, endX, endY);
    this.shape = id;
    this.type = MoveTypes.SCALE;
    this.oldHeight = this.shape.getHeight();
    this.oldWidth = this.shape.getWidth();

    this.newHeight = oldHeight;
    this.newWidth = oldWidth;

  }

  /**
   * Changes the size of a shape by two different dimensions.
   *
   * @param widthScale  - the new width we want to generate's rate of scale.
   * @param heightScale - the new height we want to generate's rate of scale.
   * @return - a new shape that has the dimensiosn that we want.
   * @throws IllegalArgumentException - if the new height and width are invalid.
   */
  public IShape changeSize(double widthScale, double heightScale) throws IllegalArgumentException {
    if (widthScale == 0 || heightScale == 0) {
      throw new IllegalArgumentException("The specified command would not change the scale of the" +
              "shape");
    }
    if (widthScale < 0 || heightScale < 0) {
      throw new IllegalArgumentException("the specified size would result in a " +
              "negative height/width");
    }
    double width = this.shape.getWidth();
    double height = this.shape.getHeight();

    if (widthScale < 1) {
      this.newWidth = width / widthScale;
    } else if (widthScale >= 1) {
      this.newWidth = width * widthScale;
    }

    if (heightScale < 1) {
      this.newHeight = height / heightScale;
    } else if (heightScale >= 1) {
      this.newHeight = height * heightScale;
    }


    if (height < 0 || width < 0) {
      throw new IllegalArgumentException("the specified scaling would result in a negative" +
              "width and or height");
    }

    IShape newShape = this.shape;
    newShape.setWidth(newWidth);
    newShape.setHeight(newHeight);

    return newShape;
  }


  @Override
  public int getStartTime() {
    return this.startTime;
  }

  @Override
  public int getEndTime() {
    return this.endTime;
  }

  @Override
  public IShape tween(int tick, IShape shapeToTween) {
    IShape shape = shapeToTween;
    double newWidth = tweenHelper((int) this.getOldWidth(), (int) this.getNewWidth(),
            this.startTime, this.endTime, tick);
    double newHeight = tweenHelper((int) this.getOldHeight(), (int) this.getNewHeight(),
            this.startTime, this.endTime, tick);
    shape.setWidth((int) newWidth);
    shape.setHeight((int) newHeight);

    return shape;
  }

  @Override
  public String getID() {
    return this.shape.getID();
  }

  @Override
  public float getRed() {
    return 0;
  }

  @Override
  public float getBlue() {
    return 0;
  }

  @Override
  public float getGreen() {
    return 0;
  }

  @Override
  public int compareTo(IMotion o) {
    return this.startTime - o.getStartTime();
  }

  @Override
  public double getNewHeight() {
    return this.newHeight;
  }

  @Override
  public double getNewWidth() {
    return this.newWidth;
  }

  @Override
  public double getOldWidth() {
    return this.oldWidth;
  }

  @Override
  public double getOldHeight() {
    return this.oldHeight;
  }

}
