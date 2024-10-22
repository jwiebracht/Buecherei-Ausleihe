/*
 * Buch.h
 *
 *  Created on: 30.06.2024
 *      Author: jonas
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch: public Medium {
public:
	Buch(std::string initTitel, std::string initAutor);

	std::string autor;

	void ausgabe(std::ostream&) const;

	virtual ~Buch();
};

#endif /* BUCH_H_ */
