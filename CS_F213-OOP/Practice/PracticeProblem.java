import java.awt.*;
import java.io.*;
import java.awt.event.*;

public class PracticeProblem extends Frame {
	PracticeProblem() {
		setName("Form 69 :0");
		setVisible(true);

		setSize(600, 600);

		setLayout(new FlowLayout());

		Label l1 = new Label("Text Editor: Form 69");
		l1.setBounds(300, 100, 200, 100);
		add(l1);

		Label l2 = new Label("Name");
		l2.setBounds(100, 300, 200, 100);
		add(l2);

		TextField t2 = new TextField();
		t2.setBounds(300, 300, 400, 100);
		add(t2);

		Choice gender = new Choice();
		gender.add("Male");
		gender.add("Female");
		gender.setBounds(300, 300, 300, 300);
		add(gender);

		Checkbox c1 = new Checkbox("Life is great");
		add(c1);
		Checkbox c2 = new Checkbox("Life is bad");
		add(c2);
		Checkbox c3 = new Checkbox("Life sucks");
		add(c3);

		Scrollbar sb = new Scrollbar();
		sb.setBounds(400, 200, 20, 200);
		sb.addAdjustmentListener(
			new AdjustmentListener(){
				public void adjustmentValueChanged(AdjustmentEvent e){
					System.out.println(e.getValue());
				}
			}
		);
		add(sb);

		Button b1 = new Button("Save");
		b1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));
					bw.write("Name: " + t2.getText());
					bw.append("Gender: " + gender.getSelectedItem());
					bw.close();
				} catch (IOException ioe) {
					System.out.println("Some error occured while saving file");
				}
			}
		});
		b1.setBounds(400, 500, 50, 20);
		add(b1);

		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.out.println("Closing Form 69");
				System.exit(0);
			}
		});
	}

	public static void main(String[] args) {
		PracticeProblem pp = new PracticeProblem();
	}
}
