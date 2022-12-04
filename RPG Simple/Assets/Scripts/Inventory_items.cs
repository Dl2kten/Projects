using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "Item", menuName = "Inventory_items")]
public class Inventory_items : ScriptableObject
{
    public List<Item> items = new List<Item>();
    public int gold = 10;
}
