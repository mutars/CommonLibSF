#pragma once

#include "RE/I/IVirtualMachine.h"
#include "RE/I/IVMObjectBindInterface.h"
#include "RE/I/IVMDebugInterface.h"
#include "RE/I/IVMRemoteDebuggerInterface.h"
#include "RE/I/IVMFunctionMessageDispatch.h"
#include "RE/I/IVMSaveLoadInterface.h"
#include "RE/L/LinkerProcessor.h"
#include "RE/B/BSTEvent.h"

namespace RE::BSScript {

    struct StatsEvent;

    namespace Internal {
        class VirtualMachine
                : public IVirtualMachine,
                  IVMObjectBindInterface,
                  IVMSaveLoadInterface,
                  IVMDebugInterface,
                  IVMRemoteDebuggerInterface,
                  IVMFunctionMessageDispatch,
                  BSTEventSource<BSScript::StatsEvent> {
        public:
            virtual ~VirtualMachine();

            void *unk060;  // 060 GameScript::Logger : BSScript::ErrorLogger : BSTEventSource<BSScript::LogEvent> : BSTEventDetail::SourceBase
            void *unk068;  // 068 BSScript::SimpleAllocMemoryPagePolicy : BSScript::IMemoryPagePolicy
            GameScript::HandlePolicy *pObjectHandlePolicy;  // 070 GameScript::HandlePolicy : BSScript::IObjectHandlePolicy
            GameScript::ObjectBindPolicy *pObjectBindPolicy;  // 078 GameScript::ObjectBindPolicy : BSScript::ObjectBindPolicy
            void *unk080;  // 080
            void *unk088;  // 088
            void *unk090;  // 090
            void *unk098;  // 098
            GameScript::SavePatcher *unk0A0;  // 0A0 GameScript::savePatcher
            char pad0A8[0x1D0 - 0xA8];  // 0A8
            BSScript::LinkerProcessor *linkerProcessor;
            char pad1D8[0x4040 - 0x1D8];

        };
//        static_assert(sizeof(VirtualMachine) == 0xA8);
        static_assert(offsetof(VirtualMachine, unk060) == 0x060);
        static_assert(offsetof(VirtualMachine, unk0A0) == 0x0A0);
        static_assert(offsetof(VirtualMachine, linkerProcessor) == 0x1D0);
    } // size 0x4040 aligment 128
}
