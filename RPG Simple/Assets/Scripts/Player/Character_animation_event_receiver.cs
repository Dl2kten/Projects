using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Character_animation_event_receiver : MonoBehaviour
{
    public Character_combat combat;
    public void attack_hit_event()
    {
        combat.attack_hit_anim_event();
    }
}
