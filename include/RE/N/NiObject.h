#pragma once

#include "RE/N/NiRefObject.h"

namespace RE
{
	class BSLight;
	class NiAVObject;
	class NiRTTI;
	class NiNode;

#pragma pack(push, 1)
	struct NiCloneProcess
	{
		uint64_t  unk0{0};
		uint64_t  unk8{0};
		uint64_t  unk10{0};
		uint64_t  unk18{0};
		uint32_t  dword_7FF744EB3960{1};
		uint16_t  flag{0x2400};
		uint8_t   flag26{1};
		uint8_t  unk27;
		float     unk_28{1.0f};
		float     unk_2C{1.0f};
		float    unk_30{1.0f};
	};
#pragma pack(pop)

	class __declspec(novtable) NiObject : public NiRefObject
	{
	public:
		SF_RTTI(NiObject);

		virtual ~NiObject() = default;

		virtual NiRTTI*     GetRTTI();
		virtual NiNode*     GetAsNiNode();
		virtual NiNode*     GetAsNiSwitchNode();
		virtual void*       Unk5() { return nullptr; }
		virtual void*       Unk6() { return nullptr; }
		virtual void*       Unk7() { return nullptr; }
		virtual void*       Unk8() { return nullptr; }
		virtual NiAVObject* GetAsBSGeometry() { return nullptr; }
		virtual void*       Unk10() { return nullptr; }
		virtual void*       Unk11() { return nullptr; }
		virtual void*       Unk12() { return nullptr; }
		virtual void*       Unk13() { return nullptr; }
		virtual void*       Unk14() { return nullptr; }
		virtual void*       Unk15() { return nullptr; }
		virtual void*       Unk16() { return nullptr; }
		virtual void*       Unk17() { return nullptr; }
		virtual void*       Unk18() { return nullptr; }
		virtual void*       Unk19() { return nullptr; }
		virtual void*       Unk20() { return nullptr; }
		virtual void*       Unk21() { return nullptr; }
		virtual void*       Unk22() { return nullptr; }
		virtual void*       Unk23() { return nullptr; }
		virtual void*       Unk24() { return nullptr; }
		virtual void*       Unk25() { return nullptr; }
		virtual void*       Unk26() { return nullptr; }
		virtual void*       Unk27() { return nullptr; }
		virtual void*       Unk28() { return nullptr; }
		virtual void*       Unk29() { return nullptr; }
		virtual void*       Unk30() { return nullptr; }
		virtual BSLight*    GetAsBSLight() { return nullptr; }
		virtual void*       Unk32() { return nullptr; }
		virtual void*       Unk33() { return nullptr; }
		virtual void*       Unk34() { return nullptr; }
		virtual void*       Unk35() { return nullptr; }
		virtual void*       Unk36() { return nullptr; }
		virtual void*       Unk37() { return nullptr; }
		virtual void*       Unk38() { return nullptr; }
		virtual void*       Unk39() { return nullptr; }
        virtual void*       Unk40() { return nullptr; } // all castings end here
        virtual void*       createClone(NiCloneProcess* cloningProcess);
        virtual void*       streaming1(); // some sort of streaming 2
		virtual void*       Unk43();
		virtual void*       Unk44();
        virtual void*       streaming2();  // some sort of streaming
        virtual bool        equals(NiObject* second);
		virtual void*       Unk47();
		virtual void*       Unk48();
		virtual void*       Unk49();
        virtual void*       getRTTIDelegate();  // calls GetRTTI internally
		virtual void*       Unk51();
		virtual void*       Unk52();
		virtual void*       Unk53();
		virtual void*       Unk54();
	};
	static_assert(sizeof(NiObject) == 0x10);
}
