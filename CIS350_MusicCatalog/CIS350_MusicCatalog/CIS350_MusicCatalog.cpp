// ======================================================================
// CIS-350-001 - Final Project: Symphony Instrument and Music Catalog
// Made by: Cody, Christian, Angela
// Dataset: https://www.upf.edu/web/mtg/irmas
// Date: 2026-10-31
// ======================================================================

#include <iostream>
#include <unordered_map>
#include "Excerpt.h"

using namespace std;

// Instrument Code -> Instrument Key
const unordered_map<string, string> INSTRUMENTS = {
    { "cel", "Cello" },
    { "cla", "Clarinet" },
    { "flu", "Flute" },
    { "gac", "Acoustic Guitar" },
    { "gel", "Electric Guitar" },
    { "org", "Organ" },
    { "pia", "Piano" },
    { "sax", "Saxophone" },
    { "tru", "Trumpet" },
    { "vio", "Violin" },
    { "voi", "Human Singing Voice" }
};

string menu_get_instrument()
{
    // TODO: Implement

    /*
    * Ouput might look something like this
    * 
    * Available Instruments:
    * 1. Cello
    * 2. Clarinet
    * 3. Flute
    * 4. Acoustic Guitar
    * ...
    * 
    * Enter a number that corresponds to an instrument above: 2
    * 
    * Which returns:
    *     2 -> Clarinet -> cla
    *     return: cla
    */
}

string menu_get_excerpt()
{
    // TODO: Implement

    /*
    * Output might look something like this
    * 
    * Chosen instrument: Clarinet
    * Enter the name of an excerpt you wish to find (Case-Sensitive):
    * > 02. Yesterdays-10
    * 
    * <search performed here>
    * 
    * Found 1 match:
    * - Name: 02. Yesterdays-10
    * - Instruments:
    *   > Clarinet
    *   > Piano
    */
}

void avl_implementation()
{
    // TODO: Implement
    return;
}

void hash_implementation()
{
    // TODO: Implement
    return;
}

int main()
{
    // Uncomment a line below to run an implemnetation using a specific data structure
    //avl_implementation();   // AVL Trees
    //hash_implementation();  // Hash Map
}
