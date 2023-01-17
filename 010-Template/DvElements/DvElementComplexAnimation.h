enum <uint32> AnimationType
{
    SkeletalAnimation = 1,
    UVAnimation = 2,
    MaterialAnimation = 4
};

typedef struct
{
    AnimationType type;
    dvString filename;

}ComplexAnimation<optimize=false, read=Str("%s", filename.str), name="Animation">;

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
	char data[0x8];
	uint32 field_6c;
	ComplexAnimation animations[0x10];
    uint32 field_03;        // is active anim count?
    
}DvElementComplexAnimation<optimize=false, read=Str("%s", elementName.str), name="DvElementComplexAnimation">;