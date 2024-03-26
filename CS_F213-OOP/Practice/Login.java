import java.awt.*;
import java.awt.event.*;

public class Login extends Frame {
    Boolean status = false;;

    Login(){
        super("Halo all, welcome to my app");

        setSize(900, 700);

        setVisible(true);

        setLayout(new FlowLayout());

        Label label1 = new Label("UserName: ");
        label1.setBounds(100, 100, 100, 100);
        add(label1);

        TextField textField = new TextField();
        textField.setBounds(200, 100, 100, 100);
        add(textField);

        Label label2 = new Label("Password: ");
        label2.setBounds(100, 200, 100, 100);
        add(label2);

        TextField textField2 = new TextField();
        textField2.setBounds(200, 200, 100, 100);
        add(textField2);

        Button b = new Button("Login");
        b.setBounds(300, 300, 100, 100);
        add(b);

        b.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if(textField.getText().equals("Santa")){
                    if(textField2.getText().equals("Icecream")){
                        status = true;
                        repaint();
                    }
                }
            }
        });

        addKeyListener(new KeyAdapter(){
            public void keyPressed(KeyEvent e){
                System.out.println(e.getKeyChar());
            }
        });
        
        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
    }
    
    public void paint(Graphics g){
        if(status == true){
            System.out.println("Login Successful");
            g.drawRect(20, 20, 100, 100);
        }
    }

    public static void main(String[] args) {
        Login login = new Login();
    }
}
