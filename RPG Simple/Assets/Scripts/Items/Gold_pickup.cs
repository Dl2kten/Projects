using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gold_pickup : Interactable
{
    public Item gold_amount;
    public override void interact()
    {
        base.interact();
        pickup();
    }

    void pickup()
    {
        Debug.Log("Gold");
        Inventory.instance.inventory_items.gold += gold_amount.sell_worth;
        Inventory.instance.on_Item_Change_Call_Back.Invoke();
    }
}
