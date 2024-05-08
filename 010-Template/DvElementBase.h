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
        local DvNodeType m_node_type;
		local string m_node_name;
        local int m_childCount;
        local int m_baseSize;
        SetRandomBackColor();
        struct node_info_core
        {
            GUID dv_guid <name = "GUID">;
            DvNodeType node_type <name = "Node Type">;
            int32 nodeSize <name = "Node Size", read=Str("%d",this * 4), write=(this = Atoi( value ) / 4 )>;
            int32 childCount <name = "Child Count">;
            uint32 flag <name = "Flags">;
            int priority <name = "Priority">;
            byte padding[12] <name = "Padding">;
            dvString name <name = "Name">;

			m_node_name = Strlen(name.str) <= 0 ? "Node" : name.str;
            m_node_type = node_type;
            m_childCount = childCount;
            m_baseSize = nodeSize;
        } node_info<name = "Node Properties">;
		
        local int i = 0;
		SetRandomBackColor();
        ReadNodeByType(m_node_type);

        if (m_childCount > 0)
            struct Children
            {
                for (i = 0; i < m_childCount; i++)
                    ReadNode();
            } children<name = "Children">;

        //  byte unky[GetSizeOfNode(nodeSize, category)];

    } node<name = Str("%s (%s)",m_node_name,GetNodeTypeName(m_node_type))>;
}

void ReadNodeByType(DvNodeType node_type)
{
	switch (node_type)
	{
		case Path:
		{
			struct path_node
			{
				Matrix44 matrix<name = "Transform Matrix">;
				uint flag<name = "Flags">;
				byte padding[12];
			} path<name = "Path Info">;
			break;
		}
		case PathMotion:
		{
			struct path_motion_node
			{
				uint32 flag<name = "Flags">;
				uint32 frameStart<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
				uint32 frameEnd<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
				uint32 padding;
			} path_motion<name = "Path Motion Info">;
			break;
		}
		case Camera:
		{
			struct camera_node
			{
				uint32 flag<name = "Flags">;
				uint32 frameProgressionCount<name = "Frame Progression Count">;
				uint32 captionCount<name = "Caption Count">;
				uint32 field_0C;
				SetRandomBackColor();
				float frameProgression[frameProgressionCount]<name = "Frame Progression">;
				SetRandomBackColor();
				float frameProgressionSpeed[frameProgressionCount]<name = "Frame Progression Speed">;
			} camera<name = "Camera Info">;
			break;
		}
		case CameraMotion:
		{
			struct camera_motion_node
			{
				uint32 flag<name = "Flags">;
				uint32 frameStart<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
				uint32 frameEnd<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
				uint32 field_0C;
			} camera_motion<name = "Camera Motion Info">;
			break;
		}
		case Character:
		case ModelCustom:
		{
			struct character_model_node
			{
				uint32 useMasterLevel;
				dvString name1;
				dvString name2;
				dvString name3;
				char unk[0x4C];
			} character_model<name = "Character/Custom Model Info">;
			break;
		}
		case CharacterMotion:
		case MotionModel:
		{
			struct character_model_motion_node
			{
				uint32 flag<name = "Flags">;
				// Need to figure out
				uint32 frameStart<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
				uint32 frameEnd<read = Str("%d", this / 100), write = (this = Atoi(value) * 100)>;
				uint32 field_0C;
				// Mostly is Dst0000 (DiEventState 0000)
				char asmStateName[8]<name = "ASM State Name">;
				// is speed
				float field_50;
				uint32 field_54;
				uint32 field_58[4];
			} character_model_motion<name = "Character/Custom Model Motion Info">;
			break;
		}
		case CharacterBehavior:
		{
			struct character_behavior_node
			{
				local int size = m_baseSize * 4;
				byte unkBytes[size];
			} character_behavior<name = "Character Behavior Info">;
			break;
		}
		case Asset:
			break;
		case ModelNode:
		{
			struct modelnode_node
			{
				uint32 field_00;
				dvString name1<name = "Node Name">;
				byte padding[12]<name = "Padding">;
			} modelnode<name = "Model Node Info">;
			break;
		}
		case Element:
		{
			struct element_node
				{
					DvElementID elementID <name = "Element ID">;
					float frameStart <name = "Frame Start">;
					float frameEnd <name = "Frame End">;
					int32 version <name = "Version">;
					uint32 flag <name = "Flag">;
					DvElementPlayType playType <name = "Play Type">;
					DvElementUpdateTiming elementUpdateTiming <name = "Element Update Timing">;
					uint32 padding <name = "Padding">;
				} element <name = "Element Properties">;
			if (IsUnknownElement(element.elementID))
				struct unknown_node
				{
					local int size = m_baseSize * 4 - sizeof(element_node);
					byte unkBytes[size];
				} unknown<name = "Unknown Element Info">;
			else
				ReadElement(element.elementID);
			break;
		}
		// Not used in Sonic Frontiers
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