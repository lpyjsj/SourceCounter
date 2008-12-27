#ifndef CATEGORIZATIONOBSERVER_H
#define CATEGORIZATIONOBSERVER_H


class CategorizationObserver
{
	public:
		CategorizationObserver();
		virtual ~CategorizationObserver();

		virtual void UpdateCategorizationCtrls(void) = 0;
	protected:
	private:
};

#endif // CATEGORIZATIONOBSERVER_H
