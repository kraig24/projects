package cs5004.animator.model;

/**
 * this is an abstract class to minimixe code reproduction for our motion classes.
 */
public abstract class AbstractMotion implements IMotion {

  protected double tweenHelper(double start, double end, int startVal, int endVal, double tick) {
    if (tick > endVal || tick < startVal) {
      throw new IllegalArgumentException("Your tick is outside these values");
    }
    double denominator = endVal - startVal;
    double numeratorA = endVal - tick;
    double numeratorB = tick - startVal;
    return (start * numeratorA / denominator) + (end * numeratorB / denominator);
  }

  protected String shape;

  protected int startTime;
  protected int endTime;
  protected int startX;
  protected int startY;
  protected int endX;
  protected int endY;
  protected MoveTypes type;

  /**
   * Our abstract class to store movable objects.
   *
   * @param startTime - time the object starts
   * @param endTime   - time the object disappears.
   * @param startX    - starting x coordinate.
   * @param startY    - starting y coordinate.
   * @param endX      - our ending x value.
   * @param endY      our ending y value.
   */
  protected AbstractMotion(int startTime, int endTime, int startX, int startY, int endX, int endY) {
    this.startTime = startTime;
    this.endTime = endTime;
    this.startX = startX;
    this.startY = startY;
    this.endX = endX;
    this.endY = endY;


  }

  @Override
  public void setStartTime(int t1) {
    this.startTime = t1;
  }

  @Override
  public void setEndTime(int t2) {
    this.endTime = t2;
  }

  @Override
  public void setStartX(int x) {
    this.startX = x;
  }

  @Override
  public void setStartY(int y) {
    this.startY = y;
  }

  @Override
  public void setEndX(int x) {
    this.endX = x;
  }

  @Override
  public void setEndY(int y) {
    this.endY = y;
  }

  @Override
  public int getEndY() {
    return this.endY;
  }

  @Override
  public int getEndX() {
    return this.endX;
  }

  @Override
  public int getStartY() {
    return this.startY;
  }

  @Override
  public int getStartX() {
    return this.startX;
  }

  @Override
  public boolean containsTick(int tick) {
    return tick >= startTime && tick <= endTime;
  }

  @Override
  public String getMoveType() {
    return this.type.toString();
  }

  @Override
  public int getStartTime() {
    return this.startTime;
  }

  @Override
  public int getEndTime() {
    return this.endTime;
  }

  /**
   * get the value of a shape in motion.
   *
   * @param tick         - our current spot in the time of animation.
   * @param shapeToTween - the shape we are working with.
   * @return a valu that says where/ or what the shape is like.
   */
  @Override
  public abstract IShape tween(int tick, IShape shapeToTween);
}
