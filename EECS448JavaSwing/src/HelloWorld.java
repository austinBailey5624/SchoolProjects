//Kept for reference from 
//https://wiki.ittc.ku.edu/ittc_wiki/index.php/EECS448:Lab6
//on 3/21/2016

//http://docs.oracle.com/javase/tutorial/uiswing/components/toplevel.html
import javax.swing.*;        
 
public class HelloWorld 
{
    /**
     * Create the GUI and show it. 
     */
    private static void createAndShowGUI() 
    {
        //Create and set up the window.
        JFrame frame = new JFrame("HelloWorldSwing"); //Window title
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Exit when closed
 
        //Create a "Hello World" label and add it to the content pane.
        JLabel label = new JLabel("Hello World");
        frame.getContentPane().add(label); //Note that is Pane not Panel
        
        label = new JLabel("GoodBye Mars");
        frame.getContentPane().add(label);
        //Display the window.
        frame.pack();    //Put everything together
        frame.setVisible(true); //Make it visible
    }
 
    public static void main(String[] args) 
    {
                createAndShowGUI();
    }
}