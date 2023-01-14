using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(Character_stats))]
public class Health_UI : MonoBehaviour
{
    public GameObject ui_prefab;
    public Transform target;

    float visible_time = 5f, last_visible;
    Transform ui;
    Image health_slider;

    // Start is called before the first frame update
    void Start()
    {
        foreach(Canvas c in FindObjectsOfType<Canvas>())
        {
            if(c.renderMode == RenderMode.WorldSpace)
            {
                ui = Instantiate(ui_prefab, c.transform).transform;
                health_slider = ui.GetChild(0).GetComponent<Image>();
                ui.gameObject.SetActive(false);
                break;
            }
        }

        GetComponent<Character_stats>().on_Health_Changed += on_health_changed;
    }

    // Update is called once per frame
    void LateUpdate()
    {
        if(ui != null)
        {
            ui.position = target.position;
            ui.forward = -Camera.main.transform.forward;

            if(Time.time - last_visible >= visible_time)
            {
                ui.gameObject.SetActive(false);
            }
        }
        
    }

    /// <summary>
    /// Show Health_ui when attacked, assigned to event on_Health_Changed
    /// </summary>
    /// <param name="max_health"></param>
    /// <param name="curr_health"></param>
    void on_health_changed(int max_health, int curr_health)
    {
        if(ui != null)
        {
            ui.gameObject.SetActive(true);
            health_slider.fillAmount = curr_health / (float)max_health;

            if(curr_health <= 0)
            {
                Destroy(ui.gameObject);
            }

            last_visible = Time.time;
        }
    }
}
