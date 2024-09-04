#pragma once
#include "RE/N/NiAVObject.h"

namespace RE {
	class BSGeometry: public NiAVObject
	{
		float unk130[12];
		uintptr_t *unk160;
		uint64_t unk168;
		uint64_t unk170;
		uint64_t unk178;
		uint8_t flags180;
		uint8_t pad181;
		uint16_t pad182;
		uint32_t unk184;
		uint32_t unk188;
		uint8_t pad190[12];
		uint32_t unk198;
		uint64_t unk1A0;
		uintptr_t *unk1A8;
		uintptr_t unk1B0;
		uint64_t unk1B8;
		uint64_t unk1C0;
		uint64_t unk1C8;
		uintptr_t *unk1D0;
		uint32_t unk1D8_handleId;
		uint16_t unk1DC;
		uint16_t unk1DE;
		uintptr_t *unk1E0;
		uint32_t unk1E8_handleId1;
		uint32_t unk1EC_handleId2;
		uint32_t unk1F0;
		uint32_t unk1F4;
		uint8_t pad1F8[8];
	};
	static_assert(sizeof(BSGeometry) == 0x200);
}