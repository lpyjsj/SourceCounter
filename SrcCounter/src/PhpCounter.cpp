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
const wxString CSZ_SINGLE_QUOTE = _T('\'');
const wxString CSZ_DOUBLE_QUOTE = _T('\"');

const int N_INTEREST_SZ_NUM = 6;

const wxString CSZ_INTEREST[N_INTEREST_SZ_NUM] =
{
    CSZ_LT_Q,		// 1
    CSZ_Q_GT,		// 2
    CSZ_SLASH_SLASH,		// 3
    CSZ_SLASH_ASTERISK,		// 4
    CSZ_ASTERISK_SLASH,		// 5
    CSZ_SHARP,				// 6
    //CSZ_SINGLE_QUOTE,		// 7
    //CSZ_DOUBLE_QUOTE,		// 8
};

///////////////////////////////////////////////////////////////////////

wxString PhpCounter::ms_strType = _T("PHP");

PhpCounter::PhpCounter()
{
}

PhpCounter::~PhpCounter()
{
}

void PhpCounter::countingSourceFile(wxTextFile& file, int& nLines, int& nCodeLines,
                                     int& nCommentLines, int& nCodeCommentLines, int& nBlankLines)
{
    //
    wxString strCurLine;

    bool bPhpCodeMode				= false;	// When start with "<?" is TRUE, otherwise "?>" is FALSE
    bool bDelimitedCommentMode		= false;	// Delimited Comment Mode /* */
    bool bSingleLineCommentMode		= false;
    bool bSingleQuoteMode			= false;	//
    bool bDoubleQuoteMode			= false;

    bool bHasQuote = false;	//

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

        ///////////////////////////////////////////////////////////////
        strCurLine.Trim(); // Trim from right
        strCurLine.Replace(_T("\\'"), _T("XX")); // TODO: need test

        ///////////////////////////////////////////////////////////////
        MapIntToStr mapIndexToString;
        pickupString(strCurLine, mapIndexToString);

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

		bHasQuote = false; // Important

        MapIntToStr::iterator it;
        int nIndexForPickup = -1;
        wxString strForPickup;

        for ( it = mapIndexToString.begin(); it != mapIndexToString.end(); ++it )
        {
            nIndexForPickup = it->first;
            strForPickup = it->second;

            ///////////////////////////////////////////////////////////
            if (bPhpCodeMode)
            {// Php code mode /////////////////////////////////////////
                if (bDelimitedCommentMode)
                {// DelimitedCommentMode //////////////////////////////
                    if (strForPickup != CSZ_ASTERISK_SLASH)
                    {// Skip next pickuped string, until appear */
                        nCommentLines++;
                    }
                    else
                    {// Case: */
                        if (!existStringInMap(mapIndexToString, it, NDirectionForward, CSZ_SLASH_ASTERISK))
                        {
                            nCommentLines++;
                        }
                        bDelimitedCommentMode = false;
                    }
                    // Finally
                    continue;
                }

                if (bSingleLineCommentMode)
                {// Single line comment mode //////////////////////////
                    if (strForPickup != CSZ_Q_GT)
                    {// Skip next pickuped string, until appear ?>
                    }
                    else
                    {// Case: code // Comment ?>
                        bSingleLineCommentMode = false;
                        bPhpCodeMode = false;
                    }
                    // Finally
                    continue;
                }

                if (bSingleQuoteMode)
                {// Single quote mode /////////////////////////////////
                    if (strForPickup != CSZ_SINGLE_QUOTE)
                    {// Skip any next sensetive string, until ' appear
                    }
                    else
                    {
                        bSingleQuoteMode = false;

                        if(!bHasQuote)
							nCodeLines++;
                    }
                    continue;
                }

                if (bDoubleQuoteMode)
                {// Double quote mode /////////////////////////////////
                    if (strForPickup != CSZ_DOUBLE_QUOTE)
                    {// Skip any next sensetive string, until " appear
                    }
                    else
                    {
                        bDoubleQuoteMode = false;
                    }
                    continue;
                }

                ///////////////////////////////////////////////////////
                if (strForPickup == CSZ_SLASH_SLASH)
                {// Case: code; // comment
                    bSingleLineCommentMode = existStringInMap(mapIndexToString, it, NDirectionBack, CSZ_Q_GT);

                    if (nIndexForPickup > 0 &&
						(!existStringInMap(mapIndexToString, it, NDirectionForward, CSZ_SINGLE_QUOTE )
							&& !existStringInMap(mapIndexToString, it, NDirectionForward, CSZ_DOUBLE_QUOTE)))
                    {// Case: code; // comment
                        nCodeLines++;
                    }
                    nCommentLines++;

                    if (!bSingleLineCommentMode)
                    {// Case: /////////////////////////////////////////
                    	break;
                    }
                    continue;
                }

                if (strForPickup == CSZ_SHARP)
                {// Case: code; # comment
                    bSingleLineCommentMode = existStringInMap(mapIndexToString, it, NDirectionBack, CSZ_Q_GT);

                    if (nIndexForPickup > 0  &&
						(!existStringInMap(mapIndexToString, it, NDirectionForward, CSZ_SINGLE_QUOTE )
							&& !existStringInMap(mapIndexToString, it, NDirectionForward, CSZ_DOUBLE_QUOTE)))
                    {// Case: code; # comment
                        nCodeLines++;
                    }
                    nCommentLines++;

					if (!bSingleLineCommentMode)
                    {// Case: #########################################
                    	break;
                    }
                    continue;
                }

                if (strForPickup == CSZ_SINGLE_QUOTE)
                {// Case: code ' quote ';
                    bSingleQuoteMode = true;

					if(!bHasQuote)
					{
						nCodeLines++;
						bHasQuote = true;
					}
                    continue;
                }

                if (strForPickup == CSZ_DOUBLE_QUOTE)
                {// Case: code " quote ";
                    bDoubleQuoteMode = true;

					if(!bHasQuote)
					{
						nCodeLines++;
						bHasQuote = true;
					}
                    continue;
                }

                if (strForPickup == CSZ_SLASH_ASTERISK)
                {// Case: code; /* comment
                    bDelimitedCommentMode = true;

                    if (nIndexForPickup > 0  &&
						(!existStringInMap(mapIndexToString, it, NDirectionForward, CSZ_SINGLE_QUOTE )
							&& !existStringInMap(mapIndexToString, it, NDirectionForward, CSZ_DOUBLE_QUOTE)))
                    {// Case: code; /* comment
                        nCodeLines++;
                    }
                    nCommentLines++;
                    continue;
                }

                if (strForPickup == CSZ_Q_GT)
                {// Case: code ?>
                    bPhpCodeMode = false;

                    if (!existStringInMap(mapIndexToString, it, NDirectionForward, CSZ_LT_Q))
						nCodeLines++;	// +1
                    continue;
                }

                ///////////////////////////////////////////////////////
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
            if (nFlag == 0)
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

void PhpCounter::pickupString(wxString& strLine, MapIntToStr& mapIntToStr)
{
    wxString strForPickup;
    wxString strTemp;
    int nCutStrNum;
    int nIndex;

    for (int i=0; i<N_INTEREST_SZ_NUM; i++)
    {
        strForPickup = CSZ_INTEREST[i];
        strTemp = strLine;
        nCutStrNum = 0;
        nIndex = -1;

        nIndex = strTemp.Find(strForPickup);
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
}
