/**
  @file   WolrdGenerator.h
  @brief  contains the definition of the class WolrdGenerator as well as the 
          preprocessor directives for exporting and importing classes and
          functions
  @author mwilhelm
  @date   2013-11-27
**/

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the WORLDGENERATOR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// WORLDGENERATOR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef WORLDGENERATOR_EXPORTS
#define WORLDGENERATOR_API __declspec(dllexport)
#else
#define WORLDGENERATOR_API __declspec(dllimport)
#endif

class Universe;
struct ParameterContainer;

/**
  @class WorldGenerator
  @brief represents the entry point of the world generation process. contains
         functions to exchange ParameterContainer with the calling application.
         this class is exported from the WorldGenerator.dll
**/
class WORLDGENERATOR_API WorldGenerator {
  protected:
    WorldGenerator();

  public:
    static /*WORLDGENERATOR_API*/ WorldGenerator* getInstance();
	  ParameterContainer get_world_parameters();
	  bool set_world_parameters(ParameterContainer world_parameters);
	  bool doTheGodJob();

  private:
	  static WorldGenerator *instance_; //!< holds the singleton instance
    Universe *universe_; //!< stores the universe
    ParameterContainer *world_parameters_; //!< parameter container to exchange parameters with the calling application
};

extern WORLDGENERATOR_API int nWorldGenerator;

WORLDGENERATOR_API int fnWorldGenerator(void);
