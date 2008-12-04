#ifndef CATEGORIZEMGR_H
#define CATEGORIZEMGR_H

#include "Rule.h"
#include "CategorizationObserver.h"

///////////////////////////////////////////////////////////////////////
WX_DEFINE_ARRAY(Rule*, ArrayRule);

///////////////////////////////////////////////////////////////////////


class CategorizeMgr
{
public:
    CategorizeMgr();
    virtual ~CategorizeMgr();


	///////////////////////////////////////////////////////////////////

	void Preview(wxString& strPathForCategorize);
	void Categorize();

	ArrayCategorizationFileInfo*  GetCategorizationFileInfos()	{ return &m_arrCategorizationFileInfo; }

	void SetBaseDestPath(wxString& strPath) { m_strDesktopPath = strPath; }

    //
    // observer pattern method
    //

    /**
     * Add obvserver to subject.
     *
     * @param pObserver observer object
     */
    void			AttachObserver( CategorizationObserver* pObserver );

    /**
     * Notify the observers.
     * SubClass Object call this method.
     */
    void			Notify();

protected:
private:
    CategorizationObserver*			m_pObserver;		///< Observer for categorization

	ArrayRule 						m_arrRule;	///< Rules for categorization
	ArrayCategorizationFileInfo 	m_arrCategorizationFileInfo;	///< Files info for categorize

	wxArrayString 					m_arrStrSubFolder;	///<

	wxString						m_strDesktopPath;

	///////////////////////////////////////////////////////////////////

    void getSubFolder(wxString& strFolderPath, wxArrayString& arrSubFolder, bool bRecursive = true);

	void getFolderAllFile(wxString& strFolderPath, ArrayCategorizationFileInfo& arrFileInfo );

};

#endif // CATEGORIZEMGR_H
