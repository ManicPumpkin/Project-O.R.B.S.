//=============================================================================
/**
  @file	  Log.h
  @brief	This file contains a class for an abstract log system.

          The log system writes errors, warnings, infos and debug messages into
          a HTML file. For the log system to write debug messages there must be
          set the varbiable Log::debug_mode_ to true. Otherwise the log system
          will ignore all messages sent by Log::LOG_DEBUG().
          To get a proper HTML file, one has to be sure to call the 
          deconstructor of this class. To write messages use following 
          functions:
          LOG_DEBUG(std::string msg), 
          LOG_INFO(std::string msg), 
          LOG_WARNING(std::string msg), 
          LOG_ERROR(std::string msg, string id).
  @author	drubner, mwilhelm
  @date   2012-08-15
**/
//=============================================================================
// DLL IMPORT/EXPORT DEFINES
//=============================================================================
#ifdef LOG_EXPORTS
#define LOG_API __declspec(dllexport)
#else
#define LOG_API __declspec(dllimport)
#endif

//=============================================================================
// CLASS
//=============================================================================
/**
  @class  Log
  @brief  This class contains all functions for the log system.

          The log system writes errors, warnings, infos and debug messages into
          a HTML file. For the log system to write debug messages there must be
          set the varbiable Log::debug_mode_ to true. Otherwise the log system
          will ignore all messages sent by Log::LOG_DEBUG().
          To get a proper HTML file, one has to be sure to call the
          deconstructor of this class. To write messages use following
          functions:
          LOG_DEBUG(std::string msg), 
          LOG_INFO(std::string msg), 
          LOG_WARNING(std::string msg), 
          LOG_ERROR(std::string msg, string id).
**/
LOG_API class Log {
public:
  bool debug_mode_ = false;

  LOG_API Log(std::string &path, std::string &file_name);
  LOG_API ~Log();
  LOG_API inline void LOG_DEBUG(std::string msg);
  LOG_API inline void LOG_INFO(std::string msg);
  LOG_API inline void LOG_WARNING(std::string msg);
  LOG_API inline void LOG_ERROR(std::string msg, std::string id);
  //inline LOG_API void LOG_MSGBOXERR(LPCSTR msg, LPCSTR id);

protected:

private:
  std::string file_name_;
  std::string path_;
  std::string full_path_;

  bool startLog();
  bool stopLog();
  bool logIt(std::string msg);
  std::string currentTime();
  std::string currentDate();
};