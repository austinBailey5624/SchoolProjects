package greenwolf.genericrpg;

/**
 * Created by austin on 3/25/2016.
 */
public class Actor
{
    String m_name;
    private int m_maxHp;//max HP
    private int m_curHp;//Current Hp
    //    int m_mp;
    private int m_atk;
    private int m_def;

    public Actor()
    {
        m_maxHp=100;
        m_curHp=100;
        m_atk=10;
        m_def=10;
    }
    public int getMaxHp()
    {
        return m_maxHp;
    }
    public void setMaxHP(int maxHp)
    {
        m_maxHp = maxHp;
    }
    public int getCurHp()
    {
        return m_curHp;
    }
    public void setCurHp(int curHp)
    {
        m_curHp=curHp;
    }
    public boolean reduceHp(int damage)//returns true if kiled, false else
    {
        m_curHp=m_curHp-damage;
        if(m_curHp>0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    public int getAtk()
    {
        return m_atk;
    }
    public void setAtk(int attack)
    {
        m_atk=attack;
    }
    public int getDef()
    {
        return m_def;
    }
    public void setDef(int defense)
    {
        m_def=defense;
    }
    public void basicAttck(Character opponent)
    {
        opponent.reduceHp(this.getAtk());
    }
}
