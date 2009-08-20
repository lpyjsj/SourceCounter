#include "ShellCounter.h"

wxString ShellCounter::ms_strType = _T("Shell");

ShellCounter::ShellCounter()
{
	//ctor
}

ShellCounter::~ShellCounter()
{
	//dtor
}

void ShellCounter::countingSourceFile(wxTextFile& file, int& nLines, int& nCodeLines,
                                     int& nCommentLines, int& nCodeCommentLines, int& nBlankLines )
{
    countLines(file, m_pRule, nLines, nCodeLines, nCommentLines, nCodeCommentLines, nBlankLines );
}
