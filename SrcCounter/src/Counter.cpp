#include "Counter.h"

Counter::Counter()
{
    //ctor
}

Counter::~Counter()
{
    //dtor
}
void Counter::Counting(CountingFileInfo& countingFileInfo, CountingParam& countingParam)
{
	m_nLineCountingType = countingParam.m_settingParam.m_nCountingMethodType;

	//////////////////////////////////////////////////////////////////////////
	int nSize			= 0;
	int nLines			= 0;
	int nCodeLines		= 0;
	int nCommentLines	= 0;
	int nBlankLines		= 0;

    ///////////////////////////////////////////////////////////////////
    wxTextFile file;
    if (!file.Open(countingFileInfo.m_strFileFullPath, wxConvISO8859_1))
    {
        return;
    }

	//////////////////////////////////////////////////////////////////////////
	countingSourceFile( file, nSize, nLines, nCodeLines, nCommentLines, nBlankLines );

	//////////////////////////////////////////////////////////////////////////
	countingFileInfo.m_nSize				= nSize;
	countingFileInfo.m_nTotalStatement		= nLines;
	countingFileInfo.m_nCodeStatement		= nCodeLines;
	countingFileInfo.m_nCommentStatement	= nCommentLines;
	countingFileInfo.m_nBlankStatement		= nBlankLines;

	///////////////////////////////////////////////////////////////////
	file.Close();
}

//////////////////////////////////////////////////////////////////////////
