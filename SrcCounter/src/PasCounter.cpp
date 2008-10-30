/**
 * @file PasCounter.cpp
 * @brief implementation of the PascalCounter class.
 * @author Boom( boomworks@hotmail.com )
 * @author Copyright(C) 2004-2005 BoomWorks.Net , All right reserved.
 * @date 2005-12-10
 * $Revision: $
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

PascalCounter::PascalCounter()
{}

PascalCounter::~PascalCounter()
{}

void PascalCounter::countingSourceFile( wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines )
{
    // get file size
//	nSize = file.Len();

    //////////////////////////////////////////////////////////////////////////

    BOOL bHasSettedCommentFlag	= FALSE;	//œA•Ë˜Î—RÄ‰Š•´ šo"{"•¯TRUE, "}"•¯FALSE
    BOOL bHasSettedQuatoFlag	= FALSE;	//œuŒ›Š¬—RÄ‰Š•´ •ÕŠÌ™¹˜Îšo“ä•ûŒô"•¯TRUE, ˜a™¹˜Îšo“ä•ûŒô"•¯FALSE

    wxString bufCurLine;
    for ( bufCurLine = file.GetFirstLine(); !file.Eof(); bufCurLine = file.GetNextLine() )
    {
        //BOOL bStatisticedAsComment	= FALSE;	//‰]˜Îœ——¨œA•Ë˜Î•ÅŒ‘™Ï—RÄ
        //BOOL bStatisticedAsCode		= FALSE;	//‰]˜Îœ——¨Šø‘é˜Î•ÅŒ‘™Ï—RÄ

        nLines++;

        bufCurLine.Trim(false); //˜gJ—Âü—V‹ctŒï’›Ä‰Œ›”£‹”

        if ( bufCurLine.Len() == 0 )
        { //—¨tˆÕ˜Î OK
            nBlankLines++;
            continue;
        }

        //////////////////////////////////////////////////////////////////////////

        bufCurLine.Trim();
        int nLen = bufCurLine.Len();
        if ( !bHasSettedCommentFlag
                && bufCurLine[ 0 ]			==  _T( '{' )
                && bufCurLine[ nLen - 1 ]	==  _T( '}' ))
        {
            nCommentLines++;
            continue;
        }
        else if ( !bHasSettedCommentFlag
                  && bufCurLine.Find( _T( "{" )) != -1
                  && bufCurLine.Find( _T( "}" )) != -1 )
        {
            nCommentLines++;
            nCodeLines++;
            continue;
        }

        if ( !bHasSettedCommentFlag )
        {
            if ( bufCurLine[0]	== _T( '/' )
                    && bufCurLine[1]		== _T( '/' ) )
            {
                nCommentLines++;
                continue;
            }
            else if ( bufCurLine.Find( _T( "//" )) != -1 )
            { // šÛ‰¹[‘Å ™¹˜Îíšo''‹c—È–à
                nCommentLines++;
                nCodeLines++;
                continue;
            }
        }

        //////////////////////////////////////////////////////////////////////////
        if ( !bHasSettedCommentFlag
                && bufCurLine[0] == _T('{')
                && bufCurLine.Find( _T( '}' )) == -1 )
        {
            bHasSettedCommentFlag = TRUE;
            nCommentLines++;
            continue;
        }

        if (bHasSettedCommentFlag
                && bufCurLine[nLen - 1] != _T('}') )
        {
            nCommentLines++;
            continue;
        }
        else if ( bHasSettedCommentFlag
                  && bufCurLine[nLen - 1] == _T('}'))
        {
            bHasSettedCommentFlag = FALSE;
            nCommentLines++;
            continue;
        }

        //////////////////////////////////////////////////////////////////////////

        if ( bufCurLine.Find( _T( "//" ) ) == -1
                && bufCurLine.Find( _T( "{" ) ) == -1
                && bufCurLine.Find( _T( "}" ) ) == -1 )
        { //”å›‰]˜ÎŒ÷‰]Ë—ÜœA•ËŒ›Ešğ™¨‰¹•ÅœA•Ë˜ÎE™¨‰¹•ÅŠø‘é˜Î
            if ( bHasSettedCommentFlag )
            {
                nCommentLines++;
                continue;
            }
            else
            {
                nCodeLines++;
                continue;
            }
        }

        //////////////////////////////////////////////////////////////////////////

        if ( bufCurLine.Find( _T( "//" ) ) == 0 && !bHasSettedCommentFlag && !bHasSettedQuatoFlag )
        { // single line comment
            nCommentLines++;
            continue;
        }

        //////////////////////////////////////////////////////////////////////////


        //////////////////////////////////////////////////////////////////////////

    }// End for
}
