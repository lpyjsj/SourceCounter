#ifndef EXTNAMERULE_H
#define EXTNAMERULE_H

#include "Rule.h"

class ExtNameRule : public Rule
{
public:
    ExtNameRule();
    virtual ~ExtNameRule();

    ///////////////////////////////////////////////////////////////////

	wxArrayString m_arrStrExtName;
	wxString m_strBaseDestPath;

	///////////////////////////////////////////////////////////////////

    virtual void Execute(ArrayCategorizationFileInfo& arrFileInfo);

protected:
private:

};

#endif // EXTNAMERULE_H
