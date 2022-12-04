using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player_stats : Character_stats
{
    // Start is called before the first frame update
    void Start()
    {
        Equipment_manager.instance.on_Equipment_Changed_Call_Back += on_equipment_changed;
    }

    /// <summary>
    /// If equip/remove equipment, change armor, damage stats
    /// </summary>
    /// <param name="new_item"></param>
    /// <param name="old_item"></param>
    public void on_equipment_changed(Equipment new_item, Equipment old_item)
    {
        if(new_item != null)
        {
            armor.add_modifier(new_item.armor_modifier);
            damage.add_modifier(new_item.dmg_modifier);
        }

        if(old_item != null)
        {
            armor.remove_modifier(old_item.armor_modifier);
            damage.remove_modifier(old_item.dmg_modifier);
        }
    }

    /// <summary>
    /// Calls game_over when hp <= 0
    /// </summary>
    public override void die()
    {
        base.die();
        Player_manager.instance.game_over();
    }
}
