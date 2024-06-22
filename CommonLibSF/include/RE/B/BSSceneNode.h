#pragma once
#include "RE/N/NiNode.h"
namespace RE
{

	class BSRenderNode : public NiNode
	{
	public:
		virtual ~BSRenderNode() = default;
		virtual uint32_t getSceneId(int* sceneIdOut);
	};

	class BSSceneNode : public BSRenderNode
	{
	public:
		SF_RTTI_VTABLE(BSSceneNode);
		SF_HEAP_REDEFINE_NEW(BSSceneNode);
		BSSceneNode(std::string a_name)
		{
			BSFixedString name = a_name;
			Init(name);
		}

		BSSceneNode* Init(BSFixedString name)
		{
			using func_t = decltype(&BSSceneNode::Init);
			REL::Relocation<func_t> func{ ID::BSSceneNode::Construct };
			return func(this, name);
		}
		virtual ~BSSceneNode() = default;
		virtual uint32_t getSceneId(int* sceneIdOut) override;
		uint32_t         sceneKeyID{0xFFFFFF};  // 0x150
	};
	static_assert(sizeof(BSSceneNode) == 0x160);
}
