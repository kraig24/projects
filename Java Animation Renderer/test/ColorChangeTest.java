//import org.junit.Before;
//import org.junit.Test;
//
//import ColorChange;
//import IModel;
//import IMotion;
//import Model;
//import ShapeType;
//
//import static org.junit.Assert.assertEquals;
//
///**
// * This class tests the functionality of the ColorChange class.
// */
//public class ColorChangeTest {
//  private IMotion color;
//
//
//  @Before
//  public void setUp() throws Exception {
//
//    IMotion color;
//    IModel model;
//
//
//    model = new Model();
//    model.addShape("A", ShapeType.RECTANGLE, 3, 4, 5, 6, 7, 8, 9, 0,
//            100);
//
//    color = new ColorChange(31, 40, 3, 4, 5, 6, 7,
//            8, 9, "A");
//    model.addMotion("A", color);
//
//  }
//
//
//  @Test
//  public void getStartTime() {
//    assertEquals(31, color.getStartTime());
//  }
//
//  @Test
//  public void getEndTime() {
//    assertEquals(40, color.getEndTime());
//  }
//
//  @Test
//  public void getID() {
//    assertEquals("A", color.getID());
//  }
//
//
//  @Test
//  public void getRed() {
//    assertEquals(7, color.getRed());
//  }
//
//  @Test
//  public void getBlue() {
//    assertEquals(9, color.getBlue());
//
//  }
//
//  @Test
//  public void getGreen() {
//    assertEquals(8, color.getGreen());
//
//  }
//}