/**
 * @file CounterObserver.h
 * @brief CouterObserver.h: interface for the CCouterObserver class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * @date 2005-11-22
 * $Revision: $
 */

#if !defined(AFX_COUTEROBSERVER_H__B7F3AC6D_D7C0_4E37_B873_A899D697C16E__INCLUDED_)
#define AFX_COUTEROBSERVER_H__B7F3AC6D_D7C0_4E37_B873_A899D697C16E__INCLUDED_

/**
 * @class CCounterObserver
 * CCounter's Observer Interface. Use Observer Pattern.
 *
 * @author Boom( boomworks@gmail.com )
 */
class CCounterObserver
{
public:

	/**
	 * Constructor.
	 */
	CCounterObserver();

	/**
	 * Distructor.
	 */
	virtual ~CCounterObserver();

	/**
	 * Update statistic infomation.
	 */
	virtual void UpdateCountingInfoCtrls( void ) = 0;
};

#endif // !defined(AFX_COUTEROBSERVER_H__B7F3AC6D_D7C0_4E37_B873_A899D697C16E__INCLUDED_)
