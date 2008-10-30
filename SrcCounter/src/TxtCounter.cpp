/**
 * @file TxtCounter.cpp
 * @brief implementation of the TxtCounter class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 BoomWorks.Net , All right reserved.
 * @date 2005-12-10
 * $Revision: $
 */

#include "TxtCounter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TxtCounter::TxtCounter()
{

}

TxtCounter::~TxtCounter()
{

}

void TxtCounter::countingSourceFile(wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines )
{
    wxString str;
    for ( str = file.GetFirstLine(); !file.Eof(); str = file.GetNextLine() )
    {
        // do something with the current line in str
        nLines++;

        str.Trim(false);
		if( str.Len() == 0 )
		{
			nBlankLines++;
			continue;
		}
    }
}
