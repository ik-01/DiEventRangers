typedef struct
{
    dvString elementName;
    uint32 field_40;
    float frameStart;
    float frameEnd;
    uint32 field_4c[3];
    uint32 field_4d;
    uint32 field_4e;
    uint32 field_4f;
    float data[0x20];
    
}DvElementCyberSpaceNoise<optimize=false, read=Str("%s", elementName.str), name="DvElementCyberSpaceNoise">;