using UnityEngine;

public class Item_pickup : Interactable
{
    public Item item;
    public override void interact()
    {
        base.interact();
        pickup();
    }

    void pickup()
    {
        Debug.Log("Pick up item" + item.name);

        if (Inventory.instance.add(item))
        {
            var temp = Instantiate(gameObject, new Vector3(-1, -1, -1), Quaternion.identity);
            Inventory.instance.add_object(temp);
            Destroy(gameObject);
        }
    }
}
