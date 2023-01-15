typedef struct
{
    dvString elementName;
    char data[0xEC];
    
}DvElementAura<optimize=false, read=Str("%s", elementName.str), name="DvElementAura">;