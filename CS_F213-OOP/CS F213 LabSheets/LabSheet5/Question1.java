import java.awt.*;
import java.awt.event.*;    

public class Question1 extends Frame{
    Question1() {
        
        Frame f = new Frame("Cringe");
        
        Label x = new Label("Hello World");
        x.setBounds(200, 200, 50, 50);
        f.add(x);
        
        Button b = new Button("Click Me!");
        b.setBounds(30,100,80,30);  
        f.add(b);
        
        Button b2 = new Button("Click Me 2!");
        b2.setBounds(120,100,80,30);  
        f.add(b2);
        
        Button b4 = new Button("Click Me 3!");
        b4.setBounds(200,100,80,30);  
        f.add(b4); 
        
        f.addWindowListener(new WindowAdapter() {    
            public void windowClosing (WindowEvent e) {   
                System.exit(0); 
                f.dispose();    
            }    
        });    
        
        f.paint(f.getGraphics());
    }
    
    public void paint(Graphics g){
        g.drawArc(0, 0, 70, 70, 0, 120);

        int xpoints[] = {20, 200, 20, 200, 0};
        int ypoints[] = {450, 450, 650, 650, 200};
        int num = 5;
        g.drawPolygon(xpoints, ypoints, num);
    }
    
    public static void main(String args[]){
        Question1 q = new Question1();
        q.setLayout(null);
        q.setSize(600, 1500);
        q.setVisible(true); 
    }
}