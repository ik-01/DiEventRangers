enum <uint32> DvResourceKind
{
	ResourceKind_Dummy=0,
    ResourceKind_tex=1,
    ResourceKind_Character=2,
    ResourceKind_Model=3,
    ResourceKind_MotionCamera=4,
    ResourceKind_MotionPath=5,
    ResourceKind_MotionModel=6,
    ResourceKind_MotionCharacter=7,
    ResourceKind_EquipModel=8,
    ResourceKind_Behavior=9
};


string GetNameOfResource(DvResourceKind resourceKind)
{
    local string m_resource_name;

    switch (resourceKind)
    {
        default: m_resource_name = "Unknown"; break;
		case ResourceKind_Dummy: m_resource_name = "Unknown"; break;
        case ResourceKind_tex: m_resource_name = "Tex"; break;
        case ResourceKind_Character: m_resource_name = "Character"; break;
        case ResourceKind_Model: m_resource_name = "Model"; break;
        case ResourceKind_MotionCamera: m_resource_name = "Camera Motion"; break;
        case ResourceKind_MotionPath: m_resource_name = "Motion Path"; break;
        case ResourceKind_MotionModel: m_resource_name = "Motion Model"; break;
        case ResourceKind_MotionCharacter: m_resource_name = "Character Motion"; break;
        case ResourceKind_EquipModel: m_resource_name = "Custom Model"; break;
        case ResourceKind_Behavior: m_resource_name = "Character Behavior"; break;
    }

    return m_resource_name;
}

void ReadDvResource (uint32 address)
{
	struct DvResource
	{
		SetRandomBackColor();
		DvObject resourceObject <name="Resource Object">;
		struct Resource
		{
			SetRandomBackColor();
			GUID dv_guid <name="GUID">;
			DvResourceKind dvResourceKind <name="Resource Type">;
			uint32 flag <name="Flags">;
			uint32 field_18;
			char filename[192];
			
			// They're empty idk
			byte data[596];
		} resource [resourceObject.count]<optimize=false, name="DvResource", read=Str("%s (%s)", filename, GetNameOfResource(dvResourceKind))>;
	}dvResource<optimize=false, name="Resource">;
}