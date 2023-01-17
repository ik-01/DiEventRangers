typedef struct
{
    dvString elementName;
    uint32 field_40;
    float frameStart;
    float frameEnd;
    char data[0x154];
    
}DvElementUnknownCamera<optimize=false, read=Str("%s", elementName.str), name="DvElementUnknownCamera">;