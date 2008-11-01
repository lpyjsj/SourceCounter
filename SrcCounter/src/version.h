#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "01";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2008";
	static const double UBUNTU_VERSION_STYLE = 8.11;
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";
	
	//Standard Version Type
	static const long MAJOR = 2;
	static const long MINOR = 0;
	static const long BUILD = 10;
	static const long REVISION = 61;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 172;
	#define RC_FILEVERSION 2,0,10,61
	#define RC_FILEVERSION_STRING "2, 0, 10, 61\0"
	static const char FULLVERSION_STRING[] = "2.0.10.61";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 10;
	

}
#endif //VERSION_H
