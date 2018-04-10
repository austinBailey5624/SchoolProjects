package Exercise1Dice;
import javax.swing.JFrame;

public class main 
{
	private static void createAndDisplayGUI()
	{
		JFrame frame = new JFrame("Dice Program");
		Dice myDice = new Dice();
		
		frame.getContentPane().add(myDice.getContent());
		frame.pack();
		frame.setVisible(true);
	}
	public static void main(String[] args)
	{
		createAndDisplayGUI();
	}
}
