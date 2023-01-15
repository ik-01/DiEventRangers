typedef struct
{
    dvString elementName;
    uint32 field_40;
    char data[0x29C];
    
}DvElementVariablePointLight<optimize=false, read=Str("%s", elementName.str), name="DvElementVariablePointLight">;