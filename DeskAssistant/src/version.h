#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "29";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2008";
	static const double UBUNTU_VERSION_STYLE = 8.11;
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 0;
	static const long BUILD = 0;
	static const long REVISION = 85;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 151;
	#define RC_FILEVERSION 1,0,0,85
	#define RC_FILEVERSION_STRING "1, 0, 0, 85\0"
	static const char FULLVERSION_STRING[] = "1.0.0.85";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 55;
	

}
#endif //VERSION_H
