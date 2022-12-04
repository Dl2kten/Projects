using UnityEngine;

public class Dialogue_trigger : MonoBehaviour
{
    [SerializeField] private Dialogue dialogue;

    private void Start()
    {
        Dialogue_manager.instance.start_dialogue(dialogue);
    }
}
