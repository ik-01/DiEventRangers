typedef struct
{
    dvString elementName;
    uint32 field_40;
    float frameStart;
    float frameEnd;
    uint32 field_4c;
	uint32 field_50;
	uint32 field_54;
	uint32 field_58;
	uint32 field_5c;
	byte field_60;
	byte pad[3];
	uint32 field_64;
	uint32 field_68;
	uint32 field_6c;
    float field_70[32];
    
}DvElementFade<optimize=false, read=Str("%s", elementName.str), name="DvElementFade">;