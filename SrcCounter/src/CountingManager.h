/**
 * @file CountingManager.h
 * @brief CountingManager.h: interface for the CountingManager class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 BoomWorks.Net , All right reserved.
 * @date 2005-11-23
 * $Revision: $
 */

#if !defined(AFX_STATISTICMANAGER_H__B44677A9_720F_4A8B_989B_492D20627458__INCLUDED_)
#define AFX_STATISTICMANAGER_H__B44677A9_720F_4A8B_989B_492D20627458__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Counter.h"
#include "CountingParam.h"
#include "CountingInfo.h"
#include "CounterObserver.h"

//////////////////////////////////////////////////////////////////////////

/** Source types number */
extern const int N_COLUMN_NUM;

/** Source type string list */
extern const wxChar* CSZ_COLUMN_NAMES[];

/** manager status flag */
enum NManagerStatus
{
    NManagerStatusNormal = 0,	///< normal
    NManagerStatusStop,			///< stop
    NManagerStatusRunning,		///< running status
    NManagerStatusComplete		///< compeletly
};

//typedef CMap<int, int, CCounter*, CCounter*&> MapStrToCounter;
WX_DECLARE_STRING_HASH_MAP( Counter*, MapStrToCounter);

//////////////////////////////////////////////////////////////////////////

/**
 * @class CountingManager
 * statistic mananger class.
 *
 * @author Boom( boomworks@gmail.com )
 */
class CountingManager
{
public:

    /**
     * constructor.
     */
    CountingManager();

    /**
     * distructor.
     */
    virtual ~CountingManager();

public:

    /**
     * set statistic condition.
     *
     * @param pParam statistic condition object
     */
    void    SetCountingParam( CountingParam* pParam );

    /**
     * Get counting parameters
     */
    CountingParam*    GetCountingParam(void) {return &m_countingParam;}

    /**
     * Create counter by source file extend name.
     *
     * @param strFileExtendName counter identify name
     * @return counter object pointer
     */
    Counter*		CreateCounter( wxString strFileExtendName );

    /**
     * Get counting information.
     * @return CountingInfo*
     */
    virtual CountingInfo*	GetCountingInfo(void);

    /**
     * clear manager status and preserver data.
     */
    void			Clear();

    /**
     * get manager status.
     *
     * @return status flag
     */
    NManagerStatus	GetStatus();

    /**
     * Set manager status.
     *
     * @param nStatus manager status
     */
    void SetStatus( NManagerStatus nStatus );

	//
	// Strating and stop counting method

    /**
     * start statistic source files.
     */
    void			StartCounting();

    /**
     * stop statistic source files.
     */
    void			StopCounting();

    //
    // observer pattern method
    //

    /**
     * Add obvserver to subject.
     *
     * @param pObserver observer object
     */
    void			AttachObserver( CCounterObserver* pObserver );

    /**
     * Notify the observers.
     * SubClass Object call this method.
     */
    void			Notify();

    //
    // Save counting result to file.
    //

    void SaveCountingResultToCSV(wxString strFilePath);

private:

	// Counter pointer section
    CCounterObserver*		m_pObserver;		///< Observer for counting
    MapStrToCounter		    m_mapStrToCounter;  ///< Hashmap for store counter pointer

	// Counting parameter and result information section
    CountingParam		    m_countingParam;	///< Counting parametera
    CountingInfo			m_countingInfo;		///< preserver statistic infomation

	// Counting status info
    BOOL					m_bStopCounting;	///< stop statistic flag
    NManagerStatus			m_countingStatus;	///< statistic status

    //////////////////////////////////////////////////////////////////////////

    /**
     * Add sub folder to arraylist for counting.
     */
    void addSubSrcFolder();

    /**
     * Is counting file
     */
    bool isCountingFile(wxString& strFileExtName);

    /**
     * get file ext name string.
     *
     * @param strFileName file name
     * @param strExt file ext name
     */
    void getFileExtName( wxString& strFileName, wxString& strExt );

    /**
     * get file name and dir form full path.
     *
     * @param strFullPath FullPath
     * @param strFileName FileName
     * @param strDir Dir
     */
    void getFileNameAndDirFromFullPath( wxString& strFullPath, wxString& strFileName, wxString& strDir );
};

inline NManagerStatus CountingManager::GetStatus()
{
    return m_countingStatus;
}

inline void CountingManager::SetStatus(NManagerStatus nStatus )
{
    m_countingStatus = nStatus;
}

#endif // !defined(AFX_STATISTICMANAGER_H__B44677A9_720F_4A8B_989B_492D20627458__INCLUDED_)
