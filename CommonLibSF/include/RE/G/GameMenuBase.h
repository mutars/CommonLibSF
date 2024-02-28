#pragma once

#include "RE/I/IMenu.h"

namespace RE
{
	class GameMenuBase :
		public IMenu  // 00
	{
	public:
		SF_RTTI_VTABLE(GameMenuBase);

		GameMenuBase()
		{
			using func_t = GameMenuBase* (*)(GameMenuBase*);
			REL::Relocation<func_t> func(REL::ID(130577));
			func(this);
		}

		virtual ~GameMenuBase() = default;	// 00

		//override
		virtual uint64_t Unk10() override
		{
			using func_t = decltype(&GameMenuBase::Unk10);
			REL::Relocation<func_t> func(REL::ID(141505));
			return func(this);
		};

		virtual uint64_t Unk11() override
		{
			using func_t = decltype(&GameMenuBase::Unk11);
			REL::Relocation<func_t> func(REL::ID(141506));
			return func(this);
		};

		//add
		virtual bool Unk1B() { return true; }  //1B
	};
}
