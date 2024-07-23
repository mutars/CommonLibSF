#pragma once

#include "RE/N/NativeFunctionBase.h"

namespace RE::BSScript
{
	class NativeFunction : public NF_util::NativeFunctionBase
	{
	public:
		NativeFunction() = delete;

		NativeFunction(const char* a_name, const char* a_className, bool a_isStatic, std::uint32_t a_numParams) :
			NativeFunctionBase(a_className, a_name, a_numParams, a_isStatic, false)
		{
		}

		virtual ~NativeFunction()
		{
			using func_t = std::add_pointer_t<void(NativeFunction*)>;
			REL::Relocation<func_t> func{ REL::ID(196398) };
			func(this);
		}

		virtual bool HasStub() const override { return _stub != nullptr; }
		virtual bool MarshallAndDispatch(Variable& a_self, Internal::VirtualMachine& a_vm, std::uint32_t a_stackID, Variable& a_resultValue, const StackFrame& a_stackFrame) override = 0;

	protected:
		std::function<void()> _stub;
	};
}
