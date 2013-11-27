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

// This class is exported from the WorldGenerator.dll
class WORLDGENERATOR_API WorldGenerator {
  protected:
    WorldGenerator();

  public:
    static /*WORLDGENERATOR_API*/ WorldGenerator* getInstance();
	  ParameterContainer get_world_parameters();
	  bool set_world_parameters(ParameterContainer world_parameters);
	  bool doTheGodJob();

  //protected:

  private:
	  static WorldGenerator *instance_;
	  Universe *universe_;
	  ParameterContainer *world_parameters_;
};

extern WORLDGENERATOR_API int nWorldGenerator;

WORLDGENERATOR_API int fnWorldGenerator(void);
