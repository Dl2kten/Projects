using UnityEngine;

public class Interactable : MonoBehaviour
{
    public Transform front_interaction_transform; //if only want player to interact with front of object
    public float radius = 2.5f;
    Transform player;
    bool is_focus = false;
    bool has_interacted = false;
    // Update is called once per frame
    void Update()
    {
        if(is_focus && !has_interacted)
        {
            float distance = Vector3.Distance(player.position, front_interaction_transform.position);
            if(distance < radius )
            {
                interact();
                has_interacted=true;
            }
        }
    }

    public virtual void interact()
    {
        Debug.Log("interacting " + player.name);
    }

    public void on_focus(Transform player_transform)
    {
        is_focus= true;
        player = player_transform;
        has_interacted = false; //multiple interaction activations
    }

    public void on_defocus()
    {
        is_focus= false;
        player= null;
        has_interacted = false;
    }
    private void OnDrawGizmosSelected()
    {
        if(!front_interaction_transform)
        { //set to object itself till a new front empty point created
            front_interaction_transform = transform;
        }

        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(front_interaction_transform.position, radius);
    }
}
