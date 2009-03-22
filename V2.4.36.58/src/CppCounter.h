/**
 * @file CppCounter.h
 * @brief CppCounter.h: interface for the CppCounter class.
 * @author Boom( boomworks@hotmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * @date 2005-11-24
 * $Revision: $
 */

#if !defined(AFX_CPPCOUNTER_H__B3F2A448_1CFB_4464_9ABB_5C6F6579C1AF__INCLUDED_)
#define AFX_CPPCOUNTER_H__B3F2A448_1CFB_4464_9ABB_5C6F6579C1AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Counter.h"

//////////////////////////////////////////////////////////////////////////

/**
 * @class CppCounter
 * cpp/cxx/c source file counter class.
 *
 * @author Boom( boomworks@hotmail.com )
 */
class CppCounter : public Counter
{
public:

	/**
	 * get instance.
	 *
	 * @return CppCounter pointer
	 */
	static CppCounter*	GetInstance();

	/**
	 * distructor.
	 */
	virtual ~CppCounter();

	/**
	 * counting source file.
	 *
	 * @param strFilePath source file path
	 * @param nLines total lines
	 * @param nCodeLines total code lines
	 * @param nCommentLines comment lines
	 * @param nBlankLines blank lines
	 */
	virtual void countingSourceFile( wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines );

    static wxString ms_strType;

private:

	static CppCounter* ms_instance;		///< static instance

	/**
	 * constructor.
	 */
	CppCounter();

};


//////////////////////////////////////////////////////////////////////////

/**
 * @class CJavaCounter
 * java source file counter class.
 *
 * @author Boom( boomworks@hotmail.com )
 */
//class CJavaCounter : public CppCounter
//{
//public:
//
//	/**
//	 * get instance.
//	 *
//	 * @return CJavaCounter pointer
//	 */
//	static CJavaCounter*	GetInstance();
//
//	/**
//	 * distructor.
//	 */
//	virtual ~CJavaCounter();
//
//	/**
//	 * counting source file.
//	 *
//	 * @param strFilePath source file path
//	 * @param nSize	file size
//	 * @param nLines total lines
//	 * @param nCodeLines total code lines
//	 * @param nCommentLines comment lines
//	 * @param nBlankLines blank lines
//	 */
//	virtual void countingSourceFile( wxString& strFilePath,int& nSize, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines );
//
//protected:
//
//	/**
//	 * constructor.
//	 */
//	CJavaCounter();
//
//private:
//	// static instance
//	//	static CJavaCounter* ms_instance;
//
//};
//
//inline CJavaCounter* CJavaCounter::GetInstance()
//{
//	if ( ms_instance == 0)
//	{
//		ms_instance = new CJavaCounter;
//	}
//	return (CJavaCounter*)ms_instance;
//}
//
//////////////////////////////////////////////////////////////////////////

#endif // !defined(AFX_CPPCOUNTER_H__B3F2A448_1CFB_4464_9ABB_5C6F6579C1AF__INCLUDED_)
