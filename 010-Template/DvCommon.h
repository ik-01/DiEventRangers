typedef struct
{
	uint32 count <name="Count">;
	uint32 allocatedSize <name="Size">;
	uint64 padding <hidden=true>;
} DvObject <name="DvObject">;

typedef struct
{
	SetRandomBackColor();
	DvObject cutInfoObject <name="Cut Info Object">;
	float frame[cutInfoObject.count] <name="Cut Frame">;
} DvCutInfo <name="DvCutInfo">;

typedef struct
{
	SetRandomBackColor();
	DvObject disableFrameInfoObject <name="Disable Frame Info Object">;
	struct DvDisableFrameInfoData
	{
		float Start <name="Start">;
		float End <name="End">;;
	}disableFrameInfoData[disableFrameInfoObject.count] <name="Disable Frame Info">;
} DvDisableFrameInfo <name="DvDisableFrameInfo">;

typedef struct
{
	SetRandomBackColor();
	DvObject resourceCutInfoObject <name="Resource Cut Info Object">;
	float resourceCut[resourceCutInfoObject.count] <name="ResourceCut">;
} DvResourceCutInfo <name="DvResourceCutInfo">;

typedef struct
{
	SetRandomBackColor();
	DvObject soundInfoObject <name="Sound Info Object">;
	uint32 soundInfo[soundInfoObject.count] <name="Sound Info">;
} DvSoundInfo <name="DvSoundInfo">;

typedef struct
{
	int32 condType<name = "Type">;
    int32 parameterSize<name = "Parameters Size">;
	byte padding[8]<name = "Padding", hidden = false>;
	byte data[parameterSize];
} ConditionData <optimize=false,name="Condition Data">;

typedef struct
{
	int destPageIndex<name = "Destination Page ID">;
	int conditionNum<name = "Condition Count">;
	int conditionSize<name = "Condition Size">;
	byte padding[4]<name = "Padding", hidden = false>;
	ConditionData conditions[conditionNum];
} TransitionData <optimize=false,name="Transition Data">;

typedef struct
{
	SetRandomBackColor();
	uint32 version <hidden=true>;
	uint32 flag <hidden=true>;
	uint32 frameStart <name = "Frame Start", read=Str("%d",this / 100), write=(this = Atoi( value ) * 100 )>;
	uint32 frameEnd  <name = "Frame End", read=Str("%d",this / 100), write=(this = Atoi( value ) * 100 )>;
	uint32 transitionCount <name = "Transition Count">;
	uint32 transitionSize <name = "Transition Size">;
	uint32 skipFrame <name = "Skip Frame", read=Str("%d",this/100), write=(this = Atoi( value ) * 100 )>; 
	uint32 index <name = "Page Index">;
	uint32 skipLinkIndexNum <name = "Skip Link Index Num">;
	uint32 padding[3] <hidden=true>;
	char name[0x20] <name = "Page Name">;
	// Need to figure this struct
	byte randomData[skipLinkIndexNum*4];
	TransitionData transition[transitionCount];
	
} AuthPage <optimize=false, name="AuthPage", read=Str("%s",name), comment="Note: Name string using UTF-8. You need to change text encoding in 'View'">;


typedef struct
{
	SetRandomBackColor();
	DvObject authPageObject <name="Auth Page Object">;
	AuthPage authPage[authPageObject.count] <name="AuthPage">;
} DvAuthPage <name="DvAuthPage">;

void ReadDvCommon (uint32 address)
{
	struct DvCommon
	{
		SetRandomBackColor();
		
		// For some reason it's empty
		uint32 version <hidden=true>;
		uint32 flags <hidden=true>;
		
		float frameStart <name = "Frame Start">;
		float frameEnd <name = "Frame End">;
		uint32 nodeDrawNum <name = "Draw Node Num">;
		uint32 cutInfoPointer <name = "Cut Info Pointer", format=hex, read=GetFixedOffset>;
		uint32 authPagePointer <name = "Auth Page Pointer", format=hex, read=GetFixedOffset>;
		uint32 disableFrameInfoPointer <name = "Disable Frame Info Pointer", format=hex, read=GetFixedOffset>;
		uint32 resourceCutInfoPointer <name = "Resource Cut Info Pointer", format=hex, read=GetFixedOffset>;
		uint32 soundInfoPointer <name = "Sound Cut Info Pointer", format=hex, read=GetFixedOffset>;
		uint32 nodeInfoPointer <name = "Node Info Pointer",format=hex, read=GetFixedOffset>;
		float chainCameraIn<name = "Chain Camera In">;
		float chainCameraOut<name = "Chain Camera Out">;
		int32 type <name = "Type">;
        int32 skipPointTick<name = "Skip Point Tick">;
		uint32 padding<hidden=true>;
		
		FSeek(cutInfoPointer + m_relOffset);
		DvCutInfo dvCutInfo;
		FSeek(authPagePointer + m_relOffset);
		DvAuthPage dvAuthPage;
		
		// Not using in Sonic Frontiers
		FSeek(disableFrameInfoPointer + m_relOffset);
		DvDisableFrameInfo dvDisableFrameInfo;
		FSeek(resourceCutInfoPointer + m_relOffset);
		DvResourceCutInfo dvResourceCutInfo;
		FSeek(soundInfoPointer + m_relOffset);
		DvSoundInfo dvSoundInfo;
		
		// Read DiEvent nodes.
		ReadNodes(nodeInfoPointer + m_relOffset);
		
	} dvCommon <name="Common">;
}