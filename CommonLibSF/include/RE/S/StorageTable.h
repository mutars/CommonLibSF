#pragma once
#include "RE/utils.h"

namespace RE {
    namespace StorageTable {
        // template<typename T, typename V>
        struct HostOnlyMemory;
        class AsyncTableColumnBase;
        class WriterDirectStorageData;
        class ObserverDirectStorageData;

        struct alignas(8) Storage{

        };

		struct MultiViewData: Storage {
			BSTSmallArray<uint32_t, 16> multiViewDataArray; // 0x0
		};
		static_assert(sizeof(MultiViewData) == 0x20);

        struct HashBucket {
            void* unk_0;
            uint16_t bucketIndex;
            uint16_t unk_A;
            uint32_t unk_C;
        };
        static_assert(sizeof(HashBucket) == 0x10);

        //template<typename T, typename V>
        struct alignas(64) HashTable {
            uint32_t threadID;
            uint32_t refCount;
            uint64_t unk_8[15];
            uint32_t unk_80; // either last Element or ActiveElement
            uint32_t unk_84;
            uint64_t unk_88;
            uint64_t unk_90;
            HostOnlyMemory* pParent; // 98
            HashBucket* pBucketsPointer; // A0
            //void* pad_A8;
            uint32_t bucketsSize; //B0 = default 96
            uint32_t unk_B4; // 64 or 16
            uint32_t unk_B8; // 16
            //uint32_t pad_BC;
            HashBucket buckets[0x1000]; // 0xC0 looks like this is initial capacity driven by some logic max size is x4 of initial capacity, for debug purpose will hardcode it to reasonable max
        };
        static_assert(sizeof(HashTable) == 0x1000*0x10+0xC0);

//        template<typename T, typename V>
        struct HostOnlyMemory {
            virtual void unk_0(); // or destructor
            virtual void unk_1();
            virtual void unk_2();
            virtual void unk_3();
            virtual void unk_4();

            void*       pTableData; // pointer equal to unk_18
            HashTable* unk_10; // hashtable size 0x700 aligment 64, could be wrong and this so far looks like array list
            void*       tableData; // 0x18  for truct StorageTable::HostOnlyMemory<StorageTable::Camera::Storage,NiCamera * __ptr64,0>: will be pointing to allocated memory with pointers to NiCameras
            void*    unk_20;
            uint64_t unk_28; // 0x28
        };
        static_assert(sizeof(HostOnlyMemory) == 0x30);

        struct Camera: public Storage {
            AsyncTableColumnBase* pColumnCameraCut; // 0x0 <struct StorageTable::Camera::Storage, struct StorageTable::CameraCut>
            AsyncTableColumnBase* pColumnCameraScisors; // 0x8 AsyncTableColumn Camera::Storage->StorageTable::CameraScisors
            AsyncTableColumnBase* pColumnCameraView; // 0x10 AsyncTableColumn Camera::Storage->StorageTable::CameraView
            AsyncTableColumnBase* pColumnCameraFrustum; // 0x18 AsyncTableColumn Camera::Storage->StorageTable::CameraFrustum
            AsyncTableColumnBase* pColumnCameraTransform; // 0x20 AsyncTableColumn Camera::Storage->StorageTable::CameraTransform
            AsyncTableColumnBase* pColumnCameraFrustum2; // 0x28 AsyncTableColumn Camera::Storage->StorageTable::CameraFrustum
			WriterDirectStorageData* pWriterColumnData;  // 0x30 writeDirectColumnAta ?$WriterDirectStorageData@UStorage@Camera@StorageTable@@@Sto : StorageTable::DirectColumnDataStorageInterface
            ObserverDirectStorageData* pObserverStorageData; // 0x38 template Camera::Storage generic
            void* unk_40; // byte buffer
            void* unk_48; // byte buffer
        };

        struct RenderGraph: public Storage {
            AsyncTableColumnBase* pRenderGraphOptionsAT; // struct StorageTable::RenderGraphOptions
            AsyncTableColumnBase* pImageProcessAT; // 0x8 class StorageTable::StrongKey<struct StorageTable::ImageProcess::Storage
            AsyncTableColumnBase* pImGuiAT; // 0x10 class StorageTable::StrongKey<struct StorageTable::ImGuiST::Storage>
            AsyncTableColumnBase* pBinkMovieAT; // 0x18 class StorageTable::StrongKey<struct StorageTable::BinkMovie::Storage
            AsyncTableColumnBase* pFaceCustomisationRequestAT; // 0x20 struct StorageTable::RenderGraph::FaceCustomizationRequest
            AsyncTableColumnBase* pPauseFrameGenerationAT; // 0x28 struct StorageTable::PauseFrameGenerationData
            AsyncTableColumnBase* pScaleFormMenusDataAT; // 0x30 struct StorageTable::ScaleformMenusData
            AsyncTableColumnBase* pVisualizationSetupAT; // 0x38 struct CreationRenderer::VisualizationSetup
            AsyncTableColumnBase* pMultiViewDataAT; // 0x40 struct StorageTable::MultiCameraViewData
            AsyncTableColumnBase* pDenderGrapStorageDatAT; // 0x48 struct StorageTable::RenderGraphStorageData
			WriterDirectStorageData*   unk_50;  // 0x50 ??? nulltr
			ObserverDirectStorageData* pObserverDirectStorageData;  // 0x58 ObserverDirectStorageData<struct StorageTable::RenderGraph::Storage
            void* unk_60; // 0x60 byte buffer
            void* unk_68; // 0x68 byte buffer
        };

        struct CameraView: public Storage {
            AsyncTableColumnBase* pColumnHeightfieldSettings; // struct StorageTable::HeightfieldSettings
            AsyncTableColumnBase* pColumnDirectionalShadowData; // struct CreationRenderer::DirectionalShadowData
            AsyncTableColumnBase* pColumnDAverageLuminanceFutureReadback; // struct StorageTable::AverageLuminanceFutureReadback
            AsyncTableColumnBase* unk4; // 0x18
            AsyncTableColumnBase* unk5; // 0x20
            AsyncTableColumnBase* unk6; // 0x28
            AsyncTableColumnBase* unk7; // 0x30
            AsyncTableColumnBase* unk8; // 0x38
            AsyncTableColumnBase* unk9; // 0x40
            WriterDirectStorageData* pWriterColumnData;  // TODO
            ObserverDirectStorageData* pObserverStorageData; // TODO: check type
            void* unk_40; // byte buffer
            void* unk_48; // byte buffer
        };

        struct alignas(2048 << 2) AsyncColumnRowBuffer {
            uint32_t unk0;
            uint32_t unk4;
            uint8_t unk8[0x3FD*8-8];
            void* unk_1FE8;
            void* unk_1FF0;
            void* unk_1FF8;
        };
        static_assert(sizeof(AsyncColumnRowBuffer) == 0x2000);
		static_assert(offsetof(AsyncColumnRowBuffer, unk_1FE8) == 0x1FE8);

        struct alignas(8) AsyncColumRow {
            uint64_t unk_0;
            uint32_t unk_8;
            AsyncColumnRowBuffer* unk_10;
            AsyncColumnRowBuffer* unk_18;
            uint64_t unk_20;
            uint32_t unk_28;
            uint32_t pad_2C;
            uint32_t unk_30;
            uint64_t unk_38;
            uint64_t unk_40;
            int32_t unk_48;
            uint64_t unk_50;
            uint64_t unk_58;
            int32_t unk_60;
			uint64_t flags_68; // 0x68
        };
        static_assert(sizeof(AsyncColumRow) == 0x70);

        //template<typename T, typename V>
        class alignas(64) AsyncTableColumnBase {
        public:
            virtual ~AsyncTableColumnBase() = 0;
            virtual void unk_1();
            virtual void unk_2();

            uint64_t unk_8;
            uint64_t unk_10;
            uint64_t unk_18;
            uint64_t unk_20;
            uint64_t unk_28;
            uint64_t unk_30;
            uint64_t unk_38;
			uint32_t* indexes;  // pointer to allocated memory (0x200++ size) aligment 4 objectId to index in Memory objectID & 0xFFFFFF
            uint64_t unk_48;
            uint64_t unk_50;
            uint64_t unk_58;
            uint64_t unk_60;
            uint64_t unk_68;
            uint64_t unk_70;
            uint64_t unk_78;
            uint64_t unk_80;
            uint32_t unk_88;
            uint32_t unk_8C;
            uint64_t unk_90;
            uint64_t unk_98;
            uint64_t unk_A0;
            uint64_t unk_A8;
            uint64_t unk_B0;
            uint64_t unk_B8;
            uint64_t unk_C0;
            AsyncColumRow* rows[64]; // 0xC8  will iterate starting from 0xC8 pointers 64 times and validate 0x68 in each pointer
			uint64_t* unk_2C8;  // pointer to allocated memory (0x200++ size) aligment 4
			uint64_t* unk_2D0;  // pointer to allocated memory (0x200++ size) aligment 8 0x200 points to 2D0 
            uint64_t unk_2D8[29];
            HostOnlyMemory pHostOnlyMemory; // 3C0 actual offset
            uint64_t unk_400[3]; // pads
        };
		//auto t = check_size<sizeof(AsyncTableColumnBase), 0x440>;
        static_assert(offsetof(AsyncTableColumnBase, unk_2D8) == 0x2D8);
        static_assert(offsetof(AsyncTableColumnBase, rows) == 0xC8);
		static_assert(offsetof(AsyncTableColumnBase, pHostOnlyMemory) == 0x3C0);
        static_assert(sizeof(AsyncTableColumnBase) == 0x440);

        class StorageDataBase {
        public:
            virtual ~StorageDataBase() = 0;
            virtual void unk_1();
            virtual void unk_2();
            virtual void unk_3();
            virtual void unk_4();
            virtual void unk_5();
            virtual void allocateFreeSlotAndSwapBuffers();

            // members
            void* unk_8;
            void* unk_10;
            void* unk_18;
            uint64_t unk_20;
            uint64_t unk_28;
            uint64_t unk_30;
            uint64_t unk_38;
            void* unk_40; //pointer arg in constructor
            void* unk_48;
            void* unk_50;
            uint64_t unk_58; // 0x1FAh
            uint64_t unk_60;
            void* unk_68;
            void* unk_70;
            uint64_t unk_78; // 0x1FAh
            uint64_t unk_80;
            uint64_t unk_88;
            uint32_t unk_90[8];
            uint64_t unk_B0;
            uint32_t unk_B8[8];
            void* unk_D8;
            uint32_t unk_E0;

        };
        static_assert(offsetof(StorageDataBase, unk_40) == 0x40);
        static_assert(offsetof(StorageDataBase, unk_E0) == 0xE0);
        static_assert(sizeof(StorageDataBase) == 0xE8);

        template <typename Storage>
        class StorageData: public StorageDataBase {
        public:
            virtual ~StorageData() = 0;
            Storage storageData; // 0xE8
        };

        class CameraStorageData: public StorageData<StorageTable::Camera> {
        public:
            virtual ~CameraStorageData() = 0;

        };
        static_assert(sizeof(CameraStorageData) == 0x138);

        class CameraViewStorageData: public StorageData<StorageTable::CameraView> {
        public:
            virtual ~CameraViewStorageData() = 0;

        };
        static_assert(sizeof(CameraViewStorageData) == 0x150);


        class RenderGraphStorageData: public StorageData<StorageTable::RenderGraph> {
        public:
            virtual ~RenderGraphStorageData() = 0;
        };
        static_assert(sizeof(RenderGraphStorageData) == 0x158);

        struct alignas(8) DirectColumnDataStorageInterface {
            virtual void unk_0();
            virtual void unk_1();
            virtual void unk_2();
            virtual void unk_3();
        };

//        template <typename T>
        class WriterDirectStorageData: public DirectColumnDataStorageInterface {
        public:
            HostOnlyMemory* pHostOnlyMemory; // 0x8
        };
        static_assert(sizeof(WriterDirectStorageData) == 0x10);


        class ObserverDirectStorageData: public DirectColumnDataStorageInterface {
            HostOnlyMemory* pHostOnlyMemory; // 0x8
        };;
    }

}
