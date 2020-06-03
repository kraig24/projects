package cs5004.animator.model;

/**
 * these are specified commands that I can have formatted through a switch statement later on. I
 * learned my lesson from the marble assignment and know that using strings is a bad idea.
 */
public enum MoveTypes {
  MOVE {
    @Override
    public String toString() {
      return "Move";
    }

  }, COLORCHANGE {
    @Override
    public String toString() {
      return "Color";
    }

  }, SCALE {
    @Override
    public String toString() {
      return "Scale";
    }

  }
}
