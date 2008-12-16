#ifndef RULE_H
#define RULE_H

#include "CategorizationFileInfo.h"

///////////////////////////////////////////////////////////////////////
WX_DEFINE_ARRAY(CategorizationFileInfo*, ArrayCategorizationFileInfo);
///////////////////////////////////////////////////////////////////////

class Rule
{
	public:
		Rule();
		virtual ~Rule();

		virtual void Execute( CategorizationFileInfo* pFileInfo ) = 0;

		///////////////////////////////////////////////////////////////

		bool m_bSelected;

		wxString m_strBaseDestPath;

	protected:
	private:
};

#endif // RULE_H
