#pragma once

#include "RE/C/CreationRenderer.h"
#include "RE/C/CreationRendererPrivate.h"
#include "RE/S/StorageTable.h"

namespace RE::StorageTable
{
	struct alignas(0) RenderGraphOptions
	{
		uint8_t data[0x20];
		uint32_t flags;
		uint32_t pad24;
		uint8_t trailing[8];
	};
	static_assert(sizeof(RenderGraphOptions) == 48);
	static_assert(offsetof(RenderGraphOptions, flags) == 0x20);

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


		void Register(uint32_t *idOut) {
			using func_t = decltype(&RenderGraphHandle::Register);
			REL::Relocation<func_t> func{ REL::ID(201716) };
			return func(this, idOut);

		}

		static void ResetUpscalerHistory(uint32_t renderGraphHandleId) {
			if(renderGraphHandleId == 0xFFFFFF) {
				return;
			}
			auto upscalerHistoryResetData = &Get()->storageData.pObserverDirectStorageData->pUpscalerHistoryResetData->pTableData[renderGraphHandleId & 0xFFFFFF];
			if(upscalerHistoryResetData == nullptr) {
				return;
			}
			upscalerHistoryResetData->resetHistory = 1;
		}
		
		inline static bool getResetHistory(uint32_t renderGraphHandleId) {
			RenderGraphHandle* pHandle = Get();
			if (pHandle == nullptr) {
				return false;
			}
			auto renderGraphOptionsIndex = pHandle->storageData.pRenderGraphOptions->indexes[renderGraphHandleId & 0xFFFFFF];
			auto& renderGraphOptions = pHandle->storageData.pRenderGraphOptions->pHostOnlyMemory.pTableData[renderGraphOptionsIndex];
			// probalby if upscaler is enabled
			if((renderGraphOptions.flags & 0x3C) == renderGraphOptions.flags) {
				auto& upscalerHistoryResetData = pHandle->storageData.pObserverDirectStorageData->pUpscalerHistoryResetData->pTableData[renderGraphHandleId & 0xFFFFFF];
				return upscalerHistoryResetData.resetHistory;
			}
			return false;
		} 

		static RenderGraphHandle* Get() {
			static REL::Relocation<RenderGraphHandle**> singleton{ REL::ID(772639) };
			return *singleton;
		}

		static MultiCameraViewData* GetMultiViewData(uint32_t renderGraphId) {
			using func_t = decltype(&RenderGraphHandle::GetMultiViewData);
			REL::Relocation<func_t> func{ REL::ID(201322) };
			return func(renderGraphId);
		}

		static void SetMultiViewData(uint32_t renderGraphId, MultiCameraViewData* data) {
			using func_t = decltype(&RenderGraphHandle::SetMultiViewData);
			REL::Relocation<func_t> func{ REL::ID(201997) };
			return func(renderGraphId, data);
		}
	};

	static_assert(sizeof(RenderGraphHandle) == 0x158);

	using MultiViewAllocator = BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator<uint32_t, 4>>;

}
