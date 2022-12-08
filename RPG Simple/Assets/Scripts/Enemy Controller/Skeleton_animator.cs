using UnityEngine;
using UnityEngine.AI;

public class Skeleton_animator : Character_animator
{
    NavMeshAgent agent;

    protected override void Start()
    {
        base.Start();
        agent = GetComponent<NavMeshAgent>();
    }

    protected override void Update()
    {
        float speed_percent = agent.velocity.magnitude / agent.speed;

        animator.SetFloat("speed_percentage", speed_percent, 0.1f, Time.deltaTime);
        animator.SetBool("in_combat", combat.in_combat);
    }
}
