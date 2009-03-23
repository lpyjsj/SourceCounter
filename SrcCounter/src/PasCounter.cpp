/**
 * @file PasCounter.cpp
 * @brief implementation of the PascalCounter class.
 * @author Boom( boomworks@hotmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * $Author: $
 * $Date: $
 * $Revision: $
 * $ID: $
 */

#include <wx/textfile.h>

#include "PasCounter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

wxString PascalCounter::ms_strType = _T("Pascal");

PascalCounter::PascalCounter()
{}

PascalCounter::~PascalCounter()
{}

void PascalCounter::countingSourceFile(wxTextFile& file, int& nLines, int& nCodeLines,
                                     int& nCommentLines, int& nCodeCommentLines, int& nBlankLines  )
{
    countLines(file, m_pRule, nLines, nCodeLines, nCommentLines, nCodeCommentLines, nBlankLines );
}
