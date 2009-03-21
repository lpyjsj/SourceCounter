#include "AspxCounter.h"

wxString AspxCounter::ms_strType = _T("Aspx");

AspxCounter::AspxCounter()
{
    //ctor
}

AspxCounter::~AspxCounter()
{
    //dtor
}

void AspxCounter::countingSourceFile(
    wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines )

{
#ifdef __WXDEBUG__
	countingAspx_ver_2(file, nLines, nCodeLines, nCommentLines, nBlankLines);

#else
	countingAspx_ver_1(file, nLines, nCodeLines, nCommentLines, nBlankLines);

#endif
}

void AspxCounter::countingAspx_ver_2(
    wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines )
{
	// TODO:
	countingAspx_ver_1(file, nLines, nCodeLines, nCommentLines, nBlankLines);
}

void AspxCounter::countingAspx_ver_1(
    wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines )
{
    //
    wxString strCurLine;

    bool bMultiLineCodeMode			= false;	// When start with "<%" is TRUE, otherwise "%>" is FALSE
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

        if (!bMultiLineCodeMode)
        {
            if (!bDelimitedCommentMode)
            {
                if ( 0 == strCurLine.Find(_T("<%"))  && strCurLine.Find(_T("%>")) == (nCurLineLen -2) )
                {// Special case: <% xxx %>
                    // TODO: Check // or /**/ " '
                    nCodeLines++;
                    continue;
                }

                if ( strCurLine.Find( _T( "<%" )) != -1 && strCurLine.Find( _T( "%>" )) != -1 )
                {// Case: html <% xxx %> html
                    // TODO: Check // or /**/
                    //nCommentLines++;
                    nCodeLines++;
                    continue;
                }

                if ( strCurLine[ 0 ] == _T( '<' ) && strCurLine[ 1 ] ==	_T( '%' )
                        && strCurLine.Find( _T( "%>" )) == -1 )
                {// Case: <% xxx
                    // TODO: finding <% and set bMultiLineCodeMode to true
                    bMultiLineCodeMode = true;
                    nCodeLines++;
                    continue;
                }

                if (strCurLine.Find(_T("<%")) != -1 && strCurLine.Find(_T("%>")) == -1 )
                {// Case: xxx <% xxx
                    bMultiLineCodeMode = true;
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
        {// bMultiLineCodeMode is true
            if (!bDelimitedCommentMode)
            {//
                nCurLineLen = strCurLine.Len();

                if (1 == nCurLineLen)
                {// Special case: { or }
                    nCodeLines++;
                    continue;
                }

                if (strCurLine[nCurLineLen - 2] !=	_T('%') && strCurLine[nCurLineLen - 1] != _T('>')
                        && strCurLine[0] == _T('/') && strCurLine[1] == _T('/') )
                {// Special case: // xxx %>
                    nCommentLines++;
                    continue;
                }

                if ( strCurLine[nCurLineLen - 2] != _T('%') && strCurLine[nCurLineLen - 1] != _T('>')
                        && strCurLine.Find( _T( "//" )) != -1 )
                {// Case: xxx // xxx
                    nCommentLines++;
                    nCodeLines++;
                    continue;
                }

                if ( strCurLine[nCurLineLen - 2] == _T('%') && strCurLine[nCurLineLen - 1] ==  _T('>'))
                {// Case: xxx %>
                    bMultiLineCodeMode = false;
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

                if (strCurLine.Find(_T("%>")) != -1 )
                {// xxx %> xxx
                    bMultiLineCodeMode = false;
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
        }// End if bMultiLineCodeMode
    }// End for
}
