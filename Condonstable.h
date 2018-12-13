#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<cstring>
using namespace std;

class Protein;

struct codon
{
	char value[4]; // {a,b,c,'\0'}
	char aminoacid;


};

class Codonstable
{
private:
	codon codons[64];
	ifstream file;
public:
	Codonstable();//construcor
	void load_codons_from_file(string codons_file_name);//load codons sequence from file
	codon get_aminoacid(char*value);//get the aminoacid char
	void set_codon(char*value, char aminoacid, int index);//adds a new aminoacid
	~Codonstable();//destructor
};

