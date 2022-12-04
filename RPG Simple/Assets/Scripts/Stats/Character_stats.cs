using UnityEngine;

public class Character_stats : MonoBehaviour
{
    public Stat armor;
    public Stat damage;
    public Stat vit;

    public int curr_health { get; private set; }
    public event System.Action<int, int> on_Health_Changed;

    private void Awake()
    {
        curr_health = vit.get_base_value() * 10;
    }

    /// <summary>
    /// Changes health based on damage taken
    /// </summary>
    /// <param name="dmg"></param>
    public void take_dmg(int dmg)
    {
        dmg -= armor.get_base_value();
        dmg = Mathf.Clamp(dmg, 0, int.MaxValue);
        curr_health -= dmg;
        Debug.Log(transform.name + " takes " + dmg + " damage.");
        
        if(on_Health_Changed!= null)
        {
            on_Health_Changed(vit.get_base_value() * 10, curr_health);
        }

        if(curr_health <= 0)
        {
            die();
        }
    }

    /// <summary>
    /// Called when health reaches 0
    /// </summary>
    public virtual void die()
    {
        Debug.Log(transform.name + " died.");
    }
}
