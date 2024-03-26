import java.awt.*;
import java.awt.event.*;

class Stack {
    public int array[] = new int[10];
    public int i = -1;

    public void push(int x){
        i++;
        array[i] = x;
    }

    public int pop(){
        if(i == -1) return 999999;
        return array[i--];
    }

    public int top(){
        return array[i];
    }
}

public class AWT2 extends Frame {
    TextArea ta;
    Stack stack = new Stack();

    AWT2() {
        setLayout(new GridLayout());
        setBackground(Color.MAGENTA);

        TextField textField = new TextField();
        add(textField);

        Button b = new Button("Push");
        b.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Push Button Clicked");
                stack.push(Integer.parseInt(textField.getText()));
                repaint();
            }
        });

        Button b2 = new Button("Pop");
        b2.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Pop Button Clicked");
                stack.pop();
                repaint();
            }
        });

        ta = new TextArea();
        ta.setBounds(200, 200, 200, 200);

        add(b);
        add(ta);
        add(b2);


        textField.addKeyListener(new KeyAdapter(){
            public void keyPressed(KeyEvent k){
                System.out.print(k.getKeyChar());
            }
        });
    }

    public void paint(Graphics g){
        String s = "";
        System.out.println(stack.i);
        for(int c = 0; c <= stack.i; c++){
            s += stack.array[c] + "\n";
        }
        ta.setText(s);
    }

    public static void main(String[] args) {
        AWT2 awt2 = new AWT2();

        awt2.setSize(800, 400);
        awt2.setVisible(true);
    }
}
