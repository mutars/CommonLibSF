#pragma once

namespace RE
{
	struct IMovementInterface
	{
	public:
		virtual ~IMovementInterface();  // 00
	};
	static_assert(sizeof(IMovementInterface) == 0x8);

	struct IMovementPlayerControls : public IMovementInterface
	{
	public:
		virtual ~IMovementPlayerControls();  // 00
		virtual void updateLocation(void) = 0;		  // 01
		virtual void unk2(void) = 0;		  // 02
		virtual void unk3(void) = 0;		  // 03
	};
	static_assert(sizeof(IMovementInterface) == 0x8);
}
