#pragma once

#ifdef MATHLIB_EXPORTS
	#define LIB_API __declspec(dllexport)
	#define EXPLICIT_EXPORT
#else
	#define EXPLICIT_EXPORT extern
	#ifndef _LIB
		#define LIB_API __declspec(dllimport)
	#else
		#define LIB_API
	#endif //!LIB
#endif // MATHLIB_EXPORTS