package cs5004.animator.model;
/**
 * Created by vidojemihajlovikj on 7/24/19.
 */

/**
 * These are the specified kinds of shapes that we can currently have in our animation. Can be
 * appended later on, however we may just switch to using points rather than making more enumerated
 * types for the more complex shapes.
 */
public enum ShapeType {
  RECTANGLE {
    @Override
    public String toString() {
      return "Rectangle";
    }

  }, ELLIPSE {
    @Override
    public String toString() {
      return "Ellipse";
    }

  }
}
