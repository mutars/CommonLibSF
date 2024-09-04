#pragma once

#include "RE/C/CreationRenderer.h"
#include "RE/C/CreationRendererPrivate.h"
#include "RE/S/StorageTable.h"

namespace RE::StorageTable
{
	struct alignas(0) ImageSpaceData
	{
		uint8_t data[0x4];  // StorageTable::StrongKey<struct StorageTable::ImageSpaceData::Storage>
	};
	static_assert(sizeof(ImageSpaceData) == 4);

	// Camera::Storage members

	struct alignas(0) CameraCut
	{
		uint8_t data[0x40];  // 0x0
	};
	static_assert(sizeof(CameraCut) == 64);

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
	struct CameraBlocksData
	{
		char data[0x2B0*3];
		/**
		 * 0x8 -> 0x66 4 bytes unknown also possible current->past something
		 * 0x50 -> 0x150 8floats current->past something
		 * 0x70 -> 0x170 8floats current->past something
		 *
		 *
		 */
	};
	static_assert(sizeof(CameraBlocksData) == 0x2B0*3); // either 160 size or 0x2B0*3

	struct CameraBlocks {
		CameraBlocksData* data;
		uint32_t unk;
		uint32_t unk2;
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
			WriterDirectStorageData<Storage, NiCamera*>*        pWriterColumnData;         // 0x30 writeDirectColumnAta ?$WriterDirectStorageData@UStorage@Camera@StorageTable@@@Sto : StorageTable::DirectColumnDataStorageInterface
			ObserverCameraHostOnlyTables<Storage>*              pObserverStorageData;      // 0x38 struct HostOnlyMemory<StorageTable::CameraBlocks>
			void*                                               buffer1;                   // byte buffer
			void*                                               buffer2;                   // byte buffer
		};

		// Camera Block is set of pointers to different vtable funcs from StorageTable Observers 0 index is Particle, next is ParentTransform
	};

	class CameraHandle : public StorageData<StorageTable::Camera::Storage>
	{
	public:
		virtual ~CameraHandle() = 0;

		void Register(uint32_t* idOut) {
			using func_t = decltype(&CameraHandle::Register);
			REL::Relocation<func_t> func{ REL::ID(94969) };
			return func(this, idOut);
		}

		static NiCamera* GetCamera(uint32_t id) {
			return Get()->storageData.pWriterColumnData->pHostOnlyMemory->pTableData[id & 0xFFFFFF];
		}

		static CameraHandle* Get() {
			static REL::Relocation<CameraHandle**> singleton{ REL::ID(772608) };
			return *singleton;
		}
	};

	static_assert(sizeof(CameraHandle) == 0x138);

}
