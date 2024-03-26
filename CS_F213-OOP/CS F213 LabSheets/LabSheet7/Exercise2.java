import java.awt.*;
import java.awt.event.*;


public class Exercise2 extends Frame {
    int x = 0;
    Exercise2() {
        setLayout(new FlowLayout());

        add(new Label("Counter"));

        TextField t = new TextField();
        t.setEditable(false);
        t.setText(Integer.toString(x));
        add(t);

        Button b = new Button("Add");
        b.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                x++;
                t.setText(Integer.toString(x));
            }
        });
        add(b);

        setVisible(true);

        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
    }

    public static void main(String args[]){
        Exercise2 exercise2 = new Exercise2();
        exercise2.setSize(400, 500);
    }
}