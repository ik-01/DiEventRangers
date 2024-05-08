enum <uint32> AnimationType
{
    SkeletalAnimation = 1,
    UVAnimation = 2,
    VisibilityAnimation = 3,
    MaterialAnimation = 4
};

typedef struct
{
    AnimationType type;
    dvString filename;

}CompositeAnimation<optimize=false, read=Str("%s", filename.str), name="Animation", optimize=false>;

typedef struct
{
	uint32 field_00;
	char AsmStateName[8];
	uint32 field_0c;
	CompositeAnimation animations[16];
    uint32 activeAnimCount <name="Active Animation Count">; 
    
}DvElementCompositeAnimation<optimize=false, name="DvElementCompositeAnimation">;