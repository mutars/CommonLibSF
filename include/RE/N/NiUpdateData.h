#pragma once

namespace RE
{
	class NiPoint4;
	class NiCamera;

	class NiUpdateData
	{
		float         delta = 0;
		float         unk04 = 0;
        NiCamera* camera = nullptr;
		NiPoint4*     unk10 = nullptr;
		NiPoint4*     unk18 = nullptr;
        uint64_t  unk20 = 0; // memset 0,36 here looks like allockation for 36 bytes
        uint64_t  unk28 = 0;
        uint64_t  unk30 = 0; // unk34 float possible deltaY/X rotation
        uint32_t  flags = 0x10;
        uint32_t  flags2 = 1;
        uint32_t  flags3 = 1;
        uint32_t  frameCounter = 0; // timer or counter or frame counter get's from offset 0x59AE8A0
        float     unk48 = 0; // possible delta X/Y rotation
        uint32_t  unk4C = 0;
        float     unk50 = 0; // unk50 is rotation matrix
		float         unk54 = 0;
		float         unk58 = 0;
        uint32_t  unk5C = 0;
	};
}
