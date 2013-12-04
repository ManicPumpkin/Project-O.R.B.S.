//=============================================================================
/**
  @file	Log.h
  @brief	This file contains function declarations and definitions for the 
          logging system.

          The log system writes errors, warnings and other messages into 
          a HTML file. For the log system to work properly there must be made 
          some defines in the first place. These defines are:
          DEBUG_MODE TRUE|FALSE
          LOG_FILE file_name
          LOG_PATH relative_or_absolute_path
          To get a proper HTML file, one has to call InitializeLog() before
          writing messages and StopLog() after the last message. To write
          messages use following functions:
          LOG_DEBUG(string msg)
          LOG_INFO(string msg)
          LOG_WARNING(string msg
          LOG_ERROR(string msg, string id)

  @author	drubner, mwilhelm
  @date Created at 2012-08-15
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
// INCLUDES
//=============================================================================
//#include <string.h>

//=============================================================================
//	DEFINES
//=============================================================================
#define LOG_FILE "logfile.html"
#define LOG_PATH ".\\log\\"
#define LOG_FILEPATH			LOG_PATH LOG_FILE
#define DEBUG_MODE true

//=============================================================================
//	FUNCTIONS
//=============================================================================
LOG_API bool	InitializeLog();
LOG_API bool	StopLog();
/*LOG_API*/ bool	Log(std::string msg);
///*LOG_API*/ bool	Log(std::string msg, std::string space);
/*LOG_API*/ std::string			CurrentTime();
/*LOG_API*/ std::string			CurrentDate();

//=============================================================================
//	INLINE
//=============================================================================
/*inline*/ LOG_API void LOG_DEBUG(std::string msg);
/*inline*/ LOG_API void LOG_INFO(std::string msg);
/*inline*/ LOG_API void LOG_WARNING(std::string msg);
/*inline*/ LOG_API void LOG_ERROR(std::string msg, std::string id);
//inline LOG_API void LOG_MSGBOXERR(LPCSTR msg, LPCSTR id);