package cs5004.animator.model;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

import cs5004.animator.util.TweenModelBuilder;

/**
 * This is our Model for generating an animation via a text output for a 2D easy animator.
 */
public class Model implements IModel {
  private int ticksPerSecond;
  java.util.Map<String, IShape> shapes;
  //java.util.Map<String, Integer> times;
  java.util.Map<IMotion, IShape> motionsToShapesMap = new HashMap<IMotion, IShape>();
  List<IMotion> motionList;
  //

  /**
   * The Model's constructor. This model takes no parameters, but makes two Hashmaps, one to pair
   * the shape's ID with an animated shape, and another to map the time to the ID.
   */
  public Model(int ticksPerSecond) {
    shapes = new java.util.LinkedHashMap<>();
    //times = new java.util.LinkedHashMap<String, Integer>();
    motionList = new ArrayList<>();
    this.ticksPerSecond = ticksPerSecond;


  }

  /**
   * Takes the ID of an animated shape and adds a motion to it. This is saved into an array for each
   * animated shape.
   *
   * @param id     A string that specifies which shape the user wants.
   * @param motion - a class object that is inherited from IMotion: so far can be Colorchange,
   *               Scale, and Move.
   */
  public void addMotion(String id, IMotion motion) throws IllegalStateException {

    IShape shape = shapes.get(id);
    if (shapeCheck(id, motion.getStartTime(), motion.getEndTime())) {
      if (motionCheck(motion)) {
        motionList.add(motion);
        motionsToShapesMap.put(motion, shape);
      } else {
        throw new IllegalStateException("Motion check");
      }
      // shape.

    } else {
      throw new IllegalStateException("This movement conflicts with an existing one!\n");
    }


  }

  /**
   * is a checker for our shapes to see if the shape is currently in the hashmap.
   *
   * @param id    - the string Id to look up the shape.
   * @param start - the start time for the motion.
   * @param end   - the end time for the motion.
   * @return a boolean whether or not the shape is in there and it supports an addition.
   */
  private boolean shapeCheck(String id, int start, int end) {
    IShape container = shapes.get(id);
    if (container == null) {
      return false;
    } else {
      return start >= container.getStart() && end <= container.getEnd();
    }
  }


  /**
   * is a checker to se if we can add a motion to the shape without any errors.
   *
   * @param motion - the current IMotion we are trying to add.
   * @return true if it would be successful, false otherwise.
   */
  private boolean motionCheck(IMotion motion) {
    for (IMotion i : motionList
    ) {
      if (i.getID().equals(motion.getID()) && i.getClass().equals(motion.getClass())) {
        if (!(i.getEndTime() < motion.getEndTime() || i.getStartTime() > motion.getStartTime())) {
          return false;
        }
      }


    }
    return true;
  }


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
  public void addShape(String id, ShapeType type,
                       int x, int y, int w, int h, float r, float g, float b, int start, int end) {

    if (id == null || type == null) {
      throw new IllegalArgumentException("Can't have null inputs");
    }
    IShape shape;

    switch (type) {
      case RECTANGLE:
        shape = new Rectangle(x, y, w, h, r, g, b, start, end, id);

        break;
      case ELLIPSE:
        shape = new Ellipse(x, y, w, h, r, g, b, start, end, id);
        break;
      default:
        shape = null;
    }
    if (shape != null) {

      //This seems to pass in the data we need right now -TM
      // AnimatedShape animatedShape = new AnimatedShape(shape);
      shapes.putIfAbsent(id, shape);

    }
  }

  /**
   * Removes a shape from our hashmap by looking it up by the specified key which is a string.
   *
   * @param id - the specified string key.
   */
  @Override
  public void removeShape(String id) {
    shapes.remove(id);
  }


  /**
   * returns the list of current Animated shapes saved in the hashmap by iterating over the hashmap
   * by key value, which in our case is the String ID. Then, we simply call on the shapes toString
   * to print the custom output for us.
   *
   * @return a Concatenated String that has all of our current shapes in the specified format.
   */
  @Override
  public String getState() {
    //TODO: append data following the correct format to the stringbuilder
    //String data = "Shapes:\n";
    ArrayList<IShape> container = new ArrayList<>(shapes.values());

    StringBuilder data = new StringBuilder();
    data.append("Shapes:\n");
    Collections.sort(container);
    for (IShape shape : container
    ) {
      data.append("\nName: ").append(shape.getID()).append("\n").append("Type: ")
              .append(shape.getShapeType()).append("\n");
      if (shape.getShapeType().equals("Rectangle")) {
        data.append("Min corner: (").append(shape.getX()).append(",").append(shape.getyValue())
                .append("), Width: ").append(shape.getWidth()).append(", Height: ")
                .append(shape.getHeight());
        break;
      } else if (shape.getShapeType().equals("Ellipse")) {
        data.append("Center: (").append(shape.getX()).append(",").append(shape.getyValue())
                .append("), X radius: ").append(shape.getWidth()).append(", Y radius: ")
                .append(shape.getHeight());
        break;

      }
      double startSecond = shape.getStart() / ticksPerSecond;
      double endSecond = shape.getEnd() / ticksPerSecond;
      data.append(", Color: (").append(shape.getR() * 255).append(",")
              .append(shape.getG() * 255).append(",").append(shape.getB() * 255).append(")")
              .append("\nAppears at: t=").append(startSecond).append("\nDisappears at: t=")
              .append(endSecond);

    }


    Collections.sort(motionList);
    for (int i = 0; i < motionList.size(); i++) {
      data.append("\nShape ").append(motionList.get(i).getID());

      switch (motionList.get(i).getMoveType()) {
        case "Move":
          data.append(" moves from (")
                  .append(motionList.get(i).getStartX()).append(",").append(motionList.get(i)
                  .getStartY()).append(") to (").append(motionList.get(i).getEndX()).append(",")
                  .append(motionList.get(i).getEndY()).append(") ");
          break;
        case "Color":
          data.append(" changes color from (").append(motionList.get(i).getRed()).append(",")
                  .append(motionList.get(i).getGreen() * 255).append(",")
                  .append(motionList.get(i).getBlue() * 255).append(") to (")
                  .append(motionList.get(i).getRed() * 255).append(",")
                  .append(motionList.get(i).getGreen() * 255).append(",")
                  .append(motionList.get(i).getBlue() * 255).append(") ");
          break;
        case "Scale":
          data.append(" scales from Width: ").append(motionList.get(i).getStartX())
                  .append(", Height: ").append(motionList.get(i).getStartY()).append(" to Width: ")
                  .append(motionList.get(i).getEndX()).append(" Height: ")
                  .append(motionList.get(i).getEndY());
          break;

        default:
          /**
           * not used but needed for javadocs.
           */
      }

      //double startSecond = motionList.get(i).getStartTime() / ticksPerSecond;
      // double endSecond = motionList.get(i).getEndTime() / ticksPerSecond;
      data.append("from t=").append(tickConversion(motionList.get(i).getStartTime(),
              ticksPerSecond)).append(" to t=")
              .append(tickConversion(motionList.get(i).getEndTime(), ticksPerSecond));

    }

    //recan hardcode this part
    //TODO: get time data, decide how to pass ID to AnimatedShape class -TM
    //for (String key : shapes.keySet()) {
    //data += "Name: " + key + " " + shapes.get(key).toString() + "\n";

    //}
    return data.toString();
  }

  /**
   * Finds the maximum height we need to make our display box.
   *
   * @return an integer, representing the minimum height we need for our view box.
   */
  private int getSvgHeight() {
    ArrayList<Integer> temp = new ArrayList<>();

    for (IMotion iMotion : motionList) {
      temp.add(iMotion.getStartY());
      temp.add(iMotion.getEndY());
    }
    return Collections.max(temp) * 2;
  }

  /**
   * a getter to receive the width of the svg we are working with.
   *
   * @return an integer representing the maximum size we need to make our display.
   */
  private int getSvgWidth() {
    ArrayList<Integer> temp = new ArrayList<>();

    for (IMotion iMotion : motionList) {
      temp.add(iMotion.getStartX());
      temp.add(iMotion.getEndX());
    }
    return Collections.max(temp) * 2;
  }

  /**
   * A helper function that outputs the result of the motions of a shape.
   *
   * @param shape   an IShape taken from an array of IShapes.
   * @param iMotion an IMotion taken from a list of IMotions
   */
  private String motionHelper(IShape shape, IMotion iMotion) {
    StringBuilder temp = new StringBuilder();
    switch (iMotion.getMoveType()) {
      case "Move":
        String template = temp.append("<animate attributeType=\"xml\"").toString();
        String time = temp.append(" begin =\"")
                .append(tickConversion(iMotion.getStartTime(), ticksPerSecond))
                .append("\" dur=\"").append(tickConversion(iMotion.getEndTime()
                        - iMotion.getStartTime(), ticksPerSecond))
                .append("\"").toString();
        temp.append(" attributeName=\"x\" from=\"").append(iMotion.getStartX()).append("\" to= \"")
                .append(iMotion.getEndX()).append("\" fill =\"freeze\"></animate>\n");
        temp.append(time).append(" attributeName=\"y\" from=\"").append(iMotion.getStartY())
                .append("\" to= \"").append(iMotion.getEndY())
                .append("\" fill =\"freeze\"></animate>\n");
        break;
      case "Scale":
        temp.append("<animateTransform attributeType=\"xml\" begin=\"")
                .append(tickConversion(iMotion.getStartTime(), ticksPerSecond)).append("\" dur=\"")
                .append(tickConversion(iMotion.getEndTime() - iMotion.getStartTime(),
                        ticksPerSecond))
                .append("\" attributeName=\"transform\" type=\"scale\" from=\"")
                .append(iMotion.getOldWidth()).append(",").append(iMotion.getOldHeight())
                .append("\" to\"").append(iMotion.getNewWidth()).append(",")
                .append(iMotion.getNewHeight()).append("\" additive=\"sum\" fill=\"freeze\" />");
        break;

      case "Color":
        temp.append("<animate attributeType=\"xml\" begin=\"")
                .append(tickConversion(iMotion.getStartTime(), ticksPerSecond)).append("\" dur=\"")
                .append(tickConversion(iMotion.getEndTime() - iMotion.getStartTime(),
                        ticksPerSecond)).append("\" attributeName=\"fill\" to=\"rgb(")
                .append(shape.getR()).append(",").append(shape.getG()).append(",")
                .append(shape.getB()).append(")\" fill=\"freeze\" />");
        break;
      default:
        throw new IllegalArgumentException("Program does not recognize this motion: " + iMotion);
    }

    return temp.toString();
  }

  /**
   * Compiles the text we need to makeour SVG animation using a variety of getters.
   *
   * @return a String that is later sent to the view and transmitted into a file that can be run.
   */
  @Override
  public String svgState() {
    ArrayList<IShape> container = new ArrayList<>(shapes.values());
    StringBuilder data = new StringBuilder();
    data.append("<svg width =\"").append(getSvgWidth()).append("\" height=\"")
            .append(getSvgHeight())
            .append("\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n");
    Collections.sort(container);
    Collections.sort(motionList);
    for (IShape shape : container) {
      if (shape.getShapeType().equals("Rectangle")) {
        data.append("<rect id=\"").append(shape.getID()).append("\" x=\"").append(shape.getX())
                .append("\" y =\"").append(shape.getyValue()).append("\" width=\"")
                .append(shape.getWidth()).append("\" height =\"").append(shape.getHeight())
                .append("\" fill =\"rgb(").append(shape.getR() * 255).append(",")
                .append(shape.getB() * 255)
                .append(",").append(shape.getG() * 255).append(")\" visibility =\"")
                .append("visible").append("\">\n");
        // Iterates through shapes and motions, and if the IDs match uses a helper function to
        // add output to an SVG file.
        for (IMotion iMotion : motionList) {
          if (shape.getID().equals(iMotion.getID())) {
            //change to ticks per second
            String temp = motionHelper(shape, iMotion);
            data.append(temp);
          }
        }
        data.append("</rect>");
      }
      if (shape.getShapeType().equals("Ellipse")) {
        data.append("THIS IS AN ELLIPSE");
        data.append("<ellipse id=\"").append(shape.getID()).append("\" cx=").append(shape.getX())
                .append("\" cy =\"").append(shape.getyValue()).append("\"x-radius=\"")
                .append(shape.getWidth() / 2).append("\" y-radius =\"")
                .append(shape.getHeight() / 2)
                .append("\" fill =\"rgb(").append(shape.getR() * 255).append(",")
                .append(shape.getB() * 255)
                .append(",").append(shape.getG() * 255).append(")\" visibility =\"")
                .append("visible").append("\">\n");

        for (IMotion iMotion : motionList) {
          if (shape.getID().equals(iMotion.getID())) {
            //change to ticks per second
            String temp = motionHelper(shape, iMotion);
            data.append(temp);
          }
        }
        data.append("</ellipse>");
      }
    }
    data.append("\n</svg>");
    return data.toString();
  }

  private int tickConversion(int start, int tick) {
    int dur = (start / tick);
    if (dur == 0) {
      dur = 1;
    }
    return dur;
  }

  /**
   * this has not been implemented yet, but will store all of the shapes at a specified tick value.
   * Can be used to rewind, or speed up/ slow down our tick value later on if that is a function we
   * need.
   *
   * @param frame - a specified tick value for the time.
   * @return a list of Ishapes for that current tick time.
   */
  @Override
  public List<IShape> getAllShapesAtFrame(int frame) {
    //list with original shape, another with new shape
    ArrayList<IShape> geometricShapes = new ArrayList<>(shapes.values());

    Collections.sort(motionList);

    // List<IShape> newShapes = new ArrayList<IShape>();
    Collections.sort(geometricShapes);
    //currently only returns shape in motion
    //traverse through motion and shapes in a loop, and update new list
    IShape newShape = null;
    for (IMotion motion : motionList) {
      //for (IShape shape: geometricShapes) {

      // geometricShapes.set(geometricShapes.indexOf(shape), shape);
      if (motion.containsTick(frame)) {
        newShape = motion.tween(frame, motionsToShapesMap.getOrDefault(motion, null));
      }
    }

    return geometricShapes;
  }

  /**
   * This is the modelbuilder that was provided in the assignment.
   *
   * @param ticksPerSecond - retrieved from the console commands.
   * @return a model builder, that generates a model from file data.
   */
  public static TweenModelBuilder getBuilder(int ticksPerSecond) {
    return new ModelBuilder(ticksPerSecond);
  }

  /**
   * A class that utilizes the builder pattern to generate a model.
   */
  public static class ModelBuilder implements TweenModelBuilder {
    IModel model;

    /**
     * builds a model from scratch by reading in file data.
     *
     * @param ticksPerSecond - the speed we want the animations to play.
     */
    public ModelBuilder(int ticksPerSecond) {
      model = new Model(ticksPerSecond);
    }


    @Override
    public TweenModelBuilder addOval(String name, float cx, float cy, float xRadius, float yRadius,
                                     float red, float green, float blue, int startOfLife,
                                     int endOfLife) {
      model.addShape(name, ShapeType.ELLIPSE, (int) cx, (int) cy, (int) xRadius, (int) yRadius,
              red, green, blue, startOfLife, endOfLife);

      return this;
    }

    @Override
    public TweenModelBuilder addRectangle(String name, float lx, float ly, float width,
                                          float height, float red, float green, float blue,
                                          int startOfLife, int endOfLife) {
      model.addShape(name, ShapeType.RECTANGLE, (int) lx, (int) ly, (int) width, (int) height,
              red, green, blue, startOfLife, endOfLife);
      return this;
    }

    @Override
    public TweenModelBuilder addMove(String name, float moveFromX, float moveFromY, float moveToX,
                                     float moveToY, int startTime, int endTime) {
      IMotion move = new Move(startTime, endTime, (int) moveFromX, (int) moveFromY, (int) moveToX
              , (int) moveToY, name);
      model.addMotion(name, move);
      return null;
    }

    @Override
    public TweenModelBuilder addColorChange(String name, float oldR, float oldG, float oldB,
                                            float newR, float newG, float newB, int startTime,
                                            int endTime) {
      //TODO: this hands randoms zeroes because color doesn't give us any start and end coordinates.
      //TODO: actually get this to pass correct parameters -TM
      IMotion color = new ColorChange(startTime, endTime, 0, 0, 0, 0,
              oldR, oldG, oldB, newR, newG, newB, name);
      model.addMotion(name, color);
      return null;
    }

    @Override
    public TweenModelBuilder addScaleToChange(String name, float fromSx, float fromSy, float toSx,
                                              float toSy, int startTime, int endTime) {

      IMotion scale = new Move(startTime, endTime, (int) fromSx, (int) fromSy, (int) toSx,
              (int) toSy, name);
      model.addMotion(name, scale);
      return null;
    }

    /**
     * builds our model after everything has been compiled.
     *
     * @return a new Model that we can call data from.
     */
    @Override
    public IModel build() {
      return model;
    }
  }
}


