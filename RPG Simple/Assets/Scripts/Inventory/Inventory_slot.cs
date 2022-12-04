using UnityEngine;
using UnityEngine.UI;

public class Inventory_slot : MonoBehaviour
{
    public Image icon;
    public Button remove_button;
    Item item;
    
    /// <summary>
    /// Adds icon to inventory slot
    /// </summary>
    /// <param name="new_item"></param>
    public void add_item(Item new_item) 
    { 
        item = new_item;
        icon.sprite = item.icon;
        icon.enabled= true;

        remove_button.interactable= true;
    }

    /// <summary>
    /// Removes icon from inventory slot
    /// </summary>
    public void clear_slot()
    {
        item = null;
        icon.sprite = null;
        icon.enabled= false;

        remove_button.interactable= false;
    }

    /// <summary>
    /// On remove_button click
    /// </summary>
    public void on_remove_button()
    {
        Inventory.instance.remove_object(item);
        
        Inventory.instance.remove(item);
    }

    /// <summary>
    /// On item_button click
    /// </summary>
    public void use_item()
    {
        if(item)
        {
            item.use();
        }
    }

    /// <summary>
    /// On click in shop scene
    /// </summary>
    public void sell_item()
    {

        Dialogue_manager.instance.total += item.sell_worth;

    }
}
