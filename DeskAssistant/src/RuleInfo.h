#ifndef RULEINFO_H
#define RULEINFO_H


class RuleInfo
{
	public:
		RuleInfo();
		virtual ~RuleInfo();

//		unsigned int GetIndex() { return m_nIndex; }
//		void SetIndex(unsigned int val) { m_nIndex = val; }
//
//		unsigned int GetnType() { return m_nType; }
//		void SetnType(unsigned int val) { m_nType = val; }
//
//		wxString GetstrCondition() { return m_strCondition; }
//		void SetstrCondition(wxString val) { m_strCondition = val; }
//
//		wxString GetstrDestPath() { return m_strDestPath; }
//		void SetstrDestPath(wxString val) { m_strDestPath = val; }

		unsigned int m_nIndex;
		unsigned int m_nType;
		wxString m_strCondition;
		wxString m_strDestPath;

		bool m_bSelected;

	protected:
	private:

};

#endif // RULEINFO_H
