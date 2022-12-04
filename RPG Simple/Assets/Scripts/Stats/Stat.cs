using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class Stat
{
    [SerializeField] 
    private int base_value;

    private List<int> equip_values = new List<int>();

    /// <summary>
    /// Adds modifier from equipment
    /// </summary>
    /// <param name="modifier"></param>
    public void add_modifier(int modifier)
    {

        if(modifier != 0) 
            equip_values.Add(modifier);
    }

    /// <summary>
    /// Removes modifier from equipment
    /// </summary>
    /// <param name="modifier"></param>
    public void remove_modifier(int modifier)
    {
        if(modifier != 0)
            equip_values.Remove(modifier);
    }

    public int get_base_value() 
    {
        int final_value = base_value;
        equip_values.ForEach(x => final_value += x);

        return final_value; 
    }
}
