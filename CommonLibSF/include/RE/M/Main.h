#pragma once

namespace RE
{
	class NiAVObject;

	class Main
	{
	public:
		static NiAVObject* WorldRoot()
		{
			static REL::Relocation<NiAVObject**> singleton{ REL::ID(887308) };
			return *singleton;
		}
	};
}
