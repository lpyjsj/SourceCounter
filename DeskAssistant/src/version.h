#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "27";
	static const char MONTH[] = "12";
	static const char YEAR[] = "2008";
	static const double UBUNTU_VERSION_STYLE = 8.12;
	
	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 1;
	static const long BUILD = 8;
	static const long REVISION = 0;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 362;
	#define RC_FILEVERSION 1,1,8,0
	#define RC_FILEVERSION_STRING "1, 1, 8, 0\0"
	static const char FULLVERSION_STRING[] = "1.1.8.0";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 84;
	

}
#endif //VERSION_H
