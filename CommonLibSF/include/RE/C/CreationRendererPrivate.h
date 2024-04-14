#pragma once
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/utils.h"

namespace RE::CreationRendererPrivate {
    class alignas(0) RenderPass {
    public:
        virtual ~RenderPass();
        virtual void unk_1();
        virtual void unk_2();
        virtual void unk_3();
        virtual void unk_4();
        virtual void unk_5(); //nimpl
        virtual void unk_6(); //nimpl
        virtual void unk_7(); //nimpl


        // members
        uint64_t unk_8; // 0x8->0x98 is a copy from another pass 0x0->0x90
        uint64_t unk_10;
        uint64_t unk_18;
        uint64_t unk_20;
        uint64_t unk_28;
        uint64_t unk_30;
        uint64_t unk_38;
        uint64_t unk_40;
        uint64_t unk_48;
        uint64_t unk_50;
        uint64_t unk_58;
        uint64_t unk_60;
        uint64_t unk_68;
        uint64_t unk_70;
        uint64_t unk_78;
        uint64_t unk_80;
        uint64_t unk_88;
        uint64_t unk_90; // first byte set to zero probably type RenderPass/RenderGraph
        uint64_t unk_98;
        uint64_t unk_A0;
        uint64_t unk_A8;
        uint64_t unk_B0;
        uint64_t unk_B8;
        uint64_t unk_C0;
        uint64_t unk_C8;
        uint64_t unk_D0;
        BSFixedString unk_D8;
		RenderPass* pSelfOrParent;
        uint64_t unk_E8;
    };
//    check_size<sizeof(RenderPass), 0xF8> trace_size11;
    static_assert(sizeof(RenderPass) == 0xF0);

    class TemporalAA_idTech7RenderPass: public RenderPass {

    };
    static_assert(sizeof(TemporalAA_idTech7RenderPass) == 0xF0);

    class RenderGraph: public RenderPass {
    public:
        ~RenderGraph() override;
        virtual void updateOrAddSubGraphs(); // update views 
        virtual void unk_9();
        virtual void unk_10();
        BSTArray<void*> arrayF0; // 0xF0 size of int32(a2->0x20)
        uint8_t unk_100[0x228 - 0x100];
        BSTSmallArray<RenderGraph, 2688> renderGraphs; // 228h element size  0x150u 8 elementsx0x150 size
		uint8_t unk_CB8[0xD20 - 0xCB8]; // 0xCC0
		uint32_t renderGraphID; // 0xD20
		uint32_t unk_D24; // some byteflag at 0xD26
    };
    static_assert(sizeof(BSTSmallArray<uint32_t, 16>) == 0x20);
    static_assert(sizeof(BSTSmallArray<RenderGraph, 2688>) == 2688+0x10);
	static_assert(offsetof(RenderGraph, arrayF0) == 0xF0);
	static_assert(offsetof(RenderGraph, renderGraphs) == 0x228);
	static_assert(offsetof(RenderGraph, renderGraphID) == 0xD20);
    static_assert(sizeof(RenderGraph) == 0xD28);

    class RenderViewSubGraph: public RenderGraph {
    public:
        ~RenderViewSubGraph() override;

		uint32_t subViewId; // 0xD28
		uint32_t unk_D2C; // pad
    };
    static_assert(sizeof(RenderViewSubGraph) == 0xD30);

    
    class MainRenderGraph: public RenderGraph {
    public:
		~MainRenderGraph() override;
		BSTSmallArray<uint32_t, 16>      multiViewDataArray; // 0xD28 4 elem 4 size represent viewIndexes from StorageTable::REnderGraph::MiltiView
		BSTSmallArray<BSFixedString, 32> subGraphNames;
    };
	static_assert(offsetof(MainRenderGraph, multiViewDataArray) == 0xD28);
	static_assert(offsetof(MainRenderGraph, subGraphNames) == 0xD48);
	static_assert(sizeof(MainRenderGraph) == 0xD78);

    // REnder Graph struct REL::ID(885886)
    // RenderSceneSubGraph  (qword_1459AA8D8 + 232)

    struct RenderPassItem {
        uint64_t unk_0;
        uint64_t unk_8;
        uint64_t unk_10;
        uint64_t unk_18;
    };
    static_assert(sizeof(RenderPassItem) == 0x20);

    struct RenderPassData {
        uint64_t unk_0;
        uint64_t unk_8;
        RenderPassItem unk_10[64];
    };

}
