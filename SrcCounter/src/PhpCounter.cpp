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

        MapIntToStr::iterator it;
        wxString strForPickup;
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
                    	nCommentLines++;
                        continue;
                    }
                    else
                    {// Case: */
                    	if(!existStringInMap(mapIndexToString, it, NDirectionForward, CSZ_SLASH_ASTERISK))
                    	{
                    		nCommentLines++;
                    	}
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
                    if (existStringInMap(mapIndexToString, it, NDirectionBack, CSZ_Q_GT ))
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
                    nCodeLines++;	// +1
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

bool PhpCounter::existStringInMap(MapIntToStr& mapIntToStr, MapIntToStr::iterator& itt, NDirection nDirection, wxString strForFind)
{
    bool bRet = false;

    MapIntToStr::iterator it;
    int nFlag = 0;
    wxString strTemp;
    for ( it = mapIntToStr.begin(); it != mapIntToStr.end(); ++it )
    {
        if (it == itt)
            nFlag = 1;

		strTemp = it->second;
        if (nDirection == NDirectionBack)
        {
            if (nFlag == 1)
            {
                if (strTemp == strForFind)
                {
                    bRet = true;
                    break;
                }
            }
        }
        else
        {
			if(nFlag == 0)
			{
                if (strTemp == strForFind)
                {
                    bRet = true;
                    break;
                }
			}
        }
    }// END for

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
	//
    countingEx(file, nLines, nCodeLines, nCommentLines, nBlankLines);

}
