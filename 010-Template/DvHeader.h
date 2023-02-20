typedef struct
{
	SetRandomBackColor();
	uint32 count;
	uint32 field_04;
	uint32 field_08;
	uint32 field_0c;
	float frame[count];
} DvCutInfo <name="DvCutInfo">;

typedef struct
{
	SetRandomBackColor();
	uint32 count;
	uint32 field_04;
	uint32 field_08;
	uint32 field_0c;
	uint32 field_10[count];
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
	uint32 transitionCount;
	uint32 transitionSize;
	uint32 skipFrame <read=Str("%d",this/100), write=(this = Atoi( value ) * 100 )>; // Needs to figure out
	uint32 index;
	uint32 skipLinkIndexNum;
	uint32 padding[3];
	char name[0x20];
	if (skipLinkIndexNum != 0)
	{
		uint32 field_50;
		int32 field_54;
		int32 field_58;
		int32 field_5c;
	}
	// Need to figure this struct
	int32 field_60[transitionSize/4];
	
} QTE <optimize=false,name="QTE", read=Str("%s",name), comment="Note: Name string using UTF-8. You need to change text encoding in 'View'">;


typedef struct
{
	SetRandomBackColor();
	uint32 count;
	uint32 allocatedSize;
	uint32 flags;
	uint32 padding;
	QTE qte[count];
} DvQTE <name="DvQTE">;


typedef struct
{
	local int i;
	SetRandomBackColor();
	
	// For some reason it's empty
	uint32 version;
	uint32 flags;
	float frameStart;
	float frameEnd;
	uint32 nodeDrawNum;
	uint32 cutInfoPointer <format=hex, read=GetFixedOffset>;
	uint32 authPagePointer <format=hex, read=GetFixedOffset>;
	uint32 disableFrameInfoPointer <format=hex, read=GetFixedOffset>;
	uint32 resourceCutInfoPointer <format=hex, read=GetFixedOffset>;
	uint32 soundInfoPointer <format=hex, read=GetFixedOffset>;
	uint32 nodeInfoPointer <format=hex, read=GetFixedOffset>;
	float chainCameraIn;
	float chainCameraOut;
	uint32 type;
	uint32 skipPointTick;
	uint32 padding;
	
	FSeek(cutInfoPointer + RELATIVE_OFFSET);
	DvCutInfo dvCutInfo;
	FSeek(authPagePointer + RELATIVE_OFFSET);
	DvQTE dvQTE;
	
	// Not using in Sonic Frontiers
	FSeek(disableFrameInfoPointer + RELATIVE_OFFSET);
	DvUnknown1 dvUnk1;
	FSeek(resourceCutInfoPointer + RELATIVE_OFFSET);
	DvUnknown1 dvUnk1;
	FSeek(soundInfoPointer + RELATIVE_OFFSET);
	DvUnknown1 dvUnk1;
	
	// Node Tree
	FSeek(nodeInfoPointer + RELATIVE_OFFSET);
	DvElementBase dvElements;
	
	
} DvHeader <name="DvHeader">;