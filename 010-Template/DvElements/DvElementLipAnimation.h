typedef struct
{
    uint32 field_00;
    dvString filename <name="Filename">;
    uint32 Field44;
    uint32 Field48;
    uint32 Field4C;
    float curveData[64];
    
}DvElementLipAnimation<optimize=false, read=Str("%s", filename.str), name="DvElementLipAnimation">;