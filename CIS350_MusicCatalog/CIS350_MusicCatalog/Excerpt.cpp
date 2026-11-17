#include "Excerpt.h"

// Constructor
Excerpt::Excerpt()
{

}
Excerpt::Excerpt(string n, vector<string> ic)
{
	name = n;
	inst_codes = ic;
}

// Getters
string Excerpt::get_name() const
{
	return name;
}
vector<string> Excerpt::get_inst_codes() const
{
	return inst_codes;
}

// Setters
void Excerpt::set_name(string n)
{
	name = n;
}
void Excerpt::set_inst_codes(vector<string> ic)
{
	inst_codes = ic;
}
void Excerpt::add_inst_code(string ic)
{
	inst_codes.push_back(ic);
}

// Utilities
bool Excerpt::has_inst_code(string inst_code) const
{
	// Check if the inst_codes vector contains an inst_code
	vector<string> ics = get_inst_codes();
	auto itr = find(ics.begin(), ics.end(), inst_code);

	// If the iterator reaches the end, no result was found
	return (itr == ics.end()) ? false : true;
}