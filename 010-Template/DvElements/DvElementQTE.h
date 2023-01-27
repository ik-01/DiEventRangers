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
	QTEType field_60;
	QTEButton field_64;
	float redCircleSize;
	float redCircleThickness;
	float whiteLineThickness;
	float whiteLineSpeed;
	float multiplier;
	float redCircleOutlineThickness;
	float whiteLineOutlineThickness;
	uint32 failCount;
	uint32 field_88;
	char field_8c[0x40];
	float field_cc;
	float field_d0;
	float field_d4;
	char field_d8[0x108];
    
}DvElementQTE<optimize=false, name="DvElementQTE">;