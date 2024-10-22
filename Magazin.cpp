/**
 * @file Magazin.cpp
 * @brief Implementierung der Klasse Magazin
 *
 * Diese Datei enthält die Implementierung der Klasse Magazin,
 * die eine spezialisierte Form des Mediums darstellt und
 * zusätzliche Informationen wie Erscheinungsdatum und Sparte enthält.
 *
 * @author Jonas
 * @date 30.06.2024
 */

#include "Magazin.h"
#include "Datum.h"

/**
 * @brief Konstruktor für die Klasse Magazin
 *
 * Initialisiert ein Magazin-Objekt mit dem gegebenen Titel, Erscheinungsdatum und der Sparte.
 *
 * @param initTitel Der Titel des Magazins
 * @param initDatumAusgabe Das Erscheinungsdatum des Magazins
 * @param initSparte Die Sparte des Magazins
 */
Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte) : Medium(initTitel),
erscheinungsDatum(initDatumAusgabe), Sparte(initSparte)
{
}

/**
 * @brief Gibt die Details des Magazins aus
 *
 * Diese Methode gibt den Titel des Mediums, das Erscheinungsdatum und die Sparte des Magazins auf dem angegebenen Ausgabestream aus.
 *
 * @param out Der Ausgabestream, auf den die Informationen geschrieben werden
 */
void Magazin::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
	out << "Erscheinungsdatum: " << erscheinungsDatum << std::endl << "Sparte: " << Sparte << std::endl;
}

/**
 * @brief Versucht, das Magazin an eine Person auszuleihen
 *
 * Diese Methode überprüft, ob das Magazin älter als einen Monat ist und leiht das Magazin aus, falls dies der Fall ist.
 *
 * @param person Die Person, die das Magazin ausleihen möchte
 * @param ausleihdatum Das Datum, an dem das Magazin ausgeliehen wird
 * @return true, wenn das Magazin erfolgreich ausgeliehen wurde, false, wenn das Magazin noch keinen Monat alt ist
 */
bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
	Datum aktuellesDatum;
	if(aktuellesDatum - erscheinungsDatum > 1)
	{
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}
	else
	{
		std::cout << "Das gewünschte Magazin ist noch keinen Monat erschienen also nicht ausleihbar" << std::endl;
		return false;
	}
}

/**
 * @brief Destruktor für die Klasse Magazin
 *
 * Räumt Ressourcen auf, die von einem Magazin-Objekt verwendet wurden.
 * Der Destruktor wird hier leer gelassen, da keine speziellen
 * Aufräumaktionen erforderlich sind.
 */
Magazin::~Magazin() {
	// TODO Auto-generated destructor stub
}

