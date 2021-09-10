#ifndef CPP04_ISPACEMARINE_HPP
#define CPP04_ISPACEMARINE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ISpaceMarine {
public:
	virtual            		~ISpaceMarine() {};
	virtual ISpaceMarine 	*clone() const = 0;
	virtual void 			battleCry() const = 0;
	virtual void 			rangedAttack() const = 0;
	virtual void 			meleeAttack() const = 0;
};
#endif //CPP04_ISPACEMARINE_HPP
