using UnityEngine;

[CreateAssetMenu(fileName = "New Item", menuName = "Inventory/Item")]
public class Item : ScriptableObject
{
    new public string name = "Item name";//new overrides the name variable in inspector
    public Sprite icon = null;
    public bool is_default_item = false;
    public int sell_worth;

    public virtual void use()
    {
        Debug.Log("Using " + name);
    }

    public void remove_from_inventory()
    {
        Inventory.instance.remove(this);
    }
}
