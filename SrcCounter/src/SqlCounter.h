#ifndef SQLCOUNTER_H
#define SQLCOUNTER_H

#include "Counter.h"

class SqlCounter : public Counter
{
public:
    SqlCounter();
    virtual ~SqlCounter();

    /**
    * counting source file.
    *
    * @param strFilePath source file path
    * @param nLines total lines
    * @param nCodeLines total code lines
    * @param nCommentLines comment lines
    * @param nBlankLines blank lines
    */
    virtual void countingSourceFile( wxTextFile& file, int& nLines, int& nCodeLines,
                                     int& nCommentLines, int& nCodeCommentLines, int& nBlankLines );
    static wxString ms_strType;

protected:
private:
};

#endif // SQLCOUNTER_H
