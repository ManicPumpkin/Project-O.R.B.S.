//=============================================================================
/**
  @file	Log.cpp
  @brief	This file includes all functions of Log class.
  @author	drubner, mwilhelm
  @date	Created 2012-08-14
**/
//=============================================================================
//	Include
//=============================================================================
//#include <sstream>
#include "stdafx.h"

#include <fstream>
#include <sstream>
#include <time.h>



//TODO del include
#include <iostream>

#include "Log.h"

using namespace std;

//=============================================================================
//	(DE)CONSTRUCTORS
//=============================================================================
/**
@fn     Log
@brief  Constructor
**/
//=============================================================================
LOG_API Log::Log(std::string &path, std::string &file_name) {
  file_name_ = file_name;
  path_ = path;
  startLog();
}

//=============================================================================
/**
@fn     ~Log
@brief  Deconstructor
**/
//=============================================================================
LOG_API Log::~Log() {
  stopLog();
}

//=============================================================================
//	Functions
//=============================================================================
/**
  @fn     startLog()
  @brief  Makes log file ready for logging operations
  @return bool  1 = OK   0 = Error
**/
//=============================================================================
bool Log::startLog() {
  while(path_.substr(path_.length() - 1, 1).compare("\\") == 0) {
    path_.pop_back();
  }
  path_.push_back('\\');
  full_path_ = path_;
  full_path_.append(file_name_);

  std::ofstream file_stream;
  file_stream.open(full_path_, std::fstream::trunc);

  if(file_stream.is_open()) {
    file_stream << "<html><head>\n";
    file_stream << "<title>" << file_name_ << "</title>\n";
    file_stream << "<link rel=\"stylesheet\" href=\"logfile.css\">\n";
    file_stream << "</head><body>\n";
    file_stream << "<hr class=\"divide_double\" />\n";
    file_stream << "<p id=\"header\">" << file_name_ << "</p>\n";
    //file_stream << "<hr class=\"divide_simple\" />\n\n";
    //file_stream << "<table id=\"game_info\">\n";
    //file_stream << "<tr><th>window class name</th><td>:</td><td>" << g_wndName << "</td></tr>\n";
    //file_stream << "<tr><th>window name</th><td>:</td><td>" << g_wndTitle << "</td></tr>\n";
    //file_stream << "<tr><th>color</th><td>:</td><td>" << g_bitsColor << "</td></tr>\n";
    //file_stream << "<tr><th>depth</th><td>:</td><td>" << g_bitsDepth << "</td></tr>\n";
    //file_stream << "<tr><th>alpha</th><td>:</td><td>" << g_bitsAlpha << "</td></tr>\n";
    //file_stream << "</table>\n";
    file_stream << "<hr class=\"divide_simple\" />\n\n";
    file_stream << "<table id=\"time\">\n";
    file_stream << "<tr><th>time</th><td>:</td><td>" << currentTime() << "</td></tr>\n";
    file_stream << "<tr><th>date</th><td>:</td><td>" << currentDate() << "</td></tr>\n";
    file_stream << "</table>\n";
    file_stream << "<hr class=\"divide_double\" />\n";
    file_stream << "<table id=\"log\">\n";
  }

  file_stream.close();
  return 1;
}

//=============================================================================
/**
  @fn     stopLog()
  @brief  Stops logging
  @return bool  1 = OK   0 = Error
**/
//=============================================================================
bool Log::stopLog() {
  std::ofstream file_stream;
  file_stream.open(full_path_, std::fstream::in | std::fstream::app);

  if(file_stream.is_open())
    file_stream << "</table></body></html>\n";

  file_stream.close();
  return 1;
}

//=============================================================================
/**
  @fn     logIt
  @brief  Logs a message msg.
  @param  msg	Message to log
  @return bool  1 = OK   0 = Error
**/
//=============================================================================
/*LOG_API*/ bool Log::logIt(std::string msg) {
  std::ofstream file_stream;
  file_stream.open(full_path_, std::fstream::in | std::fstream::app);

  if(file_stream.is_open())
    file_stream << "<tr><th>" << currentTime() << "</th>" << msg << "\n";

  file_stream.close();
  return 1;
}

//=============================================================================
/**
  @fn     CurrentTime()
  @brief  Returns a timestamp of time in std::string format.
  @return std::string
**/
//=============================================================================
/*LOG_API*/ std::string Log::currentTime() {
  time_t		raw_time;
  struct tm	time_info;
  char		time_buffer[16] = "HH:MM:SS";

  time(&raw_time);
  localtime_s(&time_info, &raw_time);
  strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", &time_info);

  return time_buffer;
}

//=============================================================================
/**
  @fn     Log::fCurrentDate()
  @brief  Returns a timestamp of date in std::string format.
  @return std::string
**/
//=============================================================================
/*LOG_API*/ std::string Log::currentDate() {
  time_t raw_time;
  struct tm time_info;

  time(&raw_time);
  localtime_s(&time_info, &raw_time);

  std::stringstream string_stream;
  string_stream << (time_info.tm_year + 1900) << "-" << time_info.tm_mon << "-"
    << time_info.tm_mday;

  return string_stream.str();
}

LOG_API void Log::LOG_DEBUG(std::string msg) { if(/*DEBUG_MODE == */true) logIt("<td class=\"log_debug\">" + msg + "</td>\n"); }
LOG_API void Log::LOG_INFO(std::string msg) { logIt("<td class=\"log_info\">" + msg + "</td>\n"); }
LOG_API void Log::LOG_WARNING(std::string msg) { logIt("<td class=\"log_warning\">" + msg + "</td>\n"); }
LOG_API void Log::LOG_ERROR(std::string msg, std::string id) { logIt("<td class=\"log_error\">" + msg + "<" + id + "></td>\n"); }
//LOG_API void LOG_MSGBOXERR(LPCSTR msg, LPCSTR id) { MessageBox(NULL, msg, id, MB_OK | MB_ICONERROR); }