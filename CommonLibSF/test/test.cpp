#include "RE/Starfield.h"

namespace RE
{
	struct dummy
	{
		BSTSmallArray<CreationRendererPrivate::RenderGraphResource, 64> r;
	};
}

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

	RE::BSFixedString bsfs1();

	RE::CreationRendererPrivate::TemporalAA_idTech7RenderPass* trp = nullptr;
	(void)trp;
	RE::CreationRendererPrivate::MainRenderGraph* mrg = nullptr;
	(void)mrg;
	RE::CreationRendererPrivate::RenderSceneSubGraph *rssg = nullptr;
	(void)rssg;
	RE::CreationRendererPrivate::DLSSUpscaleRenderPass *durp = nullptr;
	(void)durp;
	RE::CreationRendererPrivate::RenderViewSubGraph* rvsg = nullptr;
	(void)rvsg;
    RE::BSScript::Internal::VirtualMachine* vm = nullptr;
    (void)vm;
	RE::CreationRendererPrivate::RenderGraphData* rgd = nullptr;
	(void)rgd;
	RE::CreationRendererPrivate::RenderPassData* rpd = nullptr;
	(void)rpd;
    RE::StorageTable::CameraStorageData* csd = nullptr;
    (void)csd;
	csd->storageData.pColumnCameraCut->pHostOnlyMemory.pTableData[0];
	csd->storageData.pColumnCameraScissors->pHostOnlyMemory.pTableData[0];
	csd->storageData.pColumnCameraView->pHostOnlyMemory.pTableData[0];
	csd->storageData.pColumnCameraFrustum->pHostOnlyMemory.pTableData[0];
	csd->storageData.pColumnCameraTransform->pHostOnlyMemory.pTableData[0];
	csd->storageData.pColumnCameraFrustumType->pHostOnlyMemory.pTableData[0];
	csd->storageData.pWriterColumnData->pHostOnlyMemory->pTableData[0];
	csd->storageData.pObserverStorageData->pCameraBlocks->pTableData[0];
	//csd->storageData.pObserverStorageData->pHostOnlyMemory.pTableData[0];



    RE::StorageTable::RenderGraphStorageDataTable* rg = nullptr;
    (void)rg;
	rg->storageData.pRenderGraphOptions->pHostOnlyMemory.pTableData[0];
	rg->storageData.pImageProcess->pHostOnlyMemory.pTableData[0];
	rg->storageData.pImGui->pHostOnlyMemory.pTableData[0];
	rg->storageData.pBinkMovie->pHostOnlyMemory.pTableData[0];
	rg->storageData.pFaceCustomisationRequest->pHostOnlyMemory.pTableData[0];
	rg->storageData.pPauseFrameGeneration->pHostOnlyMemory.pTableData[0];
	rg->storageData.pScaleFormMenusData->pHostOnlyMemory.pTableData[0];
	rg->storageData.pVisualizationSetup->pHostOnlyMemory.pTableData[0];
	rg->storageData.pMultiViewData->pHostOnlyMemory.pTableData[0].multiViewDataArray.empty();
	rg->storageData.pRenderGraphStorageData->pHostOnlyMemory.pTableData[0];
	rg->storageData.pWriterColumnData->pHostOnlyMemory->pTableData[0];
	rg->storageData.pObserverDirectStorageData->pUpscalerHistoryResetData->pTableData[0];
	rg->storageData.pObserverDirectStorageData->pFSR3ContextData->pTableData[0];
	rg->storageData.pObserverDirectStorageData->pXeSSContext->pTableData[0];
	rg->storageData.pObserverDirectStorageData->pStreamlineViewportData->pTableData[0];
	rg->storageData.pObserverDirectStorageData->pFSR2ContextData->pTableData[0];
	rg->storageData.pObserverDirectStorageData->pScaleformRebuildRenderGraphData->pTableData[0];
	rg->storageData.pObserverDirectStorageData->pRenderGraph->pTableData[0];
    RE::BSFixedString *bsfs = nullptr;
	(void)bsfs;
	RE::StorageTable::MultiViewAllocator* mva = nullptr;
	(void)mva;
	RE::CreationRendererPrivate::RenderGraphBSTAllocator rgba;
	(void)rgba;
    RE::StorageTable::CameraViewStorageData* cvsd = nullptr;
    (void)cvsd;
	RE::dummy* resources = nullptr;
	(void)resources;

	// this is so dumb, without these block optimizer thow all calsses out of pdb
	cvsd->storageData.pColumnHeightfieldSettings->pHostOnlyMemory.pTableData[0];
	cvsd->storageData.pColumnDirectionalShadowData->pHostOnlyMemory.pTableData[0];
	cvsd->storageData.pColumnDAverageLuminanceFutureReadback->pHostOnlyMemory.pTableData[0];
	cvsd->storageData.pColumnHighlightSettings->pHostOnlyMemory.pTableData[0];
	cvsd->storageData.pColumnFeatureSetup->pHostOnlyMemory.pTableData[0];
	cvsd->storageData.pColumnImageSpaceData->pHostOnlyMemory.pTableData[0];
	cvsd->storageData.pColumnClearColor->pHostOnlyMemory.pTableData[0];
	cvsd->storageData.pObserverStorageData->pSkyCubeMapData->pTableData[0];
	cvsd->storageData.pObserverStorageData->pShadowMapCameraCutData->pTableData[0];
	cvsd->storageData.pObserverStorageData->pCascadeShadowMapCache->pTableData[0];
	cvsd->storageData.pObserverStorageData->pTiledCullingData->pTableData[0];
	cvsd->storageData.pObserverStorageData->pHdrData->pTableData[0];
	cvsd->storageData.pObserverStorageData->pHdrConfig->pTableData[0];
	cvsd->storageData.pObserverStorageData->pGPUGeometryDebugHistoryData->pTableData[0];
	cvsd->storageData.pObserverStorageData->pDepthSystemVisualizationData->pTableData[0];
	cvsd->storageData.pObserverStorageData->pSkyOclussionData->pTableData[0];
	cvsd->storageData.pObserverStorageData->pHeightFieldData->pTableData[0];
	cvsd->storageData.pObserverStorageData->pProbeSystemData->pTableData[0];

	return 0;
}
