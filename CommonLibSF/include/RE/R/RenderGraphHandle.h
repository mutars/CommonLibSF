#pragma once

#include "RE/C/CreationRenderer.h"
#include "RE/C/CreationRendererPrivate.h"
#include "RE/S/StorageTable.h"

namespace RE::StorageTable
{
	struct alignas(0) RenderGraphOptions
	{
		uint8_t data[0x30];
	};
	static_assert(sizeof(RenderGraphOptions) == 48);

	struct alignas(0) RenderGraphStorageData
	{
		uint8_t data[0x10];
	};
	static_assert(sizeof(RenderGraphStorageData) == 0x10);

	struct alignas(0) PauseFrameGenerationData
	{
		uint8_t data;
	};
	static_assert(sizeof(PauseFrameGenerationData) == 1);

	struct alignas(0) ScaleformMenusData
	{
		uint8_t data[48];
	};
	static_assert(sizeof(ScaleformMenusData) == 0x30);

	struct alignas(8) MultiCameraViewData
	{
		BSTSmallArray<uint32_t, 4> multiViewDataArray;  // 0x0
	};
	static_assert(sizeof(MultiCameraViewData) == 0x20);

	struct alignas(0) UpscalerHistoryResetData
	{
		uint8_t resetHistory;
	};

	struct alignas(0) ScaleformRebuildRenderGraphData
	{
		uint8_t data[1024 << 4];  // unconfirmed size
	};

	struct alignas(0) ImageProcess
	{
		uint8_t data[0x4];  // StorageTable::StrongKey<struct StorageTable::ImageProcess::Storage>
	};


	namespace RenderGraph
	{

		struct alignas(0) FaceCustomizationRequest
		{
			uint8_t data[32];
		};
		static_assert(sizeof(FaceCustomizationRequest) == 0x20);

		template <typename ST>
		struct ObserverRenderGraphHostOnlyTables : public DirectColumnDataStorageInterface
		{
			HostOnlyMemory<ST, UpscalerHistoryResetData>*                                             pUpscalerHistoryResetData;  // 0x0 item size 1 byte struct StorageTable::UpscalerHistoryResetData
			HostOnlyMemory<ST, std::unique_ptr<
								   CreationRendererPrivate::ApiAbstractionLayer::FSR3::ContextData>>* pFSR3ContextData;  // 0x8 items size 8 bytes class std::unique_ptr<struct CreationRendererPrivate::ApiAbstractionLayer::FSR3::ContextData, struct std::default_delete<struct CreationRendererPrivate::ApiAbstractionLayer::FSR3::ContextData>
			HostOnlyMemory<ST, std::unique_ptr<
								   CreationRendererPrivate::Intel_XeSS::XeSSContext>>*                pXeSSContext;  // 0x10 item size 8 bytes class std::unique_ptr<struct CreationRendererPrivate::Intel_XeSS::XeSSContext, struct std::default_delete<struct CreationRendererPrivate::Intel_XeSS::XeSSContext>
			HostOnlyMemory<ST, std::unique_ptr<
								   CreationRendererPrivate::NV_Streamline::Utils::ViewportData>>*     pStreamlineViewportData;  // 0x18 items size 8 bytes class std::unique_ptr<struct CreationRendererPrivate::NV_Streamline::Utils::ViewportData, struct std::default_delete<struct CreationRendererPrivate::NV_Streamline::Utils::ViewportData>
			HostOnlyMemory<ST, std::unique_ptr<
								   CreationRendererPrivate::ApiAbstractionLayer::FSR2::ContextData>>* pFSR2ContextData;                  // 0x20 size8 class std::unique_ptr<struct CreationRendererPrivate::ApiAbstractionLayer::FSR2::ContextData, struct std::default_delete<struct CreationRendererPrivate::ApiAbstractionLayer::FSR2::ContextData>
			HostOnlyMemory<ST, ScaleformRebuildRenderGraphData>*                                      pScaleformRebuildRenderGraphData;  // 0x28 struct StorageTable::ScaleformRebuildRenderGraphData
			HostOnlyMemory<ST, std::unique_ptr<
								   CreationRendererPrivate::RenderGraph>>*                            pRenderGraph;  // 0x30 8 class std::unique_ptr<class CreationRendererPrivate::RenderGraph, struct std::default_delete<class CreationRendererPrivate::RenderGraph>
		};

		struct alignas(8) Storage
		{
			AsyncTableColumnBase<Storage, RenderGraphOptions>*                   pRenderGraphOptions;         // struct StorageTable::RenderGraphOptions
			AsyncTableColumnBase<Storage, uint32_t>*                             pImageProcess;               // 0x8 class StorageTable::StrongKey<struct StorageTable::ImageProcess::Storage
			AsyncTableColumnBase<Storage, uint32_t>*                             pImGui;                      // 0x10 class StorageTable::StrongKey<struct StorageTable::ImGuiST::Storage>
			AsyncTableColumnBase<Storage, uint32_t>*                             pBinkMovie;                  // 0x18 class StorageTable::StrongKey<struct StorageTable::BinkMovie::Storage
			AsyncTableColumnBase<Storage, FaceCustomizationRequest>*             pFaceCustomisationRequest;   // 0x20 struct StorageTable::RenderGraph::FaceCustomizationRequest
			AsyncTableColumnBase<Storage, PauseFrameGenerationData>*             pPauseFrameGeneration;       // 0x28 struct StorageTable::PauseFrameGenerationData
			AsyncTableColumnBase<Storage, ScaleformMenusData>*                   pScaleFormMenusData;         // 0x30 struct StorageTable::ScaleformMenusData
			AsyncTableColumnBase<Storage, CreationRenderer::VisualizationSetup>* pVisualizationSetup;         // 0x38 struct CreationRenderer::VisualizationSetup
			AsyncTableColumnBase<Storage, MultiCameraViewData>*                  pMultiViewData;              // 0x40 struct StorageTable::MultiCameraViewData
			AsyncTableColumnBase<Storage, RenderGraphStorageData>*               pRenderGraphStorageData;     // 0x48 struct StorageTable::RenderGraphStorageData item Size 0xB bytes
			WriterDirectStorageData<Storage, Storage>*                           pWriterColumnData;           // 0x50
			ObserverRenderGraphHostOnlyTables<Storage>*                          pObserverDirectStorageData;  // size 0x40 7 pointers to HostOnlyMemory 0x58 ObserverDirectStorageData<struct StorageTable::RenderGraph::Storage
			void*                                                                buffer1;                     // byte buffer
			void*                                                                buffer2;                     // byte buffer
		};

	};

	class RenderGraphHandle : public StorageData<StorageTable::RenderGraph::Storage>
	{
	public:
		virtual ~RenderGraphHandle() = 0;
	};

	static_assert(sizeof(RenderGraphHandle) == 0x158);

	using MultiViewAllocator = BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator<uint32_t, 4>>;

}
