// ======================================================================
// CIS-350-001 - Final Project: Symphony Instrument and Music Catalog
// Made by: Cody, Christian, Angela
// Dataset: https://www.upf.edu/web/mtg/irmas
// Date: 2026-10-31
// ======================================================================

#include <iostream>
#include <fstream>
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

    return "";
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

    return "";
}

vector<string> split_str(string s, char delim)
{
    vector<string> split;
    size_t substr_start;
    size_t substr_end = 0;

    // Get the start of the substring by finding the first non-delimiter character
    while ((substr_start = s.find_first_not_of(delim, substr_end)) != string::npos)
    {
        // Find the next instance of the delimiter to get the end of the substring.
        substr_end = s.find(delim, substr_start);

        // Add the substring, from the start to delimiter, to the vector.
        string substr = s.substr(substr_start, substr_end - substr_start);

        if (!substr.empty())
        {
            split.push_back(substr);
        }
    }

    return split;
}

vector<Excerpt> build_excerpts(string file_name)
{
    // Read CSV file (comma-separated)
    // Parse instrument codes (string /w codes separated by commas) to vector<string>
    // Create excerpt for each line except line 1 (header)
    vector<Excerpt> excerpts;
    ifstream file(file_name);
    string text_line;
    char delim = ',';

    // Ensure file is open
    if (!file.is_open())
    {
        cerr << "Error: Could not open file \'" << file_name << "\'\n";
        return excerpts;
    }

    // File exists
    bool first_line = true;
    while (getline(file, text_line))
    {
        // Read each line

        if (first_line)
        {
            // Skip first line as it contains the header, not data.
            first_line = false;
            continue;
        }

        if (text_line.empty())
        {
            // Skip any empty line
            continue;
        }

        // Get excerpt name
        size_t pos = text_line.find(delim);

        if (pos == string::npos)
        {
            // Line doesn't contain delimiter, so it is malformed.
            continue;
        }
        
        string ex_name = text_line.substr(0, pos);

        // Get instrument codes
        string ex_codes_str = text_line.substr(pos + 1);
        vector<string> ex_codes;

        if (ex_codes_str.find(delim) == string::npos && !ex_codes_str.empty())
        {
            // Only 1 instrument code found.
            ex_codes.push_back(ex_codes_str);
        }
        else
        {
            // Multiple instrument codes found.
            // Remove quotes from start and end
            ex_codes_str = ex_codes_str.substr(1, ex_codes_str.length() - 2);
            ex_codes = split_str(ex_codes_str, delim);
        }
            
        //Create Excerpt and add to vector
        excerpts.emplace_back(ex_name, ex_codes);
    }

    file.close();
    return excerpts;
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

void avl_implementation(string file_name)
{
    // TODO: Maybe keep track of all successful & failed searches?
    // TODO: Add way to calculate time for each search and entire algorithm.
    vector<Excerpt> excerpts = build_excerpts(file_name);

    // Iterate through all key-value pairs in the INSTRUMENTS map
    // This will be to create an AVL Tree for every type of instrument code
    for (auto const& pair : INSTRUMENTS)
    {
        // Get instrument code
        string inst_code = pair.first;

        cout << "Testing AVL Implementation with Instrument: " << inst_code << '\n';

        // Create a vector with only the Excerpts that contain the specified instrument code
        vector<Excerpt> filtered = get_excerpts_with_instrument(inst_code, excerpts);

        // Create AVL Tree
        AVLTree avl;
        for (const Excerpt& e : filtered)
        {
            // Add each excerpt to the avl tree
            avl.add_node(e.get_name());
        }

        for (const Excerpt& e : excerpts)
        {
            // Search for every excerpt name in the AVL Tree
            string ex_name = e.get_name();

            if (avl.is_empty())
            {
                cerr << "> Error: Tree is empty!\n";
                break;
            }

            // Find the node wth the excerpt name
            cout << "> Searching for node with name \'" << ex_name << "\'...\n";

            if (avl.contains(ex_name))
            {
                // AVL tree does not contain a node with the excerpt name
                cout << "> X Failed to find node with name \'" << ex_name << "\'!\n";
                continue;
            }

            // Node was found with excerpt name in the tree
            cout << "> O Found node with name \'" << ex_name << "\'!\n";
        }
    }
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
    avl_implementation("..\\..\\Datasets\\CSVs\\irmas_dataset_100.csv");   // AVL Trees
    //hash_implementation();  // Hash Map
}
