#pragma once

#include "RE/C/CreationRenderer.h"
#include "RE/C/CreationRendererPrivate.h"
#include "RE/S/StorageTable.h"

namespace RE::StorageTable
{

	struct DirectColumnDataStorageInterface;

	template <typename T, typename V>
	class AsyncTableColumnBase;

	template <typename T, typename V>
	struct HostOnlyMemory;

	template <typename T, typename V>
	class WriterDirectStorageData;

	template <typename T, typename V>
	class ObserverDirectStorageData;

	struct alignas(0) ImageSpaceData
	{
		uint8_t data[0x4];  // StorageTable::StrongKey<struct StorageTable::ImageSpaceData::Storage>
	};
	static_assert(sizeof(ImageSpaceData) == 4);

	struct alignas(0) HeightfieldSettings
	{
		uint8_t data[0x10];
	};
	static_assert(sizeof(HeightfieldSettings) == 16);

	struct alignas(0) HighlightSettings
	{
		void* data;  // unconfirmed
	};

	struct alignas(0) AverageLuminanceFutureReadback
	{
		uint8_t data[0x10];
	};
	static_assert(sizeof(AverageLuminanceFutureReadback) == 16);

	struct alignas(4) CameraViewData
	{
		uint32_t sceneId;
		uint32_t cameraViewID;
		uint8_t  unk8{ 1 };      // enabled? 0x8
		float    fov{ 85.0 };    // 0xC
		float    near{ 0.1 };    // 0x10
		float    far{ 4000.0 };  // 0x14
		uint16_t unk18{ 1 };     // 0x18
	};  // 28 size correlates with
	static_assert(sizeof(CameraViewData) == 0x1C);

	struct ClearColor
	{
		void* data;  // unconfirmed
	};

	// Camera::Storage members

	struct alignas(0) CameraCut
	{
		uint8_t data[0x60];  // 0x0
	};
	static_assert(sizeof(CameraCut) == 96);

	struct CameraScissor
	{
		float left;
		float right;
		float top;
		float bottom;
	};
	static_assert(sizeof(CameraScissor) == 0x10);  // could be 0x80*8

	struct alignas(4) CameraFrustum
	{
		float left;
		float right;
		float top;
		float bottom;
		float _near;
		float _far;
	};
	static_assert(sizeof(CameraFrustum) == 24);

	struct alignas(0) CameraFrustumType
	{
		uint8_t type;
	};
	static_assert(sizeof(CameraFrustumType) == 0x1);

	struct CameraTransformData
	{
		float data[40];  // confirmed
	};
	static_assert(sizeof(CameraTransformData) == 160);  // confirmed

	struct CameraViewport
	{
		float left;
		float right;
		float top;
		float bottom;
	};
	static_assert(sizeof(CameraViewport) == 0x10);

	struct CameraBlocks
	{
		void* func1;
		void* func2;
	};
	static_assert(sizeof(CameraBlocks) == 0x10);

	// RenderGraph Members

	struct alignas(0) UpscalerHistoryResetData
	{
		uint8_t resetHistory;
	};

	struct alignas(0) ScaleformRebuildRenderGraphData
	{
		uint8_t data[1024 << 4];  // unconfirmed size
	};

	struct alignas(8) MultiCameraViewData
	{
		BSTSmallArray<uint32_t, 4> multiViewDataArray;  // 0x0
	};
	static_assert(sizeof(MultiCameraViewData) == 0x20);

	struct alignas(0) ImageProcess
	{
		uint8_t data[0x4];  // StorageTable::StrongKey<struct StorageTable::ImageProcess::Storage>
	};

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

	namespace CameraView
	{
		template <typename ST>
		struct ObserverCameraViewHostOnlyTables : public DirectColumnDataStorageInterface
		{
			HostOnlyMemory<ST, CreationRendererPrivate::SkyCubemapSystem::SkyCubemapData>*     pSkyCubeMapData;                // 0x0 CreationRendererPrivate::SkyCubemapSystem::SkyCubemapData
			HostOnlyMemory<ST, CreationRendererPrivate::ShadowMapCameraCutData>*               pShadowMapCameraCutData;        // 0x8 item size 0x4 unkonfirmed CreationRendererPrivate::ShadowMapCameraCutData
			HostOnlyMemory<ST, CreationRendererPrivate::CascadeShadowMapCache>*                pCascadeShadowMapCache;         // 0x10 struct CreationRendererPrivate::CascadeShadowMapCache
			HostOnlyMemory<ST, CreationRendererPrivate::TiledCullingData>*                     pTiledCullingData;              // 0x18 item size 6*8 class CreationRendererPrivate::TiledCullingData
			HostOnlyMemory<ST, CreationRenderer::CGen::HDRData>*                               pHdrData;                       // 0x20 struct CreationRenderer::CGen::HDRData
			HostOnlyMemory<ST, CreationRendererPrivate::HDRSystem::HDRConfig>*                 pHdrConfig;                     // 0x28 item size 550*8 struct CreationRendererPrivate::HDRSystem::HDRConfig
			HostOnlyMemory<ST, CreationRendererPrivate::DepthSystem::HistoryData>*             pHostOnlyMemory6;               // 0x30 item size 88 struct CreationRendererPrivate::DepthSystem::HistoryData
			HostOnlyMemory<ST, CreationRendererPrivate::GPUDebugGeometry::HistoryData>*        pGPUGeometryDebugHistoryData;   // 0x38 struct CreationRendererPrivate::GPUDebugGeometry::HistoryData
			HostOnlyMemory<ST, CreationRendererPrivate::DepthSystem::VisualizationData>*       pDepthSystemVisualizationData;  // 0x40 struct CreationRendererPrivate::DepthSystem::VisualizationData
			HostOnlyMemory<ST, CreationRendererPrivate::SkyOcclusionSystem::SkyOcclusionData>* pSkyOclussionData;              // 0x48 struct CreationRendererPrivate::SkyOcclusionSystem::SkyOcclusionData
			HostOnlyMemory<ST, CreationRendererPrivate::HeightfieldSystem::HeightfieldData>*   pHeightFieldData;               // 0x50 struct CreationRendererPrivate::HeightfieldSystem::HeightfieldData
			HostOnlyMemory<ST, CreationRendererPrivate::ProbeSystem::ProbeSystemData>*         pProbeSystemData;               // 0x58 struct CreationRendererPrivate::ProbeSystem::ProbeSystemData
		};
		struct alignas(8) Storage
		{
			AsyncTableColumnBase<Storage, StorageTable::HeightfieldSettings>*       pColumnHeightfieldSettings;              // struct StorageTable::HeightfieldSettings
			AsyncTableColumnBase<Storage, CreationRenderer::DirectionalShadowData>* pColumnDirectionalShadowData;            // struct CreationRenderer::DirectionalShadowData
			AsyncTableColumnBase<Storage, AverageLuminanceFutureReadback>*          pColumnDAverageLuminanceFutureReadback;  // struct StorageTable::AverageLuminanceFutureReadback
			AsyncTableColumnBase<Storage, HighlightSettings>*                       pColumnHighlightSettings;                // struct StorageTable::HighlightSettings
			AsyncTableColumnBase<Storage, CreationRenderer::FeatureSetup>*          pColumnFeatureSetup;                     // 0x20 struct CreationRenderer::FeatureSetup itemSize is 8*5 bytes
			AsyncTableColumnBase<Storage, uint32_t>*                                pColumnImageSpaceData;                   // class StorageTable::StrongKey<struct StorageTable::ImageSpaceData::Storage> 0x84 or 0x210 size item
			AsyncTableColumnBase<Storage, ClearColor>*                              pColumnClearColor;                       // struct StorageTable::ClearColor
			AsyncTableColumnBase<Storage, CameraViewData>*                          pColumnCameraViewData;                   // struct StorageTable::CameraViewData
			WriterDirectStorageData<Storage, void*>*                                pWriterColumnData;                       // pointer to 0
			ObserverCameraViewHostOnlyTables<Storage>*                              pObserverStorageData;                    // size 0x68 12 pointers to HostOnlyMemory ObserverDirectStorageData<struct StorageTable::CameraView::Storage
			void*                                                                   buffer1;                                 // byte buffer
			void*                                                                   buffer2;                                 // byte buffer
			void*                                                                   pUnk_60;                                 // 0x60 pointer to pointers
		};
	};

	namespace Camera
	{
		template <typename ST>
		struct ObserverCameraHostOnlyTables : public DirectColumnDataStorageInterface
		{
			HostOnlyMemory<ST, StorageTable::CameraBlocks>* pCameraBlocks;
		};
		struct alignas(8) Storage
		{
			AsyncTableColumnBase<Storage, CameraCut>*           pColumnCameraCut;          // 0x0 <struct StorageTable::Camera::Storage, struct StorageTable::CameraCut>
			AsyncTableColumnBase<Storage, CameraScissor>*       pColumnCameraScissors;     // 0x8 AsyncTableColumn Camera::Storage->StorageTable::CameraScisors indexes*2
			AsyncTableColumnBase<Storage, CameraViewport>*      pColumnCameraView;         // 0x10 AsyncTableColumn Camera::Storage->StorageTable::CameraView
			AsyncTableColumnBase<Storage, CameraFrustum>*       pColumnCameraFrustum;      // 0x18 AsyncTableColumn Camera::Storage->StorageTable::CameraFrustum
			AsyncTableColumnBase<Storage, CameraTransformData>* pColumnCameraTransform;    // 0x20 AsyncTableColumn Camera::Storage->StorageTable::CameraTransform
			AsyncTableColumnBase<Storage, CameraFrustumType>*   pColumnCameraFrustumType;  // 0x28 AsyncTableColumn Camera::Storage->StorageTable::CameraFrustum
			WriterDirectStorageData<Storage, void*>*            pWriterColumnData;         // 0x30 writeDirectColumnAta ?$WriterDirectStorageData@UStorage@Camera@StorageTable@@@Sto : StorageTable::DirectColumnDataStorageInterface
			ObserverCameraHostOnlyTables<Storage>*              pObserverStorageData;      // 0x38 struct HostOnlyMemory<StorageTable::CameraBlocks>
			void*                                               buffer1;                   // byte buffer
			void*                                               buffer2;                   // byte buffer
		};

		// Camera Block is set of pointers to different vtable funcs from StorageTable Observers 0 index is Particle, next is ParentTransform
	};

	class CameraStorageData : public StorageData<StorageTable::Camera::Storage>
	{
	public:
		virtual ~CameraStorageData() = 0;
	};

	static_assert(sizeof(CameraStorageData) == 0x138);

	class CameraViewStorageData : public StorageData<StorageTable::CameraView::Storage>
	{
	public:
		virtual ~CameraViewStorageData() = 0;
	};

	static_assert(sizeof(CameraViewStorageData) == 0x150);

	class RenderGraphStorageDataTable : public StorageData<StorageTable::RenderGraph::Storage>
	{
	public:
		virtual ~RenderGraphStorageDataTable() = 0;
	};

	static_assert(sizeof(RenderGraphStorageDataTable) == 0x158);

	using MultiViewAllocator = BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator<uint32_t, 4>>;
}
