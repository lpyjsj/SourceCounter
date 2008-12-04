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

		virtual void Execute(ArrayCategorizationFileInfo& arrFileInfo) = 0;

	protected:
	private:
};

#endif // RULE_H
