enum <uint32> boss_name_type
{
    Giant = 0,
    Dragon,
    Knight,
    Rifle,
    TheEnd,
    RifleBeast
};

typedef struct
{
    uint32 field_00;
    boss_name_type boss_name <name= "Boss Name">;
}DvElementBossName<optimize=false, name="DvElementBossName">;