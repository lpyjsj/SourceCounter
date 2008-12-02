#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "02";
	static const char MONTH[] = "12";
	static const char YEAR[] = "2008";
	static const double UBUNTU_VERSION_STYLE = 8.12;
	
	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 1;
	static const long BUILD = 3;
	static const long REVISION = 15;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 320;
	#define RC_FILEVERSION 1,1,3,15
	#define RC_FILEVERSION_STRING "1, 1, 3, 15\0"
	static const char FULLVERSION_STRING[] = "1.1.3.15";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 57;
	

}
#endif //VERSION_H
