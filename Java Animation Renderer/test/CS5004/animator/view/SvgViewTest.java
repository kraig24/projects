import org.junit.Test;

import java.io.FileNotFoundException;

import cs5004.animator.controller.Controller;
import cs5004.animator.model.IModel;
import cs5004.animator.model.Model;
import cs5004.animator.view.IView;
import cs5004.animator.view.SvgView;

import static junit.framework.TestCase.assertEquals;
import static org.junit.Assert.fail;


/**
 * tests for our SVG view to make sure it can write to a file, and render correctly.
 */
public class SvgViewTest {
  private IView view;


  @org.junit.Before
  public void setUp() throws Exception {
    IModel model = new Model(10);
    view = new SvgView(10, "C:\\Users\\Kraig\\Desktop\\hw9");
    Controller controller = new Controller(view, model);
  }

  @org.junit.Test
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

    assertEquals(true, view.getViewType());
  }


  @Test
  public void getViewType() {
    assertEquals("svg", view.getViewType());
  }

  @Test
  public void testNullModel() {

    assertEquals("error", view.toString());
    try {
      view.render("");

    } catch (FileNotFoundException e) {
      /**
       * success!
       */
    }
  }

  @Test
  public void checkRightSVG() {
    String renderable = "\n" +
            "<!--the overall svg width is 560 and height is 430. By default anything\n" +
            "drawn between (0,0) and (width,height) will be visible -->\n" +
            "<svg width=\"700\" height=\"500\" version=\"1.1\"\n" +
            "     xmlns=\"http://www.w3.org/2000/svg\">\n" +
            "\n" +
            "     <!--We add a faux rectangle and keep it hidden\n" +
            "     This rectangle merely provides a reference time for all\n" +
            "     the other shapes. This is for loopback.\n" +
            "     \n" +
            "     -->\n" +
            "<rect>\n" +
            "    <!-- This is the loop back. Set duration for the duration of one\n" +
            "    animation before loopback. Ensure that this number is greater than \n" +
            "    the end of one complete animation-->\n" +
            "    <!-- this example loops back after 10 seconds -->\n" +
            "   <animate id=\"base\" begin=\"0;base.end\" dur=\"10000.0ms\" " +
            "attributeName=\"visibility\" from=\"hide\" to=\"hide\"/>\n" +
            "</rect>\n" +
            "     \n" +
            "<!--A red rectangle named R with lower left corner (200,200), " +
            "width 50 and height 100 -->\n" +
            "<rect id=\"R\" x=\"200\" y=\"200\" width=\"50\" height=\"100\" fill=\"rgb(255,0,0)\" "
            +
            "visibility=\"visible\" >\n" +
            "    <!-- starting at time=1s relative to base.begin, move the rectangle horizontally "
            +
            "from x=200 to x=300 in 4 seconds -->\n" +
            "    <!-- fill=freeze keeps it there after the animation ends -->\n" +
            "    <animate attributeType=\"xml\" begin=\"base.begin+1000ms\" dur=\"4000ms\"" +
            " attributeName=\"x\" from=\"200\" to=\"300\" fill=\"freeze\" />\n" +
            "\n" +
            "    <!-- at the end, restore all changed attributes with an instant animation of " +
            "1ms d" +
            "uration at the end -->    \n" +
            "    <animate attributeType=\"xml\" begin=\"base.end\" dur=\"1ms\" " +
            "attributeName=\"x\" " +
            "to=\"200\" fill=\"freeze\" />\n" +
            "    \n" +
            "    <!--add more animations here for this rectangle using animate tags -->\n" +
            "</rect>\n" +
            "\n" +
            "<!--A blue ellipse named \"C\" with center at (500,100), x-radius 60 and y-radius " +
            "30 -->\n" +
            "<ellipse id=\"C\" cx=\"500\" cy=\"100\" rx=\"60\" ry=\"30\" fill=\"rgb(0,0,255)\" " +
            "visibility=\"visible\" >\n" +
            "    <!-- starting at time=2s relative to base.begin, move the ellipse's center" +
            " from (500,100) to (600,400) in 5 seconds -->\n" +
            "    <!-- fill=remove, which is the default if you don't specify it, brings the " +
            "shape back to its original attributes after \n" +
            "    this animation is over -->\n" +
            "    <animate attributeType=\"xml\" begin=\"base.begin+2000.0ms\" dur=\"5000.0ms\" " +
            "attributeName=\"cx\" from=\"500\" to=\"600\" fill=\"remove\" />\n" +
            "    <animate attributeType=\"xml\" begin=\"base.begin+2000.0ms\" dur=\"5000.0ms\"" +
            " attributeName=\"cy\" from=\"100\" to=\"400\" fill=\"remove\" />\n" +
            "    <!--add more animations here for this circle using animate tags -->\n" +
            "    \n" +
            "    <!-- at the end, restore all changed attributes with an " +
            "instant animation of 1ms " +
            "duration at the end -->    \n" +
            "    <animate attributeType=\"xml\" begin=\"base.end\" dur=\"1ms\" " +
            "attributeName=\"cx\" to=\"500\" fill=\"freeze\" />\n" +
            "    <animate attributeType=\"xml\" begin=\"base.end\" dur=\"1ms\" " +
            "attributeName=\"cy\" to=\"100\" fill=\"freeze\" />\n" +
            "    \n" +
            "</ellipse>\n" +
            "\n" +
            "</svg>\n";
    try {
      view.render(renderable);
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }

    assertEquals(renderable, view.toString());
  }

  @Test
  public void checkValidOutputDir() {
    assertEquals("C:\\Users\\Kraig\\Desktop\\hw9", view.getViewType());
  }
}
