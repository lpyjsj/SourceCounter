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


	///////////////////////////////////////////////////////////////////

    virtual void Execute( CategorizationFileInfo* pFileInfo );

protected:
private:

};

#endif // EXTNAMERULE_H
