package cs5004.animator.view;

/**
 * A class that generates a view based on the type the user specifies.
 */
public class ViewFactory {
  /**
   * Generates a view via a switch statement that checks for the String specifier in console.
   *
   * @param viewType - the String referenced above. is either SVG or Text.
   * @param output   the file we want to latter write to. its full location is specified.
   * @param ticks    - the speed we want the animation to play at.
   * @return a new view that is later handled in main.
   * @throws IllegalArgumentException - if viewType is not text or SVG.
   */
  public static IView makeView(String viewType, String output, String ticks)
          throws IllegalArgumentException {


    /**
     * This class is meant to determine what kind of view the user wants. All that it does is puts
     * the data through a switch statement, and whatever case matches, it generates that type of
     * view. This is known as the Simple Factory Pattern.
     */

    int tickPerSec = Integer.parseInt(ticks);
    if (viewType.equalsIgnoreCase("text")) {
      return new cs5004.animator.view.TextualView(tickPerSec, output);
    } else if (viewType.equalsIgnoreCase("svg")) {
      return new SvgView(tickPerSec, output);
    } else if (viewType.equalsIgnoreCase("visual")) {
      return new AnimationView(tickPerSec);

    } else {
      throw new IllegalArgumentException("specified view is not supported currently");
    }
  }
}
