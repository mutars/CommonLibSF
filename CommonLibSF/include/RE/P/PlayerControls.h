#pragma once

#include "RE/B/BSInputEventUser.h"
#include "RE/B/BSInputEventReceiver.h"
#include <RE/B/BSTSingleton.h>
#include <RE/B/BSTEvent.h>
#include <RE/I/IMovementInterface.h>
#include <RE/M/MenuOpenCloseEvent.h>
#include "RE/utils.h"
namespace RE
{ 
	struct PositionPlayerEvent;
	struct MenuModeChangeEvent;
	struct TESCellGravityChangeEvent;
	struct TESFurnitureEvent;
	class UserEventEnabledEvent;

	namespace PlayerControls
	{
		class PlayerInputHandler : public BSInputEventUser
		{
		public:
			virtual ~PlayerInputHandler();  // 00

			virtual void Unk_10(void);  // 10
			virtual void Unk_11(void);  // 11
			virtual void Unk_12(void);  // 12
			virtual void Unk_13(void);  // 13
			virtual void Unk_14(void);  // 14
			virtual void Unk_15(void);  // 15

			void*    sharedBuffer;  // passed from 0x3C Manager pointer
			uint16_t unk48;
			uint8_t  unk4A;
		};
		class NvidiaStreamlineInputHandler : public BSInputEventUser
		{
		public:
			void* sharedBuffer;  // 0x40 passed from 0x3C Manager pointer
			uint16_t unk48;
			uint8_t unk4A;
		}; 
		class AutoMoveHandler : public PlayerInputHandler
		{};
		class DebugCameraHandler : public PlayerInputHandler
		{};
		class GravJumpHandler : public PlayerInputHandler
		{
		public:
			uint16_t unk50;
		};
		class HeldStateHandler : public PlayerInputHandler
		{
		public:
			~HeldStateHandler() override;  // 00

			virtual void Unk_16(void);  // 16
			virtual void Unk_17(void);  // 17
			uint16_t     unk50;
		};
		class AlternateAttackHandler : public HeldStateHandler
		{
		public:
			uint8_t unk58;
		};
		static_assert(sizeof(AlternateAttackHandler) == 0x60);
		class FlightMovementHandler : public HeldStateHandler
		{
		public:
			void*    unk58;
			void*    unk60;
			void*    unk68;
			void*    unk70;
			uint32_t unk78;
			uint16_t unk7C;
			uint8_t  unk7E;
			void*    unk80;  // FlightControlModes array possible
			void*    unk88;
			float    unk90;
			float    unk94;
		};
		class GrabRotationHandler : public HeldStateHandler
		{
			uint8_t unk50;
		};
		class MonocleHandler : public PlayerInputHandler
		{};
		class LookHandler : public PlayerInputHandler
		{
		public:
			float unk50;
		};
		class MovementHandler : public PlayerInputHandler
		{};
		class PlayerCameraHandler : public PlayerInputHandler
		{
		public:
			void* unk50;
		};
		class TogglePOVHandler : public HeldStateHandler
		{
		public:
			uint8_t unk58;
		};
		class WeaponFocusHandler : public HeldStateHandler
		{
		public:
			void*   unk58;
			uint8_t unk60;
		};
		class ZKeyHandler : public HeldStateHandler
		{
		public:
			void*    unk58;
			uint32_t unk60;
			uint8_t  unk64;
		};

		class Manager :
			public BSInputEventReceiver,
			public BSTSingletonSDM<PlayerControls::Manager, BSTSingletonSDMOpStaticBuffer>,
			public IMovementPlayerControls,
			public BSTEventSink<MenuModeChangeEvent>,
			public BSTEventSink<MenuOpenCloseEvent>,
			public BSTEventSink<PositionPlayerEvent>,
			public BSTEventSink<TESCellGravityChangeEvent>,
			public BSTEventSink<TESFurnitureEvent>,
			public BSTEventSink<UserEventEnabledEvent>
		{
		public:
			//uint32_t unk48;
			float unk4c; // +-1 forward backward //shared buffer with all handlers
			float unk50; // +-1 left right
			float unk54; // +-1 up down
			float unk58; // horizontal rotation
			float unk5c; // vertical rotation
			float unk60;
			float unk64;
			float unk68;
			float unk6c;
			float unk70;
			float unk74;
			float unk78;
			float unk7c;
			float unk80;
			float unk84;
			float unk88;
			float unk8c;
			float unk90;
			float unk94;
			float unk98;
			float unk9c;
			float unkA0;
			float unkA4;
			float unkA8;
			float unkAc;
			float unkB0;
			float unkB4;
			float unkB8;
			float unkBc;
			float unkC0;
			float unkC4;
			float unkC8;
			float unkCc;
			float unkD0;
			float unkD4;
			float unkD8;
			float unkDc;
			float unkE0;
			float unkE4;
			float unkE8;
			float unkEc;
			float unkF0;
			float unkF4;
			float unkF8;
			float unkFc;
			float unk100;
			float unk104;
			float unk108;
			float unk10c;
			float unk110;
			float unk114;
			float unk118;
			float unk11c;
			float unk120;
			float unk124;
			float unk128;
			float unk12c;
			float unk130;
			float unk134;
			float unk138;
			float unk13c; 
			float unk140;
			float unk144;
			float unk148; //shared buffer ends
			// pads
			uint64_t unk150;
			uint64_t unk158;
			uint64_t unk160;
			uint64_t unk168;
			uint64_t unk170;
			uint64_t unk178;
			uint64_t unk180;
			uint64_t unk188;
			uint64_t unk190;
			uint64_t unk198;
			uint64_t unk1A0;
			uint64_t unk1A8;
			uint64_t unk1B0;
			uint64_t unk1B8;
			uint64_t unk1C0;
			uint64_t unk1C8;
			uint64_t unk1D0;
			void*    unk1D8; // strange pointer
			uint64_t unk1E0;
			ZKeyHandler* zKeyHandler; // 0x1E8 they are possible pepee or BSTArray of handlers
			AutoMoveHandler* autoMoveHandler; // 0x1F0
			DebugCameraHandler* debugCameraHandler; // 0x1F8
			FlightMovementHandler* flightMovementHandler; // 0x200
			GrabRotationHandler* grabRotationHandler; // 0x208
			GravJumpHandler* gravJumpHandler; // 0x210
			HeldStateHandler* alternativeAttackHandler; // 0x218
			MonocleHandler* monocleHandler; // 0x220
			PlayerInputHandler* jumpHandler; // 0x228
			LookHandler* lookHandler; // 0x230
			MovementHandler* movementHandler; // 0x238
			PlayerCameraHandler* playerCameraHandler; // 0x240
			PlayerInputHandler* runHandler; // 0x248
			HeldStateHandler* shieldHandler; // 0x250
			HeldStateHandler* shipEquipmentHandler; // 0x258
			HeldStateHandler* shipEquipmentHandler2; // 0x260
			HeldStateHandler* shipEquipmentHandler3; // 0x268
			PlayerInputHandler* sneakHandler; // 0x270
			HeldStateHandler* sprintHandler; // 0x278
			TogglePOVHandler* togglePOVHandler; // 0x280
			PlayerInputHandler* toggleRunHandler;  // 0x288
			PlayerInputHandler* weaponAttackHandler; // 0x290
			PlayerInputHandler* weaponBlockHandler; // 0x298
			WeaponFocusHandler* weaponFocusHandler; // 0x2A0
			PlayerInputHandler* weaponMeleeHandler; // 0x2A8
			PlayerInputHandler* weaponReadyHandler; // 0x2B0
			PlayerInputHandler* weaponReloadHandler; // 0x2B8
			PlayerInputHandler* weaponSightedActionHandler; // 0x2C0
			PlayerInputHandler* stabornPowerHandler; // 0x2C8
			NvidiaStreamlineInputHandler* nvidiaStreamlineInputHandler; // 0x2D0
		};
		//check_size<offsetof(Manager, unk4c), 0x4c> trace_size11;
		static_assert(offsetof(Manager, unk4c) == 0x4C);
		static_assert(offsetof(Manager, zKeyHandler) == 0x1E8);
		static_assert(offsetof(Manager, nvidiaStreamlineInputHandler) == 0x2D0);


		static_assert(sizeof(PlayerInputHandler) == 0x50);
		static_assert(sizeof(AutoMoveHandler) == 0x50);
		static_assert(sizeof(GravJumpHandler) == 0x58);
		static_assert(sizeof(HeldStateHandler) == 0x58);
		static_assert(sizeof(HeldStateHandler) == 0x58);
		static_assert(sizeof(DebugCameraHandler) == 0x50);
		static_assert(sizeof(FlightMovementHandler) == 0x98);
		static_assert(sizeof(GrabRotationHandler) == 0x60);
		static_assert(sizeof(ZKeyHandler) == 0x68);

	};
}

