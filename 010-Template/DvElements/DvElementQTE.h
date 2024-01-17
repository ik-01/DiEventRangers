enum <uint32> QTEType
{
	PressPrompt = 0,
	Mash,
	RedCircle,
	TheEndVariant,
	Unknown,
};

enum <uint32> QTEButton
{
	A = 0,
	B,
	X,
	Y,
	LB_RB,
	LB,
	RB,
	MashA,
	MashB,
	MashX,
	MashY,
	MashLB,
	MashRB,
	Unknown1,
	Unknown2,
	Unknown3,
};

typedef struct
{
	QTEType qteType <name="QTE Type">;
	QTEButton qteButton <name="QTE Button">;
	float redCircleSize <name="Red Circle Size">;
	float redCircleThickness <name="Red Circle Thickness">;
	float whiteLineThickness <name="White Line Thickness">;
	float whiteLineSpeed <name="White Line Speed">;
	float multiplier  <name="Multiplier">;
	float redCircleOutlineThickness <name="Red Circle Outline Thickness">;
	float whiteLineOutlineThickness <name="White Line Outline Thickness">;
	uint32 failCount <name="Fail Count">;
	uint32 field_88;
	char field_8c[0x40];
	float field_cc;
	float field_d0;
	float field_d4;
	char field_d8[0x108];
    
}DvElementQTE<optimize=false, name="DvElementQTE">;