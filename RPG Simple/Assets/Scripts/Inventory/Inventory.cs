using System.Collections.Generic;
using UnityEngine;

public class Inventory : MonoBehaviour
{
    #region Singleton
    public static Inventory instance;

    private void Awake()
    {
        if (instance != null)
        {
            Debug.LogWarning("More than one instance of inventory");
            return;
        }

        instance = this;
    }
    #endregion

    public delegate void On_item_change();
    public On_item_change on_Item_Change_Call_Back;

    public Inventory_items inventory_items;
    
    //inventory_game_objects tracks the game objects picked up and if removed
    //displays object in scene
    public List<GameObject> inventory_game_objects = new List<GameObject>();
    public int space = 20;

    /// <summary>
    /// Add item to list if inventory not full
    /// </summary>
    /// <param name="item"></param>
    /// <returns></returns>
    public bool add(Item item)
    {
        if (!item.is_default_item)
        {
            if (inventory_items.items.Count == space)
            {
                Debug.Log("Full inventory");
                return false;
            }
            inventory_items.items.Add(item);
        }

        //update UI for inventory, can attach functions to delegate
        if (on_Item_Change_Call_Back != null)
            on_Item_Change_Call_Back.Invoke();

        return true;
    }

    /// <summary>
    /// Remove item from items list
    /// </summary>
    /// <param name="item"></param>
    public void remove(Item item)
    {
        inventory_items.items.Remove(item);

        if (on_Item_Change_Call_Back != null)
            on_Item_Change_Call_Back.Invoke();
    }

    /// <summary>
    /// Adds game object to list of game objects
    /// </summary>
    /// <param name="game_object"></param>
    public void add_object(GameObject game_object)
    {
        inventory_game_objects.Add(game_object);
    }

    /// <summary>
    /// Remove game object from list of game objects
    /// </summary>
    /// <param name="item"></param>
    public void remove_object(Item item)
    {
        for (var i = 0; i != inventory_items.items.Count; i++)
        {
            if (item == inventory_items.items[i])
            {
                //remove and display item near player
                var player_pos = FindObjectOfType<Third_person_movement>().transform.position;
                player_pos -= new Vector3((float)0.6, (float)0.6, (float)0.6);
                inventory_game_objects[i].transform.position = player_pos;
                
                inventory_game_objects.Remove(inventory_game_objects[i]);
            }
        }
    }

    /// <summary>
    /// Moved equipped items back to inventory
    /// </summary>
    public void inventory_show_items()
    {
        for (var i = 0; i != Equipment_manager.instance.equipped_items.current_equipment.Length; ++i)
        {
            if (Equipment_manager.instance.equipped_items.current_equipment[i] != null)
            {
                Inventory.instance.add(Equipment_manager.instance.equipped_items.current_equipment[i]);
                Equipment_manager.instance.equipped_items.current_equipment[i] = null;
            }
        }
        if (on_Item_Change_Call_Back != null)
            on_Item_Change_Call_Back.Invoke();
    }
}
