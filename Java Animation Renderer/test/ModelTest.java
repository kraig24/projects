//import org.junit.ComparisonFailure;
//import org.junit.Test;
//
//import ColorChange;
//import IModel;
//import IMotion;
//import Model;
//import Move;
//import Scale;
//import ShapeType;
//
//import static org.junit.Assert.assertEquals;
//import static org.junit.Assert.fail;
//
///**
// * tests to make sure that the model provides the correct output we are looking for.
// */
//public class ModelTest {
//  IModel model = new Model();
//
//  @Test
//  public void addMotionWithoutShape() {
//    try {
//      IMotion motion = new Move(31, 40, 100, 100, 200, 200,
//              "T");
//      model.addMotion("T", motion);
//      fail();
//    } catch (IllegalStateException e) {
//      /**
//       * success!
//       */
//    }
//
//  }
//
//  @Test
//  public void addMotion() {
//    model.addShape("T", ShapeType.ELLIPSE, 5, 6, 7, 8, 9, 10, 11, 1,
//            100);
//    IMotion motion = new Move(31, 40, 100, 100, 200, 200,
//            "T");
//    model.addMotion("T", motion);
//
//    assertEquals("Shapes:\n" +
//            "\n" +
//            "Name: T\n" +
//            "Type: Ellipse\n" +
//            "Center: (5,6), X radius: 7.0, Y radius: 8.0\n" +
//            "Shape T moves from (100,100) to (200,200) from t=31 to t=40", model.getState());
//
//
//  }
//
//  @Test
//  public void addShape() {
//    model.addShape("R", ShapeType.RECTANGLE, 2, 2, 10, 12, 5, 6, 7, 0,
//            20);
//
//
//    model.addShape("T", ShapeType.ELLIPSE, 5, 6, 7, 8, 9, 10, 11, 1,
//            100);
//
//    assertEquals("Shapes:\n" +
//            "Name: R \n" +
//            "Type: Rectangle\n" +
//            "Min Corner: (2,2), Width: 10, Height: 12, Color: (5,6,7)\n" +
//            "Appears at: t=0\n" +
//            "Disappears at: t=20\n" +
//            "\n" +
//            "Name: T \n" +
//            "Type: Ellipse\n" +
//            "Min Corner: (5,6), Width: 7, Height: 8, Color: (9,10,11)\n" +
//            "Appears at: t=1\n" +
//            "Disappears at: t=100\n\n", model.getState());
//
//  }
//
//  @Test
//  public void removeShape() {
//    model.removeShape("R");
//
//    assertEquals("Shapes:\n" +
//            "Name: T \n" +
//            "Type: Ellipse\n" +
//            "Min Corner: (5,6), Width: 7, Height: 8, Color: (9,10,11)\n" +
//            "Appears at: ***STARTTIME***\n" +
//            "Disappears at: ***ENDTIMR***\n\n", model.getState());
//  }
//
//
//  @Test
//  public void testNullShape() {
//    try {
//
//
//      model.addShape(null, null, 0, 0, 0, 0, 0, 0, 0, 0, 0);
//      assertEquals("t", model.getState());
//      fail();
//    } catch (IllegalArgumentException e) {
//      /**
//       * success!
//       */
//
//    }
//  }
//
//  @Test
//  public void testEmptyShape() {
//    model.addShape("Q", ShapeType.ELLIPSE, 0, 0, 0, 0, 0, 0, 0,
//            0, 0);
//    assertEquals("Shapes:\n" +
//            "\n" +
//            "Name: Q\n" +
//            "Type: Ellipse\n" +
//            "Center: (0,0), X radius: 0.0, Y radius: 0.0, Color: (0,0,0)\n" +
//            "Appears at: t=0\n" +
//            "Disappears at: t=0", model.getState());
//
//  }
//
//
//
//  @Test
//  public void testTwoShapesAtSameTime() {
//    try {
//
//
//      model.addShape("Q", ShapeType.ELLIPSE, 0, 0, 2, 4, 0, 0, 0,
//              0, 100);
//      model.addShape("R", ShapeType.ELLIPSE, 0, 0, 2, 4, 0, 0, 0,
//              0, 100);
//
//      IMotion motion = new ColorChange(1, 2, 2, 3, 4, 5,
//              6, 7, 8, "Q");
//      IMotion motionTwo = new ColorChange(1, 2, 2, 3, 4, 5,
//              4, 5, 6, "Q");
//      model.addMotion("Q", motion);
//      model.addMotion("Q", motionTwo);
//      fail();
//    } catch (IllegalStateException e) {
//      /** success!
//       *
//       */
//    }
//  }
//
//  @Test
//  public void testManyModelInputs() {
//    IMotion motion = new Move(31, 40, 100, 100, 200, 200,
//            "T");
//    IMotion scale = new Scale(3, 5, 50, 20, 60, 90,
//            "R");
//    model.addShape("R", ShapeType.RECTANGLE, 2, 2, 10, 12, 5, 6, 7,
//            0, 100);
//    IMotion motion2 = new ColorChange(29, 30, 100, 200, 100,
//            200, 2, 3, 4, "R");
//    model.addShape("T", ShapeType.ELLIPSE, 5, 6, 7, 8, 9, 10, 11,
//            30, 90);
//    model.addMotion("T", motion);
//    model.addMotion("R", motion2);
//    model.addMotion("R", scale);
//    model.addShape("Q", ShapeType.ELLIPSE, 5, 6, 7, 8, 9, 10, 11,
//            12, 75);
//
//    assertEquals("Shapes:\n" +
//            "\n" +
//            "Name: R\n" +
//            "Type: Rectangle\n" +
//            "Min corner: (2,2), Width: 10.0, Height: 12.0, Color: (5,6,7)\n" +
//            "Appears at: t=0\n" +
//            "Disappears at: t=100\n" +
//            "Name: Q\n" +
//            "Type: Ellipse\n" +
//            "Center: (5,6), X radius: 7.0, Y radius: 8.0, Color: (9,10,11)\n" +
//            "Appears at: t=12\n" +
//            "Disappears at: t=75\n" +
//            "Name: T\n" +
//            "Type: Ellipse\n" +
//            "Center: (5,6), X radius: 7.0, Y radius: 8.0, Color: (9,10,11)\n" +
//            "Appears at: t=30\n" +
//            "Disappears at: t=90\n" +
//            "Shape R scales from Width: 50, Height: 20 to Width: 60 Height: 90from t=3 to t=5\n" +
//            "Shape R changes color from (2,3,4) to (2,3,4) from t=29 to t=30\n" +
//            "Shape T moves from (100,100) to (200,200) from t=31 to t=40", model.getState());
//  }
//
//  @Test
//  public void testComparisonFail() {
//
//    try {
//      model.addShape("R", ShapeType.RECTANGLE, 2, 2, 10, 12, 5, 6, 7,
//              0, 100);
//      IMotion scaling = new Scale(1, 2, 3, 4, 5, 6, "Q");
//
//      model.addMotion("R", scaling);
//
//      assertEquals("", model.getState());
//      fail();
//    } catch (ComparisonFailure e) {
//      /**
//       * success!
//       */
//    }
//
//  }
//
//  @Test
//  public void testScaleRect() {
//    model.addShape("R", ShapeType.RECTANGLE, 2, 2, 10, 12, 5, 6, 7,
//            0, 100);
//    IMotion scaling = new Scale(1, 2, 3, 4, 5, 6, "R");
//
//    model.addMotion("R", scaling);
//
//    assertEquals("Shapes:\n" +
//                    "\n" +
//                    "Name: R\n" +
//                    "Type: Rectangle\n" +
//                    "Min corner: (2,2), Width: 10.0, Height: 12.0, Color: (5,6,7)\n" +
//                    "Appears at: t=0\n" +
//                    "Disappears at: t=100\n" +
//                    "Shape R scales from Width: 3, Height: 4 to Width: 5 Height: 6from
//                    t=1 to t=2",
//            model.getState());
//  }
//
//  @Test
//  public void testScaleEllipse() {
//    model.addShape("R", ShapeType.ELLIPSE, 2, 2, 10, 12, 5, 6, 7,
//            0, 100);
//    IMotion scaling = new Scale(1, 2, 3, 4, 5, 6, "R");
//
//    model.addMotion("R", scaling);
//
//    assertEquals("Shapes:\n" +
//                    "\n" +
//                    "Name: R\n" +
//                    "Type: Ellipse\n" +
//                    "Center: (2,2), X radius: 10.0, Y radius: 12.0, Color: (5,6,7)\n" +
//                    "Appears at: t=0\n" +
//                    "Disappears at: t=100\n" +
//                    "Shape R scales from Width: 3, Height: 4 to Width: 5 Height: 6from t=1 to
//                    t=2",
//            model.getState());
//  }
//}