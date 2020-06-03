package cs5004.animator.model;

/**
 * this is an abstract class to minimixe code reproduction for our motion classes.
 */
public abstract class Motions implements IMotion {
  protected String shape;

  protected int startTime;
  protected int endTime;
  protected int startX;
  protected int startY;
  protected int endX;
  protected int endY;
  protected MoveTypes type;


  protected Motions(int startTime, int endTime, int startX, int startY, int endX, int endY) {
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
}
