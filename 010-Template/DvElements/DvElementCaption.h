enum<int32> LanguageType
{
    ENGLISH = 0,
    FRENCH = 1,
    ITALIAN = 2,
    GERMAN = 3,
    SPANISH = 4,
    POLISH = 5,
    PORTUGUESE = 6,
    RUSSIAN = 7,
    JAPANESE = 8,
    CHINESE = 9,
    CHINESE_SIMPLIFIED = 10,
    KOREAN = 11,
};

typedef struct
{
	char captionName[0x10] <name="Caption Name">;
	LanguageType language <name="Language">;
	uint32 field_1c;		// is padding?
    
}DvElementCaption<optimize=false, read=Str("%s (%s)", captionName, EnumToString(language)), name="DvElementCaption">;