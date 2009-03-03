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

void CppCounter::countingSourceFile(wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines )
{
    // get file size
    // nSize = file.Len();

    //////////////////////////////////////////////////////////////////////////

    BOOL bCommentSet = FALSE; //œA•Ë˜Î—RÄ‰Š•´ šo"/*"•¯TRUE, "*/"•¯FALSE
    BOOL bQuatoSet = FALSE;   //œuŒ›Š¬—RÄ‰Š•´ •ÕŠÌ™¹˜Îšo“ä•ûŒô"•¯TRUE, ˜a™¹˜Îšo“ä•ûŒô"•¯FALSE

    wxString bufRead;


    for ( bufRead = file.GetFirstLine(); !file.Eof(); bufRead = file.GetNextLine() )
    {
        BOOL bStatedComment = FALSE;//‰]˜Îœ——¨œA•Ë˜Î•ÅŒ‘™Ï—RÄ
        BOOL bStatedCode = FALSE;   //‰]˜Îœ——¨Šø‘é˜Î•ÅŒ‘™Ï—RÄ

        nLines++;

        bufRead.Trim(false); //˜gJ—Âü—V‹ctŒï’›Ä‰Œ›”£‹”

        if ( bufRead.Len() ==0 ) //—¨tˆÕ˜Î
        {
            nBlankLines++;
            continue;
        }

        if ( bCommentSet && bufRead.Find( _T("*/") ) == -1 )
        {
            nCommentLines++;
            continue;
        }

        if ( bufRead.Find( _T("//") ) ==-1 && bufRead.Find( _T("/*") ) ==-1 && bufRead.Find( _T("*/") ) ==-1 )
        {//”å›‰]˜ÎŒ÷‰]Ë—ÜœA•ËŒ›Ešğ™¨‰¹•ÅœA•ËŒ›E™¨‰¹•ÅŠø‘é˜Î
            if ( bCommentSet )
            {
                nCommentLines++;
                continue;
            }
            else
            {
                if ( bufRead.Find( _T('"') ) ==-1 )
                {
                    nCodeLines++;
                    continue;
                }
            }
        }

        if ( bufRead.Find( _T("//") ) ==0 && !bCommentSet && !bQuatoSet )
        {
            nCommentLines++;
            continue;
        }

        BOOL bDoubleSlashFound = FALSE;
        BOOL bSplashStarFound = FALSE;

        for (unsigned int i=0; i<bufRead.Len()-1; i++)
        {
            // TCHAR cTemp = bufRead[i];
            if ( bufRead[i] == _T('/') && bufRead[i+1] == _T('/') && !bCommentSet && !bQuatoSet )
            {
                if ( !bStatedComment
                        && ( m_nLineCountingType == NStatisticAll || m_nLineCountingType == NStatisticCommentOnly ))
                {
                    bStatedComment = TRUE;
                    nCommentLines++;
                }
                bDoubleSlashFound = TRUE;
                //i++;//šEŒÁ+1E‹J™°’Zšo•°’SšbŠ¤
                break;
            }
            else if ( bufRead[i] == _T('/') && bufRead[i+1] == _T('*') && !bCommentSet && !bQuatoSet )
            {
                if ( !bStatedComment
                        && ( m_nLineCountingType == NStatisticAll || m_nLineCountingType == NStatisticCommentOnly ))
                {
                    bStatedComment = TRUE;
                    nCommentLines++;
                }
                bCommentSet = TRUE;
                bSplashStarFound = TRUE;
                i++;
            }
            //Ä–ƒŠø‘é˜Î‰w˜éšØbCommentSetw‰t›¬”O
            else if ( bufRead[i] != _T(' ') && bufRead[i] != _T('\t') && !bCommentSet )
            {
                if ( !bStatedCode )
                {
                    bStatedCode = TRUE;
                    nCodeLines++;
                }
                if ( bufRead[i] == _T('\\') )
                {//\›¬ñ‹cœuŒ›™¨–ö
                    i++;
                    continue;
                }
                if ( bufRead[i]=='\'' )
                {
                    if ( bufRead[i+1]=='\\' )
                        i+=2;
                    else
                        i+=1;
                    continue;
                }
                if ( bufRead[i]=='"' )
                {//"‰w˜é™û“î›Ö•ÑEŒÎ˜¹ltzhou
                    bQuatoSet = !bQuatoSet;
                }
            }
            else if ( bufRead[i]=='*' && bufRead[i+1]=='/' && bCommentSet && !bQuatoSet )
            {
                if ( !bStatedComment
                        && ( m_nLineCountingType == NStatisticAll || m_nLineCountingType == NStatisticCommentOnly))
                {
                    bStatedComment = TRUE;
                    nCommentLines++;
                }
                bCommentSet = FALSE;
                bSplashStarFound = TRUE;
                i++;
            }
        }

        if ( bDoubleSlashFound )
        {
            if ( m_nLineCountingType == NStatisticCommentOnly && bStatedCode ) //”å›—RÄŒ\ŒG—¨‹y”û›ÔE”q—K•¯šoŠø‘é˜Îš‹œA•Ë˜ÎEšğ›¹ÄœA•Ë˜Î
            {
                nCodeLines--;
            }

            if ( m_nLineCountingType == NStatisticCodeOnly && !bStatedCode ) //”å›—RÄŒ\ŒG—¨‹y™¹›ÔE”q—²œ——¨Šø‘é˜Î—RÄE’Å’S‰w—¨œA•Ë˜Î
            {
                nCommentLines++;
            }
            continue;
        }

        if ( bufRead[bufRead.Len() -1]=='"'&&!bCommentSet )
        {//”ò’±˜Îœñ™¹Œô•Å"Ešğ‰w‹¦šb²w‰tbQuatoSetEÅŠø‘é˜Î™¹˜ÎEŒ‘šğ‰GŠë
            bQuatoSet = !bQuatoSet;
            if ( !bQuatoSet )
            {
                if ( !bStatedCode )
                {
                    bStatedCode = TRUE;
                    nCodeLines++;
                }
            }
            else
            {
//				CStdioFile fileLog;
//				if( fileLog.Open( m_strLogFile, CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate ) ==TRUE )
//				{
//					wxString strMsg;
//					if( fileLog.Len() ==0 )
//					{
//						strMsg.Format( "—Âü\t˜Î\t—È–à\n", strFileName, nLines );
//						fileLog.WriteString( strMsg );
//					}
//					strMsg.Format( "%s\t%d\tœuŒ›Š¬Z˜Î—²šb\\\n", strFileName, nLines );
//					fileLog.WriteString( strMsg );
//					fileLog.Close();
//				}
            }
            continue;
        }

        if ( bufRead[bufRead.Len() -1]!=' ' && bufRead[bufRead.Len() -1]!='\t' && !bCommentSet
                && bufRead[bufRead.Len() -2]!='*' && bufRead[bufRead.Len() -1]!='/' )
        {//”å›œñ™¹ŒôœuŒ›ŒftŒï’›Ä‰Œ›E”q”O’†—Ü/*Eœñ‘\ŒôœuŒ›‰¹•Å*/Ešğ—¨Šø‘é˜Î
            if ( !bStatedCode )
            {
                bStatedCode = TRUE;
                nCodeLines++;
            }
        }

        if ( bSplashStarFound )
        {
            if ( m_nLineCountingType == NStatisticCommentOnly && bStatedCode ) //”å›—RÄŒ\ŒG—¨‹y”û›ÔE”q—K•¯šoŠø‘é˜Îš‹œA•Ë˜ÎEšğ›¹ÄœA•Ë˜Î
            {
                nCodeLines--;
            }

            if ( m_nLineCountingType == NStatisticCodeOnly && !bStatedCode && !bStatedComment ) 	//”òŒÁ˜Î—ÜŠø‘é”å    /*abc*/ //222
                //‹J•Å—RÄŒ\ŒG•Å‹y™¹›ÔEšğ˜æ™¨œVÑœA•Ë˜ÎÄ•û™¹ŠÌ
            {
                bStatedComment = TRUE;
                nCommentLines++;
            }
        }

        if ( !bStatedComment && bCommentSet ) //h’Ú•Å”O’†šo/*EšØ‹y™¹›Ô—RÄŒ\ŒG›ÎE—²œ——¨Šø‘é˜ÎÄ–ƒE’Å’S‰]˜În‹¦•ÅœA•Ë˜Î
        {
            if ( m_nLineCountingType == NStatisticCodeOnly && !bStatedCode )
            {
                bStatedComment = TRUE;
                nCommentLines++;
            }
        }
    }
}
