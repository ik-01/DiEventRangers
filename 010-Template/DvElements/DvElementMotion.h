typedef struct
{
	dvString elementName;
	uint32 field_40[4];
	// Mostly is Dst0000 (DiEventState 0000)
	char asmStateName[8];
	float field_50;
	uint32 field_54[5];
    
}DvElementMotion<optimize=false, read=Str("%s", elementName.str), name="DvElementMotion">;