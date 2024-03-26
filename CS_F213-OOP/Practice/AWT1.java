import java.awt.*;
import java.awt.event.*;

public class AWT1 extends Frame {
    AWT1() {
        super("Title is Title");

        System.out.println("Starting the Frame");

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.out.println("Closing the Frame");
                System.exit(0);
            }
        });
    }

    public void paint(Graphics g) {
        System.out.println("Printing");
        g.setColor(Color.blue); // sets blue color for drawing
        g.drawRect(40, 40, 200, 200);// display a rectangle to contain
        g.drawOval(90, 70, 80, 80);// to draw oval (face)
        g.drawOval(110, 95, 5, 5);// to draw a left eye
        g.drawOval(145, 95, 5, 5);// to draw a right eye
        g.drawLine(130, 95, 130, 115);// to draw a nose
        g.drawArc(113, 115, 35, 20, 0, -180);// to draw a mouth
    }

    public static void main(String[] args) {
        AWT1 f = new AWT1();
        f.setSize(800, 400);
        f.setVisible(true);
        f.repaint();
    }
}
