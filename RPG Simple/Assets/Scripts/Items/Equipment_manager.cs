using UnityEngine;

public class Equipment_manager : MonoBehaviour
{
    #region Singleton
    public static Equipment_manager instance;
    private void Awake()
    {
        if(instance != null)
        {
            Debug.LogWarning("More than one equipment manager");
            return;
        }

        instance = this;
    }
    #endregion

    public delegate void On_Equipment_Changed(Equipment new_item, Equipment old_item);
    public On_Equipment_Changed on_Equipment_Changed_Call_Back;
    public event System.Action on_Equipment_Changed_UI;

    //public Equipment[] current_equipment { get; private set; }
    public Equipped_items equipped_items;
    public Equipment[] default_items;
    public SkinnedMeshRenderer body_mesh;
    
    SkinnedMeshRenderer[] curr_meshes;
    Inventory inventory;

    // Start is called before the first frame update
    void Start()
    {
        curr_meshes = new SkinnedMeshRenderer[equipped_items.current_equipment.Length];
        inventory = Inventory.instance;

        if(body_mesh)
            equip_default_items();
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.U))
        {
            unequip_all();
        }
    }

    
    /// <summary>
    /// Equip new equipment in correct slot
    /// </summary>
    /// <param name="new_item"></param>
    public void equip(Equipment new_item)
    {
        int slot_index = (int)new_item.equip_slot;

        //if already has an equipment, switch
        if (equipped_items.current_equipment[slot_index] != null )
        {
            inventory.add(equipped_items.current_equipment[slot_index]);
        }

        set_equipment_blend_shapes(new_item, 100);

        if (on_Equipment_Changed_Call_Back != null)
            on_Equipment_Changed_Call_Back.Invoke(new_item, equipped_items.current_equipment[slot_index]);
        if (on_Equipment_Changed_UI != null)
            on_Equipment_Changed_UI.Invoke();

        equipped_items.current_equipment[slot_index] = new_item;
        if (curr_meshes[slot_index] != null)
        { //double check curr_meshes[slot_index] is not null
            Destroy(curr_meshes[slot_index].gameObject);
        }

            SkinnedMeshRenderer new_mesh = Instantiate<SkinnedMeshRenderer>(new_item.skinned_mesh);
            new_mesh.transform.parent = body_mesh.transform;
            new_mesh.bones = body_mesh.bones;
            new_mesh.rootBone = body_mesh.rootBone;
            curr_meshes[slot_index] = new_mesh;
    }

    /// <summary>
    /// Unequip equipment in set slot and return to inventory
    /// </summary>
    /// <param name="slot_index"></param>
    public void unequip(int slot_index)
    {
        if (equipped_items.current_equipment[slot_index] != null )
        {
            if (curr_meshes[slot_index] != null )
            { //double check curr_meshes[slot_index] is not null
                Destroy(curr_meshes[slot_index].gameObject);
            }

            set_equipment_blend_shapes(equipped_items.current_equipment[slot_index], 0);
            inventory.add(equipped_items.current_equipment[slot_index]);

            if (on_Equipment_Changed_Call_Back != null)
                on_Equipment_Changed_Call_Back.Invoke(null, equipped_items.current_equipment[slot_index]);
            if (on_Equipment_Changed_UI != null)
                on_Equipment_Changed_UI.Invoke();

            equipped_items.current_equipment[slot_index] = null;

            if(slot_index < default_items.Length)
            {
                equip_default_item(slot_index);
            }
        }

    }

    /// <summary>
    /// Unequip all current equipments
    /// </summary>
    public void unequip_all()
    {
        for(var i = 0; i != equipped_items.current_equipment.Length; ++i)
        {
            unequip(i);
        }
        equip_default_items();
    }


    /// <summary>
    /// Set the regions of body mesh to correct blendshape value so can't see
    /// through armor
    /// </summary>
    void set_equipment_blend_shapes(Equipment new_item, int weight)
    {
        foreach(Equipment_mesh_region blend_shape in new_item.covered_mesh_regions)
        {
            body_mesh.SetBlendShapeWeight((int)blend_shape, weight);
        }
    }

    /// <summary>
    /// Equip default hair, shirt, pants, shoes
    /// </summary>
    void equip_default_items()
    {
        foreach(Equipment equipment in default_items)
        {
            equip(equipment);
        }
    }


    /// <summary>
    /// Equip a specific default item
    /// </summary>
    /// <param name="slot_index"></param>
    void equip_default_item(int slot_index)
    {
        equip(default_items[slot_index]);
    }
}
