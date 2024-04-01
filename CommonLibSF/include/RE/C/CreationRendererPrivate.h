#pragma once

//#include "RE/utils.h"

namespace RE::CreationRendererPrivate {
    class RenderPass {
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
        void* unk_8;
        void* unk_10;
        void* unk_18;
        void* unk_20;
        void* unk_28;
        void* unk_30;
        void* unk_38;
        void* unk_40;
        void* unk_48;
        void* unk_50;
        void* unk_58;
        void* unk_60;
        void* unk_68;
        void* unk_70;
        void* unk_78;
        void* unk_80;
        void* unk_88;
        char  unk_90;
        uint8_t  unk_91[100];

    };
//    check_size<sizeof(RenderPass), 0xF8> trace_size11;
    static_assert(sizeof(RenderPass) == 0xF8);

    class TemporalAA_idTech7RenderPass: public RenderPass {

    }; //size F8
    static_assert(sizeof(TemporalAA_idTech7RenderPass) == 0xF8);

    // REnder Graph struct REL::ID(885886)
    // RenderSceneSubGraph  (qword_1459AA8D8 + 232)
}
