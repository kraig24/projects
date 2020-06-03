package cs5004.animator.model;

/**
 * Created by vidojemihajlovikj on 7/24/19.
 */
public interface IShape extends Comparable<IShape> {

  /**
   * gets the x coordinate for the shape.
   *
   * @return - the x coordinate.
   */
  int getX();

  /**
   * gets the y coordinate for the shape.
   *
   * @return - the y value.
   */
  int getyValue();


  /**
   * gets the width for the shape.
   *
   * @return - the width, and integer.
   */
  double getWidth();

  /**
   * gets the height for the shape.
   *
   * @return - the height, an integer.
   */
  double getHeight();


  /**
   * gets the current RGB value for RED.
   *
   * @return - the RED value, an integer.
   */
  float getR();


  /**
   * gets the current RGB value for GREEN.
   *
   * @return the GREEN value, and integer.
   */
  float getG();


  /**
   * gets the current RGB value for BLUE.
   *
   * @return the BLUE value, an integer.
   */
  float getB();

  /**
   * sets the width to a new width. in scale.
   *
   * @param width - the new width the object should be.
   */
  void setWidth(double width);


  /**
   * sets the height to a new height, in scale.
   *
   * @param height the new height the object should be.
   */
  void setHeight(double height);

  /**
   * sets the x to a new location.
   *
   * @param x - the new x coordinate.
   */
  void setX(int x);


  /**
   * sets to new y value.
   *
   * @param y our new y val.
   */
  void setY(int y);

  /**
   * sets new red value.
   *
   * @param r - our new red val.
   */
  void setR(double r);

  /**
   * sets our new green value.
   *
   * @param g - the new green value.
   */
  void setG(double g);


  /**
   * sets the blue to e new value.
   *
   * @param b our new blue value.
   */
  void setB(double b);


  /**
   * Gets our starting time for our shape.
   *
   * @return the start time.
   */
  int getStart();


  /**
   * gets our end time.
   *
   * @return our end time.
   */
  int getEnd();


  /**
   * gets the ID of the shape.
   *
   * @return our ID.
   */
  String getID();


  /**
   * gets the shape type we are working with.
   *
   * @return our shape's type.
   */
  String getShapeType();


  /**
   * makes a copy of our current shape.
   *
   * @return and ishape that is identical to our current shape.
   */
  IShape makeCopy();

  /**
   * states whether the shape is insides our current tick.
   *
   * @param frame Our current frame.
   * @return true or fale if it is in the frame.
   */
  boolean containsTick(int frame);


}
