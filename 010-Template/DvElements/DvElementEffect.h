typedef struct
{
    Matrix44 mtx;
    uint32 field_9c;
    dvString filename;
    char field_dc[0x20];
    float field_fc[0x80];
    
}DvElementEffect<optimize=false, read=Str("%s", filename.str), name="DvElementEffect">;