import javax.swing.*;
import java.awt.event.KeyEvent;//Used for menu hotkeys (optional)

public class Menu
{
	private static void createAndShowGUI()
	{
		//Create a frame
		JFrame frame = new JFrame("Menu Demo");
		
		//Where the GUI is created:
		JMenuBar menuBar; //The entire bar
		JMenu menu, submenu; //A single drop-down menu
		JMenuItem menuItem; //A single item in a menu
		JRadioButtonMenuItem rbMenuItem; //radio button menu item
		JCheckBoxMenuItem cbMenuItem; //checkbox menu item

		//Create the menu bar.
		menuBar = new JMenuBar();

		//Build the first menu.
		menu = new JMenu("A Menu");
		menu.setMnemonic(KeyEvent.VK_A); //Allows for hotkey access, Alt+a
		menuBar.add(menu); //Add to menu bar

		//a group of JMenuItems
		menuItem = new JMenuItem("A text-only menu item"); 
		menu.add(menuItem); //add to the menu. NOTE: We add items to menus and menus to menu bar

		menuItem = new JMenuItem("Both text and icon");
		menu.add(menuItem);

		menuItem = new JMenuItem("Another option");
		menu.add(menuItem);

		//a group of radio button menu items
		menu.addSeparator();
		ButtonGroup group = new ButtonGroup();
		rbMenuItem = new JRadioButtonMenuItem("A radio button menu item");
		rbMenuItem.setSelected(true);
		group.add(rbMenuItem);
		menu.add(rbMenuItem);

		rbMenuItem = new JRadioButtonMenuItem("Another radio button");
		group.add(rbMenuItem);
		menu.add(rbMenuItem);

		//a group of check box menu items
		menu.addSeparator();
		cbMenuItem = new JCheckBoxMenuItem("A check box menu item");
		menu.add(cbMenuItem);

		cbMenuItem = new JCheckBoxMenuItem("Another one");
		menu.add(cbMenuItem);

		//a submenu
		menu.addSeparator();
		submenu = new JMenu("A submenu");
		submenu.setMnemonic(KeyEvent.VK_S); //Again some option hotkey access

		menuItem = new JMenuItem("An item in the submenu");
		submenu.add(menuItem);

		menuItem = new JMenuItem("Another item");
		submenu.add(menuItem);
		menu.add(submenu);

		//Build second menu in the menu bar.
		menu = new JMenu("Another Menu");
		menuBar.add(menu);

		frame.setJMenuBar(menuBar);
		
		frame.pack();
		frame.setVisible(true);
	}
	
	public static void main(String[] args)
	{
		createAndShowGUI();
	}
}