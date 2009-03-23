#ifndef NORMALCOUNTER_H
#define NORMALCOUNTER_H

#include "Counter.h"

class NormalCounter : public Counter
{
public:
    NormalCounter();
    virtual ~NormalCounter();

    ///////////////////////////////////////////////////////////////


protected:

    /**
    * counting source file.
    *
    * @param strFilePath source file path
    * @param nLines total lines
    * @param nCodeLines total code lines
    * @param nCommentLines comment lines
    * @param nBlankLines blank lines
    */
    virtual void countingSourceFile( wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines ) = 0;


private:
};

#endif // NORMALCOUNTER_H
