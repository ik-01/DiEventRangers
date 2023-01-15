typedef struct
{
    dvString elementName;
    uint32 field_40;
    float frameStart;
    float frameEnd;
    char field_4c[0x34];
    
}DvElementNearFarSettings<optimize=false, read=Str("%s", elementName.str), name="DvElementNearFarSettings">;