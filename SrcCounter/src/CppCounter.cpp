/**
 * @file CppCounter.cpp
 * @brief implementation of the CppCounter class.
 * @author Boom( boomworks@hotmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * @date 2005-12-10
 * $Revision: $
 */

#include <wx/textfile.h>
#include "CppCounter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CppCounter
//////////////////////////////////////////////////////////////////////

wxString CppCounter::ms_strType = _T("C");

CppCounter* CppCounter::ms_instance = 0;

CppCounter::CppCounter()
{}

CppCounter::~CppCounter()
{}

CppCounter* CppCounter::GetInstance()
{
    if ( ms_instance == 0)
    {
        ms_instance = new CppCounter;
    }
    return ms_instance;
}

void CppCounter::countingSourceFile(wxTextFile& file, int& nLines, int& nCodeLines,
                                     int& nCommentLines, int& nCodeCommentLines, int& nBlankLines )
{
    countLines(file, m_pRule, nLines, nCodeLines, nCommentLines, nCodeCommentLines, nBlankLines );
}
