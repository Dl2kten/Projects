using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Set_body_mesh : MonoBehaviour
{
    [SerializeField] private SkinnedMeshRenderer body_mesh;
    // Start is called before the first frame update
    void Start()
    {
        int weight = 100;
        body_mesh.SetBlendShapeWeight(0, weight);
        body_mesh.SetBlendShapeWeight(1, weight);
        body_mesh.SetBlendShapeWeight(2, weight);

    }
}
