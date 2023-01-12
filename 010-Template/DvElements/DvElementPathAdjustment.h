typedef struct
{
    dvString elementName;
    char data[0x70];
    
}DvElementPathAdjustment<optimize=false, read=Str("%s", elementName.str), name="DvElementPathAdjustment">;