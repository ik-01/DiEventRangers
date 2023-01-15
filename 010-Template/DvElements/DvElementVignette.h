typedef struct
{
    dvString elementName;
    uint32 field_40;
    float frameStart;
    float frameEnd;
    uint32 field_4c[3];
    uint32 field_4d;
    uint32 field_4e;
    char data[0xc8];
    float data1[0x20];
    
}DvElementVignette<optimize=false, read=Str("%s", elementName.str), name="DvElementVignette">;