typedef struct
{
    Matrix44 TransformMatrix <name="Transform Matrix">;
    uint32 field_9c;
    dvString filename <name="Filename">;
    uint32 field_dc[8];
    float m_anim_data[128] <name="Animation Data", optimize=false>;
    
}DvElementEffect<optimize=false, read=Str("%s", filename.str), name="DvElementEffect">;