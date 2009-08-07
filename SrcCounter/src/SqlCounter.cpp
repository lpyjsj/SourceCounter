#include "SqlCounter.h"

wxString SqlCounter::ms_strType = _T("Sql");

SqlCounter::SqlCounter()
{
	//ctor
}

SqlCounter::~SqlCounter()
{
	//dtor
}

void SqlCounter::countingSourceFile(wxTextFile& file, int& nLines, int& nCodeLines,
                                     int& nCommentLines, int& nCodeCommentLines, int& nBlankLines )
{
    countLines(file, m_pRule, nLines, nCodeLines, nCommentLines, nCodeCommentLines, nBlankLines );
}
