#ifndef CHICKEN_H
#define CHICKEN_H
#include "FarmAnimal.h"
class Chicken: public FarmAnimal
{
	public:
		Chicken();
	
	protected:
		int getEggs()const;
		void setEggs(int eggs)const;
		int m_eggs;
};
#endif
