/**
 * @file CountingParam.h
 * @brief CountingParam.h: interface for the CountingParam class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 BoomWorks.Net , All right reserved.
 * @date 2005-11-23
 * $Revision: $
 */

#if !defined(AFX_STATISTICCONDITION_H__06A1F691_7E19_4E86_81F7_CA3F8C6CB4B5__INCLUDED_)
#define AFX_STATISTICCONDITION_H__06A1F691_7E19_4E86_81F7_CA3F8C6CB4B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/** define source type id */
enum NSourceFileType
{
	// TODO:

	// c and cpp
	NTypeH			= 1,		///<
	NTypeC			= 2,		///<
	NTypeCPP		= 4,		///< .cpp
	NTypeCXX		= 8,		///<
	NTypeRC			= 32,		///< plaint text
	NTypeTLH		= 64,		///<
	NTypeTLI		= 128,		///<

	// delphi
	NTypePAS		= 256,		///<
	NTypeDFM		= 512,		///<  plaint text

	// vb
	NTypeBAS		= 1024,		///<
	NTypeFRM		= 2048,		///<
	NTypeCTL		= 4096,		///<
	NTypeCLS		= 8192,		///<

	// java
	NTypeJAVA		= 16384,	///<

	NTypeHTML		= 32768,	///< macro script (VBA)
	NTypeASP		= 65536,		///<
	NTypeJSP		= 65536 + 65536,		///<

};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * @class SettingParam
 * More setting pramaeter for Counting.
 *
 * @author Boom( boomworks@gmail.com )
 */
class SettingParam
{
public:
    SettingParam();
    virtual ~SettingParam();

	int m_nCountingMethodType;		///< when code and comment in one line

private:

};

/**
 * @class CountingParam
 * Counting parameter class.
 *
 * @author Boom( boomworks@gmail.com )
 */
class CountingParam
{
public:

	/**
	 * constructor.
	 */
	CountingParam();

	/**
	 * distructor.
	 */
	virtual ~CountingParam();

    //
	// Counting parameter member list
	//

    wxArrayString       m_arrSrcFolderPath;         ///< Storing source folder path for counting
    wxArrayString       m_arrSrcType;               ///< Storing source type for counting

	bool				m_bRecursiveCounting;		///< Recursive folder counting flag

	SettingParam        m_settingParam;             ///< More setting parameter for counting

};

#endif // !defined(AFX_STATISTICCONDITION_H__06A1F691_7E19_4E86_81F7_CA3F8C6CB4B5__INCLUDED_)
