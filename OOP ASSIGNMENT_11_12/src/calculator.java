//IMPORTING THE REQUIRED PACKAGES
import java.awt.*;
import java.awt.event.*;

public class calculator implements ActionListener {
    public static void main(String[] args){
        new calculator();
    }
    //DECLARING THE REQUIRED VARIABLES AND COMPONENTS
    double a=0,b=0,c=0;
    Frame reqFrame;
    Button b1,b2,b3,b4,b5;
    TextField textField1,textField2,textField3;
    Label l1,l2,l3,l4;
    //CONSTRUCTOR FOR THE CLASS
    calculator(){
        //CREATING THE FRAME IT'S COMPONENTS AND PLACING THEM
        reqFrame = new Frame("CALCULATOR");
        l1 = new Label("Operand 1");
        l1.setBounds(100,85,100,15);
        l2 = new Label("Operand 2");
        l2.setBounds(100,235,100,15);
        l3 = new Label("Result");
        l3.setBounds(100,385,100,15);
        l4 = new Label("Operators",Label.CENTER);
        l4.setBounds(490,85,210,15);
        textField1 = new TextField();
        textField1.setBounds(100,100,340,100);
        textField2 = new TextField();
        textField2.setBounds(100,250,340,100);
        textField3 = new TextField();
        textField3.setBounds(100,400,340,100);
        b1 = new Button("+");
        b1.setBounds(490,100,100,100);
        b2 = new Button("-");
        b2.setBounds(600,100,100,100);
        b3 = new Button("*");
        b3.setBounds(490,250,100,100);
        b4 = new Button("/");
        b4.setBounds(600,250,100,100);
        b5 = new Button("Clear");
        b5.setBounds(490,400,210,100);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        reqFrame.add(l1);
        reqFrame.add(l2);
        reqFrame.add(l3);
        reqFrame.add(l4);
        reqFrame.add(textField1);
        reqFrame.add(textField2);
        reqFrame.add(textField3);
        reqFrame.add(b1);
        reqFrame.add(b2);
        reqFrame.add(b3);
        reqFrame.add(b4);
        reqFrame.add(b5);
        reqFrame.setSize(800,600);
        reqFrame.setLayout(null);
        reqFrame.setVisible(true);
    }
    //ACTION PERFORMED FUNCTION TO CALCULATE THE REQUIRED BY EVENT HANDLING
    public void actionPerformed(ActionEvent e){
        if(e.getSource()==b5){
            a=0;
            b=0;
            c=0;
            textField1.setText("");
            textField2.setText("");
            textField3.setText("");
        }
        else{
            a=Double.parseDouble(textField1.getText());
            b=Double.parseDouble(textField2.getText());
            if(e.getSource()==b1){
                c=a+b;
            }
            else if(e.getSource()==b2){
                c=a-b;
            }
            else if(e.getSource()==b3){
                c=a*b;
            }
            else if(e.getSource()==b4){
                c=a/b;
            }
            textField3.setText(String.valueOf(c));
            textField1.setText(String.valueOf(c));
            textField2.setText("");
        }
    }
}
