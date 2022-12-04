using UnityEngine;
using UnityEngine.UI;

public class Character_info_slot : MonoBehaviour
{
    public Image icon;
    Equipment equipment;

    /// <summary>
    /// Adds equipment to slot for display
    /// </summary>
    /// <param name="equipment"></param>
    public void add_equipment(Equipment new_equipment)
    {
        if(new_equipment.icon != null)
        {
            equipment = new_equipment;
            icon.sprite = equipment.icon;
            icon.enabled = true;
        }
        
    }

    /// <summary>
    /// On button press for character equipment slots
    /// </summary>
    public void unequip_slot()
    {
        if(equipment != null)
        {
            Equipment_manager.instance.unequip((int)equipment.equip_slot);
            equipment = null;
            icon.sprite = null;
            icon.enabled = false;
        }
    }
}
