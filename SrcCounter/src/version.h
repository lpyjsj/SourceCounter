#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "01";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2009";
	static const double UBUNTU_VERSION_STYLE = 9.04;
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";
	
	//Standard Version Type
	static const long MAJOR = 2;
	static const long MINOR = 4;
	static const long BUILD = 53;
	static const long REVISION = 43;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 462;
	#define RC_FILEVERSION 2,4,53,43
	#define RC_FILEVERSION_STRING "2, 4, 53, 43\0"
	static const char FULLVERSION_STRING[] = "2.4.53.43";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 50;
	

}
#endif //VERSION_H
