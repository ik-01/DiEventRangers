typedef struct
{
    RGBA32 Color <name="Color", read=Str("RGBA: [%d,%d,%d,%d]", this.R,this.G,this.B,this.A)>;
    float Distance;
    float NoiseTextureScrollSpeed;
    float BlurScale;
    float ColorGain;
    float NoiseGain;
}
AuraNode<optimize=false, name="AuraNode">;


typedef struct
{
    AuraNode Nodes[2];
    uint32 field_00;
    float AnimData[32];
    
}DvElementAura<optimize=false, name="DvElementAura">;