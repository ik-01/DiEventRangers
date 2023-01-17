typedef struct
{
    dvString elementName;
    uint32 field_40;
    float frameStart;
    float frameEnd;
    char data[0x194];
    
}DvElementQTE<optimize=false, read=Str("%s", elementName.str), name="DvElementQTE">;