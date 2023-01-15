typedef struct
{
    dvString elementName;
    uint32 field_40;
    dvString name1;
    dvString name2;
    dvString name3;
    char data[0x4C];
    
}DvElementModel<optimize=false, read=Str("%s", elementName.str), name="DvElementModel">;