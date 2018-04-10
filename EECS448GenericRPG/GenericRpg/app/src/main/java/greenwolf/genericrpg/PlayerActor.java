package greenwolf.genericrpg;

/**
 * Created by austin on 3/25/2016.
 */
public class PlayerActor extends Actor
{
    private int m_level;
    private int m_exp;
    public PlayerActor()
    {
        this.setAtk(10);
        this.setDef(10);
        this.setMaxHP(100);
        this.setCurHp(100);
    }

    public int getLevel()
    {
        return m_level;
    }
    public void setLevel(int level)
    {
        m_level=level;
    }
    public int getExp()
    {
        return m_exp;
    }
    public void setExp(int experience)
    {
        m_exp=experience;
    }
    public void gainExp(int gainedExp)
    {
        m_exp=m_exp+gainedExp;
        if(m_exp>=getLevel()*100)
        {
//            levelUp;
        }
    }
    public void levelup(int excessExp)
    {
        this.setLevel(this.getLevel()+1);
        gainExp(excessExp);
    }
}
