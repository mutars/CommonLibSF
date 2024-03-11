#pragma once
#include "RE/B/BSAnimationGraph.h"
namespace RE{
	class AnimationManager :
	public BSAnimationGraph
	{
	public:
		void* rawData[99];
	};
	static_assert(sizeof(AnimationManager) == 0x3C0);
}
