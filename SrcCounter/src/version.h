#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "20";
	static const char MONTH[] = "08";
	static const char YEAR[] = "2009";
	static const double UBUNTU_VERSION_STYLE = 9.08;
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";
	
	//Standard Version Type
	static const long MAJOR = 2;
	static const long MINOR = 4;
	static const long BUILD = 90;
	static const long REVISION = 1;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 575;
	#define RC_FILEVERSION 2,4,90,1
	#define RC_FILEVERSION_STRING "2, 4, 90, 1\0"
	static const char FULLVERSION_STRING[] = "2.4.90.1";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 91;
	

}
#endif //VERSION_H
