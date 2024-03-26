import java.awt.*;
import java.awt.event.*;

public class RectonClick extends Frame {
	Button b1;
	boolean status;
	
	RectonClick(){
		status = false;
		setBackground(Color.yellow);
		setTitle("title");
		setLayout(null);
		b1 = new Button("Draw Rect");
		b1.setBounds(50, 400, 100, 30);
		add(b1);
		b1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				status = true;
				repaint();
			}
		});
	}
	
	public void paint(Graphics g){
		if(status == true) g.drawRoundRect(100, 100, 200, 80, 100, 100);
	}

	
	public static void main(String args[]){
		Frame f = new RectonClick();
		f.setSize(500, 500);
		f.setVisible(true);
	}	
}
