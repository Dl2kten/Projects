using UnityEngine;
using UnityEngine.AI;

public class Enemy_controller : MonoBehaviour
{
    public float look_radius = 10f;
    Transform target;
    NavMeshAgent agent;
    Character_combat combat;

    // Start is called before the first frame update
    void Start()
    {
        agent = GetComponent<NavMeshAgent>();
        target = Player_manager.instance.player.transform;
        combat = GetComponent<Character_combat>();
    }

    // Update is called once per frame
    void Update()
    {
        float distance = Vector3.Distance(transform.position, target.position);
        if (distance <= look_radius)
        {
            face_target();
            agent.SetDestination(target.position);
            if (distance <= agent.stoppingDistance + 1)
            {
                combat.attack(target.GetComponent<Character_stats>());
            }
        }
    }


    /// <summary>
    /// Rotate enemy to face player when close up
    /// </summary>
    void face_target()
    {
        Vector3 direction = (target.position - transform.position).normalized;
        Quaternion look_rotation = Quaternion.LookRotation(new Vector3(direction.x, 0, direction.z));
        transform.rotation = Quaternion.Slerp(transform.rotation, look_rotation, Time.deltaTime * 5f);
    }

    /// <summary>
    /// Draw radius of enemy awareness
    /// </summary>
    private void OnDrawGizmosSelected()
    {
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, look_radius);
    }
}
