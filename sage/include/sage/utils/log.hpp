#ifndef SAGE_LOG_HPP
#define SAGE_LOG_HPP

#include "sage/core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h" // For logging user-defined classes & structs.

namespace sage {

  class SAGE_API Log {
   private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;

   public:
    static void init();
    inline static std::shared_ptr<spdlog::logger>& getCoreLogger() {
      return s_CoreLogger;
    }
    inline static std::shared_ptr<spdlog::logger>& getClientLogger() {
      return s_ClientLogger;
    }

  };

}  // namespace sage

// Core log macros.
#ifdef SAGE_DIST  //! Strip out log from distribution builds.
  #define SAGE_CORE_TRACE(...)
  #define SAGE_CORE_INFO(...)
  #define SAGE_CORE_WARN(...)
  #define SAGE_CORE_ERROR(...)
  #define SAGE_CORE_FATAL(...)
#else
  #define SAGE_CORE_TRACE(...)      ::sage::Log::getCoreLogger()->trace(__VA_ARGS__)
  #define SAGE_CORE_INFO(...)       ::sage::Log::getCoreLogger()->info(__VA_ARGS__)
  #define SAGE_CORE_WARN(...)       ::sage::Log::getCoreLogger()->warn(__VA_ARGS__)
  #define SAGE_CORE_ERROR(...)      ::sage::Log::getCoreLogger()->error(__VA_ARGS__)
  #define SAGE_CORE_FATAL(...)      ::sage::Log::getCoreLogger()->fatal(__VA_ARGS__)
#endif

// Client log macros.
#define SAGE_TRACE(...)              ::sage::Log::getClientLogger()->trace(__VA_ARGS__)
#define SAGE_INFO(...)               ::sage::Log::getClientLogger()->info(__VA_ARGS__)
#define SAGE_WARN(...)               ::sage::Log::getClientLogger()->warn(__VA_ARGS__)
#define SAGE_ERROR(...)              ::sage::Log::getClientLogger()->error(__VA_ARGS__)
#define SAGE_FATAL(...)              ::sage::Log::getClientLogger()->fatal(__VA_ARGS__)

#endif  // !SAGE_LOG_HPP
