#pragma once

#include "RE/N/NiSmartPointer.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/T/TESCameraState.h"
#include "RE/F/FirstPersonState.h"
#include "RE/N/NiNode.h"

namespace RE
{
	class TESCameraState;

	class TESCamera
	{
	public:
		SF_RTTI(TESCamera);

		virtual ~TESCamera();  // 00

		// add
		virtual void SetCameraRoot(NiNode* a_cameraRoot);  // 01
		virtual void SetEnabled(bool a_enabled);           // 02
		virtual void Update();                             // 03
		virtual void Unk_04();                             // 04

		// members
		NiPointer<NiNode> cameraRoot;    // 08 - NiPointer<NiNode>
		TESCameraState*   currentState;  // 10 - BSTSmartPointer<TESCameraState> FistPersonState 240b size
		void*			  arr1;         // 18 - some pointer to thread local global pointer 10*QWDORD array also increments refcount
		bool              enabled;       // 20
		float             unk24;         // 24
		float             unk28;         // 28
		float             unk2C;         // 2C
		float             unk30;         // 30
		float             unk34;         // 34
		float             unk38;         // 38
		float             unk3C;         // 3C
		float             unk40;         // 40
		std::uint32_t     pad44;         // 44
	};
	static_assert(offsetof(TESCamera, enabled) == 0x20);
	static_assert(offsetof(TESCamera, unk40) == 0x40);
	static_assert(sizeof(TESCamera) == 0x48);
}
