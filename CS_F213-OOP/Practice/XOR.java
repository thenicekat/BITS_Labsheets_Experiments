import java.awt.*;
import java.awt.event.*;

public class XOR extends Frame {
    int chX = 1000, chY = 1000;

    public XOR(){
        addMouseMotionListener(new MouseMotionAdapter(){
            public void mouseMoved(MouseEvent m){
                int x = m.getX();
                int y = m.getY();
                chX = x-10;
                chY = y-10;
                repaint();
            }
        });
    }

    public void paint(Graphics g){
        g.setColor(Color.blue);
        g.fillRect(20, 40, 60, 60);

        g.setColor(Color.red);
        g.fillRect(80, 40, 60, 60);

        g.setColor(Color.green);
        g.fillRect(140, 40, 60, 60);
        
        g.setXORMode(Color.black);
        g.drawLine(chX-10, chY, chX+10, chY);
        g.drawLine(chX, chY-10, chX, chY+10);
        g.setPaintMode();
    }

    public static void main(String args[]){
        XOR appwin = new XOR();
        appwin.setSize(new Dimension(200, 150));
        appwin.setTitle("XOR");
        appwin.setVisible(true);
    }
}

