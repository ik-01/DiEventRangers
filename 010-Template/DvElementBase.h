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


// Made it by guessing
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
	Path = 1,
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

struct DvElementBase;

typedef struct
{
    SetRandomBackColor();
    GUID guid;
    DvElementCategory category;
    uint32 nodeSize <read=Str("%d",this * 4), write=(this = Atoi( value ) / 4 )>; 
    uint32 childElementsCount;
    uint32 flags;
    uint32 priority;
    uint32 field_24;
    uint32 field_28;
    uint32 field_2c;
	dvString elementName;
	switch (category)
    {
		case Path:
		{
			Matrix44 mtx;
			uint32 field_80;
			uint32 field_84;
			uint32 field_88;
			uint32 field_8c;
			break;
		}
		case Camera:	
		case CameraMotion:
		{
			uint32 field_80;
			uint32 field_84;
			uint32 field_88;
			uint32 field_8c;
			break;
		}
		case Character: 
		{	
			uint32 field_40;
			DvElementModel	dvModel;
			break;
		}
		case CharacterMotion:
		{
			uint32 field_40[4];
			// Mostly is Dst0000 (DiEventState 0000)
			char asmStateName[8];
			float field_50;
			uint32 field_54;
			DvElementMotion dvMotion;
			break;
		}
		case ModelCustom: 
		{	
			uint32 field_40;
			DvElementModel	dvModel;
			break;
		}
		case MotionModel:
		{
			uint32 field_40[4];
			// Mostly is Dst0000 (DiEventState 0000)
			char asmStateName[8];
			float field_50;
			uint32 field_54;
			DvElementMotion dvMotion;
			break;
		}
		case ModelNode:
		{
			DvElementID id;
			dvString boneName;
			uint32 field_4c;
			uint32 field_50;
			uint32 field_54;
			switch (id)
			{
				case 8:   DvElementEffect	dvEffect;	break;
			}
			break;
		}
		case Element:
		{
			DvElementID id;
			float frameStart;
			float frameEnd;
			uint32 version;
			uint32 flag;
			uint32 playType;
			uint32 updateTiming;
			uint32 field_5c;
			switch (id)
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
			break;
		}
		
	}
    /* switch (id)
    {
		case 4:     DvElementCamera                     dvCamera;               break;

		case 10:    DvElementShadowResolution           dvShadowResolution;     break;
		case 12:    DvElementMotion                     dvMotion;               break;
		case 13:    DvElementModelClipping              dvModelClipping;        break;

		case 16:    DvElementNearFarSettings            dvNearFar;              break;
		case 20:    DvElementRootPath                   dvRootPath;             break;
		case 25:    DvElementGeneralTrigger             dvGeneralTrigger;       break;
		case 26:    DvElementSound                      dvSound;                break;
		case 28:    DvElementPathAdjustment             dvPathAdjustment;       break;
		case 29:    DvElementUVAnimation                dvUVAnim;               break;
		case 34:    DvElementGameCamera                 dvGameCamera;           break;
		case 40:    DvElementLetterBox                  dvLetterBox;            break;
		case 41:    DvElementCyberSpaceNoise            dvCyberSpaceNoise;      break;
		
		case 47:    DvElementSun                        dvSun;                  break;
		case 48:    DvElementCameraExposure             dvCameraExposure;       break;
		case 49:    DvElementTime                       dvTime;                 break;
		case 51:    DvElementBloomParam                 dvBloom;                break;
		case 57:    DvElementChromaticAberration        dvChromaticAberration;  break;
		case 59:    DvElementAura                       dvAura;                 break;
		case 60:    DvElementDOF                        dvDOF;                  break;
		case 68:    DvElementModel                      dvModel;                break;
		case 73:    DvElementAuraRoad                   dvAuraRoad;             break;
		case 80:    DvElementCameraShakeLoop            dvCameraShakeLoop;      break;
		case 83:    DvElementAtmosphereHeightFogParam   dvCameraHeightFog;      break;
		case 88:    DvElementUnknownCamera              dvUnknownCamera;        break;
		case 89:    DvElementLookAtIK                   dvLookAtIK;             break;
		case 90:    DvElementVignette                   dvCameraVignette;       break;
		case 95:    DvElementSpotlightModel             dvSpotlightModel;       break;
		case 104:   DvElementQTE                        dvQTE;                  break;
		case 144:   DvElementModelFade                  dvModelFade;            break;
		case 156:   DvElementPathInterpolation          dvPathInterpolation;    break;
		case 168:   DvElementVariablePointLight         dvPointLight;           break;
		
		case 276:   DvElementCameraOffset               dvCameraOffset;         break;
		case 285:   DvElementComplexAnimation           dvComplexAnimation;     break;
		case 290:   DvElementCameraControlParam         dvCameraControlParam;   break;
		default: Warning("Not implemented DvElement detected!"); break; */
	if (childElementsCount) DvElementBase childElements[childElementsCount];
    
    
} DvElementBase<optimize=false, name="DvElementBase", read=Str("Category: %s", EnumToString(category))>;