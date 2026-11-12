#pragma once
#include "string"

using namespace std;
class Excerpt
{
private:
	string name;
	string inst_code;	// Instrument Code

public:
	// Constructor
	Excerpt();
	Excerpt(string, string);

	// Getters
	string get_name() const;
	string get_inst_code() const;

	// Setters
	void set_name(string);
	void set_inst_code(string);
};