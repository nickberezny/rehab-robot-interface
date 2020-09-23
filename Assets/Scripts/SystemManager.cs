using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SystemManager : MonoBehaviour
{
    public static SystemManager Instance { get; private set; }

    private void Awake()
    {
        if (Instance != null)
        {
            Destroy(this.gameObject);
            return;
        }
        else
        {
            Instance = this;
            DontDestroyOnLoad(this);

        }
    }

    private void Start()
    {
        loadScene(1);
    }


    public void loadScene(int sceneNumber)
    {
        SceneManager.LoadScene(sceneNumber);
    }
}
