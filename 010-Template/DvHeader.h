typedef struct
{
	SetRandomBackColor();
	uint32 count;
	uint32 field_04;
    uint32 field_08;
	uint32 field_0c;
	float frame[count];
} DvUnknown1 <name="DvUnknown1">;


typedef struct
{
	local int i;
	SetRandomBackColor();
	
	uint32 field_00;
	uint32 field_04;
	uint32 field_08;
	float frames;
	uint32 field_10;
	uint32 offsetTable[6] <format=hex, name="Offset Table", read=GetFixedOffset>;
	float field_2c;
	float field_30;
	uint32 field_34;
	uint32 field_38;
	uint32 field_3c;
	
	for (i = 0; i < 6; i++)
	{
		if (i != 5)
		{
			FSeek(offsetTable[i] + RELATIVE_OFFSET);
			DvUnknown1 dvUnk1;
		}
		else
		{
			FSeek(offsetTable[i] + RELATIVE_OFFSET);
			DvElementBase dvElements;
		}
	}
	
} DvHeader <name="DvHeader">;