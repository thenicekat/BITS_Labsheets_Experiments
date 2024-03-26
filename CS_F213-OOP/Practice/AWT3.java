import java.awt.*;
import java.awt.event.*;

public class AWT3 extends Frame {
	AWT3(){
		super("Hi Lob");
		System.out.println("Hello World");

		setSize(1000,1000);
		setVisible(true);

		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.out.println("Closing the Frame");
				System.exit(0);
			}
		});

		addKeyListener(new KeyAdapter(){
			public void keyPressed(KeyEvent e){
				System.out.println(e.getKeyChar());
			}	
		});
	}

	public void paint(Graphics g){
		g.drawRect(0, 0, 200, 200);
	}

	public static void main(String args[]){
		AWT3 awt3 = new AWT3();
	}
}
