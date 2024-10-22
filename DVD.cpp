/**
 * @file DVD.cpp
 * @brief Implementierung der Klasse DVD
 *
 * Diese Datei enthält die Implementierung der Klasse DVD,
 * die eine spezialisierte Form des Mediums darstellt und
 * zusätzliche Informationen wie Altersfreigabe und Genre enthält.
 *
 * @author Jonas
 * @date 30.06.2024
 */

#include "DVD.h"

/**
 * @brief Konstruktor für die Klasse DVD
 *
 * Initialisiert ein DVD-Objekt mit dem gegebenen Titel, der Altersfreigabe und dem Genre.
 *
 * @param initTitel Der Titel der DVD
 * @param initAltersfreigabe Die Altersfreigabe der DVD
 * @param initGenre Das Genre der DVD
 */
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) : Medium(initTitel),
altersFreigabe(initAltersfreigabe), genre(initGenre)
{
}

/**
 * @brief Gibt die Details der DVD aus
 *
 * Diese Methode gibt den Titel des Mediums, die Altersfreigabe und das Genre der DVD auf dem angegebenen Ausgabestream aus.
 *
 * @param out Der Ausgabestream, auf den die Informationen geschrieben werden
 */
void DVD::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
	out << "Altersfreigabe: " << altersFreigabe << std::endl << "Genre: " << genre << std::endl;
}

/**
 * @brief Versucht, die DVD an eine Person auszuleihen
 *
 * Diese Methode überprüft, ob die Person die Altersfreigabe erfüllt und leiht die DVD aus, falls dies der Fall ist.
 *
 * @param person Die Person, die die DVD ausleihen möchte
 * @param ausleihdatum Das Datum, an dem die DVD ausgeliehen wird
 * @return true, wenn die DVD erfolgreich ausgeliehen wurde, false, wenn die Altersfreigabe nicht erfüllt ist
 */
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	Datum aktuellesDatum;
	if(aktuellesDatum - person.getGeburtsdatum() > altersFreigabe * 12)
	{
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}
	else
	{
		std::cout << "Du erfüllst die Altersvorgabe nicht, du darfst diese DVD noch nicht ausleihen" << std::endl;
		return false;
	}
}

/**
 * @brief Destruktor für die Klasse DVD
 *
 * Räumt Ressourcen auf, die von einem DVD-Objekt verwendet wurden.
 * Der Destruktor wird hier leer gelassen, da keine speziellen
 * Aufräumaktionen erforderlich sind.
 */
DVD::~DVD() {
	// TODO Auto-generated destructor stub
}


