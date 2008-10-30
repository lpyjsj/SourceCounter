/**
 * @file BasCounter.cpp
 * @brief VbsCounter.cpp: implementation of the CVbsCounter class.
 * @author Boom( boomworks@hotmail.com )
 * @author Copyright(C) 2004-2005 BoomWorks.Net , All right reserved.
 * @date 2005-11-25
 * $Revision: $
 */

#include <wx/textfile.h>
#include "BasCounter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BasicCounter* BasicCounter::ms_instance = 0;

BasicCounter::BasicCounter()
{}

BasicCounter::~BasicCounter()
{}

void BasicCounter::countingSourceFile( wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines )
{
	// nSize = file.Len();

	wxString bufRead;

	//while( file.ReadString( bufRead ))
    for ( bufRead = file.GetFirstLine(); !file.Eof(); bufRead = file.GetNextLine() )
	{
		nLines++;

		bufRead.Trim(false);

		if( bufRead.Len() == 0 )
		{
			nBlankLines++;
			continue;
		}

		if( bufRead.Find( _T("'") ) == 0 )
		{
			nCommentLines++;
			continue;
		}

		//
		if( bufRead.Find( _T("'") ) == -1 )
		{
			nCodeLines++;
		}
		else
		{
			switch( m_nLineCountingType )
			{
				case NStatisticAll:
				nCodeLines++;
				nCommentLines++;
				break;

				case NStatisticCodeOnly:
				nCodeLines++;
				break;

				case NStatisticCommentOnly:
				nCommentLines++;
				break;

				default:
				break;
			}
			continue;
		}
	}
}
