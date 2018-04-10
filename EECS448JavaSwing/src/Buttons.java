import javax.swing.*;
import java.awt.*;

public class Buttons
{
	private static void createAndDisplayGUI()
	{
		JFrame frame = new JFrame("Button Demo");
		
		JButton leftButton = new JButton("left button");
		JButton middleButton = new JButton("middle button");
		JButton rightButton = new JButton("right button");
		JPanel content = new JPanel();
		
		//Add the buttons to the panel
		content.add(leftButton);
		content.add(middleButton);
		content.add(rightButton);
		
		//Add the content to the main pane
		frame.getContentPane().add(content);
				
		frame.pack();
		frame.setVisible(true);
	}
	
	public static void main(String[] args)
	{
		createAndDisplayGUI();		
	}
}