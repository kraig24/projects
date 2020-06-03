package cs5004.animator.model;

/**
 * Created by vidojemihajlovikj on 7/31/19.
 */
public class ViewShape {
  private int x;
  private int y;
  private int w;
  private int h;
  private float r;
  private float g;
  private float b;
  private String type;

  /**
   * makes a view shape that is sent to the view later on.
   *
   * @param shape the shape we are sending to the view.
   */
  public ViewShape(IShape shape) {
    x = shape.getX();
    y = shape.getyValue();
    w = (int) shape.getWidth();
    h = (int) shape.getHeight();
    r = shape.getR();
    g = shape.getG();
    b = shape.getB();
    type = shape.getShapeType();
  }


  /**
   * returns our current x.
   *
   * @return current x.
   */
  public int getX() {
    return x;
  }

  /**
   * returns our current y value.
   *
   * @return current y val.
   */
  public int getY() {
    return y;
  }

  /**
   * gets our current width.
   *
   * @return the current width val.
   */
  public int getW() {
    return w;
  }

  /**
   * gets our current height.
   *
   * @return the current height.
   */
  public int getH() {
    return h;
  }

  /**
   * gets our current red value.
   *
   * @return the current red.
   */
  public float getRed() {
    return this.r;
  }


  /**
   * gets our current green value.
   *
   * @return the current green val.
   */
  public float getG() {
    return this.g;
  }

  /**
   * gets our current blue value.
   *
   * @return our current b val.
   */
  public float getB() {
    return this.b;
  }


  /**
   * gets our current shape type.
   *
   * @return the shape type.
   */
  public String getShapeType() {
    return type;
  }
}
