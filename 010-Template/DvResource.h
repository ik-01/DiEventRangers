enum <uint32> DvResourceType
{
    Animator = 2,
    CameraAnimation = 4,
    Animation1 = 6,
    Animation2 =7,
};

typedef struct
{
    SetRandomBackColor();
    GUID guid;
    DvResourceType dvResourceType <name="DvResourceType">;
    uint32 field_14;
    uint32 field_18;
    dvString filename;
	
	// They're empty idk
    byte data[0x2D4];
}DvResource<optimize=false, name="DvResource", read=Str("%s (%s)", filename.str, EnumToString(dvResourceType))>;


typedef struct
{
    SetRandomBackColor();
    uint32 count;
	uint32 field_04;
    uint32 field_08;
	uint32 field_0c;
    DvResource dvResource[count];
}DvResources<optimize=false, name="DvResources">;