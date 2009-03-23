/**
 * @file CountingFileInfo.h
 * @brief CountingFileInfo.h: interface for the CountingFileInfo class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * @date 2005-11-23
 * $Revision: $
 */

#if !defined(AFX_COUNTINGFILEINFO_H__E0D79A54_6BE0_4316_957F_77AA1CD18AAC__INCLUDED_)
#define AFX_COUNTINGFILEINFO_H__E0D79A54_6BE0_4316_957F_77AA1CD18AAC__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/**
 * @class CountingFileInfo
 * current statisticing source file info.
 *
 * @author Boom( boomworks@gmail.com )
 */
class CountingFileInfo
{
public:

	/**
	 * constructor.
	 */
	CountingFileInfo();

    CountingFileInfo(CountingFileInfo& fileInfo);

	/**
	 * disconstructor.
	 */
	virtual ~CountingFileInfo();

	/**
	 * clear counting file infomation.
	 */
	void Clear();

	// attribute
	wxString        m_strFileFullPath;      ///< Couing file full path
	wxString		m_strFolderPath;		///< current counting folder path
	wxString		m_strFileName;			///< current counting file name
	wxString        m_strFileExtName;       ///< Current counting file extend name

	int			m_nSize;				///< current counting file size

	int			m_nTotalStatement;		///< current counting file statement
	int			m_nCodeStatement;		///< current counting file code statement
	int			m_nCommentStatement;	///< current counting file comment statement
	int			m_nCodeCommentStatement;	///< current counnting file code comment at one line
	int			m_nBlankStatement;		///< current counting file blank statement

	float		m_nManDay;		///< Source code man-days
	float		m_nCost;		///< Cost of source code

	// Boom: add UT and IT counting Info on 2009-3-3
	float		m_fUtCase;
	float		m_fUtDefect;
	float		m_fItCase;
	float		m_fItDefect;
};

inline void CountingFileInfo::Clear()
{
    m_strFileFullPath.Empty();
    m_strFolderPath.Empty();
	m_strFileName.Empty();
	m_strFileExtName.Empty();

	m_nSize = 0;

	m_nTotalStatement		= 0;
	m_nCodeStatement		= 0;
	m_nCommentStatement		= 0;
	m_nCodeCommentStatement = 0;
	m_nBlankStatement		= 0;

	m_nManDay	= 0.0;
	m_nCost		= 0.0;

	// Boom: add UT and IT counting info on 2009-3-3
	m_fUtCase = 0.0;
	m_fUtDefect = 0.0;
	m_fItCase = 0.0;
	m_fItDefect = 0.0;
}


#endif // !defined(AFX_COUNTINGFILEINFO_H__E0D79A54_6BE0_4316_957F_77AA1CD18AAC__INCLUDED_)
