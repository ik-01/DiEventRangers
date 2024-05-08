typedef struct
{
	Vector2 position;
	Vector2 scale;
	float size;
	float rotation;
	float field_18;
	uint32 alpha;
	float field_1c;
	float unk1;
	float unk2;
	Vector2 Center;
	Vector2 Direction;
	float penumbraScale;
	float minPenumbraScale;
	float maxPenumbraScale;
	float bokehScale;
	float minDOFOpacityScale;
	float maxDOFOpacityScale;
	float minOpacityScale;
	float maxOpacityScale;
	float minOpacityDist;
	float maxOpacityDist;
}VignetteParam1;

typedef struct
{
	Vector2 position;
	Vector2 scale;
	float size;
	float rotation;
	float field_18;
	uint32 alpha;
	float field_1c;
	float unk1;
	float unk2;
	float unk3;
	float penumbraScale;
	float unk4;
	float minPenumbraScale;
	float maxPenumbraScale;
	float bokehScale;
	float minDOFOpacityScale;
	float maxDOFOpacityScale;
	float minOpacityScale;
	float maxOpacityScale;
	float minOpacityDist;
	float maxOpacityDist;
}VignetteParam2;


typedef struct
{
	uint32 field_00;
	uint32 field_04;
	VignetteParam1 param1;
	VignetteParam2 param2;
	float curveData[0x20];
    
}DvElementVignetteParam<optimize=false, name="DvElementVignetteParam">;