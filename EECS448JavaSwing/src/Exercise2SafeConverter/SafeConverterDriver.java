/*
 * 	@FileName:		SafeConverterDriver.java
 * 	@Author:		Austin Bailey
 * 	@Date:			3/21/2016
 * 	@Purpose:		Convert Between Celcius,Kelvin and Farhenheit in Java SwingSet
 */
package Exercise2SafeConverter;

import java.awt.BorderLayout;

import javax.swing.JFrame;
public class SafeConverterDriver 
{
	private static void createAndDisplayGUI()
	{
		JFrame frame = new JFrame("Temperature Converter");
		SafeConverter safeConverter = new SafeConverter();
		
		frame.getContentPane().add(safeConverter.getContent1(), BorderLayout.NORTH);
		frame.getContentPane().add(safeConverter.getContent2(),BorderLayout.CENTER);
		frame.getContentPane().add(safeConverter.getContent3(),BorderLayout.SOUTH);
		frame.pack();
		frame.setVisible(true);
	}
	
	
	public static void main(String[] args)
	{
		createAndDisplayGUI();
	}
}
