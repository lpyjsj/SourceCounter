#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "08";
	static const char MONTH[] = "12";
	static const char YEAR[] = "2009";
	static const char UBUNTU_VERSION_STYLE[] = "9.12";
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";
	
	//Standard Version Type
	static const long MAJOR = 2;
	static const long MINOR = 5;
	static const long BUILD = 3;
	static const long REVISION = 0;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 616;
	#define RC_FILEVERSION 2,5,3,0
	#define RC_FILEVERSION_STRING "2, 5, 3, 0\0"
	static const char FULLVERSION_STRING[] = "2.5.3.0";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 5;
	

}
#endif //VERSION_H
