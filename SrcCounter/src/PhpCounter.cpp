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

const wxString CSZ_LT_Q = _T("<?");
const wxString CSZ_Q_GT = _T("?>");
const wxString CSZ_SLASH_SLASH = _T("//");
const wxString CSZ_SLASH_ASTERISK = _T("/*");
const wxString CSZ_ASTERISK_SLASH = _T("*/");
const wxString CSZ_SHARP = _T("#");

const int N_INTEREST_SZ_NUM = 6;

const wxString CSZ_INTEREST[N_INTEREST_SZ_NUM] =
{
//    _T("<?"),	// 0
//    _T("?>"),	// 1
//    _T("//"),	// 2
//    _T("/*"),
//    _T("*/"),
//    _T("#"),	// 5
    CSZ_LT_Q,		// 1
    CSZ_Q_GT,		// 2
    CSZ_SLASH_SLASH,		// 3
    CSZ_SLASH_ASTERISK,		// 4
    CSZ_ASTERISK_SLASH,		// 5
    CSZ_SHARP,				// 6
};

///////////////////////////////////////////////////////////////////////

PhpCounter::PhpCounter()
{
}

PhpCounter::~PhpCounter()
{
}

void PhpCounter::countingEx(
    wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines)
{
    //
    wxString strCurLine;

    bool bPhpCodeMode				= false;	// When start with "<?" is TRUE, otherwise "?>" is FALSE
    bool bDelimitedCommentMode		= false;	// Limited Comment Mode /* */
    bool bSingleLineCommentMode		= false;

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

//        MapIntToStr::iterator it;
//        wxString strTemp;
//        int key = 0;
//        for ( it = mapIndexToString.begin(); it != mapIndexToString.end(); ++it )
//        {
//            key = (int)it->first;
//            wxString value = it->second;
//            strTemp.Printf(_T("%d"), key);
//            //strTemp = (wxString)value;
//            wxMessageBox(strTemp +_T(", ") +value);
//        }

        MapIntToStr::iterator it;
        wxString strForPickup;

        if (mapIndexToString.empty())
        {
            if (bPhpCodeMode)
            {
                if (bDelimitedCommentMode)
                {
                    nCommentLines++;
                    continue;
                }

                nCodeLines++;
                continue;
            }
        }

        for ( it = mapIndexToString.begin(); it != mapIndexToString.end(); ++it )
        {
            strForPickup = it->second;

            ///////////////////////////////////////////////////////////
            if (bPhpCodeMode)
            {// Php code mode
                if (bDelimitedCommentMode)
                {// DelimitedCommentMode
                    if (strForPickup != CSZ_ASTERISK_SLASH)
                    {// Skip next pickuped string, until appear */
                        continue;
                    }
                    else
                    {// Case: */
                        bDelimitedCommentMode = false;
                        continue;
                    }
                }

                if (bSingleLineCommentMode)
                {// Single line comment mode
                    if (strForPickup != CSZ_Q_GT)
                    {// Skip next pickuped string, until appear ?>
                        continue;
                    }
                    else
                    {// Case: code // Comment ?>
                        bSingleLineCommentMode = false;
                        bPhpCodeMode = false;
                        continue;
                    }
                }

                if (strForPickup == CSZ_SLASH_SLASH)
                {// Case: code // comment
                    // TODO: if after //, there are have ?> SingleLineCommentMode is true, otherwise false
                    if (existInMap(it, CSZ_Q_GT, mapIndexToString))
                    {
                        bSingleLineCommentMode = true;

                    }
                    else
                    {
                        bSingleLineCommentMode = false;
                    }
                    nCommentLines++;
                    continue;
                }

                if (strForPickup == CSZ_SLASH_ASTERISK)
                {// Case: code /* comment
                    bDelimitedCommentMode = true;
                    nCommentLines++;
                    continue;
                }

                if (strForPickup == CSZ_Q_GT)
                {// Case: code ?>
                    bPhpCodeMode = false;
                    continue;
                }

            }
            else
            {// Not php code mode
                if (strForPickup != CSZ_LT_Q)
                {// Skip pickup string, until the <? appear
                    continue;
                }
                else
                {// Case: <?
                    bPhpCodeMode = true;
                    nCodeLines++;
                    continue;
                }
            }

        }// END map for

    }// END line for
}

bool PhpCounter::existInMap(MapIntToStr::iterator& itt, wxString strForFind, MapIntToStr& mapIntToStr)
{
    bool bRet = false;

    MapIntToStr::iterator it;
    int nFlag = 0;
    wxString strTemp;
    for ( it = mapIntToStr.begin(); it != mapIntToStr.end(); ++it )
    {
        if (it == itt)
            nFlag = 1;

        if (nFlag == 1)
        {
            strTemp = it->second;

            if (strTemp == strForFind)
                bRet = true;
        }
    }

    return bRet;
}


void PhpCounter::pickupString(wxString& strLine, wxString strForPickup, MapIntToStr& mapIntToStr)
{
    wxString strTemp(strLine);

    int nLen = strTemp.Len();
    int nCutStrNum = 0;

    int nIndex = strTemp.Find(strForPickup);
    while (nIndex != -1 )
    {
        nIndex = strTemp.Find(strForPickup);
        if (nIndex == -1)
            break;

        mapIntToStr[nCutStrNum + nIndex] = strForPickup;

        strTemp = strTemp.Mid(nIndex + strForPickup.Len());
        nCutStrNum = nCutStrNum + nIndex + strForPickup.Len();

    }
}

void PhpCounter::pickupInterestString(wxString& strLine, MapIntToStr& mapIntToStr)
{
    //
    for (int i=0; i<N_INTEREST_SZ_NUM; i++)
    {
        pickupString(strLine, CSZ_INTEREST[i], mapIntToStr);

    }// END for
}

///////////////////////////////////////////////////////////////////////

void PhpCounter::countingSourceFile(
    wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines )
{

#ifdef __WXDEBUG__

    countingEx(file, nLines, nCodeLines, nCommentLines, nBlankLines);

#else
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

                if (strCurLine[0] == _T('/') && strCurLine[1] == _T('*')
                        && strCurLine[nCurLineLen -2] == _T('*') && strCurLine[nCurLineLen - 1] == _T('/') )
                {// Case: /* xxx */
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

#endif
}
