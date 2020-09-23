using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SceneComm : MonoBehaviour
{
    public void loadScene(int sceneNumber)
    {
        SystemManager.Instance.loadScene(sceneNumber);
    }

}
