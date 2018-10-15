using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;


public class PlayerMovement : MonoBehaviour {

    //This is a reference to the Rigidbody component called "rb"
    public Rigidbody rb;

    
    public float forwardforce = 200f;
    public float sidewaysforce = 500f;
    public float upwardforce = 600f;
    public int Start()
    {
        Scene currentScene = SceneManager.GetActiveScene();
        return currentScene.buildIndex;
    }
    



    // We marked this as "Fixed Update"because we are using it to mess with physics
    public void FixedUpdate() {
        rb.AddForce(0, 0, forwardforce * Time.deltaTime);    //Add a forward force 	


        float temp = Input.acceleration.x ; //Used Accelerometer
        transform.Translate(temp, 0, 0);




        if (Input.GetKey("d"))
        {
            
            
            Right();
           
        }

        if (Input.GetKey("a"))
        {
           
            
            Left();
        }
        if (Start() == 9)
        {
            if (Input.GetKey("w"))
            {
                Fly();
            }
        }
        if (rb.position.y < -1f)
        {
            FindObjectOfType<GameManager>().EndGame();
        }

    }


    public void Right()
    {
        rb.AddForce(sidewaysforce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
    }
    public void Left()
    {
        rb.AddForce(-sidewaysforce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
    }
    public void Fly()
    {
        rb.AddForce(0, upwardforce * Time.deltaTime, 0, ForceMode.VelocityChange);
    }
}