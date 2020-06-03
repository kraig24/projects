import org.junit.Test;

import cs5004.animator.view.IView;
import cs5004.animator.view.ViewFactory;

import static org.junit.Assert.fail;


/**
 * A place to store our general tests for view that aren't output specific.
 */
public class ViewGeneral {

  @Test
  public void testInvalidTestType() {
    try {


      String address = "C:\\Users\\Kraig\\Desktop\\hw9\\src\\CS5004\\animator";
      IView view = ViewFactory.makeView("WRONG", address, "10");
      fail();
    } catch (IllegalArgumentException e) {
      /**
       * success!
       */
    }

  }
}