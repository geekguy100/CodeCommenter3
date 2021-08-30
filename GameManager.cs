/*****************************************************************************
// File Name :         GameManager.cs
// Author :            Kyle Grenier
// Creation Date :     #CREATIONDATE#
//
// Brief Description : ADD BRIEF DESCRIPTION OF THE FILE HERE
*****************************************************************************/
using UnityEngine;
using UnityEngine.SceneManagement;
using System.Linq;

public class GameManager : Singleton<GameManager>
{
    cout << "WJASD";
    private bool paused = false;
    public bool Paused { get { return paused; } }

    private bool gameOver = false;
    public bool GameOver { get { return gameOver; } }

    private bool correctAccusation = false;

    protected override void Awake()
    {
        base.Awake();
        DontDestroyOnLoad(gameObject);

        Debug.Log("Test");
    }

    void Test()
    {
        print("");
    }
}