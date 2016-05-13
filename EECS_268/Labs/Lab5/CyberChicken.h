#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H
#include "Chicken.h"
class CyberChicken: public Chicken
{
	public:
		CyberChicken();
		int getCyberEggs()const;
		void setCyberEggs(int eggs);
};
#endif 
