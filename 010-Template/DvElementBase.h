// TODO: MOVE INCLUDES TO SEPARATE FILE
#include "DvElements/DvElementAtmosphereHeightFogParam.h"
#include "DvElements/DvElementAura.h"
#include "DvElements/DvElementAuraRoad.h"
#include "DvElements/DvElementBloomParam.h"
#include "DvElements/DvElementCamera.h"
#include "DvElements/DvElementCameraControlParam.h"
#include "DvElements/DvElementCameraExposure.h"
#include "DvElements/DvElementCameraOffset.h"
#include "DvElements/DvElementCameraShakeLoop.h"
#include "DvElements/DvElementCaption.h"
#include "DvElements/DvElementComplexAnimation.h"
#include "DvElements/DvElementChromaticAberration.h"
#include "DvElements/DvElementCyberSpaceNoise.h"
#include "DvElements/DvElementDOF.h"
#include "DvElements/DvElementDitherParam.h"
#include "DvElements/DvElementEffect.h"
#include "DvElements/DvElementFade.h"
#include "DvElements/DvElementGameCamera.h"
#include "DvElements/DvElementGeneralTrigger.h"
#include "DvElements/DvElementLetterBox.h"
#include "DvElements/DvElementLookAtIK.h"
#include "DvElements/DvElementMaterialAnimation.h"
#include "DvElements/DvElementModel.h"
#include "DvElements/DvElementModelClipping.h"
#include "DvElements/DvElementModelFade.h"
#include "DvElements/DvElementMotion.h"
#include "DvElements/DvElementMovieView.h"
#include "DvElements/DvElementNearFarSettings.h"
#include "DvElements/DvElementPathAdjustment.h"
#include "DvElements/DvElementPathInterpolation.h"
#include "DvElements/DvElementQTE.h"
#include "DvElements/DvElementRootPath.h"
#include "DvElements/DvElementShadowResolution.h"
#include "DvElements/DvElementSound.h"
#include "DvElements/DvElementSpotlightModel.h"
#include "DvElements/DvElementSun.h"
#include "DvElements/DvElementTime.h"
#include "DvElements/DvElementUnknownCamera.h"
#include "DvElements/DvElementUVAnimation.h"
#include "DvElements/DvElementVariablePointLight.h"
#include "DvElements/DvElementVignette.h"
#include "DvElements/DvElementVisibilityAnimation.h"
#include "DvElements/DvElementWeather.h"


// TODO: FIND UNIMPLEMENTED ElementID
enum <uint32> DvElementID
{
	//DvElementTypeCamera = 4,         
	//DvElementTypeAtmosphereHeightFogParam = 83,
	//DvElementTypeAuraRoad = 73,
	//DvElementTypeBloomParam = 51,
	//DvElementTypeControlParam = 290,
	//DvElementTypeLookAtIK = 89,
	//DvElementTypeModelFade = 144,
	//DvElementTypePathInterpolation = 156,
	//DvElementTypeRootPath = 20,
	DvElementTypeSun = 1018,
	//DvElementTypeUnknownCamera = 88,
	Aura = 1027,
	CameraExposure = 1003,
	CameraOffset = 17,
	CameraShakeLoop = 7,
	Caption = 1015,
	ChromaticAberration = 1008,
	DvElementTypeComplexAnimation = 16,
	Culling = 11,
	CyberSpaceNoise = 1029,
	DOF = 1001,
	DitherParam = 1023,
	Effect = 8,
	Fade = 1010,
	GameCamera = 21,
	GeneralTrigger = 1021,
	LetterBox = 1011,
	DvElementTypeMaterialAnimation = 15,
	Model = 1,
	ModelClipping = 1012,
	Motion = 1028,
	MovieView = 1032,
	NearFarSettings = 6,
	OpeningLogo = 1037,
	PathAdjustment = 5,
	QTE = 1024,
	ShadowResolution = 1004,
	Sound = 1016,
	SpotlightModel = 26,
	Time = 1017,
	DvElementTypeUVAnimation = 13,
	VariablePointLight = 1036,
	Vignette = 1009,
	Weather = 1034,
	DvElementUnknown1 = 3,
};

enum <uint32> DvElementCategory
{
	DummyNode = 0,
	RootPath = 1,
	PathMotion,
	Camera,
	CameraMotion,
	Character,
	CharacterMotion,
	CharacterBehavior,
	ModelCustom,
	Asset,
	MotionModel,
	ModelNode,
	Element,
};

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
        local DvElementCategory m_category;
        local string m_name;
        local int m_childCount;
        local int m_baseSize;

        struct NodeProperties
        {
            GUID guid <name = "GUID">;
            DvElementCategory category <name = "Category">;
            int32 nodeSize <name = "Node Size", read=Str("%d",this * 4), write=(this = Atoi( value ) / 4 )>;
            int32 childCount <name = "Child Count">;
            uint32 flag <name = "Flags">;
            int priority <name = "Priority">;
            byte padding[12] <name = "Padding", hidden = false>;
            dvString name <name = "Name">;

            m_name = GetNameOfNode(name.str, category);
            m_category = category;
            m_childCount = childCount;
            m_baseSize = nodeSize;
        } nodeProperties<name = "Node Properties">;
		
		if (m_category == Element)
		{
			struct ElementProperties
			{
				DvElementID elementID <name = "Element ID">;
				float frameStart <name = "Frame Start">;
				float frameEnd <name = "Frame End">;
				int32 version <name = "Version">;
				uint32 flag <name = "Flag">;
				uint32 playType <name = "Play Type">;
				uint32 updateTiming <name = "Update Timing Mode">;
				uint32 padding <name = "Padding">;
			} elementProperties <name = "Element Properties">;
		}

        local int i = 0;
		
		
		// TODO: CLEANUP ELEMENT DETECTION
        if (IsKnownCategory(m_category)) ReadCategory(m_baseSize, m_category);
        else
        {
            switch (m_category)
            {
                default: Printf("Don't know how to handle category %s\n", EnumToString(m_category));
				
                case CharacterBehavior:
                    struct UnknownInfo1
                    {
                        local int size = m_baseSize * 4;
                        byte unkBytes[size];
                    } unkinf1<name = "Unknown Info">;
                    break;

                case Element:
					if (IsKnownElement(elementProperties.elementID))
						switch (elementProperties.elementID)
						{
							case 3:		uint32							dvUnknown1[4];			break;
							case 5:		DvElementPathAdjustment			dvPathAdjustment;       break;
							case 7:		DvElementCameraShakeLoop		dvCameraShakeLoop;		break;
							case 8:		DvElementEffect					dvEffect;				break;
							case 13:	DvElementUVAnimation			dvUVAnimation;			break;
							case 14:	DvElementVisibilityAnimation	dvUVAnimation;			break;
							case 15:	DvElementMaterialAnimation		dvMaterialAnimation;	break;
							case 16:	DvElementComplexAnimation		dvComplexAnimation;		break;
							case 17:	DvElementCameraOffset			dvCameraOffset;			break;
							case 21:	DvElementGameCamera				dvGameCamera;			break;
							case 1001:	DvElementDOF					dvDOF;					break;
							case 1003:	DvElementCameraExposure			dvCameraExposure;		break;
							case 1004:	DvElementShadowResolution		dvShadowResolution;		break;
							case 1008:	DvElementChromaticAberration	dvChromaticAberration;	break;
							case 1009:	DvElementVignette				dvVignette;				break;
							case 1010:	DvElementFade					dvFade;					break;
							case 1011:	DvElementLetterBox				dvLetterBox;			break;
							case 1015:	DvElementCaption				dvCaption;				break;
							case 1016:	DvElementSound					dvSound;				break;
							case 1017:	DvElementTime					dvTime;					break;
							case 1018:	DvElementSun					dvSun;					break;
							case 1023:	DvElementDitherParam			dvDitherParam;			break;
							case 1024:	DvElementQTE					dvQTE;					break;
							case 1027:	DvElementAura					dvAura;					break;
							case 1028:	DvElementMotion					dvMotion;				break;
							case 1029:	DvElementCyberSpaceNoise		dvCyberSpaceNoise;		break;
							case 1034:	DvElementWeather				dvWeather;				break;
							case 1036:	DvElementVariablePointLight		dvPointLight;			break;
							//case 1032:	DvElementMovieView		dvMovieView;	break;
							//case 1037:	DvElementOpeningLogo	dvOpeningLogo;	break;
						}
					else
                    struct UnknownInfo
                    {
                        local int size = m_baseSize * 4 - sizeof(ElementProperties);
                        byte unkBytes[size];
                    } unkinfo<name = "Unknown Info">;
                    break;
            }
        }
		
		

        if (m_childCount > 0)
            struct Children
            {
                for (i = 0; i < m_childCount; i++)
                    ReadNode();
            } children<name = "Children">;

        //  byte unky[GetSizeOfNode(nodeSize, category)];

    } node<name = (m_name)>;
}

string GetNameOfNode(char nodename[64], DvElementCategory cat)
{
    local string categoryName;
    local string nodeName = (Strlen(nodename) <= 0 ? "Node" : nodename);

    switch (cat)
    {
        default: categoryName = "Unknown"; break;
        case RootPath: categoryName = "Path"; break;
        case PathMotion: categoryName = "Path Motion"; break;
        case Camera: categoryName = "Camera"; break;
        case CameraMotion: categoryName = "Camera Motion"; break;
        case Character: categoryName = "Character"; break;
        case CharacterMotion: categoryName = "Character Motion"; break;
        case CharacterBehavior: categoryName = "Character Behavior"; break;
        case ModelCustom: categoryName = "Custom Model"; break;
        case Asset: categoryName = "Asset"; break;
        case MotionModel: categoryName = "Motion Model"; break;
        case ModelNode: categoryName = "Model Node"; break;
        case Element: categoryName = "Element"; break;
    }

    return nodeName + " (" + categoryName + ")";
}

// TODO: REMOVE IN FUTURE UPDATES
byte IsKnownElement(DvElementID id)
{
    switch (id)
    {
        default: return 0;
        case 3:	return 1;
		case 5:	return 1;
		case 7:	return 1;
		case 8:	return 1;
		case 13: return 1;
		case 14: return 1;
		case 15: return 1;
		case 16: return 1;
		case 17: return 1;
		case 21: return 1;
		case 1001: return 1;
		case 1003:	 return 1;
		case 1004:	 return 1;
		case 1008:	 return 1;
		case 1009:	 return 1;
		case 1010:	 return 1;
		case 1011:	 return 1;
		case 1015:	 return 1;
		case 1016:	 return 1;
		case 1017:	 return 1;
		case 1018:	 return 1;
		case 1023:	 return 1;
		case 1024:	 return 1;
		case 1027:	 return 1;
		case 1028:	 return 1;
		case 1029:	 return 1;
		case 1034:	 return 1;
		case 1036:	 return 1;
		
    }
}

// TODO: REMOVE IN FUTURE UPDATES
byte IsKnownCategory(DvElementCategory cat)
{
    switch (cat)
    {
        default: return 0;
        case RootPath: return 1;
        case Camera: return 1;
		case CameraMotion: return 1;
        case Character: return 1;
		case CharacterMotion: return 1;
		case ModelCustom: return 1;
		case ModelNode: return 1;
		case MotionModel: return 1;
		
    }
}


// TODO: CLEANUP
void ReadCategory(uint baseSize, DvElementCategory cat)
{
    switch (cat)
    {
        case RootPath:
            struct TrackInfo
            {
                Matrix44 matrix<name = "Matrix">;
                uint flag<name = "Flag">;
                byte padding[12]<hidden = true>;
            } trackinfo<name = "Track Info">;
            break;
        case Camera:	
		case CameraMotion:
            struct CameraInfo
            {
                uint32 field_80;
				uint32 frameStart <read=Str("%d",this / 100), write=(this = Atoi( value ) * 100 )>;
				uint32 frameEnd  <read=Str("%d",this / 100), write=(this = Atoi( value ) * 100 )>;
				uint32 field_8c;
            } camInfo <name = "Camera Info">;
            break;
        case Character:
            struct CharacterInfo
            {
                uint32 field_00;
				dvString name1;
				dvString name2;
				dvString name3;
				char unk[0x4C];
            } charInfo <name = "Character Info">;
            break;
		case CharacterMotion:
		{
			struct CharacterMotionInfo
            {
				uint32 field_00 <hidden=true>;
				// Need to figure out
				uint32 frameStart <read=Str("%d",this / 100), write=(this = Atoi( value ) * 100 )>;
				uint32 frameEnd  <read=Str("%d",this / 100), write=(this = Atoi( value ) * 100 )>;
				uint32 field_0c <hidden=true>;
				// Mostly is Dst0000 (DiEventState 0000)
				char asmStateName[8] <name = "ASM State Name">;
				// is speed
				float field_50;
				uint32 field_54;
				uint32 field_58[4];
			} charInfo<name = "Character Motion Info">;
			break;
		}
		case ModelCustom: 
		{	
			 struct ModelCustomInfo
            {
                uint32 field_00;
				dvString name1;
				dvString name2;
				dvString name3;
				char unk[0x4C];
            } modelCustomInfo<name = "Custom Model Info">;
			break;
		}
		case MotionModel:
		{
			struct MotionModelInfo
            {
				uint32 field_00 <hidden=true>;
				// Need to figure out
				uint32 frameStart <read=Str("%d",this / 100), write=(this = Atoi( value ) * 100 )>;
				uint32 frameEnd  <read=Str("%d",this / 100), write=(this = Atoi( value ) * 100 )>;
				uint32 field_0c <hidden=true>;
				// Mostly is Dst0000 (DiEventState 0000)
				char asmStateName[8] <name = "ASM State Name">;
				// is speed
				float field_50;
				uint32 field_54;
				uint32 field_58[4];
			} charInfo<name = "Motion Model Info">;
			break;
		}
		case ModelNode: 
		{	
			 struct ModelNodeInfo
            {
                uint32 field_00;
				dvString name1;
				uint32 field_44;
				uint32 field_48;
				uint32 field_4c;
            } modelNodeInfo<name = "Model Node Info">;
			break;
		}
		
      
    }
}