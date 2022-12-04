using UnityEngine;

[CreateAssetMenu(fileName = "New Equipment", menuName = "Inventory/Equipment")]
public class Equipment : Item
{
    public int armor_modifier;
    public int dmg_modifier;
    public Equipment_slot equip_slot;
    public SkinnedMeshRenderer skinned_mesh;
    public Equipment_mesh_region[] covered_mesh_regions;
    /// <summary>
    /// Equip equipment and remove from inventory
    /// </summary>
    public override void use()
    {
        base.use();
        Equipment_manager.instance.equip(this);
        remove_from_inventory();
    }


    public void unequip(int slot_index)
    {
        Equipment_manager.instance.unequip(slot_index);
    }
}

public enum Equipment_slot { Head, Chest, Legs, Feet, Weapon, Shield }
public enum Equipment_mesh_region { Legs, Arms, Torso }
