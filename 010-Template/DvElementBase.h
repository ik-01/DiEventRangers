

void ReadNodes(int address)
{
    if (address <= 0) return;

    FSeek(address);

    struct Nodes
    {
        ReadNode();
    } nodes<name = "Nodes">;
}

void ReadNode()
{
    struct Node
    {
        local DvElementCategory m_category;
        local string m_name;
        local int m_childCount;
        local int m_baseSize;
        SetRandomBackColor();
        struct NodeProperties
        {
            GUID guid <name = "GUID">;
            DvElementCategory category <name = "Category">;
            int32 nodeSize <name = "Node Size", read=Str("%d",this * 4), write=(this = Atoi( value ) / 4 )>;
            int32 childCount <name = "Child Count">;
            uint32 flag <name = "Flags">;
            int priority <name = "Priority">;
            byte padding[12] <name = "Padding", hidden = false>;
            dvString name <name = "Name">;

            m_name = GetNameOfNode(name.str, category);
            m_category = category;
            m_childCount = childCount;
            m_baseSize = nodeSize;
        } nodeProperties<name = "Node Properties">;
		
        local int i = 0;
		SetRandomBackColor();
        ReadCategory(m_category);

        if (m_childCount > 0)
            struct Children
            {
                for (i = 0; i < m_childCount; i++)
                    ReadNode();
            } children<name = "Children">;

        //  byte unky[GetSizeOfNode(nodeSize, category)];

    } node<name = (m_name)>;
}

void ReadCategory(DvElementCategory category)
{
	switch (category)
	{
	case RootPath:
	{
		struct RootPathInfo
		{
			Matrix44 matrix<name = "Matrix">;
			uint flag<name = "Flag">;
			byte padding[12]<hidden = true>;
		} rootPathInfo<name = "Root Path Info">;
		break;
	}
	case PathMotion:
	{
		break;
	}
	case Camera:
	{
		struct CameraInfo
		{
			uint32 flag<name = "Flags">;
			uint32 frameProgressionCount<name = "Frame Progression Count">;
			uint32 captionCount<name = "Caption Count">;
			byte padding[4]<hidden = true>;
			SetRandomBackColor();
			float frameProgression[frameProgressionCount]<name = "Frame Progression">;
			SetRandomBackColor();
			float frameProgressionSpeed[frameProgressionCount]<name = "Frame Progression Speed">;
		} cameraInfo<name = "Camera Info">;
		break;
	}
	case CameraMotion:
	{
		struct CameraMotionInfo
		{
			uint32 flag<name = "Flags">;
			uint32 frameStart<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
			uint32 frameEnd<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
			byte padding[4]<hidden = true>;
		} cameraMotionInfo<name = "Camera Motion Info">;
		break;
	}
	case Character:
	{
		struct CharacterInfo
		{
			uint32 field_00;
			dvString name1;
			dvString name2;
			dvString name3;
			char unk[0x4C];
		} characterInfo<name = "Character Info">;
		break;
	}
	case CharacterMotion:
	{
		struct CharacterMotionInfo
		{
			uint32 flag<name = "Flags">;
			// Need to figure out
			uint32 frameStart<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
			uint32 frameEnd<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
			uint32 field_0c<hidden = true>;
			// Mostly is Dst0000 (DiEventState 0000)
			char asmStateName[8]<name = "ASM State Name">;
			// is speed
			float field_50;
			uint32 field_54;
			uint32 field_58[4];
		} characterMotionInfo<name = "Character Motion Info">;
		break;
	}
	case CharacterBehavior:
	{
		struct CharacterBehaviorInfo
		{
			local int size = m_baseSize * 4;
			byte unkBytes[size];
		} characterBehaviorInfo<name = "Character Behavior Info">;
		break;
	}
	case ModelCustom:
	{
		struct ModelCustomInfo
		{
			uint32 field_00;
			dvString name1;
			dvString name2;
			dvString name3;
			char unk[0x4C];
		} modelCustomInfo<name = "Custom Model Info">;
		break;
	}
	case Asset:
		break;
	case MotionModel:
	{
		struct MotionModelInfo
		{
			uint32 field_00<hidden = true>;
			// Need to figure out
			uint32 frameStart<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
			uint32 frameEnd<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
			uint32 field_0c<hidden = true>;
			// Mostly is Dst0000 (DiEventState 0000)
			char asmStateName[8]<name = "ASM State Name">;
			// is speed
			float field_50;
			uint32 field_54;
			uint32 field_58[4];
		} motionModelInfo<name = "Motion Model Info">;
		break;
	}
	case ModelNode:
	{
		struct ModelNodeInfo
		{
			uint32 field_00;
			dvString name1<name = "Node Name">;
			byte padding[12]<name = "Padding">;
		} modelNodeInfo<name = "Model Node Info">;
		break;
	}
	case Element:
	{
		struct ElementProperties
			{
				DvElementID elementID <name = "Element ID">;
				float frameStart <name = "Frame Start">;
				float frameEnd <name = "Frame End">;
				int32 version <name = "Version">;
				uint32 flag <name = "Flag">;
				DvElementPlayType playType <name = "Play Type">;
				DvElementUpdateTiming elementUpdateTiming <name = "Element Update Timing">;
				uint32 padding <name = "Padding">;
			} elementProperties <name = "Element Properties">;
        if (IsUnknownElement(elementProperties.elementID))
			struct UnknownInfo
			{
				local int size = m_baseSize * 4 - sizeof(ElementProperties);
				byte unkBytes[size];
			} unknownInfo<name = "Unknown Node Info">;
		else
            ReadElement(elementProperties.elementID);
		break;
	}
	case Stage:
		break;
	case StageScenarioFlag:
		break;
	case InstanceMotion:
		break;
	case InstanceMotionData:
		break;
	case FolderCondition:
		break;
	case CharacterBehaviorSimpleTalk:
		break;
	}
}