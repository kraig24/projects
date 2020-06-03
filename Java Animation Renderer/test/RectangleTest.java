//import org.junit.Before;
//import org.junit.Test;
//
//import IModel;
//import Rectangle;
//import CS5004.*;
//import ShapeType;
//
//import static org.junit.Assert.assertEquals;
//
///**
// * A sequence of tests to make sure our rectangle produces the correct outputs.
// */
//public class RectangleTest {
//  IModel model;
//
//  private Rectangle rect;
//
//  @Before
//  public void setUp() throws Exception {
//    //rect = new Rectangle(1, 2, 3, 4, 5, 6, 7, 8, 8,
//      //      "A");
//    rect = model.addShape("r", ShapeType.RECTANGLE, 1, 2, 3, 4, 5, 6, 7, 8, 8);
//  }
//
//  @Test
//  public void toString1() {
//
//    assertEquals("\nType: rectangle\n" +
//            "Min Corner: (1,2), Width: 3.0, Height: 4.0, Color: (5,6,7)\n" +
//            "Appears at: ***STARTTIME***\n" +
//            "Disappears at: ***ENDTIMR***\n", rect.toString());
//  }
//}