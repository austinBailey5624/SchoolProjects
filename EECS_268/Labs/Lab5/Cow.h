#ifndef COW_H
#define COW_H
#include "FarmAnimal.h"
class Cow : FarmAnimal
{
	public:
		Cow();
		~Cow();
		double getMilkProduced()const;
		void setMilkProduced(double gallons)
};
#endif
