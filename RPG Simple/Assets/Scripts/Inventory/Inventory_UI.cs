using TMPro;
using UnityEngine;

public class Inventory_UI : MonoBehaviour
{
    public GameObject inventory_UI;
    public Transform item_parent;
    public TextMeshProUGUI gold_amount;
    Inventory inventory;
    Inventory_slot[] slots;
    Inventory_sell_slot[] sell_slots;

    private void Awake()
    {
        inventory = Inventory.instance;
        inventory.on_Item_Change_Call_Back += update_UI;
        inventory.on_Item_Change_Call_Back += update_sell_ui;
        //get all the Inventory_slot objects
        slots = item_parent.GetComponentsInChildren<Inventory_slot>();
        sell_slots = item_parent.GetComponentsInChildren<Inventory_sell_slot>();

        //if(inventory_UI!= null )
        //  inventory_UI.SetActive(false);
    }

    void Update()
    {
        
        if (Input.GetKeyDown(KeyCode.I))
        {
            inventory_UI.SetActive(!inventory_UI.activeSelf);
        }    
    }

    /// <summary>
    /// When items added/removed update the inventory UI
    /// </summary>
    void update_UI()
    {
        for(var i = 0; i < slots.Length; i++)
        {
            if(i < inventory.inventory_items.items.Count)
            {
                slots[i].add_item(inventory.inventory_items.items[i]);
            } 
            else
            {
                slots[i].clear_slot();          
            }
        }

        if(slots.Length > 0)
            gold_amount.text = inventory.inventory_items.gold + "g";
    }

    /// <summary>
    /// Update ui for selling items
    /// </summary>
    void update_sell_ui()
    {
        for (var i = 0; i < sell_slots.Length; i++)
        {
            if (i < inventory.inventory_items.items.Count)
            {
                sell_slots[i].add_item(inventory.inventory_items.items[i]);
            }
            else
            { 
                sell_slots[i].clear_slot();
            }
        }
    }
}
