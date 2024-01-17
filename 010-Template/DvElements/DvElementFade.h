typedef struct
{
	RGBA32 color <name="Color", read=Str("RGBA: [%d,%d,%d,%d]", this.R,this.G,this.B,this.A)>;
    float curveData[32] <name="Curve Data", optimize=false>;
    
}DvElementFade<optimize=false,  name="DvElementFade">;