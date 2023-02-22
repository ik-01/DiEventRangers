enum <uint32> DvResourceType
{
    Animator = 2,
    CameraAnimation = 4,
    Animation1 = 6,
    Animation2 =7,
};

void ReadDvResource (uint32 address)
{
	struct DvResource
	{
		SetRandomBackColor();
		DvObject resourceObject <name="Resource Object">;
		struct Resource
		{
			SetRandomBackColor();
			GUID guid;
			DvResourceType dvResourceType <name="DvResourceType">;
			uint32 field_14;
			uint32 field_18;
			dvString filename;
			
			// They're empty idk
			byte data[0x2D4];
		} resource [resourceObject.count]<optimize=false, name="DvResource", read=Str("%s (%s)", filename.str, EnumToString(dvResourceType))>;
	}dvResource<optimize=false, name="Resource">;
}