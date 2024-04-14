#pragma once

namespace RE::BSScript
{
	class IObjectProcessor
	{
	public:
		SF_RTTI_VTABLE(BSScript__IObjectProcessor);

		virtual ~IObjectProcessor() = default;  // 00

		// add
		virtual void clone() = 0;  // 01
        virtual void unk_02() = 0;  // 02
        virtual void unk_03() = 0;  // 03

	};
	static_assert(sizeof(IObjectProcessor) == 0x8);
}
