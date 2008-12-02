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

	void Categorize(wxString& strPathForCategorize, bool bPreview = true);

	ArrayCategorizationFileInfo*  GetCategorizationFileInfos()	{ return &m_arrCategorizationFileInfo; }

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


	///////////////////////////////////////////////////////////////////

    void getSubFolder(wxString& strFolderPath, wxArrayString& arrSubFolder, bool bRecursive = true);

	void getFolderAllFile(wxString& strFolderPath, ArrayCategorizationFileInfo& arrFileInfo );


    void moveFilesToFolder(bool bPreview);
    void categorizeByTime(bool bPreview);


};

#endif // CATEGORIZEMGR_H
