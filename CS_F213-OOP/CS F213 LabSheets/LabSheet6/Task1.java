import java.awt.*;
import java.awt.event.*;    

public class Task1 extends Frame {
    Task1(){
        setLayout(new FlowLayout());
        setSize(400, 500);

        Label label = new Label("Buttons");
        add(label);

        TextField textField = new TextField();
        add(textField);

        TextArea textArea = new TextArea();
        add(textArea);

        Button b = new Button("One");
        b.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.out.println("One");
                label.setText("One");
            }
        });
        add(b);
        
        Button b2 = new Button("Two");
        b2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.out.println("Two");
                label.setText("Two");
            }
        });
        add(b2);

        Checkbox checkbox1 = new Checkbox("C++"); 
        Checkbox checkbox2 = new Checkbox("C--"); 
        Checkbox checkbox3 = new Checkbox("C__"); 
        add(checkbox1);
        add(checkbox2);
        add(checkbox3);
        checkbox1.addItemListener(new ItemListener(){
            public void itemStateChanged(ItemEvent a){
                System.out.println(a.getItem());
            }
        });

        Choice c = new Choice();   
  
        // setting the bounds of choice menu   
        c.setBounds(100, 100, 75, 75);    
  
        // adding items to the choice menu  
        c.add("Item 1");    
        c.add("Item 2");    
        c.add("Item 3");    
        c.add("Item 4");    
        c.add("Item 5");    

        c.addItemListener(new ItemListener(){
            @Override
            public void itemStateChanged(ItemEvent e) {
                System.out.println(e.getItem());
            }
        });
  
        // adding choice menu to frame  
        add(c);    

        setVisible(true);

        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
    }

    public static void main(String[] args){
        Task1 task1 = new Task1();
    }
}