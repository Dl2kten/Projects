using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class Dialogue_manager : MonoBehaviour
{
    #region Singleton
    public static Dialogue_manager instance;
    private void Awake()
    {
        if(instance != null)
        {
            Debug.LogWarning("More than one Dialogue manager.");
            return;
        }

        instance = this;
    }
    #endregion

    private List<string> sentences;
    private Item item;
    private int count = 0;
    public int total = 0;
    [SerializeField] private TextMeshProUGUI dialogue_text;
    [SerializeField] private TextMeshProUGUI name_text;
    [SerializeField] private GameObject continue_panel;
    [SerializeField] private GameObject shop_panel;
    [SerializeField] private GameObject choice_panel;
    [SerializeField] private GameObject sell_transaction_panel;
    [SerializeField] private GameObject buy_transaction_panel;
    [SerializeField] private Animator dialogue_animator;
    [SerializeField] private Animator buy_animator;
    [SerializeField] private Animator sell_animator;

    /// <summary>
    /// Starts the dialogue, calls display next sentence
    /// </summary>
    /// <param name="dialogue"></param>
    public void start_dialogue(Dialogue dialogue)
    {
        name_text.text= dialogue.name;

        sentences = new List<string>(dialogue.sentences);
        Inventory.instance.inventory_show_items();
        display_next_sentence();
    }


    /// <summary>
    /// Displays next sentence on continue button press
    /// </summary>
    public void display_next_sentence()
    {
        if(count > sentences.Count)
        {
            Debug.LogWarning("Sentences array out of range.");
            return;
        } 
        else
        {
            if(count == 2)
            {
                continue_panel.SetActive(false);
                shop_panel.SetActive(true);
                choice_panel.SetActive(false);
            }
                
            if(count == 3)
            {
                shop_panel.SetActive(false);
                choice_panel.SetActive(true);
            }
            string sentence = sentences[count++];
            StopAllCoroutines(); //in case user presses continue while text still typing
            StartCoroutine(type_sentence(sentence));
        }
    }

    /// <summary>
    /// On buy button click
    /// </summary>
    public void show_buy_panel()
    {
        dialogue_animator.SetBool("is_open", false);
        buy_animator.SetBool("is_open", true);
        shop_panel.SetActive(false);
    }


    /// <summary>
    /// On buy button click
    /// </summary>
    public void buy()
    {
        //subtract cost from gold, if not enough, text box flash red
        if(Inventory.instance.inventory_items.gold - item.shop_worth >= 0)
        {
            Inventory.instance.add(item);
            buy_transaction_panel.SetActive(false);
        }else
        {
            TextMeshProUGUI[] texts = buy_transaction_panel.GetComponentsInChildren<TextMeshProUGUI>();
            texts[0].text = "Insufficient funds!";
            texts[1].text = "Return to shop selection.";
        }

    }

    /// <summary>
    /// On sell button click
    /// </summary>
    public void show_sell_panel()
    {
        dialogue_animator.SetBool("is_open", false);
        sell_animator.SetBool("is_open", true);
        shop_panel.SetActive(false);
    }

    /// <summary>
    /// Sets the item to be sold
    /// </summary>
    /// <param name="new_item"></param>
    public void set_item(Item p_item)
    {
        item = p_item;
    }

    /// <summary>
    /// On yes_sell_button click
    /// </summary>
    /// <param name="item"></param>
    public void sell()
    {
        Inventory.instance.inventory_items.gold += item.sell_worth;
        Inventory.instance.remove(item);
        sell_transaction_panel.SetActive(false);
    }

    /// <summary>
    /// On no_sell button click
    /// </summary>
    public void no_sell()
    {
        sell_transaction_panel.SetActive(false);
        buy_transaction_panel.SetActive(false);
    }

    /// <summary>
    /// On cancel button click
    /// </summary>
    public void cancel()
    {
        buy_animator.SetBool("is_open", false);
        sell_animator.SetBool("is_open", false);
        dialogue_animator.SetBool("is_open", true);

        sell_transaction_panel.SetActive(false);
        buy_transaction_panel.SetActive(false);
        count = 3;
        display_next_sentence();
    }

    /// <summary>
    /// On no button click
    /// </summary>
    public void no_selection()
    {
        count = 2;
        display_next_sentence();
    }


    /// <summary>
    /// On yes button click
    /// </summary>
    public void yes_selection()
    {
        //SceneManager.LoadScene next scene
        Debug.Log("Load next scene");
    }

    /// <summary>
    /// Type out sentences letter by letter, animation
    /// </summary>
    /// <param name="sentence"></param>
    /// <returns></returns>
    IEnumerator type_sentence(string sentence)
    {
        dialogue_text.text = "";
        foreach(char letter in sentence.ToCharArray())
        {
            dialogue_text.text += letter;
            yield return new WaitForSeconds(0.04f);
        }
    }

}