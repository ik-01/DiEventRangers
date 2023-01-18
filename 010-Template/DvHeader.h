typedef struct
{
	SetRandomBackColor();
	uint32 count;
	uint32 field_04;
	uint32 field_08;
	uint32 field_0c;
	float frame[count];
} DvUnknown1 <name="DvUnknown1">;


// Note: this implementation is terrible
// Needs more research
typedef struct
{
	SetRandomBackColor();
	uint32 field_00;
	uint32 field_04;
	uint32 frameStart <read=Str("%d",this / 100), write=(this = Atoi( value ) * 100 )>;
	uint32 frameEnd  <read=Str("%d",this / 100), write=(this = Atoi( value ) * 100 )>;
	uint32 field_10;
	uint32 size;
	uint32 isTotalFrameCount <read=Str("%d",this/100), write=(this = Atoi( value ) * 100 )>; // Needs to figure out
	uint32 index;
	uint32 field_20;
	uint32 field_24;
	uint32 field_28;
	uint32 field_2c;
	char name[0x20];
	if (field_20 != 0)
	{
		uint32 field_50;
		int32 field_54;
		int32 field_58;
		int32 field_5c;
	}
	// Need to figure this struct
	int32 field_60[size/4];
	
} QTE <optimize=false,name="QTE", read=Str("%s",name), comment="Note: Name string using UTF-8. You need to change text encoding in 'View'">;


typedef struct
{
	SetRandomBackColor();
	uint32 count;
	uint32 allocatedSize;
	uint32 field_08;
	uint32 field_0c;
	QTE qte[count];
} DvQTE <name="DvQTE">;


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
		switch(i)
		{
			case 0:
			case 2:
			case 3:
			case 4:
				FSeek(offsetTable[i] + RELATIVE_OFFSET);
				DvUnknown1 dvUnk1;
				break;
			case 1:
				FSeek(offsetTable[i] + RELATIVE_OFFSET);
				DvQTE dvQTE;
				break;
			case 5:
				FSeek(offsetTable[i] + RELATIVE_OFFSET);
				DvElementBase dvElements;
				break;
			
		}
	}
	
} DvHeader <name="DvHeader">;