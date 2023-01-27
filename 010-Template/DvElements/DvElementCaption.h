typedef struct
{
	char captionName[0x10];
	uint32 field_70; //is language code ??
	uint32 field_78;
    
}DvElementCaption<optimize=false, read=Str("%s (%d)", captionName,field_70), name="DvElementCaption">;