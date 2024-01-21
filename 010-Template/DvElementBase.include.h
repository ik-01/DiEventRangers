#include "DvElements/DvElementAtmosphereHeightFogParam.h"
#include "DvElements/DvElementAura.h"
#include "DvElements/DvElementAuraRoad.h"
#include "DvElements/DvElementBloomParam.h"
#include "DvElements/DvElementBossName.h"
#include "DvElements/DvElementCamera.h"
#include "DvElements/DvElementCameraControlParam.h"
#include "DvElements/DvElementCameraExposure.h"
#include "DvElements/DvElementCameraOffset.h"
#include "DvElements/DvElementCameraShakeLoop.h"
#include "DvElements/DvElementCaption.h"
#include "DvElements/DvElementCompositeAnimation.h"
#include "DvElements/DvElementChromaticAberration.h"
#include "DvElements/DvElementCyberSpaceNoise.h"
#include "DvElements/DvElementDOF.h"
#include "DvElements/DvElementDitherParam.h"
#include "DvElements/DvElementDrawOff.h"
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
#include "DvElements/DvElementOverrideAsm.h"
#include "DvElements/DvElementPathAdjustment.h"
#include "DvElements/DvElementPathInterpolation.h"
#include "DvElements/DvElementQTE.h"
#include "DvElements/DvElementRifleBeastLighting.h"
#include "DvElements/DvElementRootPath.h"
#include "DvElements/DvElementShadowResolution.h"
#include "DvElements/DvElementSonicCamera.h"
#include "DvElements/DvElementSound.h"
#include "DvElements/DvElementSpotlightModel.h"
#include "DvElements/DvElementSun.h"
#include "DvElements/DvElementTime.h"
#include "DvElements/DvElementUnknownCamera.h"
#include "DvElements/DvElementUVAnimation.h"
#include "DvElements/DvElementVariablePointLight.h"
#include "DvElements/DvElementVignetteParam.h"
#include "DvElements/DvElementVisibilityAnimation.h"
#include "DvElements/DvElementWeather.h"

enum<uint32> DvElementPlayType
{
	PlayTypeNormal = 0x0,
	PlayTypeOneshot = 0x1,
	PlayTypeAlways = 0x2,
};

enum<uint32> DvElementUpdateTiming
{
	UpdateTimingOnExecPath = 0,
	UpdateTimingOnPreUpdate = 1,
	UpdateTimingCharacterFixPosture = 2,
	UpdateTimingOnPostUpdateCharacter = 3,
	UpdateTimingOnUpdatePos = 4,
	UpdateTimingOnFixBonePosture = 5,
	UpdateTimingOnEvaluateDetailMotion = 6,
	UpdateTimingCharacterJobUpdate = 7,
	UpdateTimingModifyPoseAfter = 8,
	UpdateTimingJobRegister = 9,
	UpdateTimingMotionUpdate = 10,
	UpdateTimingNormal = 2
};

// TODO: FIND UNIMPLEMENTED ElementID
enum<uint32> DvElementID
{
	// ParameterSpecifiedCamera = 1,
	ElementID_DrawOff = 3,
	ElementID_PathAdjustment = 5,
	ElementID_CameraShake = 6,
	ElementID_CameraShakeLoop = 7,
	ElementID_Effect = 8,
	ElementID_PathInterpolation = 10,
	ElementID_Culling = 11,
	// NearFarSetting = 12,
	ElementID_UVAnimation = 13,
	ElementID_VisibilityAnimation = 14,
	ElementID_MaterialAnimation = 15,
	ElementID_CompositeAnimation = 16,
	ElementID_CameraOffset = 17,
	// ElementID_ModelFade = 18,
	ElementID_SonicCamera = 20,
	ElementID_GameCamera = 21,
	//ElementID_SpotlightModel = 26,

	ElementID_DOF = 1001,
	//ElementID_ColorCorrection = 1002,
	ElementID_CameraExposure = 1003,
	ElementID_ShadowResolution = 1004,
	ElementID_AtmosphereHeightFogParam = 1007,
	ElementID_ChromaticAberration = 1008,
	ElementID_VignetteParam = 1009,
	ElementID_Fade = 1010,
	ElementID_LetterBox = 1011,
	ElementID_ModelClipping = 1012,
	ElementID_BossName = 1014,
	ElementID_Caption = 1015,
	ElementID_Sound = 1016,
	ElementID_Time = 1017,
	ElementID_Sun = 1018,
	ElementID_LookAtIK = 1019,
	ElementID_CameraBlurParam = 1020,
	ElementID_GeneralTrigger = 1021,
	ElementID_DitherParam = 1023,
	ElementID_QTE = 1024,
	//ElementID_FacialAnimation = 1025,
	ElementID_OverrideAsm = 1026,
	ElementID_Aura = 1027,
	ElementID_ChangeTimeScale = 1028,
	ElementID_CyberSpaceNoise = 1029,
	ElementID_AuraRoad = 1031,
	ElementID_MovieView = 1032,
	ElementID_Weather = 1034,
	ElementID_VariablePointLight = 1036,
	ElementID_OpeningLogo = 1037,
	ElementID_TheEndCableObject = 1042,
	ElementID_RifleBeastLighting = 1043
};

enum<uint32> DvNodeType
{
	Dummy = 0,
	Root = 0,
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
	Stage,
	StageScenarioFlag,
	InstanceMotion,
	InstanceMotionData,
	FolderCondition,
	CharacterBehaviorSimpleTalk,
	InvalidNode = 0xFFFFFFFF,
};

// TODO: Reformat coding style when all elements will be found
void ReadElement(DvElementID id)
{
	switch (id)
	{
		case ElementID_DrawOff:						DvElementDrawOff					dvElementDrawOff;			break;
		case ElementID_PathAdjustment:				DvElementPathAdjustment				dvPathAdjustment;			break;
		case ElementID_CameraShake:																					break;
		case ElementID_CameraShakeLoop:				DvElementCameraShakeLoop			dvCameraShakeLoop;			break;
		case ElementID_Effect:						DvElementEffect						dvEffect;					break;
		case ElementID_PathInterpolation:																			break;
		case ElementID_Culling:																						break;
		case ElementID_UVAnimation:					DvElementUVAnimation				dvUVAnimation;				break;
		case ElementID_VisibilityAnimation:																			break;
		case ElementID_MaterialAnimation:			DvElementMaterialAnimation			dvMaterialAnimation;		break;
		case ElementID_CompositeAnimation:			DvElementCompositeAnimation			dvCompositeAnimation;		break;
		case ElementID_CameraOffset:				DvElementCameraOffset				dvCameraOffset;				break;
		case ElementID_SonicCamera:					DvElementSonicCamera				dvSonicCamera;				break;
		case ElementID_GameCamera:					DvElementGameCamera					dvGameCamera;				break;
		//case ElementID_SpotlightModel:		break;
		case ElementID_DOF:							DvElementDOF						dvDOF;						break;
		//case ElementID_ColorCorrection:		break;
		case ElementID_CameraExposure:				DvElementCameraExposure				dvCameraExposure;			break;
		case ElementID_ShadowResolution:			DvElementShadowResolution			dvShadowResolution;			break;
		case ElementID_AtmosphereHeightFogParam:	DvElementAtmosphereHeightFogParam	dvAtmosphereHeightFogParam;	break;
		case ElementID_ChromaticAberration:			DvElementChromaticAberration		dvChromaticAberration;		break;
		case ElementID_VignetteParam:				DvElementVignetteParam				dvVignetteParam;			break;
		case ElementID_Fade:						DvElementFade						dvFade;						break;
		case ElementID_LetterBox:					DvElementLetterBox					dvLetterBox;				break;
		case ElementID_ModelClipping:																				break;
		case ElementID_BossName:					DvElementBossName					dvBossName;					break;
		case ElementID_Caption:						DvElementCaption					dvCaption;					break;
		case ElementID_Sound:						DvElementSound						dvSound;					break;
		case ElementID_Time:						DvElementTime						dvTime;						break;
		case ElementID_Sun:							DvElementSun						dvSun;						break;
		case ElementID_LookAtIK:																					break;
		case ElementID_CameraBlurParam:																				break;
		case ElementID_GeneralTrigger:				DvElementGeneralTrigger				dvGeneralTrigger;			break;																			break;
		case ElementID_DitherParam:					DvElementDitherParam				dvDitherParam;				break;
		case ElementID_QTE:							DvElementQTE						dvQTE;						break;
		case ElementID_OverrideAsm:					DvElementOverrideAsm				dvOverrideAsm;				break;
		case ElementID_Aura:						DvElementAura						dvAura;						break;
		case ElementID_ChangeTimeScale:																				break;
		case ElementID_CyberSpaceNoise:				DvElementCyberSpaceNoise			dvCyberSpaceNoise;			break;
		case ElementID_AuraRoad:																					break;
		case ElementID_ModelClipping:																				break;
		case ElementID_MovieView:					DvElementMovieView					dvMovieView;				break;
		case ElementID_Weather:						DvElementWeather					dvWeather;					break;
		case ElementID_VariablePointLight:			DvElementVariablePointLight			dvPointLight;				break;
		case ElementID_TheEndCableObject:																			break;
		case ElementID_RifleBeastLighting:			DvElementRifleBeastLighting			dvRifleBeastLighting;		break;
		
		// case 14:	DvElementVisibilityAnimation	dvUVAnimation;			break;

		// case 1018:	DvElementSun					dvSun;					break;
		// case 1023:				break;
		// case 1028:	DvElementMotion					dvMotion;				break;

	}
}


string GetNodeTypeName(DvNodeType type)
{
    local string typeName;

    switch (type)
    {
        default: typeName = "Unknown"; break;
        case Path: typeName = "Path"; break;
        case PathMotion: typeName = "Path Motion"; break;
        case Camera: typeName = "Camera"; break;
        case CameraMotion: typeName = "Camera Motion"; break;
        case Character: typeName = "Character"; break;
        case CharacterMotion: typeName = "Character Motion"; break;
        case CharacterBehavior: typeName = "Character Behavior"; break;
        case ModelCustom: typeName = "Custom Model"; break;
        case Asset: typeName = "Asset"; break;
        case MotionModel: typeName = "Motion Model"; break;
        case ModelNode: typeName = "Model Node"; break;
        case Element: typeName = "Element"; break;
    }

    return typeName;
}

// Until all nodes will be figured out
byte IsUnknownElement(DvElementID id)
{
	switch(id)
	{
		case 1: return true; break;
		case ElementID_CameraShake: return true; break;
		case ElementID_PathInterpolation: return true; break;
		case ElementID_Culling: return true; break;
		case 12: return true; break;
		case 18: return true; break;
		case ElementID_VisibilityAnimation: return true; break;
		case 26: return true; break;
		case 1002: return true; break;
		case 1007: return true; break;
		case ElementID_ModelClipping: return true; break;
		case ElementID_LookAtIK: return true; break;
		case ElementID_CameraBlurParam: return true; break;
		case ElementID_ChangeTimeScale: return true; break;
		case ElementID_AuraRoad: return true; break;
		case ElementID_ModelClipping: return true; break;
		case ElementID_TheEndCableObject: return true; break;
		default: return false; break;
	}
}