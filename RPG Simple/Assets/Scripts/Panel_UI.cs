using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class Panel_UI : MonoBehaviour
{
    public GameObject sell_panel_UI;
    public Transform buy_item_parent;
    public Transform item_parent;
    public TextMeshProUGUI sell_gold_amount;
    public TextMeshProUGUI buy_gold_amount;
    Inventory inventory;
    Inventory_sell_slot[] sell_slots;
    Button[] buttons;

    private void Start()
    {
        inventory = Inventory.instance;
        inventory.on_Item_Change_Call_Back += update_sell_ui;
        sell_slots = item_parent.GetComponentsInChildren<Inventory_sell_slot>();
        buttons = buy_item_parent.GetComponentsInChildren<Button>();
        set_sell_item_info();
    }

    /// <summary>
    /// Displays item names and price in buy panel
    /// </summary>
    void set_sell_item_info()
    {
        for (int i = 0; i < buttons.Length; i++)
        {
            TextMeshProUGUI[] texts = buttons[i].GetComponentsInChildren<TextMeshProUGUI>();
            Item item = buttons[i].GetComponent<Sale_item>().item;

            texts[0].text = item.name;
            texts[1].text = item.shop_worth + "g";
        }
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

        sell_gold_amount.text = inventory.inventory_items.gold + "g";
        buy_gold_amount.text = inventory.inventory_items.gold + "g";
    }
}
