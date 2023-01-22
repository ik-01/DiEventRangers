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
	uint32 field_60;
	uint32 field_64;
	GUID guid;
	uint32 field_78[11];
	float field_80[64];
    
}DvElementLookAtIK<optimize=false, read=Str("%s", elementName.str), name="DvElementLookAtIK">;