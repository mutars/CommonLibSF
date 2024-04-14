#pragma once

namespace RE::BSService {
    namespace Detail {
        template <class T>
        struct ISubscriberTable {

        };

        template <class T>
        class TSubscriberTable: public ISubscriberTable<T> {
            ~TSubscriberTable() = default;

            virtual void Unk_01() = 0;
            virtual void Unk_02() = 0;
        };
    }
}