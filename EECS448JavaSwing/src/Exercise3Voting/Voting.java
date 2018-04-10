package Exercise3Voting;

import java.io.*;

import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class Voting 
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
	
	private JLabel label1;
	private JLabel label2;
	private JLabel label3;
//	FileInputStream in=null;

	FileWriter out = null;
	String votingFor;
	String first;
	String second;
	int fileAlreadyExists=0;//0 if not checked, 1 if exists, 2 if not exits
//	private JLabel nextLine;
	public Voting()
	{
		panel1 = new JPanel();
		panel2 = new JPanel();
		panel3 = new JPanel();

		button1 = new JButton("Submit Name");
		button2 = new JButton("Bernie Sanders");
		button3 = new JButton("Hillary Clinton");
		button4 = new JButton("Donald Trump");
		button5 = new JButton("Ted Cruz");

		
		text1 = new JTextField(3);
		text2 = new JTextField(3);

		
		label1 = new JLabel("First Name:");
		label2 = new JLabel("Last Name");
		label3 = new JLabel("Message Box");

		button1.addActionListener(button1Listener());
		button2.addActionListener(button2Listener());
		button3.addActionListener(button3Listener());
		button4.addActionListener(button4Listener());
		button5.addActionListener(button5Listener());
		panel1.add(label1);
		panel1.add(text1);
		panel1.add(label2);
		panel1.add(text2);
		panel1.add(button1);	
		
		panel2.add(button2);
		panel2.add(button3);
//		panel2.add(label3);

		

		panel3.add(button4);
		panel3.add(button5);
		panel3.add(label3);

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
				first = text1.getText();
				second = text2.getText();
				File f = new File(first + "_" + second + "_ballot.txt");
				//the following code was taken from http://stackoverflow.com/questions/1816673/how-do-i-check-if-a-file-exists-in-java
				if(f.exists() && !f.isDirectory())
				{
					fileAlreadyExists=1; //means file already exists
				}//end code taken from
				else
				{
					fileAlreadyExists=2; //means file does not already exist
//					panel2.add(button2);
//					panel2.add(button3);
//					panel3.add(button4);
//					panel3.add(button5);
//					getContent2();
//					getContent3();
				}
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
				String newText;
				if(fileAlreadyExists==0)
				{
					newText="Please enter your name before voting";
					label3.setText(newText);
					System.out.println(newText);
				}
				else if(fileAlreadyExists==1)
				{
					newText="You have already voted!";
					label3.setText(newText);
				}
				else if(fileAlreadyExists==2)
				{
					System.out.println("Got here");//debugging
					newText="Thank you for voting!";
					label3.setText(newText);
					try
					{
						out = new FileWriter(first + "_" + second + "_ballot.txt");
						out.write(first+ " " + second + "voted for: Bernie Sanders");
					}
					catch(FileNotFoundException e2)
					{
						
					}
					catch(IOException e2)
					{
						
					}
				}
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
				if(fileAlreadyExists==0)
				{
					label3.setText("Please enter your name before voting");
					System.out.println("Please enter your name before voting");
				}
				else if(fileAlreadyExists==1)
				{
					label3.setText("You have already voted!");
				}
				else if(fileAlreadyExists==2)
				{
					label3.setText("Thank you for voting!");
					try
					{
						out = new FileWriter(first + "_" + second + "_ballot.txt");
						out.write(first+ " " + second + "voted for: Hillary Clinton");
					}
					catch(FileNotFoundException e2)
					{
						
					}
					catch(IOException e2)
					{
						
					}
				}
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
				if(fileAlreadyExists==0)
				{
					label3.setText("Please enter your name before voting");
					System.out.println("Please enter your name before voting");
				}
				else if(fileAlreadyExists==1)
				{
					label3.setText("You have already voted!");
				}
				else if(fileAlreadyExists==2)
				{
					label3.setText("Thank you for voting!");
					try
					{
						out = new FileWriter(first + "_" + second + "_ballot.txt");
						out.write(first+ " " + second + "voted for: Donald Trump");
					}
					catch(FileNotFoundException e2)
					{
						
					}
					catch(IOException e2)
					{
						
					}
				}
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
				if(fileAlreadyExists==0)
				{
					label3.setText("Please enter your name before voting");
					System.out.println("Please enter your name before voting");
				}
				else if(fileAlreadyExists==1)
				{
					label3.setText("You have already voted!");
				}
				else if(fileAlreadyExists==2)
				{
					label3.setText("Thank you for voting!");
					try
					{
						out = new FileWriter(first + "_" + second + "_ballot.txt");
						out.write(first+ " " + second + "voted for: Ted Cruz");
					}
					catch(FileNotFoundException e2)
					{
						
					}
					catch(IOException e2)
					{
						
					}
				}
			}
		};
		return listener;
	}
}
