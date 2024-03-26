import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Exercise1 extends Frame {
    Exercise1() {
        setLayout(new GridLayout(3, 2));

        setName("Whom do you love?");

        setSize(500, 500);

        Label l1 = new Label("Name: ");
        add(l1);

        TextField name = new TextField(10);
        add(name);

        Label l2 = new Label("Love out of 10: ");
        add(l2);

        TextField love = new TextField(10);
        add(love);

        Button submit = new Button("Submit");
        submit.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                l1.setText("Name: " + name.getText());
                l2.setText("Love out of 10: " + love.getText());
            }
        });
        add(submit);

        setVisible(true);

        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
    }

    public static void main(String args[]){
        Exercise1 exercise1 = new Exercise1();
    }
}