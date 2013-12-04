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

#include "Log.h"

//=============================================================================
//	Functions
//=============================================================================
/**
  @fn     InitializeLog()
  @brief  Makes log file ready for logging operations
  @return bool  1 = OK   0 = Error
**/
//=============================================================================
LOG_API bool InitializeLog() {
  std::ofstream file_stream;
  CreateDirectoryA(LOG_PATH, NULL);
  file_stream.open(LOG_FILEPATH, std::fstream::trunc);

  if(file_stream.is_open()) {
    file_stream << "<html><head>\n";
    file_stream << "<title>" << LOG_FILE << "</title>\n";
    //file_stream << "<link rel=\"stylesheet\" href=\"logfile.css\">\n";
    file_stream << "</head><body>\n";
    /*file_stream << "<hr class=\"divide_double\" />\n";
    file_stream << "<p id=\"header\">" << LOG_FILE << "</p>\n";
    file_stream << "<hr class=\"divide_simple\" />\n\n";
    file_stream << "<table id=\"game_info\">\n";
    file_stream << "<tr><th>window class name</th><td>:</td><td>" << g_wndName << "</td></tr>\n";
    file_stream << "<tr><th>window name</th><td>:</td><td>" << g_wndTitle << "</td></tr>\n";
    file_stream << "<tr><th>color</th><td>:</td><td>" << g_bitsColor << "</td></tr>\n";
    file_stream << "<tr><th>depth</th><td>:</td><td>" << g_bitsDepth << "</td></tr>\n";
    file_stream << "<tr><th>alpha</th><td>:</td><td>" << g_bitsAlpha << "</td></tr>\n";
    file_stream << "</table>\n";*/
    //file_stream << "<hr class=\"divide_simple\" />\n\n";
    file_stream << "<table id=\"time\">\n";
    file_stream << "<tr><th>time</th><td>:</td><td>" << CurrentTime() << "</td></tr>\n";
    file_stream << "<tr><th>date</th><td>:</td><td>" << CurrentDate() << "</td></tr>\n";
    file_stream << "</table>\n";
    //file_stream << "<hr class=\"divide_double\" />\n";
    file_stream << "<table id=\"log\">\n";
  }

  file_stream.close();
  return 1;
}

//=============================================================================
/**
  @fn     StopLog()
  @brief  Stops logging
  @return bool  1 = OK   0 = Error
**/
//=============================================================================
LOG_API bool StopLog() {
  std::ofstream file_stream;
  file_stream.open(LOG_FILEPATH, std::fstream::in | std::fstream::app);

  if(file_stream.is_open())
    file_stream << "</table></body></html>\n";

  file_stream.close();
  return 1;
}

//=============================================================================
/**
  @fn     Log()
  @brief  Log a message into the mFile file
  @param  msg	Message to log
  @return bool  1 = OK   0 = Error
**/
//=============================================================================
/*LOG_API*/ bool Log(std::string msg) {
  std::ofstream file_stream;
  file_stream.open(LOG_FILEPATH, std::fstream::in | std::fstream::app);

  if(file_stream.is_open())
    file_stream << "<tr><th>" << CurrentTime() << "</th>" << msg << "\n";

  file_stream.close();
  return 1;
}

//=============================================================================
/**
  @fn     CurrentTime()
  @brief  Create timestamp of time
  @return std::string tTime
**/
//=============================================================================
/*LOG_API*/ std::string CurrentTime() {
  time_t		raw_time;
  struct tm	time_info;
  char		time_buffer[16] = "HH:MM:SS";

  time(&raw_time);
  localtime_s(&time_info, &raw_time);
  strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", &time_info);

  //return string_stream.str();
  return time_buffer;
}

//=============================================================================
/**
  @fn     Log::fCurrentDate()
  @brief  Create timestamp of date
  @return std::string tDate
**/
//=============================================================================
/*LOG_API*/ std::string CurrentDate() {
  time_t raw_time;
  struct tm time_info;

  time(&raw_time);
  localtime_s(&time_info, &raw_time);

  std::stringstream string_stream;
  string_stream << (time_info.tm_year + 1900) << "-" << time_info.tm_mon << "-"
    << time_info.tm_mday;

  return string_stream.str();
}

LOG_API void LOG_DEBUG(std::string msg) { if(DEBUG_MODE == true) Log("<td class=\"log_debug\">" + msg + "</td>\n"); }
LOG_API void LOG_INFO(std::string msg) { Log("<td class=\"log_info\">" + msg + "</td>\n"); }
LOG_API void LOG_WARNING(std::string msg) { Log("<td class=\"log_warning\">" + msg + "</td>\n"); }
LOG_API void LOG_ERROR(std::string msg, std::string id) { Log("<td class=\"log_error\">" + msg + "<" + id + "></td>\n"); }
//LOG_API void LOG_MSGBOXERR(LPCSTR msg, LPCSTR id) { MessageBox(NULL, msg, id, MB_OK | MB_ICONERROR); }