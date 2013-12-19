//=============================================================================
/**
  @file	  Log.h
  @brief	This file contains a class for an abstract log system.

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

#pragma warning (disable:4251)

//=============================================================================
// CLASS
//=============================================================================
/**
  @class  Log
  @brief  This class contains all functions for the log system.

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
**/
//=============================================================================
class LOG_API Log {
protected:
  Log();

public:
  ~Log();
  //inline static Log* getInstance() { if (instance_ == NULL) { instance_ = new Log(); } return instance_; }
  static Log* getInstance();
  inline void set_file_path_and_name(std::string &path, std::string &file_name);
  inline bool LOG_DEBUG(std::string msg);
  inline bool LOG_INFO(std::string msg);
  inline bool LOG_WARNING(std::string msg);
  inline bool LOG_ERROR(std::string msg, std::string id);
  //inline LOG_API void LOG_MSGBOXERR(LPCSTR msg, LPCSTR id);

  bool debug_mode_ = false;

protected:

private:
  bool startLog();
  bool stopLog();
  bool logIt(std::string msg);
  std::string currentTime();
  std::string currentDate();

  static Log *instance_;
  std::string file_name_;
  std::string path_;
  std::string full_path_;
};

LOG_API inline bool LOG_DEBUG(std::string msg) { return Log::getInstance()->LOG_DEBUG(msg); }
LOG_API inline bool LOG_INFO(std::string msg) { return Log::getInstance()->LOG_INFO(msg); }
LOG_API inline bool LOG_WARNING(std::string msg) { return Log::getInstance()->LOG_WARNING(msg); }
LOG_API inline bool LOG_ERROR(std::string msg, std::string id) { return Log::getInstance()->LOG_ERROR(msg, id); }