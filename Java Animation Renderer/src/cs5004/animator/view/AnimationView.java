package cs5004.animator.view;

import java.awt.*;
import java.io.FileNotFoundException;

import javax.swing.*;

import cs5004.animator.model.ViewShape;

/**
 * Created by vidojemihajlovikj on 7/31/19.
 */
public class AnimationView extends JFrame implements IView {
  DrawingPanel drawingPanel;
  JButton play;
  JButton pause;

  private String viewType;

  /**
   * Our animation vie that is created to render a live animation.
   *
   * @param ticksPerSec the ticks per second that should be playing.
   */
  public AnimationView(int ticksPerSec) {
    this.viewType = "animation";

    drawingPanel = new DrawingPanel();
    drawingPanel.setBackground(Color.white);
    play = new JButton("play");
    pause = new JButton("pause");

    JScrollPane pane = new JScrollPane(drawingPanel);
    pane.add(drawingPanel);
    pane.setVisible(true);
    pane.setSize(750, 750);
    setSize(750, 750);


    setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

    setLayout(new BorderLayout());

    add(drawingPanel, BorderLayout.CENTER);
    add(play, BorderLayout.SOUTH);
    add(pause, BorderLayout.NORTH);


    setVisible(true);
  }

  public void setVisibility(boolean value) {
    setVisible(value);
  }


  @Override
  public void render(String text) throws FileNotFoundException {
    throw new IllegalArgumentException("Trying to render text when user specified animation");

  }

  @Override
  public String getViewType() {
    return this.viewType;
  }

  //what to add here?
  public void renderList(java.util.List<ViewShape> shapes) {
    drawingPanel.drawShapes(shapes);
  }


}
