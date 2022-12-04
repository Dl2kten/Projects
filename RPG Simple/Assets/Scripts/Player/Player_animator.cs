using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public struct Weapon_animations
{
    public Equipment weapon;
    public AnimationClip[] clips;
}

public class Player_animator : Character_animator
{
    public Weapon_animations[] w_animations;
    Dictionary<Equipment, AnimationClip[]> weapon_anim_dict;

    protected override void Start()
    {
        base.Start();
        Equipment_manager.instance.on_Equipment_Changed_Call_Back += on_equipment_changed;
        weapon_anim_dict = new Dictionary<Equipment, AnimationClip[]>();
        foreach(Weapon_animations wa in w_animations) 
        { 
            weapon_anim_dict.Add(wa.weapon, wa.clips);
        }
    }

    /// <summary>
    /// Grips weapon if weapon/shield equipped
    /// </summary>
    /// <param name="new_item"></param>
    /// <param name="old_item"></param>
    void on_equipment_changed(Equipment new_item, Equipment old_item)
    {
        if(new_item!= null && new_item.equip_slot == Equipment_slot.Weapon)
        {
            animator.SetLayerWeight(1, 1);
            if (weapon_anim_dict.ContainsKey(new_item))
            {
                curr_attack_anim_set = weapon_anim_dict[new_item];
            }
        } 
        else if(new_item == null && old_item != null && old_item.equip_slot == Equipment_slot.Weapon)
        {
            animator.SetLayerWeight(1, 0);
            curr_attack_anim_set = default_attack_anim_set;
        }

        if (new_item != null && new_item.equip_slot == Equipment_slot.Shield)
        {
            animator.SetLayerWeight(2, 1);
        }
        else if (new_item == null && old_item != null && old_item.equip_slot == Equipment_slot.Shield)
        {
            animator.SetLayerWeight(2, 0);
        }
    }
   
}
