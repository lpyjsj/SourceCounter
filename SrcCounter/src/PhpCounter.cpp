///////////////////////////////////////////////////////////////////////
// PhpCounter.cpp: implementation of the PhpCounter class.
///////////////////////////////////////////////////////////////////////

#include <wx/textfile.h>
#include "PhpCounter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

///////////////////////////////////////////////////////////////////////

const int N_INTEREST_SZ_NUM = 6;

const wxString SZ_INTEREST[N_INTEREST_SZ_NUM] =
{
    _T("<?"),	// 0
    _T("?>"),	// 1
    _T("//"),	// 2
    _T("/*"),
    _T("*/"),
    _T("#"),	// 5
};

///////////////////////////////////////////////////////////////////////

PhpCounter::PhpCounter()
{
}

PhpCounter::~PhpCounter()
{
}

void PhpCounter::countingSourceFile(
    wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines)
{
    //
    wxString strCurLine;

    bool bPhpMultiCodeMode			= false;	// When start with "<?" is TRUE, otherwise "?>" is FALSE
    bool bDelimitedCommentMode		= false;	// Limited Comment Mode /* */

    int nCurLineLen = 0;
    for ( strCurLine = file.GetFirstLine(); !file.Eof(); strCurLine = file.GetNextLine() )
    {
        // Total lines
        nLines++;

        // Blank lines
        strCurLine.Trim(false); // Trim from left
        nCurLineLen = strCurLine.Len();
        if ( 0 == nCurLineLen )
        {// Counting blank lines
            nBlankLines++;
            continue;
        }

        /////////////////////////////////////////////////////////////////////////////////

        MapIntToStr mapIndexToString;

        pickupInterestString(strCurLine, mapIndexToString);


        MapIntToStr::iterator it;
        wxString strTemp;
        for ( it = mapIndexToString.begin(); it != mapIndexToString.end(); ++it )
        {
            int key = (int)it->first;
            wxString value = it->second;
            strTemp.Printf(_T("%d, %s"), key, (wxString)value);
            //strTemp = (wxString)value;
            wxMessageBox(strTemp);
        }

    }// END for
}

void PhpCounter::pickupInterestString(wxString& strLine, MapIntToStr& mapIntToStr)
{
    int nLen = strLine.Len();
    int nCurRealIndex = 0;
    int nIndex = -1;
    int i = 0;
    wxString strTemp;

    do
    {
        //

        for (i=0; i<N_INTEREST_SZ_NUM; i++)
        {
            nIndex = strLine.Find(SZ_INTEREST[i]);
            if (nIndex != -1 )
            {
                mapIntToStr[nCurRealIndex + nIndex] = SZ_INTEREST[i];
                strLine = strLine.Mid(nIndex + SZ_INTEREST[i].Len());
                // nCurRealIndex += nIndex;
				i = 0;
            }

        }// END for

//        if (i == N_INTEREST_SZ_NUM - 1)
//            break;

    }
    while (i != N_INTEREST_SZ_NUM);

	//

}

void PhpCounter::countingSourceFile1(
    wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines )
{
    //
    wxString strCurLine;

    bool bPhpMultiCodeMode			= false;	// When start with "<?" is TRUE, otherwise "?>" is FALSE
    bool bDelimitedCommentMode		= false;	// Limited Comment Mode /* */

    int nCurLineLen = 0;
    for ( strCurLine = file.GetFirstLine(); !file.Eof(); strCurLine = file.GetNextLine() )
    {
        // Total lines
        nLines++;

        // Blank lines
        strCurLine.Trim(false); // Trim from left
        nCurLineLen = strCurLine.Len();
        if ( 0 == nCurLineLen )
        {// Counting blank lines
            nBlankLines++;
            continue;
        }

        //////////////////////////////////////////////////////////////////////////

        strCurLine.Trim(); // Trim from right
        nCurLineLen = strCurLine.Len();

        if (!bPhpMultiCodeMode)
        {
            if (!bDelimitedCommentMode)
            {
                if ( 0 == strCurLine.Find(_T("<?php"))  && strCurLine.Find(_T("?>")) == (nCurLineLen -2) )
                {// Special case: <?php xxx ?>
                    // TODO: Check // or /**/ " '
                    nCodeLines++;
                    continue;
                }

                if ( strCurLine.Find( _T( "<?" )) != -1 && strCurLine.Find( _T( "?>" )) != -1 )
                {// Case: html <?php xxx ?> html
                    // TODO: Check // or /**/
                    //nCommentLines++;
                    nCodeLines++;
                    continue;
                }

                if ( strCurLine[ 0 ] == _T( '<' ) && strCurLine[ 1 ] ==	_T( '?' )
                        && strCurLine.Find( _T( "?>" )) == -1 )
                {// Case: <? xxx
                    // TODO: finding <? and set bPhpMultiCodeMode to true
                    bPhpMultiCodeMode = true;
                    nCodeLines++;
                    continue;
                }

                if (strCurLine.Find(_T("<?")) != -1 && strCurLine.Find(_T("?>")) == -1 )
                {// Case: xxx <? xxx
                    bPhpMultiCodeMode = true;
                    nCodeLines++;
                    continue;
                }

                // Default case:
                // Not php code, so count nothing

            }
            else
            {// Impossible case, do nothing
            }

        }
        else
        {// bPhpMultiCodeMode is true
            if (!bDelimitedCommentMode)
            {//
                nCurLineLen = strCurLine.Len();

                if (1 == nCurLineLen)
                {// Special case: { or }
                    nCodeLines++;
                    continue;
                }

                if (strCurLine[nCurLineLen - 2] !=	_T('?') && strCurLine[nCurLineLen - 1] != _T('>')
                        && strCurLine[0] == _T('/') && strCurLine[1] == _T('/') )
                {// Special case: // xxx ?>
                    nCommentLines++;
                    continue;
                }

                if ( strCurLine[nCurLineLen - 2] != _T('?') && strCurLine[nCurLineLen - 1] != _T('>')
                        && strCurLine.Find( _T( "//" )) != -1 )
                {// Case: xxx // xxx
                    nCommentLines++;
                    nCodeLines++;
                    continue;
                }

                if ( strCurLine[nCurLineLen - 2] == _T('?') && strCurLine[nCurLineLen - 1] ==  _T('>'))
                {// Case: xxx ?>
                    bPhpMultiCodeMode = false;
                    nCodeLines++;
                    continue;
                }

                if (strCurLine.Find(_T("/*")) != -1 && strCurLine.Find(_T("*/")) == -1)
                {// Case: xxx /* xxx
                    // TODO: Check /* exist, set bDelimitedCommentMode = ture;
                    bDelimitedCommentMode = true;
                    nCommentLines++;
                    continue;
                }

                if (strCurLine.Find(_T("?>")) != -1 )
                {// xxx ?> xxx
                    bPhpMultiCodeMode = false;
                    nCodeLines++;
                }

                // Default case:
                nCodeLines++;
                continue;

            }
            else
            {// bDelimitedCommentMode = true
                if (1 == nCurLineLen)
                {// Special Case:
                    /*
                     * <= strCurLine
                     */
                    nCommentLines++;
                    continue;
                }
                if (strCurLine[nCurLineLen -2] == _T('*') && strCurLine[nCurLineLen - 1] == _T('/'))
                {// Case: xxx */
                    bDelimitedCommentMode = false;
                    nCommentLines++;
                    continue;
                }

                // Default case:
                /*
                 xxx <= strCurLine
                 */
                nCommentLines++;

            }// End if bDelimitedCommentMode
        }// End if bPhpMultiCodeMode
    }// End for
}
