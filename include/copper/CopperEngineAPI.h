///////////////////////////////////////////////////////////////////////////////
// Plugin architecture                                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef COPPER_ENGINE_API_H
#define COPPER_ENGINE_API_H

// ------------------------------------------------------------------------- //

// Platform recognition
#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
  #define COPPER_ENGINE_WINRT 1
#elif defined(WIN32) || defined(_WIN32)
  #define COPPER_ENGINE_WIN32 1
#else
  #define COPPER_ENGINE_LINUX 1
#endif

// ------------------------------------------------------------------------- //

// Decides whether symbols are imported from a dll (client app) or exported to
// a dll (COPPER_ENGINE library). The COPPER_ENGINE_SOURCE symbol is defined by
// all source files of the library, so you don't have to worry about a thing.
#if defined(_MSC_VER)

  #if defined(COPPER_ENGINE_STATICLIB)
    #define COPPER_ENGINE_API
  #else
    #if defined(COPPER_ENGINE_SOURCE)
      // If we are building the DLL, export the symbols tagged like this
      #define COPPER_ENGINE_API __declspec(dllexport)
    #else
      // If we are consuming the DLL, import the symbols tagged like this
      #define COPPER_ENGINE_API __declspec(dllimport)
    #endif
  #endif

#elif defined(__GNUC__)

  #if defined(COPPER_ENGINE_STATICLIB)
    #define COPPER_ENGINE_API
  #else
    #if defined(COPPER_ENGINE_SOURCE)
      #define COPPER_ENGINE_API __attribute__ ((visibility ("default")))
    #else
      // If you use -fvisibility=hidden in GCC, exception handling and RTTI
      // would break if visibility wasn't set during export _and_ import
      // because GCC would immediately forget all type infos encountered.
      // See http://gcc.gnu.org/wiki/Visibility
      #define COPPER_ENGINE_API __attribute__ ((visibility ("default")))
    #endif
  #endif

#else

  #error Unknown compiler, please implement shared library macros

#endif

// ------------------------------------------------------------------------- //

#endif // COPPER_ENGINE_API_H
