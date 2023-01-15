typedef struct
{
	dvString elementName;
	uint32 field_40;
	float frameStart;
	float frameEnd;
	char field_48[0x34];
	float field_80[32];
    
}DvElementCameraExposure<optimize=false, read=Str("%s", elementName.str), name="DvElementCameraExposure">;