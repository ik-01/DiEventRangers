typedef struct
{
    dvString elementName;
    uint32 field_40;
    float frameStart;
    float frameEnd;
    char data[0x18];
    dvString filename;
    char data1[0x10];
    
}DvElementUVAnimation<optimize=false, read=Str("%s", elementName.str), name="DvElementUVAnimation">;