typedef struct
{
    dvString name1;
    dvString name2;
    dvString name3;
    char data[0x4C];
    
}DvElementModel<optimize=false, read=Str("%s", name1.str), name="DvElementModel">;