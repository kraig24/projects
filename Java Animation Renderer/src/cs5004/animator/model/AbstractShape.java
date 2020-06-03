package cs5004.animator.model;

/**
 * this is an abstract shape to minimize code reproduction for our different shape types. the
 * Javadoc information can be found in the IShape interface.
 */
public abstract class AbstractShape implements IShape {

  protected int xValue;
  protected int yValue;
  protected double width;
  protected double height;
  protected float r;
  protected float g;
  protected float b;
  protected int start;
  protected int end;
  protected String id;
  protected ShapeType type;

  /**
   * An abstarct shape that can have a multitiude of motions that happen to it.
   *
   * @param xValue - our current x value.
   * @param yValue - our current y value.
   * @param width  - our current width.
   * @param height our current height.
   * @param r      - our rgb red value.
   * @param g      - our rgb g value.
   * @param b      - our rgb blue value.
   * @param start  - the start time.
   * @param end    the end time.
   * @param id     - the id we can use to look it up in a hashmap.
   */
  //refactored most of this guys to have clearer names- TM
  protected AbstractShape(int xValue, int yValue, int width, int height, float r, float g, float b,
                          int start, int end, String id) {
    this.xValue = xValue;
    this.yValue = yValue;
    this.width = width;
    this.height = height;
    this.id = id;
    this.start = start;
    this.end = end;

    this.r = r;
    this.g = g;
    this.b = b;

  }

  @Override
  public int getX() {
    return this.xValue;
  }

  @Override
  public int getyValue() {
    return this.yValue;
  }

  @Override
  public double getWidth() {
    return this.width;
  }

  @Override
  public double getHeight() {
    return this.height;
  }

  @Override
  public float getR() {
    return this.r;
  }

  @Override
  public float getG() {
    return this.g;
  }

  @Override
  public float getB() {
    return this.b;
  }


  @Override
  public void setWidth(double width) {
    this.width = width;
  }

  @Override
  public void setHeight(double height) {
    this.height = height;
  }

  @Override
  public void setX(int x) {
    this.xValue = x;
  }

  @Override
  public void setY(int y) {
    this.yValue = y;

  }

  public void setR(double r) {
    this.r = (float) r;
  }

  public void setG(double g) {
    this.g = (float) g;
  }

  public void setB(double b) {
    this.b = (float) b;
  }

  @Override
  public int getStart() {
    return this.start;
  }

  @Override
  public int getEnd() {
    return this.end;
  }

  @Override
  public String getID() {
    return this.id;
  }


  @Override
  public int compareTo(IShape o) {
    return this.start - o.getStart();
  }

  @Override
  public String getShapeType() {
    return this.type.toString();
  }

  /**
   * Makes a copy ofan abstract shape.
   *
   * @return an Ishape copy.
   */
  @Override
  public abstract IShape makeCopy();


  /**
   * marks whether or not a frame is greater than the start time and earlier than the end time.
   *
   * @param frame Our current frame.
   * @return true or false.
   */
  public boolean containsTick(int frame) {
    return frame >= start && frame <= end;
  }
}
