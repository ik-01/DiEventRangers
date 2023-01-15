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
    Matrix44 mtx;
    uint32 field_9c;
    dvString filename;
    char field_dc[0x20];
    float field_fc[0x80];
    
}DvElementEffect<optimize=false, read=Str("%s", elementName.str), name="DvElementEffect">;