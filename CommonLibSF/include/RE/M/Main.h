#pragma once

namespace RE
{
	class NiNode;
	class NiCamera;
    class BSSceneNode;
    class NiAVObject;

	class Main
	{
	public:
		struct SceneGraphRoot
		{
			NiCamera* camera00; //NiPointer<NiCamera>
            NiNode* pNiNodeWorld08; //08 NiNode
            NiNode* pNiNode10; //10 NiNode
            NiNode* pNiNode18; //18 NiNode
            NiNode* pNiNode20; //20 NiNode
            void* pVoid28; //28
            NiNode* pNiNode30; //30 NiNode
            NiNode* pNiNode38; //38 NiNode
            NiNode* pNiNode40; //40 NiNode
            NiNode* pNiNode48; //48 NiNode
            NiNode* pNiNode50; //50 NiNode
            NiNode* pNiNode58; //58 NiNode
            void* pVoid60; //60
            std::uint64_t qword68; //68
            BSSceneNode* pBSSceneNode70; //70 BSSceneNode
			NiNode* worldCameraRoot; //78 NiNode
			NiCamera* worldCamera; // 80 NiCamera
            std::uint64_t qword80; //88
            BSSceneNode* pBSceneNode90; //90 BSceneNode
            std::uint64_t qword98; //98
            NiAVObject* pShadowLightNode; //A0 BSShadowLight : BSLight : NiAVObject
            NiCamera* pNiCameraA8; //A8 NiCamera source of frustum port and some other stuff
            NiCamera* pNiCameraB0; //B0 NiCamera
            std::uint64_t qwordB8; //B8
            std::uint64_t qwordC0; //C0
            std::uint64_t qwordC8; //C8
            std::uint64_t qwordD0; //D0
            std::uint64_t qwordD8; //D8
            std::uint64_t qwordE0; //E0
            std::uint64_t qwordE8; //E8
            std::uint64_t qwordF0; //F0
            void* pVoidF8; //F8
            std::uint64_t qword100; //100
            std::uint64_t qword108; //108
            std::uint64_t qword110; //110
            NiNode* pNiNode118; //118 NiNode
            NiNode* pNiNode120; //120 NiNode



        };
		static_assert(offsetof(SceneGraphRoot, worldCamera) == 0x80);
		static_assert(offsetof(SceneGraphRoot, pShadowLightNode) == 0xA0);
		static_assert(offsetof(SceneGraphRoot, pNiNode118) == 0x118);

		static SceneGraphRoot* WorldRoot()
		{
			static REL::Relocation<SceneGraphRoot**> singleton{ REL::ID(887308) };
			return *singleton;
		}

		static NiCamera* WorldCamera()
		{
			return WorldRoot()->worldCamera;
		}
	};
}
