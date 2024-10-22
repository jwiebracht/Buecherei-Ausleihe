/*!
 * Praktikum Informatik 1 
 *
 * @file Medium.cpp
 * @brief Implementierung der Klasse Medium
 *
 * Diese Datei enthält die Implementierung der Klasse Medium,
 * die grundlegende Eigenschaften und Funktionen eines Mediums bereitstellt.
 */

#include "Medium.h"

#include <string>
#include <iostream>

unsigned int Medium::currentID = 1;

/*!
 * @brief Konstruktor für die Klasse Medium
 *
 * Initialisiert ein Medium-Objekt mit dem gegebenen Titel und weist eine eindeutige ID zu.
 *
 * @param initTitel Der Titel des Mediums
 */
Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

/*!
 * @brief Destruktor für die Klasse Medium
 *
 * Räumt Ressourcen auf, die von einem Medium-Objekt verwendet wurden.
 * Der Destruktor wird hier leer gelassen, da keine speziellen
 * Aufräumaktionen erforderlich sind.
 */
Medium::~Medium(void)
{
}

/*!
 * @brief Gibt die Details des Mediums aus
 *
 * Diese Methode gibt die ID, den Titel und den Status des Mediums auf dem angegebenen Ausgabestream aus.
 *
 * @param out Der Ausgabestream, auf den die Informationen geschrieben werden
 */
void Medium::ausgabe(std::ostream& out) const
{
    if (status)
    {
        out << "ID: " << ID << std::endl
            << "Titel: " << titel << std::endl
            << "Status : Das Medium ist seit dem " << datumAusgeliehen
            << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    }
    else
    {
    	out << "ID: " << ID << std::endl
            << "Titel: " << titel << std::endl
            << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}

/*!
 * @brief Versucht, das Medium an eine Person auszuleihen
 *
 * Diese Methode überprüft, ob das Medium bereits verliehen ist und leiht es aus, falls dies nicht der Fall ist.
 *
 * @param person Die Person, die das Medium ausleihen möchte
 * @param ausleihdatum Das Datum, an dem das Medium ausgeliehen wird
 * @return true, wenn das Medium erfolgreich ausgeliehen wurde, false, wenn das Medium bereits verliehen ist
 */
bool Medium::ausleihen(Person person, Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}

/*!
 * @brief Gibt das Medium zurück
 *
 * Diese Methode setzt den Status des Mediums zurück, wenn es verliehen war.
 */
void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zurückgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}

/*!
 * @brief Gibt die ID des Mediums zurück
 *
 * @return Die ID des Mediums
 */
unsigned int Medium::getID()
{
    return ID;
}

/*!
 * @brief Gibt den Status des Mediums zurück
 *
 * @return true, wenn das Medium verliehen ist, false sonst
 */
bool Medium::getStatus()
{
	return status;
}

/*!
 * @brief Überladener Ausgabestreamoperator für die Klasse Medium
 *
 * Diese Methode ermöglicht die Ausgabe der Details eines Mediums durch den << Operator.
 *
 * @param out Der Ausgabestream
 * @param medium Das Medium, dessen Details ausgegeben werden sollen
 * @return Der Ausgabestream mit den Details des Mediums
 */
std::ostream& operator<<(std::ostream& out, const Medium& medium)
{
	medium.ausgabe(out);
	return out;
}
