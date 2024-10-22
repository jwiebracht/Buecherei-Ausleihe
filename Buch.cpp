/**
 * @file Buch.cpp
 * @brief Implementierung der Klasse Buch
 *
 * Diese Datei enthält die Implementierung der Klasse Buch,
 * die eine spezialisierte Form des Mediums darstellt und
 * zusätzliche Informationen wie den Autor enthält.
 *
 * @author Jonas
 * @date 30.06.2024
 */

#include "Buch.h"

/**
 * @brief Konstruktor für die Klasse Buch
 *
 * Initialisiert ein Buch-Objekt mit dem gegebenen Titel und Autor.
 *
 * @param initTitel Der Titel des Buches
 * @param initAutor Der Autor des Buches
 */
Buch::Buch(std::string initTitel, std::string initAutor) : Medium(initTitel), autor(initAutor)
{
}

/**
 * @brief Gibt die Details des Buches aus
 *
 * Diese Methode gibt den Titel des Mediums und den Autor des Buches auf dem angegebenen Ausgabestream aus.
 *
 * @param out Der Ausgabestream, auf den die Informationen geschrieben werden
 */
void Buch::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
	out << "Der Autor der Buches ist: " << autor << std::endl;
}

/**
 * @brief Destruktor für die Klasse Buch
 *
 * Räumt Ressourcen auf, die von einem Buch-Objekt verwendet wurden.
 * Der Destruktor wird hier leer gelassen, da keine speziellen
 * Aufräumaktionen erforderlich sind.
 */
Buch::~Buch() {
	// TODO Auto-generated destructor stub
}





