using UnityEditor.Rendering;
using UnityEngine;
using UnityEngine.AI;

public class Enemy_controller : MonoBehaviour
{
    [SerializeField] private Transform[] way_points;
    private int curr_point;
    private float wait_time;
    private float start_wait_time;

    [SerializeField] private float look_radius;
    Transform target;
    NavMeshAgent agent;
    Character_combat combat;

    // Start is called before the first frame update
    void Start()
    {
        agent = GetComponent<NavMeshAgent>();
        target = Player_manager.instance.player.transform;
        combat = GetComponent<Character_combat>();
        curr_point= 0;
        start_wait_time = 3f;
        wait_time = start_wait_time;
    }

    // Update is called once per frame
    void Update()
    {
        float distance = Vector3.Distance(transform.position, target.position);
        if (distance <= look_radius)
        {
            engage(distance);
        } else if(way_points.Length != 0)
        {
            patrol();
        }
            
    }

    /// <summary>
    /// On player detect
    /// </summary>
    void engage(float distance)
    {
        face_target();
        agent.SetDestination(target.position);
            
        if (distance <= agent.stoppingDistance + 1)
        {
            combat.attack(target.GetComponent<Character_stats>());
        }
    }

    /// <summary>
    /// Have enemy patrol designated area
    /// </summary>
    void patrol()
    {
        face_target();
        agent.SetDestination(way_points[curr_point].position);
        if(agent.remainingDistance <= agent.stoppingDistance) //if within 0.2f of point position
        {
            if(wait_time <= 0)
            {
                curr_point = (curr_point + 1) % way_points.Length;
                wait_time = start_wait_time;
            } else
            {
                wait_time -= Time.deltaTime;
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
