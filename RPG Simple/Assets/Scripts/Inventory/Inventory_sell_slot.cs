using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class Inventory_sell_slot : MonoBehaviour
{
    [SerializeField] private GameObject transaction_panel;
    [SerializeField] private TextMeshProUGUI object_description;
    public Image icon;
    Item item;
    TextMeshProUGUI text;
    private void Awake()
    {
        text = GetComponentInChildren<TextMeshProUGUI>();
    }

    /// <summary>
    /// Adds icon to inventory sell slot
    /// </summary>
    /// <param name="new_item"></param>
    public void add_item(Item new_item)
    {
        item = new_item;
        icon.sprite = item.icon;
        icon.enabled = true;

        text.text = item.name + "\n" + item.sell_worth + "g";
    }

    /// <summary>
    /// Removes icon from inventory sell slot
    /// </summary>
    public void clear_slot()
    {
        item = null;
        icon.sprite = null;
        icon.enabled = false;
        if (text != null)
        {
            text.text = "";
        }
    }

    /// <summary>
    /// On click in shop scene
    /// </summary>
    public void sell_item()
    {
        object_description.text = item.name + " for " + item.sell_worth + "g?"; 
        transaction_panel.SetActive(true);
        Dialogue_manager.instance.set_item(item);
    }
}
