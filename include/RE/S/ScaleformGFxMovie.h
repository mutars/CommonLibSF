#pragma once

#include "RE/S/ScaleformGFxStateBag.h"
#include "RE/S/ScaleformPtr.h"

namespace RE::Scaleform::GFx
{
	class ASMovieRootBase;

	class __declspec(novtable) Resource
	{
	public:
		virtual ~Resource() = default;  // 00

		// add
		virtual void* GetKey();                       // 01
		virtual std::uint32_t GetResourceTypeCode() const;  // 02
		virtual void* GetResourceReport();        // 03

		// members
		uintptr_t refCount;  // 08
		void* lib;              // 10
	};

	class __declspec(novtable) MovieDef :
		public Resource,  // 00
		public StateBag   // 18
	{
	public:

		// add
		virtual std::uint32_t GetVersion() const = 0;       // 04
		virtual std::uint32_t GetLoadingFrame() const = 0;  // 05
		virtual float         GetWidth() const = 0;         // 06
		virtual float         GetHeight() const = 0;        // 07
		virtual std::uint32_t GetFrameCount() const = 0;    // 08
		virtual float         GetFrameRate() const = 0;     // 09
		virtual std::uintptr_t GetFrameRect() const = 0;     // 0A
		virtual std::uint32_t GetSWFFlags() const = 0;      // 0B
		virtual const char*   GetFileURL() const = 0;
	};

	class Movie :
		public RefCountBase<Movie, 327>,  // 00
		public StateBag                   // 10
	{
	public:
		SF_RTTI_VTABLE(Scaleform__GFx__Movie);

		enum class SetVarType : std::uint32_t
		{
			kNormal,
			kSticky,
			kPermanent
		};

		enum class SetArrayType : std::uint32_t
		{
			kInt,
			kDouble,
			kFloat,
			kString,
			kStringW,
			kValue
		};

		virtual ~Movie() = default;  // 01
		virtual MovieDef* GetMovieDef() const = 0;                                                                                                                       // 01

		// members
		Ptr<ASMovieRootBase> asMovieRoot;
	};

	class MovieImpl :
		public Movie  // 00
	{
	public:
		SF_RTTI_VTABLE(Scaleform__GFx__MovieImpl);

		virtual ~MovieImpl() = default;  // 00
		virtual MovieDef* GetMovieDef() const = 0;
	};
}
