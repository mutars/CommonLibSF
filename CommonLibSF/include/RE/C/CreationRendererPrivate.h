#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CreationRendererContext.h"
#include "RE/utils.h"

struct D3D12_CPU_DESCRIPTOR_HANDLE;
struct ID3D12Resource;

namespace RE::CreationRendererPrivate
{
	class RenderGraph;
	class RenderGraphDataInner;

	struct RenderTarget
	{
		char*    name;
		uint32_t renderTargetId;  // 0x8
		uint32_t unk_C;
		uint32_t unk_10;
		uint32_t flags;  // 0x14 &0x207A0 mask
		uint64_t unk_18;
		void*    unk_20;
	};
	static_assert(sizeof(RenderTarget) == 0x28);

#pragma pack(push, 1)
	struct RenderPassD3D12Resource
	{
		uint8_t         pad[120];
		ID3D12Resource* pResource;
		uint8_t         trailing[1024];
	};
#pragma pack(pop)

#pragma pack(push, 1)
	struct RenderPassD3D12ResourceWrapper
	{
		uint8_t                          pad[4];
		uint32_t                         width;
		uint32_t                         height;
		uint8_t                          pad1[60];
		RenderPassD3D12Resource*         pResourceContext;
		uint32_t                         sizeOrFrameCountOrIndex;
		uint32_t                         unk_48;
		RenderPassD3D12ResourceWrapper** resourcePool;
		char                             _pad1[8];
		D3D12_CPU_DESCRIPTOR_HANDLE*     m_RTVCpuDescriptors;
	};
#pragma pack(pop)

#pragma pack(push, 1)
	struct RenderGraphResource
	{
		uint8_t                         pad[184];
		uint32_t                        index;
		uint32_t                        padBC;
		RenderGraphResource*            next;
		RenderPassD3D12ResourceWrapper* pResourceWrapper;
		uint8_t                         padD0[8];
	};
#pragma pack(pop)

	struct RenderPassItem
	{
		uint32_t resourceSize;
		uint32_t unk_4;
		uint64_t renderGraphIndex;
		uint64_t stateOrFlags;
		uint64_t unk_18;
	};
	static_assert(sizeof(RenderPassItem) == 0x20);

	struct RenderGraphContext
	{
		uint32_t viewPortId;  // 0x20
	};

#pragma pack(push, 1)
	struct RenderGraphData
	{
		// v7 = *(_DWORD *)(*(&renderGRaphData->field_108 + *(unsigned int *)renderGRaphData->gap_138) + 36); === ID for column feature setup
		uint64_t              field_0;
		uint8_t               gap_8[24];
		uint32_t              rootRenderGraphID;
		uint32_t              sceneId;
		uint8_t               gap_28[200];
		uint64_t              field_F0;
		uint32_t              field_F8;
		uint32_t              field_FC;
		uint64_t              field_100;
		uint64_t              field_108;
		uint8_t               gap_110[24];
		uint64_t              field_128;
		uint64_t              field_130;  // number of items in some unk structure
		RenderGraphDataInner* pRenderGraphDataInner;
		RenderGraphContext*   pRenderGraphContext;  // 0x140
		uint64_t              field_148;
	};
#pragma pack(pop)

	struct alignas(0) RenderPassData
	{
		BSTSmallArray<RenderPassItem, 8>*       renderPassItems;  // 0x0
		BSTSmallArray<RenderGraphResource, 64>* renderGraphResources;
		RenderGraph*                            pRenderGraph;
		uint16_t                                unk_18;
	};

	class alignas(0) RenderPass
	{
	public:
		virtual ~RenderPass();

		virtual void unk_1();

		virtual void unk_2();

		virtual void unk_3();

		virtual void unk_4();

		virtual void unk_5();                                   //nimpl
		virtual void unk_6();                                   //nimpl
		virtual void unk_7(RenderGraphData*, RenderPassData*);  //nimpl

		// members
		char*  name;   // name 0x8->0x98 is a copy from another pass 0x0->0x90
		uint64_t      flags;  // 0x10 flags
		uint32_t      renderTargetLen;
		uint32_t      unk_1C;
		uint32_t      renderHandleId;
		uint32_t      cameraViewHandleID;
		uint32_t      renderTargetsSize;  // renderTargetsSize
		uint32_t      gap2A;
		RenderTarget* pRenderTargets;  // 0x30
		uint64_t      unk_38;
		uint64_t      unk_40;
		uint64_t      unk_48;
		uint64_t      unk_50;
		uint64_t      unk_58;
		uint64_t      unk_60;
		uint64_t      unk_68;
		uint64_t      unk_70;
		uint64_t      unk_78;
		uint64_t      unk_80;
		uint64_t      unk_88;
		uint64_t      unk_90;  // first byte set to zero probably type RenderPass/RenderGraph
		uint64_t      unk_98;
		uint64_t      unk_A0;
		uint64_t      unk_A8;
		uint64_t      unk_B0;
		uint64_t      unk_B8;
		uint64_t      unk_C0;
		uint64_t      unk_C8;
		uint64_t      shadingRateIndex;  // 0xD0
		BSFixedString unk_D8;
		RenderPass*   pSelfOrParent;
		uint64_t      unk_E8;
	};
	static_assert(sizeof(RenderPass) == 0xF0);

	class TemporalAA_idTech7RenderPass : public RenderPass
	{
		uint32_t colorInId;  // likely someIds colouIn/colorOut
		uint32_t colorOutId;
	};
	static_assert(sizeof(TemporalAA_idTech7RenderPass) == 0xF8);

	class MotionVectorCompositeRenderPass : public RenderPass
	{
		uint32_t unkF0;  // D3DContextTechniqueData index
		uint32_t unkF4;
	};
	static_assert(sizeof(MotionVectorCompositeRenderPass) == 0xF8);

	class DLSSUpscaleRenderPass : public RenderPass
	{
	};

#pragma pack(push, 1)
	struct RenderPassContainer
	{
		uint64_t                         field_0;
		uint64_t                         field_8;
		uint64_t                         field_10;
		uint64_t                         field_18;
		RenderPass*                      pRenderPass;
		BSTSmallArray<RenderPassItem, 8> renderPassData;
		uint64_t                         field_138;
		uint64_t                         field_140;
		uint8_t                          gap_148[2];
		char                             field_14A;
		uint8_t                          gap_14B[5];
	};
#pragma pack(pop)
	static_assert(sizeof(BSTSmallArray<RenderPassItem, 8>) == 256 + 16);
	static_assert(sizeof(RenderPassContainer) == 0x150);
	static_assert(offsetof(RenderPassContainer, pRenderPass) == 0x20);
	static_assert(offsetof(RenderPassContainer, field_138) == 0x138);

#pragma pack(push, 1)
	struct RenderGraphUnk
	{
		unsigned __int64 possibleSize;
		int              renderGraphIndex;
		__int16          possibleIDorIndex;
		char             field_E;
		bool             field_F;
	};
#pragma pack(pop)

	class RenderGraph : public RenderPass
	{
	public:
		~RenderGraph() override;

		virtual void updateOrAddSubGraphs();  // update views
		virtual void unk_9();

		virtual void unk_10();

		BSTArray<void*>                         arrayF0;  // 0xF0 size of int32(a2->0x20)
		uint8_t                                 unk_100[0x118];
		BSTSmallArray<RenderGraphResource, 64>* resources;
		BSTArray<RenderGraphUnk>*               renderGraphUnkArray;
		BSTSmallArray<RenderPassContainer, 8>   renderGraphs;            // 228h element size  0x150u 8 elementsx0x150 size
		uint8_t                                 unk_CB8[0xD20 - 0xCB8];  // 0xCC0
																		 // 0x0CE0 renderGraphsSize
		uint32_t renderGraphID;                                          // 0xD20
		uint32_t unk_D24;                                                // some byteflag at 0xD26
	};

	static_assert(offsetof(RenderGraph, arrayF0) == 0xF0);
	static_assert(offsetof(RenderGraph, renderGraphs) == 0x228);
	static_assert(offsetof(RenderGraph, renderGraphID) == 0xD20);
	static_assert(sizeof(RenderGraph) == 0xD28);

	static_assert(sizeof(BSTSmallArray<RenderPassContainer, 8>) == 2688 + 0x10);
	static_assert(sizeof(BSTSmallArray<uint32_t, 4>) == 0x20);
	using RenderGraphBSTAllocator = BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator<RenderPassContainer, 8>>;

	class FrameRenderGraph : public RenderGraph
	{
	public:
		uint32_t id;
		uint32_t unk_D2C;
	};

	class RenderViewSubGraph : public RenderGraph
	{
	public:
		~RenderViewSubGraph() override;

		uint32_t sceneId;  // 0xD28
		uint32_t unk_D2C;    // pad
	};

	static_assert(sizeof(RenderViewSubGraph) == 0xD30);

	class MainRenderGraph : public RenderGraph
	{
	public:
		~MainRenderGraph() override;

		BSTSmallArray<uint32_t, 4>      multiViewDataArray;  // 0xD28 4 elem 4 size represent viewIndexes from StorageTable::REnderGraph::MiltiView
		BSTSmallArray<BSFixedString, 4> subGraphNames;
	};

	static_assert(offsetof(MainRenderGraph, multiViewDataArray) == 0xD28);
	static_assert(offsetof(MainRenderGraph, subGraphNames) == 0xD48);
	static_assert(sizeof(MainRenderGraph) == 0xD78);

	class RenderSceneSubGraph : public RenderGraph
	{
		uint8_t   flag;  // 0xD28
		uint8_t   unk_D29;
		uintptr_t unk_D30[0x40];  // 0xD30 64 pointers
		uint64_t  unk_F30;
		uint64_t  unk_F38;
		uint32_t  unk_F40;
		uint32_t  unk_F44;
		uint32_t  unk_F48;
		uint32_t  unk_F4C;
		uint32_t  unk_F50;
		uint32_t  unk_F54;
		uint32_t  unk_F58;
		uint32_t  unk_F5C;
		uint32_t  unk_F60;
		uint32_t  unk_F64;
		uint32_t  unk_F68;
		uint32_t  unk_F6C;
	};
	static_assert(sizeof(RenderSceneSubGraph) == 0xF70);

	// REnder Graph struct REL::ID(885886)
	// RenderSceneSubGraph  (qword_1459AA8D8 + 232)

	struct alignas(0) VisualizationSetup
	{
		uint8_t data[0x3C];
	};
	static_assert(sizeof(VisualizationSetup) == 0x3C);

	struct TiledCullingData
	{
		uint8_t data[6 * 8];
	};
	static_assert(sizeof(TiledCullingData) == 6 * 8);

	struct alignas(4) CascadeShadowMapCache
	{
		uint8_t data[4];
	};
	static_assert(sizeof(CascadeShadowMapCache) == 4);

	struct ShadowMapCameraCutData
	{
		uint8_t data[1024 << 4];  // unconfirmed
	};

	namespace GPUDebugGeometry
	{
		struct HistoryData
		{
			uint8_t data[1024 << 4];  // unconfirmed
		};
	};

	namespace DepthSystem
	{
		struct VisualizationData
		{
			uint8_t data[1024 << 4];  // unconfirmed
		};

		struct HistoryData
		{
			uint8_t data[88];  // unconfirmed
		};
		static_assert(sizeof(HistoryData) == 0x58);
	};

	namespace SkyOcclusionSystem
	{
		struct SkyOcclusionData
		{
			uint8_t data[1024 << 4];  // unconfirmed
		};
	};

	namespace HeightfieldSystem
	{
		struct HeightfieldData
		{
			uint8_t data[550 * 8];
		};
	};
	static_assert(sizeof(HeightfieldSystem::HeightfieldData) == 550 * 8);

	namespace ProbeSystem
	{
		struct ProbeSystemData
		{
			void* data;  // unconfirmed
		};
	};

	namespace HDRSystem
	{
		struct HDRConfig
		{
			void* data;  // unconfirmed
		};
	}
	namespace SkyCubemapSystem
	{
		struct SkyCubemapData
		{
			void* data;  // unconfirmed
		};
	};

	namespace ApiAbstractionLayer
	{
		namespace FSR3
		{
			struct ContextData
			{
				uint8_t data[1024 << 4];  // unconfirmed
			};
		}

		namespace FSR2
		{
			struct ContextData
			{
				uint8_t data[1024 << 4];  // unconfirmed
			};
		}
	};

	namespace Intel_XeSS
	{
		struct XeSSContext
		{
			uint8_t data[1024 << 4];  // unconfirmed
		};
	}

	namespace NV_Streamline
	{
		namespace Utils
		{
			struct ViewportData
			{
				uint8_t data[1024 << 4];  // unconfirmed
										  // uint32_t offfset 0x10 viewportHandleId
			};
		}
	}

}
