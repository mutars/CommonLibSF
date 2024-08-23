#pragma once

#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSTEvent.h"
#include "RE/T/TESCamera.h"
#include "RE/T/TESCameraState.h"
#include "RE/F/FirstPersonState.h"
#include "re/utils.h"

namespace RE
{
	class BSWorldOriginShiftEvent;
	class OtherEventEnabledEvent;
	class UserEventEnabledEvent;
	class TESCameraState;
	class FirstPersonState;
	struct IdleInputEvent;

	namespace Spaceship
	{
		struct TakeOffEvent;
		struct DockEvent;
		struct LandedSetEvent;
	}

	struct CameraStates
	{
		enum CameraState : std::uint32_t
		{
			kFirstPerson = 0,
			kAutoVanity,
			kVATS,
			kIronSights,
			kPCTransition,
			kTween,
			kUnk06,
			kVehicleCamera,
			kFlightCamera,
			kShipFarTravel,
			kShipAction,
			kShipTargeting,
			kShipCombatOrbit,
			kFreeWalk,
			kFreeAdvanced,
			kFreeFly,
			kFreeTethered,
			kDialogue,
			kWorkshopIsometric,
			kPhotoMode,
			kThirdPerson,
			kFurniture,
			kHorse,
			kBleedout
		};
	};
	using CameraState = CameraStates::CameraState;

	class PlayerCamera :
		public TESCamera,                                // 00
		public BSInputEventReceiver,                     // 48
		public BSTEventSink<IdleInputEvent>,             // 58
		public BSTEventSink<UserEventEnabledEvent>,      // 60
		public BSTEventSink<OtherEventEnabledEvent>,     // 68
		public BSTEventSink<Spaceship::TakeOffEvent>,    // 70
		public BSTEventSink<Spaceship::DockEvent>,       // 78
		public BSTEventSink<Spaceship::LandedSetEvent>,  // 80
		public BSTEventSink<BSWorldOriginShiftEvent>     // 88
	{
	public:
		SF_RTTI_VTABLE(PlayerCamera);

		~PlayerCamera() override;  // 00

		// override (TESCamera)
		void SetCameraRoot(NiNode* a_root) override;  // 01
		void SetEnabled(bool a_enabled) override;     // 02
		void Unk_04() override;                       // 04

		static PlayerCamera* GetSingleton();

		void ForceFirstPerson();
		void ForceThirdPerson();
		bool IsInFirstPerson() const;
		bool IsInThirdPerson() const;
		void SetCameraState(CameraState a_cameraState);

		// More...
		// 
		uint8_t                pad_5554[4];                   //0x0090
		uint32_t               N00000A50;                     //0x0094 for real it's 64bit
		uint8_t                pad_98[4];                     //0x0098 for real it's 64bit
		float                  N00000A51;                     //0x009C
		float                  N000012E4;                     //0x00A0
		uint32_t               N00000A52;                     //0x00A4
		uint32_t               N000012DD;                     //0x00A8
		uint8_t                pad_00AC[4];                   //0x00AC
		int32_t                N00000A53;                     //0x00B0
		uint8_t                pad_00B4[188];                 //0x00B4
		uint64_t 			   pad_170;                     //0x0170
		FirstPersonState*      pFirstPersonModeState;         //0x0170
		TESCameraState*   pVanityState;                  //0x0178
		TESCameraState*   pVatsCameraState;              //0x0180
		TESCameraState*   pIronSightState;               //0x0188
		TESCameraState*   pPlayerCameraTransitionState;  //0x0190
		TESCameraState*   pTweenMenuCameraState;         //0x0198
		TESCameraState*   pThirdPersonState;             //0x01A0
		TESCameraState*   pVehicleCameraState;            //0x01A8
		TESCameraState*   pFlightCameraState;            //0x01A8
		TESCameraState*   pShipFarCameraState;           //0x01B0
		TESCameraState*   pShipActionCameraState;        //0x01B8
		TESCameraState*   pShipTargetingCameraState;     //0x01C0
		TESCameraState*   pShipCameraOrbitState;         //0x01C8
		TESCameraState*   pFreeWalkCameraState;          //0x01D0
		TESCameraState*   pFreeAdvancedCameraState;      //0x01D8
		TESCameraState*   pFreeFlyCameraState;           //0x01E0
		TESCameraState*   pFreeTetheredCameraState;      //0x01E8
		TESCameraState*   pDialogueCameraSTate;          //0x01F0
		TESCameraState*   pWorkshopIsoCameraState;       //0x01F8
		TESCameraState*   pPhotoModeCameraState;         //0x0200
		TESCameraState*   pThirdPersonState2;            //0x0208
		TESCameraState*   pFurnitureCameraState;         //0x0210
		TESCameraState*   pHorseCameraState;             //0x0218
		TESCameraState*   pBleedoutCameraState;          //0x0220
		std::uint64_t          N00000A83;                //0x0228
		std::uint64_t     N00000A84;                     //0x0230
		std::uint64_t          N00000A85;                //0x0238
		std::uint8_t           pad_0240[8];              //0x0240
		void*             pHavokSphereShape;             //0x0248
		void*             pHavokBsWorld;                 //0x0250
		float             N00000A89;                     //0x0258
		float             N000012F9;                     //0x025C
		float             fov;                           //0x0260
		float             N00001300;                     //0x0264
		float             N00000A8B;                     //0x0268
		float             fovAdj;                        //0x026C
		float             N00000A8C;                     //0x0270
		float             N0000131E;                     //0x0274
		float             notViewFov;                    //0x0278
		float             N00001321;                     //0x027C
		float             N00000A8E;                     //0x0280
		float             N00001324;                     //0x0284
		float             N0000133D;                     //0x0288
		float             N00000A8F;                     //0x028C
		std::uint8_t      N00001340;                     //0x0290
		uint8_t           pad_0291[3];                   //0x0291
		float             N00000A90;                     //0x0294
		float             N00001345;                     //0x0298
		float             position[3];                   //0x029C
		float             horizontal_rotation;           //0x02A8
		float             N00000A93;                     //0x02AC
		float             N00000A94;                     //0x02B0
		float             N00001352;                     //0x02B4
		std::int32_t           N00000A95;                     //0x02B8
		std::int32_t           N00001355;                     //0x02BC
		std::uint16_t          N00000A96;                     //0x02C0
		std::uint8_t           N00001359;                     //0x02C2
		std::uint8_t           N0000135C;                     //0x02C3
		std::int32_t           N0000135F;                     //0x02C4
		std::int16_t           N0000135D;                     //0x02C8
		std::uint8_t           N0000135A;                     //0x02CA
		std::uint8_t           N00001365;                     //0x02CB

	private:
		bool QCameraEquals(CameraState a_cameraState) const;
	};
	static_assert(offsetof(PlayerCamera, pFirstPersonModeState) == 0x178);
	static_assert(offsetof(PlayerCamera, N000012DD) == 0xA8);
	static_assert(offsetof(PlayerCamera, horizontal_rotation) == 0x2B8);
	static_assert(offsetof(PlayerCamera, fov) == 0x270);
	static_assert(sizeof(PlayerCamera) == 0x2E0);
}
