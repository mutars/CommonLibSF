#pragma once

namespace RE
{
	enum UIMessage : uint32_t
	{
		kShow = 0,
		kHide = 2
	};

	class UIMessageQueue
	{
	public:
		static UIMessageQueue* GetSingleton()
		{
			REL::Relocation<UIMessageQueue**> singleton{ REL::ID(878637) };
			return *singleton;
		}

		int64_t AddMessage(const BSFixedString& a_menuName, UIMessage a_message)
		{
			using func_t = decltype(&UIMessageQueue::AddMessage);
			REL::Relocation<func_t> func{ REL::ID(187268) };
			return func(this, a_menuName, a_message);
		}
	};
}
