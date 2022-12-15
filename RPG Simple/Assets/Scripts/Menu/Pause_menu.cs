using UnityEngine;
using UnityEngine.SceneManagement;

public class Pause_menu : MonoBehaviour
{
    public static bool Game_is_paused = false;
    [SerializeField]private GameObject pause_ui;


    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.P))
        {
            if(Game_is_paused)
            {
                resume();
            } else
            {
                pause();
            }
        }
    }

    /// <summary>
    /// Resumes game, timeScale set to normal, disables pause_ui
    /// </summary>
    public void resume()
    {
        pause_ui.SetActive(false);
        Time.timeScale = 1.0f;
        Game_is_paused=false;
    }

    /// <summary>
    /// Pauses game, timeScale set to 0, enables pause_ui
    /// </summary>
    void pause()
    {
        pause_ui.SetActive(true);
        Time.timeScale = 0f;
        Game_is_paused=true;
    }

    /// <summary>
    /// Loads main menu on Main Menu button pressed
    /// </summary>
    public void load_menu()
    {
        Time.timeScale = 1.0f;
        SceneManager.LoadScene(0);
    }

    /// <summary>
    /// Quits game on quit button pressed
    /// </summary>
    public void quit_game()
    {
        Application.Quit();
    }
}
