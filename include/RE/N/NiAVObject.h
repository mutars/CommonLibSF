#pragma once

#include "RE/N/NiBound.h"
#include "RE/N/NiObjectNET.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTransform.h"

namespace RE
{
	class NiCollisionObject;
	class NiNode;
	class NiCamera;
	class NiUpdateData;

    template <class T>
    struct BSArray
    {
        uint32_t size;
        uint32_t capacity;
        T*       data;
    };

    template <class T>
    class NiTArray
    {
    public:
        virtual ~NiTArray() = default;
        T*       entries;
        uint16_t m_arrayBufLen;    // 10 - max elements storable in m_data
        uint16_t m_emptyRunStart;  // 12 - index of beginning of empty slot run
        uint16_t m_size;           // 14 - number of filled slots
        uint16_t m_growSize;       // 16 - number of slots to grow m_data by
    };

    class NiRTTI
    {
    public:
        const char* name;
        const char* parent;
    };

	class NiAVObject: public NiObjectNET {
	public:
		//SF_RTTI_VTABLE(NiAVObject);

		virtual ~NiAVObject() = 0;

		// add
        virtual void*   Update4(NiUpdateData* data); // calls update3 or 2 function (they are all point to same address)
        virtual void*   setAsCameraRoot(void* parent); // calls *0x14598A710->tvable[1](NiAVObject)
        virtual void*   Unk57();
        virtual void*   Unk58();
        virtual void*   Unk59();
        virtual void*   Unk60();
        virtual void*   SetSelectiveFlagsAndPropagadeToParent(bool set); // flags | 1 and much more
        virtual NiNode* GetObjectByName(const BSFixedString& name);
        virtual void*   SetSelectiveUpdateFlags(); // +execute something on each controller->*0x1D8
        virtual void*   update0x800FlagsAndResetWorldBoundRadius(bool set);         // v2 | 0x800; if set is true and worldBound.radius = 1.0 if it's negative
        virtual void*   update0x10000000000Flags(bool set);  // a1->flags | 0x10000000000i64;
        virtual void*   update0x100000000Flags(bool set);    // a1->flags | 0x100000000i64;
        virtual void*   execUnk66or72OnCondition(); // result & 0x100000000i64) != 0  will execute update0x100000000Flags else Unk72 with 1 and clear flag
        virtual void*   execUnk66or72(); // (a1->flags & 0x200000000i64) == 0 will execute update0x100000000Flags else Unk72 with 0 and clear flag
        virtual void*   update0x100Flags(bool set);    //flags | 0x100;
        virtual void*   update0x20000Flags(bool set);  // flags | 0x20000 if set is true
        virtual void*   update0x80000Flags(bool set); // flags | 0x80000 is set is true
        virtual void*   Unk72();
        virtual void*   Update(NiUpdateData* dta); // pass update to all controllers and call world update
        virtual void*   Update2(NiUpdateData* data); // pass update to all controllers and call unk78 with update
        virtual void*   Update3(NiUpdateData* data); // pass update to all controllers and call unk78 with update
        virtual void*   Unk76();
        virtual void*   Unk77();
        virtual void*   Unk78(); // noop function not implemented in nicamera as well
        virtual void*   UpdateWorldData(NiUpdateData* data);
        virtual void*   UpdateTransformAndBounds(NiUpdateData* data);  // calls UpdateWorldData if flags & 4 == 0 also calls unk78 with 0 also flips flags if they are in specific state
        virtual void*   UpdateTransforms(NiUpdateData* data); // calls UpdateWorldData if flags & 4 != 0
        virtual void*   Unk82();
        virtual void*   Unk83();

        NiNode*                      parent;           // 038
		NiTransform                  local;            // 040
		NiTransform                  world;            // 080
		NiTransform                  previousWorld;    // 0C0
		NiBound                      worldBound;       // 100
		NiCollisionObject*           collisionObject;  // 110
		std::uint64_t                flags;            // 118
		void*                        unk120;           // 120
        uint32_t             lastUpdatedFrame;  // 128
        uint32_t             pad12C;  // 128
	};
	static_assert(sizeof(NiAVObject) == 0x130);
	static_assert(offsetof(NiAVObject, parent) == 0x38);
	static_assert(offsetof(NiAVObject, local) == 0x40);
	static_assert(offsetof(NiAVObject, world) == 0x80);
	static_assert(offsetof(NiAVObject, collisionObject) == 0x110);
	static_assert(offsetof(NiAVObject, flags) == 0x118);

	class NiExtraData : public NiObject
	{
	public:
		BSFixedString	m_kName;	// 10
	};

	class BSTransformExtra : public NiExtraData
	{
	public:
		NiTransform m_transform;	// 20
	};
	static_assert(offsetof(BSTransformExtra, m_transform) == 0x20);
	static_assert(sizeof(BSTransformExtra) == 0x60);

}
