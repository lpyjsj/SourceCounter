#include "RuleInfo.h"

RuleInfo::RuleInfo():
		m_nIndex(-1),
		m_nType(0),
		m_strCondition(_T("")),
		m_strDestPath(_T("")),
		m_bSelected(true)
{
	//ctor

}

RuleInfo::~RuleInfo()
{
	//dtor
}
