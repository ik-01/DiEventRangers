typedef struct
{
	dvString elementName;
	Matrix44 mtx;
	uint32 field_80;
	uint32 field_84;
	uint32 field_88;
	uint32 field_8c;
    
}DvElementRootPath<optimize=false, read=Str("%s",  elementName.str), name="DvElementRootPath">;
