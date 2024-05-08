typedef struct
{
    RGBF colorOffset;
    float sphereCurve;
    Vector2 scale;
    Vector2 position;
}ChromaticAbberationNode;


typedef struct
{
    ChromaticAbberationNode node1;
    float field_08;
    ChromaticAbberationNode node2;
    float curveData[32];
    
}DvElementChromaticAberration<optimize=false,  name="DvElementChromaticAberration">;
