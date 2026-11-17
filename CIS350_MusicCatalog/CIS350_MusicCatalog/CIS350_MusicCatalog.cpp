// ======================================================================
// CIS-350-001 - Final Project: Symphony Instrument and Music Catalog
// Made by: Cody, Christian, Angela
// Dataset: https://www.upf.edu/web/mtg/irmas
// Date: 2026-10-31
// ======================================================================

#include <iostream>
#include <unordered_map>
#include <vector>
#include "Excerpt.h"
#include "AVLTree.h"

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

vector<Excerpt> build_excerpts()
{
    // TODO: Implement
    // Read CSV file (comma-separated)
    // Parse instrument codes (string /w codes separated by commas) to vector<string>
    // Create excerpt for each line except line 1 (header)
}

vector<Excerpt> get_excerpts_with_instrument(string inst_code, vector<Excerpt> excerpts)
{
    // List of all excerpts that contain a certain instrument code
    vector<Excerpt> filtered_excerpts;

    // Iterate through all excerpts in the list
    for (const Excerpt& e : excerpts)
    {
        // If an excerpt has a specified instrument code, add it to the filtered list
        if (e.has_inst_code(inst_code))
        {
            filtered_excerpts.push_back(e);
        }
    }

    return filtered_excerpts;
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
    avl_implementation();   // AVL Trees
    //hash_implementation();  // Hash Map
}
