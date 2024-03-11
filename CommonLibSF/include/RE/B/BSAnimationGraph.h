#pragma once

namespace RE
{
	class BSAnimationGraph :
		public BSIntrusiveRefCounted,
		public BSTEventSource<BSAnimationGraphEvent>,
		public BSTEventSource<BSMovementDataChangedEvent>,
		public BSTEventSource<BSSubGraphActivationUpdate>,
		public BSTEventSource<BSTransformDeltaEvent>
	{
	public:
		virtual ~BSAnimationGraph() override;
		virtual void Unk_01(void) = 0;
		virtual void Unk_02(void) = 0;
		virtual void Unk_03(void) = 0;
		virtual void Unk_04(void) = 0;
		virtual void Unk_05(void) = 0;
		virtual void Unk_06(void) = 0;
		virtual void Unk_07(void) = 0; // update rotation matrix in NiCamera
		virtual void Unk_08(void) = 0;
		virtual void Unk_09(void) = 0;
		virtual void Unk_10(void) = 0;
		virtual void Unk_11(void) = 0;
		virtual void Unk_12(void) = 0;
		virtual void Unk_13(void) = 0;
		virtual void Unk_14(void) = 0;
		virtual void Unk_15(void) = 0;
		virtual void Unk_16(void) = 0;
		virtual void Unk_17(void) = 0;
		virtual void Unk_18(void) = 0;
		virtual void Unk_19(void) = 0;
		virtual void Unk_20(void) = 0;
		virtual void Unk_21(void) = 0;
		virtual void Unk_22(void) = 0;
		virtual void Unk_23(void) = 0;
		virtual void Unk_24(void) = 0;
		virtual void Unk_25(void) = 0;
		virtual void Unk_26(void) = 0;
		virtual void Unk_27(void) = 0;
		virtual void Unk_28(void) = 0;
		virtual void Unk_29(void) = 0;
		virtual void Unk_30(void) = 0;
		virtual void Unk_31(void) = 0;
		virtual void Unk_32(void) = 0;
		virtual void Unk_33(void) = 0;
		virtual void Unk_34(void) = 0;
		virtual void Unk_35(void) = 0;
		virtual void Unk_36(void) = 0;
		virtual void Unk_37(void) = 0;
		virtual void Unk_38(void) = 0;
		virtual void Unk_39(void) = 0;
		virtual void Unk_40(void) = 0;
		virtual void Unk_41(void) = 0;
		virtual void Unk_42(void) = 0;
		virtual void Unk_43(void) = 0;


		
	};
	static_assert(sizeof(BSAnimationGraph) == 0xA8);
}
