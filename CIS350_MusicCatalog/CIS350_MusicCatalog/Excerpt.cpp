#include "Excerpt.h"

// Constructor
Excerpt::Excerpt()
{

}
Excerpt::Excerpt(string n, string ic)
{
	name = n;
	inst_code = ic;
}

// Getters
string Excerpt::get_name() const
{
	return name;
}
string Excerpt::get_inst_code() const
{
	return inst_code;
}

// Setters
void Excerpt::set_name(string n)
{
	name = n;
}
void Excerpt::set_inst_code(string ic)
{
	inst_code = ic;
}