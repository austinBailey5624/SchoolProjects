package greenwolf.genericrpg;

/**
 * This is a class for the items in the game.
 *
 * @author Michael Wang
 * Created by Michael on 3/26/2016.
 */
public class Item extends Actor {
    private int m_type;
    private int m_limit;
    private String m_name;
    private boolean m_used;


    /**
     * This function is the constructor for the different items
     * pre - needs the parameters down below
     * post - creates a item
     * Returns - an item based off of the integer given.
     * @param typeOfItem takes in an int in order to create the weapon
     */
    public Item(int typeOfItem)
    {
        m_name = "";
        m_used = false;
        m_limit = 0;
        if(typeOfItem == 0)
        {
            m_type = 0;
            m_name = "rags";
            m_limit = 7;
        }
        else if(typeOfItem == 1)
        {
            m_type = 1;
            m_name = "sword";
            m_limit = 1;
        }
        else if(typeOfItem == 2)
        {
            m_type = 2;
            m_name = "shield";
            m_limit = 1;
        }
        else if(typeOfItem == 3)
        {
            m_type = 3;
            m_name = "armor";
            m_limit = 1;
        }
        else if(typeOfItem == 4)
        {
            m_type = 4;
            m_name = "helmet";
            m_limit = 1;
        }
        else if(typeOfItem == 5)
        {
            m_type = 5;
            m_name = "gauntlet";
            m_limit = 1;
        }
        else if(typeOfItem == 6)
        {
            m_type = 6;
            m_name = "boots";
            m_limit = 1;
        }
        else if(typeOfItem == 7)
        {
            m_type = 3;
            m_name = "hPotion";
            m_limit = 5;
        }
    }

    /**
     * This function returns the value of m_type
     * pre - none
     * post - none
     * @return m_type
     */
    public int getType()
    {
        return m_type;
    }

    /**
     *This function returns the value of m_name
     * pre - none
     * post - none
     * @return m_name
     */
    public String getName()
    {
        return m_name;
    }


    /**
     *This function returns the value of m_used
     * pre - none
     * post - none
     * @return m_used
     */
    public boolean getUsed()
    {
        return m_used;
    }

    /**
     *This function sets the valus of m_used with a given value
     * pre - needs the parameters down below
     * post - sets m_used to the isUsed boolean given
     * return - none
     * @param isUsed - boolean that tells if the item is used or not
     */
    public void setUsed(boolean isUsed)
    {
        m_used = isUsed;
    }

    /**
     *This function gives stats based off the type of the weapon and if it is equipped or not
     * pre - needs the parameters down below
     * post - gives a stat boost if the conditions are met
     * return - none
     * @param i - the item being used
     * @param pa - the player actor using the item
     * @param isUsed - if the item is equiped or not
     */
    public void ability(Item i, PlayerActor pa, boolean isUsed)
    {
        if(i.getType() == 0)
        {
            i.setUsed(isUsed);
            if(i.getUsed())
            {

            }
        }
        else if(i.getType() == 1)
        {
            i.setUsed(isUsed);
            if(i.getUsed())
            {
                pa.setAtk(pa.getAtk() + 5);
            }
        }
        else if(i.getType() == 2)
        {
            i.setUsed(isUsed);
            if(i.getUsed())
            {
                pa.setDef(pa.getDef() + 5);
            }
        }
        else if(i.getType() == 3)
        {
            i.setUsed(isUsed);
            if(i.getUsed())
            {
                pa.setDef(pa.getDef() + 10);
            }
        }
        else if(i.getType() == 4)
        {
            i.setUsed(isUsed);
            if(i.getUsed())
            {
                pa.setDef(pa.getDef() + 7);
            }
        }
        else if(i.getType() == 5)
        {
            i.setUsed(isUsed);
            if(i.getUsed())
            {
                pa.setDef(pa.getDef() + 3);
            }
        }
        else if(i.getType() == 6)
        {
            i.setUsed(isUsed);
            if(i.getUsed())
            {
                pa.setDef(pa.getDef() + 3);
            }
        }
        else if(i.getType() == 7)
        {
            i.setUsed(isUsed);
            if(i.getUsed())
            {
                pa.setCurHp(pa.getCurHp() + 5);
            }
        }
    }



}
