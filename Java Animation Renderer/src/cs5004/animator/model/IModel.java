package cs5004.animator.model;

/**
 * Created by vidojemihajlovikj on 7/24/19.
 */
public interface IModel {

  /**
   * Adds a shape into the model to be stored. Upon successful creation, an animated shape is
   * generated. this is what is stored into our hashmap. An animated shape is an IShape that can be
   * changed using our motions.
   *
   * @param id   - string key used to fins the shape later on.
   * @param type - can either be a rectangle or Ellipse right now.
   * @param x    - starting x coordinate for the startpoint.
   * @param y    - starting y coordinate for the startpoint.
   * @param w    - starting width of the shape.
   * @param h    - starting height for the shape.
   * @param r    - starting RED color number.
   * @param g    - starting GREEN color number.
   * @param b    - starting BLUE color number.
   */
  void addShape(String id, ShapeType type, int x, int y, int w, int h, float r, float g, float b,
                int start, int end);


  /**
   * Removes a shape from our hashmap by looking it up by the specified key which is a string.
   *
   * @param id - the specified string key.
   */
  void removeShape(String id);


  /**
   * returns the list of current Animated shapes saved in the hashmap by iterating over the hashmap
   * by key value, which in our case is the String ID. Then, we simply call on the shapes toString
   * to print the custom output for us.
   *
   * @return a Concatenated String that has all of our current shapes in the specified format.
   */
  String getState();

  /**
   * adds a motion to an IShape.
   *
   * @param id     the string id we use to look it up.
   * @param motion our current motion.
   */
  void addMotion(String id, IMotion motion);

  String svgState();


  /**
   * this has not been implemented yet, but will store all of the shapes at a specified tick value.
   * Can be used to rewind, or speed up/ slow down our tick value later on if that is a function we
   * need.
   *
   * @param frame - a specified tick value for the time.
   * @return a list of Ishapes for that current tick time.
   */
  java.util.List<IShape> getAllShapesAtFrame(int frame);
}


