using TMPro;
using UnityEngine;

public class Character_info_UI : MonoBehaviour
{
    public GameObject char_info_ui;
    public Transform equipments;

    public Transform attributes;
    public Transform effects;

    Character_info_slot[] slots;
    TextMeshProUGUI[] specific_attributes;
    TextMeshProUGUI[] specific_effects;
    Player_stats player_stats;

    // Start is called before the first frame update
    void Start()
    {
        Equipment_manager.instance.on_Equipment_Changed_Call_Back += update_ui;
        Equipment_manager.instance.on_Equipment_Changed_UI += set_stats;

        slots = equipments.GetComponentsInChildren<Character_info_slot>();
        specific_attributes = attributes.GetComponentsInChildren<TextMeshProUGUI>();
        specific_effects = effects.GetComponentsInChildren<TextMeshProUGUI>();
        player_stats = FindObjectOfType<Player_stats>();

        if (char_info_ui != null)
        {
            char_info_ui.SetActive(false);
        }
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.C))
        {
            char_info_ui.SetActive(!char_info_ui.activeSelf);
        }
    }

    /// <summary>
    /// Calls specific Character_info_slot in slots to add_equipment or unequip
    /// </summary>
    /// <param name="new_item"></param>
    /// <param name="old_item"></param>
    void update_ui(Equipment new_item, Equipment old_item)
    {
        
        if (new_item != null)
        {
            if (old_item != null) //check for possible loop with equipment_manager unequip here
            {
                slots[(int)old_item.equip_slot].unequip_slot();
            }
            
            slots[(int)new_item.equip_slot].add_equipment(new_item);
        }
    }


    /// <summary>
    /// Sets the stats in text fields
    /// </summary>
    void set_stats()
    {
        int damage = player_stats.damage.get_base_value();
        int armor = player_stats.armor.get_base_value();
        int vit = player_stats.vit.get_base_value();

        specific_attributes[1].text = "" + vit;
        specific_attributes[2].text = "" + damage;
        specific_attributes[3].text = "" + armor;

        specific_effects[1].text = "" + vit * 10;
        specific_effects[2].text = "" + damage;
        specific_effects[3].text = "" + armor;
    }
}
