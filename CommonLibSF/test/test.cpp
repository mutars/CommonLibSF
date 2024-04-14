#include "RE/Starfield.h"

int main(int argc, char *argv[])
{
	(void)argc;  // suppresses warning for 'argc'
	(void)argv;  // suppresses warning for 'argv'
	RE::FirstPersonState* fps = nullptr;
	RE::NiPoint2* np2 = nullptr;
	(void)np2;
	(void)fps;
	RE::PlayerControls::Manager* pcm = nullptr;
	(void)pcm;
	RE::Camera::Manager* cm = nullptr;
	(void)cm;
	RE::AnimationManager* am = nullptr;
	(void)am;
    RE::BSSceneNode* bsn = nullptr;
    (void)bsn;
	RE::CreationRendererPrivate::TemporalAA_idTech7RenderPass* trp = nullptr;
	(void)trp;
	RE::CreationRendererPrivate::MainRenderGraph* mrg = nullptr;
	(void)mrg;
	RE::CreationRendererPrivate::RenderViewSubGraph* rvsg = nullptr;
	(void)rvsg;
    RE::BSScript::Internal::VirtualMachine* vm = nullptr;
    (void)vm;
    RE::StorageTable::CameraStorageData* csd = nullptr;
    (void)csd;
    RE::StorageTable::RenderGraphStorageData* rg = nullptr;
    (void)rg;
	RE::StorageTable::AsyncTableColumnBase *atcb = nullptr;
	(void)atcb;
    RE::BSFixedString *bsfs = nullptr;
	(void)bsfs;
	RE::MultiViewAllocator *mva = nullptr;
	(void)mva;
	RE::RenderGraphBSTAllocator rgba;
	(void)rgba;
	RE::StorageTable::MultiViewData mvd;
	(void)mvd;
	return 0;
}
