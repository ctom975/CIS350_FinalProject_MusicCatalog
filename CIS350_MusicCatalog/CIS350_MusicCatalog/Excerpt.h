#pragma once
#include "string"
#include <vector>

using namespace std;
class Excerpt
{
private:
	string name;
	vector<string> inst_codes;	// Instrument Code(s)

public:
	// Constructor
	Excerpt();
	Excerpt(string, vector<string>);

	// Getters
	string get_name() const;
	vector<string> get_inst_codes() const;

	// Setters
	void set_name(string);
	void set_inst_codes(vector<string>);
	void add_inst_code(string);

	// Utilities
	bool has_inst_code(string) const;
};