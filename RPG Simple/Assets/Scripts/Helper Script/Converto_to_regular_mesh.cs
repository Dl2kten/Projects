using UnityEngine;

public class Converto_to_regular_mesh : MonoBehaviour
{
    [ContextMenu("Convert to regular mesh")]
    void convert()
    {
        SkinnedMeshRenderer skin_renderer = GetComponent<SkinnedMeshRenderer>();
        MeshRenderer mesh_renderer = gameObject.AddComponent<MeshRenderer>();
        MeshFilter mesh_filter = gameObject.AddComponent<MeshFilter>();

        mesh_filter.sharedMesh= skin_renderer.sharedMesh;
        mesh_renderer.sharedMaterials= skin_renderer.sharedMaterials;

        DestroyImmediate(skin_renderer);
        DestroyImmediate(this);
    }
}
