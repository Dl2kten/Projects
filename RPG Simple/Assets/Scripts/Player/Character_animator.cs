using UnityEngine;

public class Character_animator : MonoBehaviour
{
    public AnimationClip replaceable_attack;
    public float state_transition = 0.1f;
    public AnimatorOverrideController override_controller;
    public AnimationClip[] default_attack_anim_set;

    protected Animator animator;
    protected Character_combat combat;
    protected AnimationClip[] curr_attack_anim_set;

    float speed_percentage = 0f;
    protected virtual void Start()
    {
        animator = GetComponentInChildren<Animator>();
        combat = GetComponent<Character_combat>();

        if(override_controller == null)
        {
            override_controller = new AnimatorOverrideController(animator.runtimeAnimatorController);
        }
        
        animator.runtimeAnimatorController = override_controller;
        curr_attack_anim_set = default_attack_anim_set;
        combat.on_Attack += on_attack;
    }

    // Update is called once per frame
    protected virtual void Update()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");

        Vector3 direction = new Vector3(horizontal, 0f, vertical).normalized;

        speed_percentage = Mathf.Abs(Vector3.Dot(direction, transform.forward));
        speed_percentage = Mathf.Clamp(speed_percentage, 0f, 1f);
        animator.SetFloat("speed_percentage", speed_percentage, 0.1f, Time.deltaTime);
        animator.SetBool("in_combat", combat.in_combat);
    }


    /// <summary>
    /// Sets trigger for attack for animator
    /// </summary>
    protected virtual void on_attack()
    {
        animator.SetTrigger("attack");
        override_controller[replaceable_attack.name] = curr_attack_anim_set[
            Random.Range(0, curr_attack_anim_set.Length) ]; //chooses random attack animation if multiple
    }
}
