/*
 * 	@FileName:		SafeConverter.java
 * 	@Author:		Austin Bailey
 * 	@Date:			3/21/2016
 * 	@Purpose:		Convert Between Celcius,Kelvin and Farhenheit in Java SwingSet
 */

package Exercise2SafeConverter;

import javax.swing.*;

import java.awt.event.*;
import java.awt.Component;
import java.awt.GridLayout;

public class SafeConverter 
{
	private JPanel panel1;
	private JPanel panel2;
	private JPanel panel3;
	
	private JButton button1;
	private JButton button2;
	private JButton button3;
	private JButton button4;
	private JButton button5;
	private JButton button6;
	
	private JTextField text1;
	private JTextField text2;
	private JTextField text3;
	private JTextField text4;
	private JTextField text5;
	private JTextField text6;
	
	private JLabel label1;
	private JLabel label2;
	private JLabel label3;
	private JLabel label4;
	private JLabel label5;
	private JLabel label6;
	
//	private JLabel nextLine;
	public SafeConverter()
	{
		panel1 = new JPanel();
		panel2 = new JPanel();
		panel3 = new JPanel();
		
		button1 = new JButton("ConvertFtoC");
		button2 = new JButton("ConvertFtoK");
		button3 = new JButton("ConvertCtoK");
		button4 = new JButton("ConvertCtoF");
		button5 = new JButton("ConvertKtoF");
		button6 = new JButton("ConvertKtoC");
		
		text1 = new JTextField(3);
		text2 = new JTextField(3);
		text3 = new JTextField(3);
		text4 = new JTextField(3);
		text5 = new JTextField(3);
		text6 = new JTextField(3);
		
		label1 = new JLabel("Enter a temp from F to C        ");
		label2 = new JLabel("Enter a temp from F to K");
		label3 = new JLabel("Enter a temp from C to K        ");
		label4 = new JLabel("Enter a temp from C to F");
		label5 = new JLabel("Enter a temp from K to F        ");
		label6 = new JLabel("Enter a temp from K to C");
		
		
//		nextLine = new JLabel("<html><br></html>");
		button1.addActionListener(button1Listener());
		button2.addActionListener(button2Listener());
		button3.addActionListener(button3Listener());
		button4.addActionListener(button4Listener());
		button5.addActionListener(button5Listener());
		button6.addActionListener(button6Listener());
		
		panel1.add(text1);
		panel1.add(button1);
		panel1.add(label1);
		panel1.add(text2);
		panel1.add(button2);
		panel1.add(label2);
		
		panel2.add(text3);
		panel2.add(button3);
		panel2.add(label3);
		panel2.add(text4);
		panel2.add(button4);
		panel2.add(label4);
		
		panel3.add(text5);
		panel3.add(button5);
		panel3.add(label5);
		panel3.add(text6);
		panel3.add(button6);
		panel3.add(label6);
	}
	
	public Component getContent1()
	{
		return (panel1);
	}
	
	public Component getContent2()
	{
		return (panel2);
	}

	public Component getContent3()
	{
		return (panel3);
	}
	
	private ActionListener button1Listener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String input = text1.getText();
				double tempInF = Double.parseDouble(input);//convert String to double
				double tempInC = (tempInF-32)*(5.0/9.0); //convert F to C
				String newText = "Temp in C: " + String.format("%.2f",tempInC) + "       ";//convert double to String and
											       //only display 2 places past decimal
				label1.setText(newText);
				System.out.println(newText);
			}
		};
		
		return listener;
	}	
	
	private ActionListener button2Listener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String input = text2.getText();
				double tempInF = Double.parseDouble(input);//convert String to double
				double tempInK = (tempInF-32)*(5.0/9.0)+273; //convert F to C
				String newText = "Temp in K: " + String.format("%.2f",tempInK);//convert double to String and
											       //only display 2 places past decimal
				label2.setText(newText);
				System.out.println(newText);
			}
		};
		
		return listener;
	}	
	
	private ActionListener button3Listener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String input = text3.getText();
				double tempInC = Double.parseDouble(input);//convert String to double
				double tempInK = (tempInC +273); //convert F to C
				String newText = "Temp in K: " + String.format("%.2f",tempInK);//convert double to String and
											       //only display 2 places past decimal
				label3.setText(newText);
				System.out.println(newText);
			}
		};
		
		return listener;
	}	
	
	private ActionListener button4Listener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String input = text4.getText();
				double tempInC = Double.parseDouble(input);//convert String to double
				double tempInF = (tempInC*(9/5)+32); //convert F to C
				String newText = "Temp in F: " + String.format("%.2f",tempInF);//convert double to String and
											       //only display 2 places past decimal
				label4.setText(newText);
				System.out.println(newText);
			}
		};
		
		return listener;
	}	
	
	private ActionListener button5Listener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String input = text5.getText();
				double tempInK = Double.parseDouble(input);//convert String to double
				double tempInF = 1.8/(tempInK-273)+32; //convert F to C
				String newText = "Temp in F: " + String.format("%.2f",tempInF);//convert double to String and
											       //only display 2 places past decimal
				label5.setText(newText);
				System.out.println(newText);
			}
		};
		
		return listener;
	}
	
	private ActionListener button6Listener()
	{
		ActionListener listener = new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String input = text6.getText();
				double tempInK = Double.parseDouble(input);//convert String to double
				double tempInC = (tempInK-273); //convert F to C
				String newText = "Temp in C: " + String.format("%.2f",tempInC);//convert double to String and
											       //only display 2 places past decimal
				label6.setText(newText);
				System.out.println(newText);
			}
		};
		
		return listener;
	}
}
