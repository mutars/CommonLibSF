#pragma once
#include "RE/N/NiNode.h"
namespace RE
{

	class BSRenderNode : public NiNode
	{
		public:
		virtual ~BSRenderNode() = default;
		virtual void* getFlags(int* flagsOut);
	};

	class BSSceneNode : public BSRenderNode
	{
	public:
		virtual ~BSSceneNode() = default;
		virtual void* getFlags(int* flagsOut) override;
		uint32_t m_flags; // 0x150
	};
	static_assert(sizeof(BSSceneNode) == 0x158);
}
