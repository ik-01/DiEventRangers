#include "DvElements/DvElementAtmosphereHeightFogParam.h"
#include "DvElements/DvElementAura.h"
#include "DvElements/DvElementCamera.h"
#include "DvElements/DvElementCameraExposure.h"
#include "DvElements/DvElementCameraOffset.h"
#include "DvElements/DvElementCameraShakeLoop.h"
#include "DvElements/DvElementCaption.h"
#include "DvElements/DvElementComplexAnimation.h"
#include "DvElements/DvElementChromaticAberration.h"
#include "DvElements/DvElementCyberSpaceNoise.h"
#include "DvElements/DvElementDOF.h"
#include "DvElements/DvElementEffect.h"
#include "DvElements/DvElementFade.h"
#include "DvElements/DvElementGameCamera.h"
#include "DvElements/DvElementGeneralTrigger.h"
#include "DvElements/DvElementLetterBox.h"
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


// Made it by guessing
enum <uint32> DvElementType
{
	DvElementTypeCamera = 4,         
	DvElementTypeMovieView = 8,
	DvElementTypeShadowResolution = 10 ,
	DvElementTypeMotion = 12,
	DvElementTypeModelClipping = 13,
	DvElementTypeCaption = 14,
	DvElementTypeNearFarSettings = 16,
	DvElementTypeRootPath = 20,
	DvElementTypeGeneralTrigger = 25,
	DvElementTypeSound = 26,
	DvElementTypePathAdjustment = 28,
	DvElementTypeUVAnimation = 29,
	DvElementTypeGameCamera = 34,
	DvElementTypeLetterBox = 40,
	DvElementTypeCyberSpaceNoise = 41,
	DvElementTypeFade = 44,
	DvElementTypeSun = 47,
	DvElementTypeCameraExposure = 48,
	DvElementTypeTime = 49,
	DvElementTypeChromaticAberration = 57,
	DvElementTypeAura = 59,
	DvElementTypeDOF = 60,
	DvElementTypeModel = 68,
	DvElementTypeCameraShakeLoop = 80,
	DvElementTypeAtmosphereHeightFogParam = 83,
	DvElementTypeUnknownCamera = 88,
	DvElementTypeVignette = 90,
	DvElementTypeSpotlightModel = 95,
	DvElementTypeQTE = 104,
	DvElementTypeModelFade = 144,
	DvElementTypePathInterpolation = 156,
	DvElementTypeVariablePointLight = 168,
	DvElementTypeEffect = 177,
	DvElementTypeCameraOffset = 276 ,
	DvElementTypeComplexAnimation = 285,
};

enum <uint32> DvElementUnknownType
{
	Type1 = 1,         
	Type2 = 3, 
	Type3, 
	Type4,
	Type5,	
	Type6 = 11,
	Type7,
};

struct DvElementBase;

typedef struct
{
    SetRandomBackColor();
    GUID guid;
    DvElementUnknownType field_10;            // is type related ???
    DvElementType type;                    
    uint32 childElementsCount;
    uint32 field_1c;
    uint32 field_20;
    uint32 field_24;
    uint32 field_28;
    uint32 field_2c;
    switch (type)
    {
		case 4:     DvElementCamera                     dvCamera;               break;
		case 8:     DvElementMovieView                  dvMovieView;            break;
		case 10:    DvElementShadowResolution           dvShadowResolution ;    break;
		case 12:    DvElementMotion                     dvMotion;               break;
		case 13:    DvElementModelClipping              dvModelClipping;        break;
		case 14:    DvElementCaption                    dvCaption;              break;
		case 16:    DvElementNearFarSettings            dvNearFar;              break;
		case 20:    DvElementRootPath                   dvRootPath;             break;
		case 25:    DvElementGeneralTrigger             dvGeneralTrigger;       break;
		case 26:    DvElementSound                      dvSound;                break;
		case 28:    DvElementPathAdjustment             dvPathAdjustment;       break;
		case 29:    DvElementUVAnimation                dvUVAnim;               break;
		case 34:    DvElementGameCamera                 dvGameCamera;           break;
		case 40:    DvElementLetterBox                  dvLetterBox;            break;
		case 41:    DvElementCyberSpaceNoise            dvCyberSpaceNoise;      break;
		case 44:    DvElementFade                       dvFade;                 break;
		case 47:    DvElementSun             			dvSun;      			break;
		case 48:    DvElementCameraExposure             dvCameraExposure;       break;
		case 49:    DvElementTime                       dvTime;                 break;
		case 57:    DvElementChromaticAberration        dvChromaticAberration;  break;
		case 59:    DvElementAura                       dvAura;                 break;
		case 60:    DvElementDOF                        dvDOF;                  break;
		case 68:    DvElementModel                      dvModel;                break;
		case 80:    DvElementCameraShakeLoop            dvCameraShakeLoop;      break;
		case 83:    DvElementAtmosphereHeightFogParam   dvCameraHeightFog;      break;
		case 88:    DvElementUnknownCamera              dvUnknownCamera;        break;
		case 90:    DvElementVignette                   dvCameraVignette;       break;
		case 95:    DvElementSpotlightModel             dvSpotlightModel;       break;
		case 104:   DvElementQTE						dvQTE;					break;
		case 144:   DvElementModelFade					dvModelFade;			break;
		case 156:   DvElementPathInterpolation          dvPathInterpolation;    break;
		case 168:   DvElementVariablePointLight         dvPointLight;           break;
		case 177:   DvElementEffect                     dvEffect;               break;
		case 276:   DvElementCameraOffset               dvCameraOffset;         break;
		case 285:   DvElementComplexAnimation           dvComplexAnimation;     break;
		default: Warning("Not implemented DvElement detected!"); break;
	}
	if (childElementsCount) DvElementBase childElements[childElementsCount];
    
    
}DvElementBase<optimize=false, name="DvElementBase", read=Str("Type: %s", EnumToString(type))>;