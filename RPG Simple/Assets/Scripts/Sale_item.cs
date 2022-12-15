using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class Sale_item : MonoBehaviour
{
    public Item item;
    public Image icon;
    [SerializeField] private GameObject transaction_panel;
    [SerializeField] private TextMeshProUGUI object_description;

    /// <summary>
    /// On click for items offered by shop
    /// </summary>
    public void buy_item()
    {
        object_description.text = item.name + " for " + item.shop_worth + "g?";
        transaction_panel.SetActive(true);
        Dialogue_manager.instance.set_item(item);
    }
}
