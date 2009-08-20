#include "XmlCounter.h"

wxString XmlCounter::ms_strType = _T("Xml");

XmlCounter::XmlCounter()
{
	//ctor
}

XmlCounter::~XmlCounter()
{
	//dtor
}

void XmlCounter::countingSourceFile(wxTextFile& file, int& nLines, int& nCodeLines,
                                     int& nCommentLines, int& nCodeCommentLines, int& nBlankLines )
{
    countLines(file, m_pRule, nLines, nCodeLines, nCommentLines, nCodeCommentLines, nBlankLines );
}
