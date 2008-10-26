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

/** manager status flag */
enum NManagerStatus
{
    NManagerStatusNormal = 0,	///< normal
    NManagerStatusStop,			///< stop
    NManagerStatusRunning,		///< running status
    NManagerStatusComplete		///< compeletly
};

//////////////////////////////////////////////////////////////////////////

//typedef CMap<int, int, CCounter*, CCounter*&> MapStrToCounter;

// same, with int keys and MyClass* values
//WX_DECLARE_HASH_MAP( int, Counter*, wxIntegerHash, wxIntegerEqual, MapStrToCounter );

WX_DECLARE_STRING_HASH_MAP( Counter*, MapStrToCounter);
WX_DEFINE_ARRAY(CountingFileInfo*, ArrayCountingFileInfo);

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

    /**
     * set statistic condition.
     *
     * @param pParam statistic condition object
     */
    void			SetCountingParam( CountingParam* pParam );

    /**
     * create counter from source file type id .
     *
     * @param strFileExtendName counter identify name
     * @return counter object pointer
     */
    Counter*		CreateCounter( wxString strFileExtendName );

    /**
     * start statistic source files.
     */
    void			StartCounting();

    /**
     * stop statistic source files.
     */
    void			StopCounting();

    /**
     * clear manager.
     */
    void			Clear();

    /**
     * get statistic infomation from CCounter.
     *
     * @param countingInfo statistic info object
     */
    virtual void	GetCountingInfo( CountingInfo& countingInfo );

    ArrayCountingFileInfo* GetCountingFileInfoArr(void) { return &m_arrCountingFileInfo;}

    /**
     * get manager status.
     *
     * @return status flag
     */
    NManagerStatus	GetStatus();

    /**
     * set manager status.
     *
     * @param nStatus manager status
     */
    void SetStatus( NManagerStatus nStatus );

    //
    // observer pattern
    //

    /**
     * add ovserver to subject.
     *
     * @param pObserver observer object
     */
    void			AttachObserver( CCounterObserver* pObserver );

    /**
     * Notify the observers.
     * SubClass Object call this method.
     */
    void			Notify();


private:
    CountingParam		    m_countingParam;		///< Counting parametera

    CCounterObserver*		m_pObserver;	///< observer
    Counter*				m_pCounter;		///< CCounter Object

    CountingInfo			m_countingInfo;			///< preserver statistic infomation
    CountingFileInfo*		m_pCurCountingFileInfo;		///< current counting file infomation
    ArrayCountingFileInfo   m_arrCountingFileInfo;  ///< Array for store counting file info

    BOOL					m_bStopCounting;		///< stop statistic flag
    NManagerStatus			m_countingStatus;		///< statistic status

    MapStrToCounter		    m_mapStrToCounter;      ///< Hashmap for store counter pointer


    //////////////////////////////////////////////////////////////////////////

    void addSubSrcFolder();
    bool isCountingFile(wxString& strFileExtName);

    /**
     * get source file type id.
     *
     * @param strFileName file name or file path
     * @retval NTypeCPP/ NTypeJAVA
     * @retval -1 when faild
     */
    int getSourceFileTypeID( wxString strFileName );

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
