using UnityEngine;

public class Clear_equipment : MonoBehaviour
{
    [SerializeField] private Equipped_items equipped_items;
    [SerializeField] private Inventory_items inventory_items;

    [ContextMenu("Clear equipment list")]
    void clear_equipments()
    {
        equipped_items.current_equipment = new Equipment[System.Enum.GetNames(typeof(Equipment_slot)).Length];
    }

    [ContextMenu("Clear inventory list")]
    void clear_inventory()
    {
        inventory_items.items.Clear();
        inventory_items.gold = 10;
    }
}
