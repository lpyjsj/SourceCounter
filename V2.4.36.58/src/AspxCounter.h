#ifndef ASPXCOUNTER_H
#define ASPXCOUNTER_H

#include "Counter.h"

class AspxCounter : public Counter
{
public:

    AspxCounter();
    virtual ~AspxCounter();

    ///////////////////////////////////////////////////////////////

    /**
    * counting source file.
    *
    * @param strFilePath source file path
    * @param nLines total lines
    * @param nCodeLines total code lines
    * @param nCommentLines comment lines
    * @param nBlankLines blank lines
    */
    virtual void countingSourceFile( wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines );

    static wxString ms_strType;

protected:
private:

	void countingAspx_ver_1(wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines);
	void countingAspx_ver_2(wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines);

};

#endif // ASPXCOUNTER_H
