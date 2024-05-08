typedef struct
{
	float focus;
	float focusRange;
	float near;
	float far;
}DOFNode;


typedef struct
{
	uint32 field_60;
	DOFNode nodes[2];
	float field_84;
	float field_88;
	uint32 field_8c;
	uint32 field_90;
	float field_94;
	float field_98;
	float field_9c;
	float field_a0;
	float field_a4;
	float field_a8;
	float field_ac;
	float m_anim_data[32] <name="Animation Data", optimize=false>;
    
}DvElementDOF<optimize=false, name="DvElementDOF">;