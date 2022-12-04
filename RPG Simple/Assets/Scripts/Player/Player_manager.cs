using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Player_manager : MonoBehaviour
{
    #region Singleton
    public static Player_manager instance;

    private void Awake()
    {
        if(instance != null)
        {
            Debug.LogWarning("More than one Player manager");
            return;
        }

        instance = this;
    }
    #endregion

    public GameObject player;
    public GameObject exit_magic_circle;
    public TextMeshProUGUI level_text;
    public int enemy_count;

    /// <summary>
    /// If player dies reload scene
    /// </summary>
    public void game_over()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
    }

    /// <summary>
    /// If player defeats all enemies
    /// </summary>
    public void complete_level()
    {
        exit_magic_circle.SetActive(true);
        level_text.enabled = true;
    }
}
