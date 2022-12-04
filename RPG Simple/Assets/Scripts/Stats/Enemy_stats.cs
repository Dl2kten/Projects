public class Enemy_stats : Character_stats
{

    public override void die()
    {
        base.die();

        //add animation, drops
        Destroy(gameObject);

        if(--Player_manager.instance.enemy_count == 0)
        {
            Player_manager.instance.complete_level();
        }
    }
}
