package cs5004.animator.model;

/**
 * A class that represents moving an IShape from one spot to another.
 */
public class Move extends AbstractMotion {


  /**
   * same constrcutor as AbstractMotion, an abstract class + a id object to transmute.
   *
   * @param startTime - as stated
   * @param endTime   - as stated.
   * @param startX    - starting x spot.
   * @param startY    starting y spot.
   * @param endX      - ending x spot.
   * @param endY      - ending y spot.
   * @param id        - id to be worked on.
   */
  protected Move(int startTime, int endTime, int startX, int startY, int endX, int endY,
                 String id) {
    super(startTime, endTime, startX, startY, endX, endY);
    this.shape = id;
    this.type = MoveTypes.MOVE;
  }


  //TODO: figure out if this should be IShape or AnimatedShape for all the motions.


  /**
   * this generates an entirely new shape that uses setters to change the original ishape we were
   * handed.
   *
   * @return a new IShape that can be stored at a specific frame later on.
   */

  @Override
  public int getStartTime() {
    return this.startTime;
  }

  @Override
  public IShape tween(int tick, IShape shapeToTweeen) {
    IShape shape = shapeToTweeen;
    double newX = tweenHelper(this.getStartX(), this.getEndX(), this.startTime, this.endTime, tick);
    double newY = tweenHelper(this.getStartY(), this.getEndY(), this.startTime, this.endTime, tick);
    shape.setX((int) newX);
    shape.setY((int) newY);

    return shape;
  }

  @Override
  public String getID() {
    return this.shape;
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

  @Override
  public int compareTo(IMotion motion) {
    return this.startTime - motion.getStartTime();


  }

}
