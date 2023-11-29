#pragma once

namespace RE
{
	class IMenu;

	namespace Scaleform
	{
		template <class T>
		class Ptr;
	}

	struct BIUIMenuVisiblePausedBeginEvent;
	struct BIUIMenuVisiblePausedEndEvent;
	struct BSCursorRotationChange;
	struct BSCursorTypeChange;
	struct MenuPauseChangeEvent;
	struct MenuPauseCounterChangeEvent;
	struct TutorialEvent;

	class UI :
		//public BSTSingletonSDM<UI>,
		public BSInputEventReceiver,                             // 000
		public BSTEventSource<MenuOpenCloseEvent>,               // 010
		public BSTEventSource<MenuModeChangeEvent>,              // 038
		public BSTEventSource<MenuPauseChangeEvent>,             // 060
		public BSTEventSource<MenuPauseCounterChangeEvent>,      // 088
		public BSTEventSource<TutorialEvent>,                    // 0B0
		public BSTEventSource<BSCursorTypeChange>,               // 0D8
		public BSTEventSource<BSCursorRotationChange>,           // 100
		public BSTEventSource<BIUIMenuVisiblePausedBeginEvent>,  // 128
		public BSTEventSource<BIUIMenuVisiblePausedEndEvent>     // 150
	{
	public:
		SF_RTTI_VTABLE(UI);

		struct Entry
		{
			BSFixedString unk00;
			IMenu*        unk08;
			uint64_t      unk10;
			uint64_t      unk18;
			uint64_t      unk20;
			uint64_t      unk28;
			uint32_t      unk30;
			uint32_t      unk34;
		};

		struct Map
		{
			uint64_t unk418;
			uint64_t unk420;
			uint64_t unk428;
			uint64_t unk430;
			uint64_t unk438;
			uint64_t unk440;
			Entry*   entries;
			uint64_t capacity;
			uint64_t remaining;
		};

		template <class T>
		[[nodiscard]] auto GetEventSource()
		{
			return static_cast<BSTEventSource<T>*>(this);
		}

		inline static UI* GetSingleton()
		{
			static REL::Relocation<UI**> singleton{ ID::UI::singleton };
			return *singleton;
		}

		bool IsMenuOpen(const BSFixedString& a_name)
		{
			using func_t = decltype(&UI::IsMenuOpen);
			REL::Relocation<func_t> func{ ID::UI::IsMenuOpen };
			return func(this, a_name);
		}

		template <class T>
		void RegisterSink(BSTEventSink<T>* a_sink)
		{
			GetEventSource<T>()->RegisterSink(a_sink);
		}

		template <class T>
		void UnregisterSink(BSTEventSink<T>* a_sink)
		{
			GetEventSource<T>()->UnregisterSink(a_sink);
		}

		std::uint8_t                    pad178[0x278];  // 178
		BSTArray<Scaleform::Ptr<IMenu>> menuStack;      // 3F0
		std::uint8_t                    pad02[0x18];
		Map                             menus;  // 418
		void*                           unk460_4F8[(0x4F8 - 0x460) >> 3];
		uint16_t                        unk4F8;
		bool                            menusVisible;  // 4FA
	};
	static_assert(offsetof(UI, menuStack) == 0x3F0);
	static_assert(offsetof(UI, menus) == 0x418);
	static_assert(offsetof(UI, menusVisible) == 0x4FA);
}
