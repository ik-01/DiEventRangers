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
    char data[0x30];
    ComplexAnimation anim[0x10];
    uint32 field_03;        // is active anim count?
    
}DvElementComplexAnimation<optimize=false, read=Str("%s", elementName.str), name="DvElementComplexAnimation">;