typedef struct
{
    uint32 field_00;
    dvString filename <name="Filename">;
    uint32 Field44;
    float Field48;
    uint32 Field4C;
    uint32 Field50;
    
}DvElementVertexAnimation<optimize=false, read=Str("%s", filename.str), name="DvElementVertexAnimation">;