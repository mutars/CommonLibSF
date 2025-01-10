#pragma once
#include "NiAVObject.h"
namespace RE
{
	class NiNode : public NiAVObject
	{
	public:
		SF_RTTI_VTABLE(NiNode);
		virtual ~NiNode() = default;
		virtual void* AttachChild(NiAVObject* child, bool firstAvailable);
		virtual void* InsertChildAt(uint32_t idx, NiAVObject* child);
		virtual void* DetachChild(NiAVObject* child);
		virtual void* DetachChildOut(NiAVObject* child, NiAVObject** outObj);  //RE::NiPointer<NiAVObject>&
		virtual void* DetachChildAt(uint32_t idx);
		virtual void* DetachChildAtOut(uint32_t idx, NiAVObject** outObj);  //RE::NiPointer<NiAVObject>&
		virtual void* SetAt(uint32_t idx, NiAVObject* child);
		virtual void* SetAtOut(uint32_t idx, NiAVObject* child, NiAVObject** outObj);  //RE::NiPointer<NiAVObject>&
		virtual void* Unk92();
		virtual void* Unk93();
		virtual void* Unk94();

		NiTArray<NiNode*> children;  //NiTObjectArray<NiPointer<NiAVObject>> //130
		void*             unk148;
	};
}
