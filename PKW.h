/*
 * PKW.h
 *
 *  Created on: 23.10.2024
 *      Author: Jonas
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"
#include <iostream>

class PKW : public Fahrzeug{
public:
	PKW() = delete;
	PKW(std::string p_sName, double p_dMaxGeschwindigkeit, double p_dVerbrauch);//Konstruktor ohne optionalen Tankinhalt
	PKW(std::string p_sName, double p_dMaxGeschwindigkeit, double p_dVerbrauch, double p_dTankvolumen);
	double dTanken(double dMenge) override;
	void vSimulieren() override;
	static void vKopf();
	void vAusgeben(std::ostream& out) const override;
	double dGeschwindigkeit() const override;
	std::unique_ptr<Fahrzeug> fahrzeugErstellen() override;
	void vZeichnen(Weg& weg) const override;

	double getTankvolumen();
	double getTankinhalt();

	virtual ~PKW();

private:
	double p_dVerbrauch;
	double p_dTankvolumen;
	double p_dTankinhalt;
};

#endif /* PKW_H_ */
