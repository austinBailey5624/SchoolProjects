/*
* 	FileName:	Dice.java
* 	Author: 	Austin Bailey
* 	Date:		3/21/2016
* 	Purpose:	Implement Dice in Java Swingset
*/

package Exercise1Dice;

import javax.swing.*;

import java.awt.event.*;
import java.awt.Component;
import java.awt.GridLayout;
import java.awt.event.KeyEvent;
import java.util.Random;
public class Dice 
{
	private JPanel panel;
	private JButton button;
	private JTextField text;
	private JLabel label;
		
	public Dice()
	{
		panel = new JPanel();
		button = new JButton("Roll Dice");		
		text = new JTextField(3);//3 cols, not 20 chars
		label = new JLabel("Enter the number of the sides for the dice:");
			
		//Load the listener
		button.addActionListener(buttonListener());	
		
		//load the panel
		panel.add(text);
		panel.add(button);
		panel.add(label);
	}
	
	public Component getContent()
	{
		return panel;
	}
	
	private ActionListener buttonListener()
	{
			ActionListener listener = new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{
					String input = text.getText();
					int numSides = Integer.parseInt(input);
					Random rand = new Random();
					String newText = numSides + " sided dice rolled a " + (rand.nextInt(numSides)+1);//add randomness
					label.setText(newText);
					System.out.println(newText);
				}
			};
			return listener;
	}
}