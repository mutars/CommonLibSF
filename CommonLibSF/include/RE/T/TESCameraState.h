#pragma once
#include "RE/B/BSInputEventUser.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/P/PlayerCamera.h"
#include "RE/N/NiPoint3.h"

namespace RE
{

	class PlayerCamera;

	class TESCameraState :
		public BSIntrusiveRefCounted,  // 00
		public BSInputEventUser        // 04
	{
	public:
		SF_RTTI_VTABLE(TESCameraState);

		virtual ~TESCameraState();  // 00

		virtual void Unk_01(void);  // 10
		virtual void Unk_02(void);  // 11
		virtual void possilbeUpdateState(void);  // 12
		virtual void Unk_04(void);  // 13
		virtual void Unk_05(void);  // 14
		virtual void Unk_06(void);  // 15
		virtual void Unk_07(void);  // 16
		virtual void handleInputEvent(NiPoint3* delta);  // 17
		virtual void Unk_09(void);  // 18
		virtual void Unk_0A(void);  // 19
		virtual void Unk_0B(void);  // 20

		std::uint32_t pad1;           //0x0044
		PlayerCamera* pPlayerCamera;  //0x0048
		std::uint32_t N00000A21;      //0x0050 - camera state id enum
		std::uint32_t N00000A22;      //0x0054
	};
	static_assert(sizeof(TESCameraState) == 0x58);
}
