using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy_stats : Character_stats
{
    public GameObject coins;
    List<Collider> ragdoll_parts;
    Rigidbody body;
    Animator animator;
    private void Start()
    {
        ragdoll_parts = new List<Collider>();
        body = GetComponent<Rigidbody>();
        animator = GetComponentInChildren<Animator>();
        set_ragdoll_parts();
    }

    /// <summary>
    /// Adds ragdoll parts to List and sets them to non physical
    /// </summary>
    void set_ragdoll_parts()
    {
        Collider[] colliders = this.gameObject.GetComponentsInChildren<Collider>();
        foreach (Collider collider in colliders)
        {
            if(collider.gameObject != this.gameObject)
            {
                collider.isTrigger = true;
                ragdoll_parts.Add(collider);
            }
        }
    }

    /// <summary>
    /// Turns on ragdoll, turns off rigidbody components and disable collider
    /// </summary>
    void turn_on_ragdoll()
    {
        body.useGravity = false;
        body.velocity= Vector3.zero;
        this.gameObject.GetComponent<CapsuleCollider>().enabled = false;
        animator.enabled = false;
        animator.avatar= null;

        foreach(Collider c in ragdoll_parts)
        {
            c.isTrigger= false;
            c.attachedRigidbody.velocity= Vector3.zero;
        }
    }

    /// <summary>
    /// On skeleton health <= 0, animation and drop coins
    /// </summary>
    public override void die()
    {
        base.die();
       
        StartCoroutine(death_animation());

        if(--Player_manager.instance.enemy_count == 0)
        {
            Player_manager.instance.complete_level();
        }
    }

    /// <summary>
    /// Called on enemy death
    /// </summary>
    /// <returns></returns>
    IEnumerator death_animation()
    {
        turn_on_ragdoll();
        yield return new WaitForSeconds(2.5f);
        
        Instantiate(coins, transform.position, Quaternion.identity);
        Destroy(gameObject);
    }
}
