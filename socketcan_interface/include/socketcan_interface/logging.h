#ifndef SOCKETCAN_INTERFACE_LOGGING_H
#define SOCKETCAN_INTERFACE_LOGGING_H

#include <console_bridge/console.h>
#include <sstream>

#define ROSCANOPEN_LOG(file, line, level, args) { std::stringstream sstr; sstr << args; console_bridge::getOutputHandler()->log(sstr.str(), level, file, line); }

#define ROSCANOPEN_ERROR(args) ROSCANOPEN_LOG(__FILE__, __LINE__, console_bridge::CONSOLE_BRIDGE_LOG_ERROR, args)
#define ROSCANOPEN_INFO(args) ROSCANOPEN_LOG(__FILE__, __LINE__, console_bridge::CONSOLE_BRIDGE_LOG_INFO, args)
#define ROSCANOPEN_WARN(args) ROSCANOPEN_LOG(__FILE__, __LINE__, console_bridge::CONSOLE_BRIDGE_LOG_WARN, args)
#define ROSCANOPEN_DEBUG(args) ROSCANOPEN_LOG(__FILE__, __LINE__,console_bridge::CONSOLE_BRIDGE_LOG_DEBUG, args)

inline __attribute__ ((deprecated)) void roscanopen_log_deprecated(const std::string s, const char* f, int l) { console_bridge::getOutputHandler()->log(s, console_bridge::CONSOLE_BRIDGE_LOG_ERROR, f, l); }
#define LOG(args) { std::stringstream sstr; sstr << args; roscanopen_log_deprecated(sstr.str(), __FILE__, __LINE__); }
#endif
