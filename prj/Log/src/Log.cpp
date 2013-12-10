//=============================================================================
/**
  @file   Log.cpp
  @brief  This file contains the function defenitions of class Log.

  The log system writes errors, warnings, infos and debug messages into
  a HTML file. For the log system to write debug messages, there must
  be set the varbiable Log::debug_mode_ to true. Otherwise the log
  system will ignore all messages sent by Log::LOG_DEBUG().
  To get a proper HTML file, one has to be sure to call the
  deconstructor of this class. To write messages use following
  functions:
  Log::LOG_DEBUG(std::string msg),
  Log::LOG_INFO(std::string msg),
  Log::LOG_WARNING(std::string msg) and
  Log::LOG_ERROR(std::string msg, string id).
  For convenience, there are global functions with the same names. So
  instead of writing
  @code
  Log->LOG_INFO("this works fine");
  @endcode
  you may write
  @code
  LOG_INFO("this works fine");
  @endcode
  @author	drubner, mwilhelm
  @date	  2012-08-14
**/
//=============================================================================
//	Include
//=============================================================================
//#include <sstream>
#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

#include "Log.h"

//=============================================================================
// STATIC MEMBER DEFINITIONS
//=============================================================================
Log* Log::instance_ = 0;

//=============================================================================
// NAMESPACES
//=============================================================================
using namespace std;

//=============================================================================
//	(DE)CONSTRUCTORS
//=============================================================================
/**
@fn     Log::Log()
@brief  Default constructor
**/
//=============================================================================
Log::Log() {
  cout << "initializing log system" << endl;
  cout << "please set_file_path_and_name()" << endl;
}

//=============================================================================
/**
@fn     Log::~Log()
@brief  Deconstructor
**/
//=============================================================================
Log::~Log() {
  stopLog();
}

//=============================================================================
//	FUNCTIONS
//=============================================================================
/**
  @fn     Log::getInstance()
  @brief  Returns a singleton instance of Log.

  When a new instance of Log was created during the call of this function,
  you should call set_file_path_and_name() right after it. At least you should
  call set_file_path_and_name() before your first loggin attempt.
  @return Pointer to a singleton Log instance.
**/
//=============================================================================
Log* Log::getInstance() {
  if(instance_ == NULL) {
    instance_ = new Log();
  }
  return instance_;
}

//=============================================================================
/**
  @fn     Log::set_file_path_and_name
  @brief  Sets the path and file name of the file where the logs are written.

  This method has to get called before the first logging. As long as this
  function wasn't called with valid parameters, the initialisation of the 
  log system is not completed. 
  @param  &path       new path
  @param  &file_name  new file name
**/
//=============================================================================
void Log::set_file_path_and_name(std::string &path, std::string &file_name) {
  file_name_ = file_name;
  path_ = path;
  startLog();
}

//=============================================================================
/**
  @fn     Log::startLog()
  @brief  Makes log file ready for logging operations
  @return 1 = OK   0 = Error
**/
//=============================================================================
bool Log::startLog() {
  while(path_.substr(path_.length() - 1, 1).compare("\\") == 0) {
    path_.pop_back();
  }
  path_.push_back('\\');
  full_path_ = path_;
  full_path_.append(file_name_);

  cout << "trying to log into file " << full_path_ << endl;

  std::ofstream file_stream;
  CreateDirectoryA(path_.c_str(), NULL);
  file_stream.open(full_path_, std::fstream::trunc | std::fstream::out);

  if(file_stream.is_open()) {
    cout << "log system initialised successfully" << endl;
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
  else {
    cout << "initializing log system FAILED!" << endl;
    //cout << "Couldn't open output file stream" << endl;
    cout << "failbit " << file_stream.fail() << endl;
    cout << "badlbit " << file_stream.bad() << endl;
    cout << "eofbit " << file_stream.eof() << endl;
    return 0;
  }
  
  file_stream.flush();
  file_stream.close();
  return 1;
}

//=============================================================================
/**
  @fn     Log::stopLog()
  @brief  Stops logging
  @return 1 = OK   0 = Error
**/
//=============================================================================
bool Log::stopLog() {
  std::ofstream file_stream;
  file_stream.open(full_path_, std::fstream::in | std::fstream::app);

  if(file_stream.is_open()) {
    file_stream << "</table></body></html>\n";
    file_stream.flush();
  }

  file_stream.close();
  return 1;
}

//=============================================================================
/**
  @fn     Log::logIt
  @brief  Logs a message msg.
  @param  msg	Message to log
  @return 1 = OK   0 = Error
**/
//=============================================================================
bool Log::logIt(std::string msg) {
  std::ofstream file_stream;
  file_stream.open(full_path_, std::fstream::in | std::fstream::app);

  if(file_stream.is_open()) {
    file_stream << "<tr><th>" << currentTime() << "</th>" << msg << "\n";
    file_stream.flush();
    file_stream.close();
    return 1;
  }
  else {
    return 0;
  }
}

//=============================================================================
/**
  @fn     Log::currentTime()
  @brief  Returns a timestamp of time in std::string format.
  @return Returns a timestamp of time in std::string format.
**/
//=============================================================================
std::string Log::currentTime() {
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
  @fn     Log::currentDate()
  @brief  Returns a timestamp of date in std::string format.
  @return Returns a timestamp of date in std::string format.
**/
//=============================================================================
std::string Log::currentDate() {
  time_t raw_time;
  struct tm time_info;

  time(&raw_time);
  localtime_s(&time_info, &raw_time);

  std::stringstream string_stream;
  string_stream << (time_info.tm_year + 1900) << "-" << time_info.tm_mon << "-"
    << time_info.tm_mday;

  return string_stream.str();
}

//=============================================================================
/**
  @fn     Log::LOG_DEBUG()
  @brief  Logs a debug message
  @return 1 = OK,   0 = Error
**/
//=============================================================================
bool Log::LOG_DEBUG(std::string msg) { 
  if(debug_mode_ == true) {
    return logIt("<td class=\"log_debug\">" + msg + "</td>\n");
  }
  else {
    return 0;
  }
}

//=============================================================================
/**
  @fn     Log::LOG_INFO()
  @brief  Logs an info message
  @return 1 = OK,   0 = Error
**/
//=============================================================================
bool Log::LOG_INFO(std::string msg) { 
  return logIt("<td class=\"log_info\">" + msg + "</td>\n"); 
}

//=============================================================================
/**
  @fn     Log::LOG_WARNING()
  @brief  Logs a warning
  @return 1 = OK,   0 = Error
**/
//=============================================================================
bool Log::LOG_WARNING(std::string msg) { 
  return logIt("<td class=\"log_warning\">" + msg + "</td>\n"); 
}

//=============================================================================
/**
  @fn     Log::LOG_ERROR()
  @brief  Logs an error message and id
  @return 1 = OK,   0 = Error
**/
//=============================================================================
bool Log::LOG_ERROR(std::string msg, std::string id) { 
  return logIt("<td class=\"log_error\">" + msg + "<" + id + "></td>\n"); 
}

//LOG_API void LOG_MSGBOXERR(LPCSTR msg, LPCSTR id) { MessageBox(NULL, msg, id, MB_OK | MB_ICONERROR); }




