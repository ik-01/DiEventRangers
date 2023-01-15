typedef struct
{
    dvString elementName;
    char data[0xC4];
    
}DvElementTime<optimize=false, read=Str("%s", elementName.str), name="DvElementTime">;