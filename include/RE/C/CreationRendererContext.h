#pragma once
/*#include "d3d12.h"

class IDXGIFactory6;
class IDXGIAdapter4;

namespace RE
{
	struct D3D12Context;

	#pragma pack(push, 1)
	struct D3D12FenceData
	{
		uint64_t       field_0;
		uint8_t        gap_8[16];
		ID3D12Fence* pFence;
		uint64_t      field_20;
	};
	#pragma pack(pop)

	#pragma pack(push, 1)
	struct D3D12ContextHolderTemp
	{
		D3D12Context*                                    pD3DContext;
		D3D12CommandQueueData*                           pCommandQueue;
		D3D12CommandQueueData*                           pCommandQueue1;
		D3D12CommandQueueData*                           pCommandQueue2;
		void* pSubmitAndPresentThread;
		D3D12FenceData*                                  pFenceData;
	};
	#pragma pack(pop)

	#pragma pack(push, 1)
	struct D3D12CommandQueueData
	{
		uint8_t                        index;
		uint8_t                        gap_0[3];
		int                          field_4;
		int                          priority;
		uint8_t                        gap_C[4];
		D3D12Context*                pD3DContextData;
		int                          possRenderPass;
		int                          field_1C;
		int                          field_20;
		uint8_t                        gap_24[4];
		ID3D12CommandQueue*          pCommandQueue;
		uint64_t                       field_30;
		uint64_t                      field_38;
		struct _RTL_CRITICAL_SECTION criticalSection;
		uint64_t                      field_48;
		uint64_t                      field_50;
		uint64_t                      field_58;
		uint64_t                      field_60;
	};
	#pragma pack(pop)

	#pragma pack(push, 1)
	struct D3DDescriptorHeapData2
	{
		char                        uavOrSampler;
		uint8_t                       gap_1[3];
		int                         destriptorStart;
		int                         handleIndex;
		int                         destriptorEnd;
		D3D12Context*               pD3D12Context;
		ID3D12DescriptorHeap*       pDescriptorHeap;
		D3D12_CPU_DESCRIPTOR_HANDLE cpuDescriptorHandleStart;
		D3D12_GPU_DESCRIPTOR_HANDLE gpuDescriptorHandleStart;
		D3D12_CPU_DESCRIPTOR_HANDLE cpuDescriptorHandleAtIndex;
		D3D12_GPU_DESCRIPTOR_HANDLE gpuDescriptorHandleAtIndex;
		int                         descriptorHandleIncrimentSize;
		uint8_t                       gap_44[4];
		uint64_t                     field_48;
		uint64_t                     field_50;
	};
	#pragma pack(pop)

	#pragma pack(push, 1)
	struct D3D12DescriptorHeapData
	{
		D3D12Context*                parentContext;
		D3D12_DESCRIPTOR_HEAP_TYPE   descriptorHeapType;
		uint8_t                        gap_C[4];
		char*                        bData;
		uint8_t                        gap_18[24];
		struct _RTL_CRITICAL_SECTION criticalSection;
		ID3D12DescriptorHeap*        pDescriptorHEap;
		D3D12_CPU_DESCRIPTOR_HANDLE  cpuDescriptorHandleStart;
		int                          descriptorHandleIncrimentSize;
	};
	#pragma pack(pop)

	#pragma pack(push, 1)
	struct D3D12Context
	{
		uint64_t                     field_0;
		D3D12FenceData*              pFenceData;
		void*                        structWith5pointers;
		uint8_t                        gap_18[8];
		uint64_t                      unk20;
		uint8_t                        gap_21[8];
		uint64_t             field_30;
		uint64_t                       field_38;
		uint32_t                       field_40;
		uint32_t                       field_44;
		uint32_t                       field_48;
		uint8_t                        gap_4C[4];
		char                         field_50;
		uint8_t                        gap_51[15];
		uint64_t             field_60;
		uint64_t                       field_68;
		uint32_t                       field_70;
		uint32_t                       field_74;
		uint32_t                       field_78;
		uint8_t                        gap_7C[12];
		D3D_FEATURE_LEVEL            d3dFeatureLevel;
		uint8_t                        gap_8C[28];
		int                          field_A8;
		int                          field_AC;
		int                          field_B0;
		int                          field_B4;
		uint32_t                       field_B8;
		uint32_t                       field_BC;
		uint32_t                       field_C0;
		char                         maxShadingRate;
		char                         field_C5;
		uint8_t                        gap_C6[2];
		uint64_t                       field_C8;
		uint64_t                       field_D0;
		char                         field_D8;
		uint8_t                        gap_D9[63];
		char                         field_118;
		uint8_t                        gap_119[63];
		char                         field_158;
		uint8_t                        gap_159[63];
		char                         field_198;
		uint8_t                        gap_199[64];
		char                         field_1D9;
		uint8_t                        gap_1DA[121];
		uint8_t                        field_253[245];
		uint32_t                       field_348;
		uint8_t                        gap_34C[68];
		IDXGIFactory6*               pDXGIFactory;
		IDXGIAdapter4*               pDXGIAdapter;
		ID3D12Device3*               pD3d12Device;
		uint8_t                        gap_3A0[64];
		D3D12DescriptorHeapData*     pCBV_SRV_UAV_DescriptorHeapData;
		D3D12DescriptorHeapData*     pSampler_DescriptorHeapData;
		D3D12DescriptorHeapData*     pRTV_DescriptorHeapData;
		D3D12DescriptorHeapData*     pDSV_DescriptorHeapData;
		uint64_t                     unk408;
		D3DDescriptorHeapData2*      pSamplerDescriptorAtIndex;
		D3DDescriptorHeapData2*      pUAVDescriptorAtIndex;
		uint64_t                     unk420;
		D3D12_CPU_DESCRIPTOR_HANDLE* srvTexture1DHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* srvTexture2DHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* srvTexture2DmsHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* srvTexture3DHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* srvTextureCubeHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* srvTexutre1DArrayHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* srvTexutre2DArrayHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* srvTexutre2DmsArrayHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* srvTexutreCubeArrayHandle;
		uint64_t                     unk470;
		D3D12_CPU_DESCRIPTOR_HANDLE* uavTexture1DHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* uavTexture2DHandle;
		uint64_t                     unk488;
		D3D12_CPU_DESCRIPTOR_HANDLE* uavTexture3DHandle;
		uint64_t                     unk498;
		D3D12_CPU_DESCRIPTOR_HANDLE* uavTexture1DArrayHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* uavTexture2DArrayHandle;
		uint8_t                        gap_498[16];
		D3D12_CPU_DESCRIPTOR_HANDLE* srvTexutreDimensionBufferHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* uavTexutreDimensionBufferHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* constantBufferViewHandle;
		D3D12_CPU_DESCRIPTOR_HANDLE* samplerCPUHandler;
		uint32_t                       field_4E0;
		uint32_t                       field_4E4;
		uint8_t                        gap_4E8[32];
		void*                        strut3pointers;
		uint8_t                        gap_510[40];
		D3D12CommandQueueData*       pCommandQueueData;
		D3D12CommandQueueData*       pCommandQueueData1;
		D3D12CommandQueueData*       pCommandQueueData2;
		uint8_t                        gap_550[8];
		ID3D12Debug3*                debugInterface1;
		ID3D12Debug2*                debugInterface2;
		ID3D12Device3*               pD3d12Device2;
		ID3D12Device3*               pD3d12Device3;
	};
    #pragma pack(pop)
	//static_assert(sizeof(D3D12Context) == 0x598);

	#pragma pack(push, 1)
	struct D3DContextCommnadAllocatorData
	{
		uint64_t                 pad0;
		uint64_t                 pad8;
		uint64_t                 pad10;
		uint64_t                 pad16;
		ID3D12CommandAllocator* pID3D12CommandAllocator;
	};
	#pragma pack(pop)

	#pragma pack(push, 1)
	struct D3DContextTechniqueData
	{
		uint32_t               shaderType;
		uint8_t                bindType;
		uint8_t                 gap_4[75];
		int                  field_50;
		int                  field_54;
		char                 field_58;
		uint8_t                 gap_59[23];
		const char*          m_Name;
		ID3D12PipelineState* pPiplineState1;
		ID3D12StateObject*   pPiplineStateObject;
	};
	#pragma pack(pop)


	#pragma pack(push, 1)
	struct D3DContextBindData
	{
		void*                    m_LayoutConfigurationData;
		D3DContextTechniqueData* pD3DContextBindDataItem;
		uint8_t                    gap_10[32];
		uint64_t                  field_30;
		uint8_t                    gap_38[8];
		void*                    field_40;
		uint64_t                  field_48;
		unsigned int             techniqueCount;
		uint8_t                    gap_54[36];
		ID3D12RootSignature*     pID312RootSignature;
	};
	#pragma pack(pop)
    #pragma pack(push, 1)
	struct RenderGraphDataD3D12Context
	{
		D3D12Context*                   pD3D12Context;
		D3DContextCommnadAllocatorData* pD3DContextCommnadAllocatorData;
		ID3D12GraphicsCommandList*      pID3D12CommandList;
		D3DContextBindData*             pD3DContextBindData;
		D3DContextBindData*             pD3DContextBindDataDefault;
		uint8_t                           gap_28[16];
		uint64_t                          field_38;
		uint8_t                           raw_data[4096];
	};
	#pragma pack(pop)

	#pragma pack(push, 1)
	struct RenderGraphDataInner
	{
		uint8_t                                gap_0[280];
		uint64_t                              field_118;
		RenderGraphDataD3D12Context*         pRenderGraphDataD3D12Context;
		uint8_t                                gap_128[8];
		char                                 field_130;
		uint8_t                                raw_data[4095];
	};
	#pragma pack(pop)

};
*/
