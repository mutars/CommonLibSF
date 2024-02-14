#pragma once

namespace RE
{
	class NiAVObject;
	class NiCamera;

	class Main
	{
	public:
		static NiAVObject* WorldRoot()
		{
			static REL::Relocation<NiAVObject**> singleton{ REL::ID(887308) };
			return *singleton;
		}

		static NiCamera* WorldCamera()
		{
			return reinterpret_cast<NiCamera*>(reinterpret_cast<uintptr_t>(WorldRoot()) + 0x80);
		}
	};
}
