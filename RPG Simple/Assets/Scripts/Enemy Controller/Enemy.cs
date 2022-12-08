using UnityEngine;

[RequireComponent(typeof(Character_stats))]
public class Enemy : Interactable
{
    Player_manager player_manager;
    Character_stats my_stats;
    // Start is called before the first frame update
    void Start()
    {
        player_manager = Player_manager.instance;
        my_stats = GetComponent<Character_stats>();
    }

    /// <summary>
    /// Player attacks enemy
    /// </summary>
    public override void interact()
    {
        base.interact();
        var player_combat = player_manager.player.GetComponent<Character_combat>();
        if (player_combat != null)
        {
            player_combat.attack(my_stats);
        }
    }
}
