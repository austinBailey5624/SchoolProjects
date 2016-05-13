#ifndef FARMANIMAL_H
#define FARMANIMAL_H
#include <string>
class FarmAnimal
{
	public:
		FarmAnimal();
		std::string getName()const;
		void setName(std::string name);
		std::string getSound()const;
		void setSound(std::string sound);
	
	protected:
		std::string m_name;
		std::string m_sound;
};
#endif
