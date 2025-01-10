#pragma once

#include <RE/B/BSTSingleton.h>
#include <RE/B/BSTEvent.h>
#include <RE/N/NiPoint3.h>
#include <RE/N/NiMatrix3.h>
#include <RE/N/NiCamera.h>
#include <RE/T/TESObjectCELL.h>

namespace RE
{
	class ResetHistoryDataEvent;
	class CameraCutEvent;

	namespace Camera
	{
		class IBaseModule
		{
		public:
			virtual ~IBaseModule();
			virtual void unk1();
		};
		class PlayerModule : IBaseModule
		{
		public:
			virtual ~PlayerModule();
			virtual void unk1();
		};
		class DebugModule : IBaseModule
		{
		public:
			virtual ~DebugModule();
			virtual void unk1();
			uint8_t rawData[0xC8];
		};
		static_assert(sizeof(DebugModule) == 0xD0);
		class InteriorModule : IBaseModule
		{
			public:
			virtual ~InteriorModule();
			virtual void unk1();
			NiCamera* camera; // 0x8
		};
		static_assert(sizeof(InteriorModule) == 0x10);
		class SpaceModule : IBaseModule
		{
			public:
			virtual ~SpaceModule();
			virtual void unk1();
		};
		class Manager: 
			public BSTSingletonSDM<Camera::Manager, BSTSingletonSDMOpStaticBuffer>, 
			public BSTEventSink<ResetHistoryDataEvent>,
			public BSTEventSink<CameraCutEvent> // 0x8
		{
		public:
			DebugModule* debugModule; // 0x18
			InteriorModule* interiorModule;  // 0x20
			PlayerModule* playerModule;  // 0x28
			SpaceModule*    spaceModule;     // 0x30
			NiPoint3       position; // 0x38
			uint32_t       unk44; //flags?
			TESObjectCELL* cell; // 0x48
			NiMatrix3      rotation; // 0x50
		};
		static_assert(offsetof(Manager, debugModule) == 0x18);
		static_assert(offsetof(Manager, rotation) == 0x50);
	};
};
