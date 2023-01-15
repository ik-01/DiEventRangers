typedef struct
{
    dvString elementName;
    char data[0x450];
    
}DvElementCameraOffset<optimize=false, read=Str("%s", elementName.str), name="DvElementCameraOffset">;