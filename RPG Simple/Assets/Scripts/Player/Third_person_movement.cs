using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Third_person_movement : MonoBehaviour
{
    public CharacterController controller;
    public Transform cam;
    public TextMeshProUGUI boundary_text;

    public Transform ground_check;
    public LayerMask ground_mask; //check for ground layer
    public Vector3 velocity;

    public float speed = 6f, turn_smooth_time = 0.1f;
    public float gravity = -9.8f;
    public float ground_radius = 0.2f; //radius for sphere check
    public float jump_height = 1.5f;

    Interactable focus;
    bool is_grounded;
    float turn_smooth_velocity;

    // Update is called once per frame
    void Update()
    {
        apply_gravity();
        player_move();
        right_select(); //can move these two to different class for inputs?
        left_select();
    }

    /// <summary>
    /// Third person Player movement taking into account camera angle
    /// </summary>
    void player_move()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");

        //normalized ensures speed is same even if 2 buttons pressed at once
        Vector3 direction = new Vector3(horizontal, 0f, vertical).normalized;

        if (direction.magnitude >= 0.1f)
        {
            float target_angle = Mathf.Atan2(direction.x, direction.z) * Mathf.Rad2Deg + cam.eulerAngles.y;
            float angle = Mathf.SmoothDampAngle(transform.eulerAngles.y, target_angle, ref turn_smooth_velocity, turn_smooth_time);
            //smoothes out numbers and angles so character turns are more natural

            transform.rotation = Quaternion.Euler(0f, angle, 0f);

            //takes into account camera rotation when moving
            Vector3 move_direction = Quaternion.Euler(0f, target_angle, 0f) * Vector3.forward;
            controller.Move(move_direction.normalized * speed * Time.deltaTime);
        }

       
    }

    /// <summary>
    /// Adds gravity to player so falls when above ground
    /// </summary>
    void apply_gravity()
    {
        is_grounded = Physics.CheckSphere(ground_check.position, ground_radius, ground_mask);

        if (is_grounded)
        {

            if (velocity.y < 0)
            {
                //instead of 0, account for some delay
                velocity.y = -2f;
            }

            if (Input.GetButtonDown("Jump"))
            {
                Debug.Log("jump");
                velocity.y = Mathf.Sqrt(jump_height * -2 * gravity);
            }
        }
        else
        {
            velocity.y += gravity * Time.deltaTime;
        }

        controller.Move(velocity * Time.deltaTime);
    }

    /// <summary>
    /// Trigger for 
    /// </summary>
    /// <param name="other"></param>
    private void OnTriggerEnter(Collider other)
    {
        //Debug.Log("hit");
        if (other.gameObject.tag == "Boundary_wall")
        {
            boundary_text.enabled = true;
        }

        if(other.gameObject.name == "Next_level_trigger")
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        boundary_text.enabled = false;
    }
    /// <summary>
    /// Right mouse click, used mainly to select items, enemies
    /// </summary>
    void right_select()
    {
        if (Input.GetMouseButtonDown(1))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;

            if (Physics.Raycast(ray, out hit))
            {
                Interactable interact = hit.collider.GetComponent<Interactable>();
                if (interact)
                {
                    set_focus(interact);
                }
            }
        }
    }

    /// <summary>
    /// Left mouse click currently deselects
    /// </summary>
    void left_select()
    {
        if (Input.GetMouseButtonDown(0))
            remove_focus();
    }

    /// <summary>
    /// Sets focus on Interactable object
    /// </summary>
    /// <param name="new_focus"></param>
    void set_focus(Interactable new_focus)
    {
        Debug.Log("focus");
        focus = new_focus;
        if (focus)
        {
            focus.on_focus(transform);
        }
    }

    /// <summary>
    /// Removes focus from previously selected Interactable object
    /// </summary>
    void remove_focus()
    {
        Debug.Log("no focus");
        if (focus)
        {
            focus.on_defocus();
            focus = null;
        }

    }
}
