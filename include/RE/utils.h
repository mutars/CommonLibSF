#pragma once

namespace RE
{
	template <int s, int t>
	struct check_size
	{
		static_assert(s == t, "wrong size");
	};
}
