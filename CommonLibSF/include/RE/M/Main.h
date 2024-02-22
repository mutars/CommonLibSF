#pragma once

namespace RE
{
	class NiAVObject;
	class NiCamera;

	class Main
	{
	public:
		struct SceneGraphRoot
		{
			std::byte unk[0x80];
			NiCamera* camera;
		};

		static SceneGraphRoot* WorldRoot()
		{
			static REL::Relocation<SceneGraphRoot**> singleton{ REL::ID(887308) };
			return *singleton;
		}

		static NiCamera* WorldCamera()
		{
			return WorldRoot()->camera;
		}
	};
}
