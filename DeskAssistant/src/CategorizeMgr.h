#ifndef CATEGORIZEMGR_H
#define CATEGORIZEMGR_H


class CategorizeMgr
{
public:
    CategorizeMgr();
    virtual ~CategorizeMgr();

public:

	///////////////////////////////////////////////////////////////////

	Categorize();

protected:
private:


	///////////////////////////////////////////////////////////////////

    void getSubFolder(wxString& strFolderPath, wxArrayString& arrSubFolder);

    void moveFilesToFolder(bool bPreview);
    void categorizeByTime(bool bPreview);


};

#endif // CATEGORIZEMGR_H
