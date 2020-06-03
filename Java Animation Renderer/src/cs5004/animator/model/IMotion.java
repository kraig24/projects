package cs5004.animator.model;

/**
 * An interfact to encapsulate what each kind of motion change needs to be able to do.
 */
public interface IMotion extends Comparable<IMotion> {

  /**
   * sets the start time for when this motion will occur.
   *
   * @param t1 the starting tick.
   */
  void setStartTime(int t1);


  /**
   * sets the end time for when this motion will end.
   *
   * @param t2 - the ending tick time.
   */
  void setEndTime(int t2);


  /**
   * sets the starting coordiate for the X coordinate of the shape we are working with.
   *
   * @param x - the starting x coordinate.
   */
  void setStartX(int x);

  /**
   * sets the starting coordinate for the y coordinate of the shape we are working with.
   *
   * @param y - the starting y coordinate.
   */
  void setStartY(int y);

  /**
   * sets the ending coordinate for the x coordinate of the shape we are working with.
   *
   * @param x - the starting x coordinate.
   */
  void setEndX(int x);


  /**
   * sets the ending coordinate for the y coordinate of the shape we are working with.
   *
   * @param y - the starting y coordinate.
   */
  void setEndY(int y);

  /**
   * Gets the start time of a motion.
   *
   * @return an int, the tick at which a motion starts.
   */
  int getStartTime();


  boolean containsTick(int tick);

  /**
   * Gets the end time of a motion.
   *
   * @return an int, the tick at which a motion ends.
   */
  int getEndTime();

  /**
   * gets our startX.
   *
   * @return startx.
   */
  int getStartX();


  /**
   * gets our current startY.
   *
   * @return the starting y value.
   */
  int getStartY();


  /**
   * gets the ending X value.
   *
   * @return the ending x value.
   */
  int getEndX();


  /**
   * gets the ending y value.
   *
   * @return the ending y value.
   */
  int getEndY();


  /**
   * gets our move type.
   *
   * @return the move type: color, move, scale.
   */
  String getMoveType();


  /**
   * gets the string ID we can use to look up a shape.
   *
   * @return a string that represents the ID of a shape.
   */
  String getID();


  /**
   * gets our red value.
   *
   * @return the red value.
   */
  float getRed();


  /**
   * gets our blue value.
   *
   * @return the blue value.
   */
  float getBlue();

  /**
   * gets our green value.
   *
   * @return the green value.
   */
  float getGreen();


  /**
   * gets our newHeight.
   *
   * @return the new height.
   */
  double getNewHeight();

  /**
   * gets the newWidth.
   *
   * @return the newWidth.
   */
  double getNewWidth();

  /**
   * gets the new width.
   *
   * @return the new width.
   */
  double getOldWidth();


  /**
   * gets our old height.
   *
   * @return the old height.
   */
  double getOldHeight();

  /**
   * figured out the value of a shape in mid transformation.
   *
   * @param tick         the current spot in the animation playing time we are at.
   * @param shapeToTween - the shape being tweened.
   * @return an int value showing how far in the transformation we currently are.
   */
  IShape tween(int tick, IShape shapeToTween);

}
