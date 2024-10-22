/*
 * Magazin.h
 *
 *  Created on: 30.06.2024
 *      Author: jonas
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"

class Magazin: public Medium {
public:
	Magazin();
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

	Datum erscheinungsDatum;
	std::string Sparte;

	void ausgabe(std::ostream& out) const;
	bool ausleihen(Person person,Datum ausleihdatum);

	virtual ~Magazin();
};

#endif /* MAGAZIN_H_ */
