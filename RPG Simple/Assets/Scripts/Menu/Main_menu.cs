using UnityEngine;
using UnityEngine.SceneManagement;

public class Main_menu : MonoBehaviour
{
    /// <summary>
    /// On play button pressed load next scene
    /// </summary>
    public void play_game()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
    }

    /// <summary>
    /// On quit button press
    /// </summary>
    public void quit_game()
    {
        Application.Quit();
    }
}
