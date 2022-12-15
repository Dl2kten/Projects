using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "Item", menuName = "Equipped_items")]
public class Equipped_items : ScriptableObject
{
    //set size = number of members in enum 
    public Equipment[] current_equipment = new Equipment[System.Enum.GetNames(typeof(Equipment_slot)).Length];
}
