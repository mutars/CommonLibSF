#pragma once

namespace RE::BSService {
    namespace Detail {
        template <class T>
        struct ISubscriberTable {

        };

        template <class T>
        class TSubscriberTable: public ISubscriberTable<T> {
		public:
            ~TSubscriberTable() = default;

            virtual void Unk_01() = 0;
            virtual void Unk_02() = 0;

			uint64_t unk08;
			uint64_t unk10;
			uint64_t unk18;
			uint64_t unk20;
        };
    }
}
