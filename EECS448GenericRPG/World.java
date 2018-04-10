/**
 * @author : Will Teeple
 * @version : 1
 * @since 03/30/2016
 * Description : World class. This class stores the current map and contains
 * the methods for manipulating and displaying the players position
 */

public class World
{
  //dimension and coordinate constants
  private final int worldXDim = 7; //max x-axis length
  private final int worldYDim = 7; //max y-axis length
  private final int startLocX = 0; //x-coordinate start location
  private final int startLocY = 3; //y-coordinate start location

  //constant variables for easier code reading
  private final char tree = 'T'; //character for tree
  private final char mountain = 'M'; //character for mountain
  private final char river = 'R'; //character for river
  private final char path = 'P'; //character for path
  private final char player = '@'; //chacter for the player

  //current location variables
  public int curPosX = startLocX;
  public int curPosY = startLocY;

  //default map without player token
  private final char[][] worldArrBase =
  {{'F', 'F', 'M', 'M', 'M', 'M', 'M'},
   {'F', 'F', 'M', 'M', 'P', 'P', 'T'},
   {'F', 'F', 'F', 'F', 'P', 'F', 'F'},
   {'P', 'P', 'P', 'P', 'P', 'F', 'F'},
   {'F', 'F', 'F', 'F', 'P', 'F', 'F'},
   {'F', 'F', 'F', 'F', 'P', 'P', 'T'},
   {'F', 'F', 'F', 'F', 'F', 'F', 'F'}};

   //current map with player token
  public char[][] curWorldArr = new char[worldYDim][worldXDim];

  /**
   * @param : (pre) None
   * @param : (post) Creates a new object of type World
   * @return : None
   */
  public World()
  {
    curWorldArr = worldArrBase;
    curWorldArr[startLocY][startLocX] = player;
  }

  /**
   * @param : (pre) Existing World Object
   * @param : (post) Displays the current world map with player token
   * @return : None
   */
  void displayWorld()
  {
    for (int i = 0; i < worldYDim; i++)
    {
      System.out.println("\n");
      for (int j = 0; j < worldXDim; j++)
      {
        System.out.print(curWorldArr[i][j] + " ");
      }
    }
  }
}
