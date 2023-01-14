using UnityEngine;

[RequireComponent(typeof(Character_stats))]
public class Character_combat : MonoBehaviour
{
    public event System.Action on_Attack;

    const float combat_cooldown = 4f;
    public float attack_speed = 1f;
    public float attack_cool_down = 0f;
    public float attack_delay = 0.5f;
    public bool in_combat { get; private set; }
    
    Character_stats enemy_stats;
    Character_stats my_stats;
    float last_attack_time;
    // Start is called before the first frame update
    void Start()
    {
        my_stats= GetComponent<Character_stats>();
    }

    // Update is called once per frame
    void Update()
    {
        attack_cool_down -= Time.deltaTime;
        //Debug.Log("cool down: " + attack_cool_down);
        if(Time.time - last_attack_time > combat_cooldown)
        {
            in_combat=false;
        }
    }

    /// <summary>
    /// Attack targ_stats 
    /// </summary>
    /// <param name="targ_stats"></param>
    public void attack(Character_stats targ_stats)
    {
        if (attack_cool_down <= 0f)
        {
            //StartCoroutine(do_damage(targ_stats, attack_delay));
            enemy_stats=targ_stats;
            attack_cool_down = 1f / attack_speed;

            if(on_Attack!= null)
            {
                on_Attack();
            }

            in_combat= true;
            last_attack_time= Time.time;
        }
    }

    /*
    IEnumerator do_damage(Character_stats stats, float delay)
    {
        yield return new WaitForSeconds(delay);
        stats.take_dmg(my_stats.damage.get_base_value());

        if(stats.curr_health <= 0)
        {
            in_combat= false;
        }
    }
    */

    /// <summary>
    /// Enemy takes damage when animation event shows
    /// </summary>
    public void attack_hit_anim_event()
    {
        enemy_stats.take_dmg(my_stats.damage.get_base_value());

        if (enemy_stats.curr_health <= 0)
        {
            in_combat = false;
        }
    }
}