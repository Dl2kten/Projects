using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shop_manager : MonoBehaviour
{
    [SerializeField] private Animator buy_animator;

    /// <summary>
    /// On buy button click
    /// </summary>
    public void show_buy_panel()
    {
        buy_animator.SetBool("is_open", true);
    }
}
