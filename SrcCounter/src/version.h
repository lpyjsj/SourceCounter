#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "03";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2009";
	static const double UBUNTU_VERSION_STYLE = 9.04;
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";
	
	//Standard Version Type
	static const long MAJOR = 2;
	static const long MINOR = 4;
	static const long BUILD = 61;
	static const long REVISION = 99;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 474;
	#define RC_FILEVERSION 2,4,61,99
	#define RC_FILEVERSION_STRING "2, 4, 61, 99\0"
	static const char FULLVERSION_STRING[] = "2.4.61.99";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 58;
	

}
#endif //VERSION_H
