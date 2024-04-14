#pragma once
#include "RE/I/IObjectProcessor.h"
#include "RE/B/BSFixedString.h"

namespace RE::BSScript
{
    namespace Internal
    {
        class VirtualMachine;
    }

    class LinkerProcessor: public IObjectProcessor
    {
    public:
        SF_RTTI_VTABLE(BSScript__LinkerProcessor);

        virtual ~LinkerProcessor() = default;  // 00

        // add
        virtual void clone() = 0;  // 01
        virtual void unk_02() = 0;  // 02
        virtual void unk_03() = 0;  // 03


        Internal::VirtualMachine* pVirtualMachine;  // 08
        void* pLogger;  // 10 GameScript::Logger
        void* pCompiledScriptLoader;  // 18 BSScript::CompiledScriptLoader : BSScript::ILoader
        void* unk_20;  // 20
        void* unk_28;  // 28
        float unk_30;  // 30
        float unk_34;  // 38
        void* unk_38;  // 38
        void* unk_40;  // 40
        float unk_48;  // 48
        float unk_4C;  // 4C
        void* unk_50;  // 50
        void* unk_58;  // 58
        float unk_60;  // 60
        float unk_64;  // 64
        void* unk_68;  // 68
        void* unk_70;  // 70
        void* unk_78;  // 78 // some kind of list with NestedValues UI values
        void* unk_80;  // 80 // array or mack with UI values
    };
    static_assert(sizeof(LinkerProcessor) == 0x88);
}