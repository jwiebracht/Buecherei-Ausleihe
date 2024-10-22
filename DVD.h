/*
 * DVD.h
 *
 *  Created on: 30.06.2024
 *      Author: jonas
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

class DVD: public Medium {
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

	int altersFreigabe;
	std::string genre;

	void ausgabe(std::ostream& out) const;
	bool ausleihen(Person person, Datum ausleihdatum);

	virtual ~DVD();
};

#endif /* DVD_H_ */
