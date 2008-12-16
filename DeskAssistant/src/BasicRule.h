#ifndef BASICRULE_H
#define BASICRULE_H

#include "Rule.h"

class BasicRule : public Rule
{
	public:
		BasicRule();
		virtual ~BasicRule();

		virtual void Execute( CategorizationFileInfo* pFileInfo );

	protected:
	private:
};

#endif // BASICRULE_H
