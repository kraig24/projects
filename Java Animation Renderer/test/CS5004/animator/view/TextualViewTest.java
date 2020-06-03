

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.io.FileNotFoundException;

import cs5004.animator.controller.Controller;
import cs5004.animator.model.IModel;
import cs5004.animator.model.Model;
import cs5004.animator.view.IView;
import cs5004.animator.view.TextualView;

import static junit.framework.TestCase.assertEquals;
import static org.junit.jupiter.api.Assertions.fail;

/**
 * A class to test our textual output and see if all functionality works correctly.
 */
public class TextualViewTest {
  private IView view;


  @Before
  public void setUp() throws Exception {
    IModel model = new Model(10);
    view = new TextualView(10, "C:\\Users\\Kraig\\Desktop\\hw9");
    Controller controller = new Controller(view, model);
  }

  @Test
  public void renderMakesFile() {
    try {
      view.render("test");

    } catch (FileNotFoundException e) {
      fail();
    }

  }

  @Test
  public void renderDoesntMakeFile() {
    try {
      view.render("test");
      fail();
    } catch (FileNotFoundException e) {
      /**
       * success!
       */
    }


  }

  @org.junit.Test
  public void setVisible() {
    view.setVisible(true);

    Assert.assertEquals(true, view.getViewType());
  }


  @Test
  public void getViewType() {
    assertEquals("svg", view.getViewType());
  }

  @Test
  public void testNullModel() {
    try {
      view.render("");
      assertEquals("error", view.toString());
    } catch (FileNotFoundException e) {
      /**
       * success!
       */
    }
  }

  @Test
  public void checkRightSVG() {
    String renderable = "rectangle name disk1 min-x 190.0 min-y 180.0 width 20.0 height 30 color " +
            "0.0018560142 0.19547537 0.35467055 from 1 to 302\n" +
            "rectangle name disk2 min-x 167.5 min-y 210.0 width 65.0 height 30 color" +
            " 0.02582317 0.9691984 0.16393086 from 1 to 302\n" +
            "rectangle name disk3 min-x 145.0 min-y 240.0 width 110.0 height 30 color " +
            "0.044487324 0.17937791 0.6875181 from 1 to 302\n" +
            "move name disk1 moveto 190.0 180.0 190.0 50 from 25 to 35\n" +
            "move name disk1 moveto 190.0 50 490.0 50 from 36 to 46\n" +
            "move name disk1 moveto 490.0 50 490.0 240.0 from 47 to 57\n" +
            "move name disk2 moveto 167.5 210.0 167.5 50 from 57 to 67\n" +
            "move name disk2 moveto 167.5 50 317.5 50 from 68 to 78\n" +
            "move name disk2 moveto 317.5 50 317.5 240.0 from 79 to 89\n" +
            "move name disk1 moveto 490.0 240.0 490.0 50 from 89 to 99\n" +
            "move name disk1 moveto 490.0 50 340.0 50 from 100 to 110\n" +
            "move name disk1 moveto 340.0 50 340.0 210.0 from 111 to 121\n" +
            "move name disk3 moveto 145.0 240.0 145.0 50 from 121 to 131\n" +
            "move name disk3 moveto 145.0 50 445.0 50 from 132 to 142\n" +
            "move name disk3 moveto 445.0 50 445.0 240.0 from 143 to 153\n" +
            "change-color name disk3 colorto 0.044487324 0.17937791 0.6875181 0 1 0  from " +
            "153 to 161\n" +
            "move name disk1 moveto 340.0 210.0 340.0 50 from 153 to 163\n" +
            "move name disk1 moveto 340.0 50 190.0 50 from 164 to 174\n" +
            "move name disk1 moveto 190.0 50 190.0 240.0 from 175 to 185\n" +
            "move name disk2 moveto 317.5 240.0 317.5 50 from 185 to 195\n" +
            "move name disk2 moveto 317.5 50 467.5 50 from 196 to 206\n" +
            "move name disk2 moveto 467.5 50 467.5 210.0 from 207 to 217\n" +
            "change-color name disk2 colorto 0.02582317 0.9691984 0.16393086 0 1 0  from 217 to " +
            "225\n" +
            "move name disk1 moveto 190.0 240.0 190.0 50 from 217 to 227\n" +
            "move name disk1 moveto 190.0 50 490.0 50 from 228 to 238\n" +
            "move name disk1 moveto 490.0 50 490.0 180.0 from 239 to 249\n" +
            "change-color name disk1 colorto 0.0018560142 0.19547537 0.35467055 0 1 0  from 249 " +
            "to 257\n";
    try {
      view.render(renderable);
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }

    assertEquals(renderable, view.toString());
  }

  @Test
  public void checkValidOutputDir() {
    Assert.assertEquals("C:\\Users\\Kraig\\Desktop\\hw9", view.getViewType());
  }


}