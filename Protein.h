#pragma once
#include"sequence.h"
#include"DNA.h"
#include"RNA.h"
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class DNA;

enum Protein_Type{hormon,enzyme,TE,cellular_function};

class Protein:public sequence 
{
private:
	Protein_Type type;
public:
	Protein();
	Protein(char *p, Protein_Type atype,int length);//constructor that takes a pointer arr, type of DNA and a the length 
	DNA* get_DNAstrands_enoding_me(DNA&bigDNA);
	void print();//print the sequence of the protein and its type
	Protein operator+(Protein &obj);//operator takes two sequences and return a new sequence 
	bool operator==(Protein &obj);//see if the two sequences are equal
	bool operator!=(Protein &obj);//see if the two sequences are not equal
	friend ostream& operator<< (ostream& , Protein&);//print the sequence of the protein and its type
	friend istream& operator>> (istream&, Protein&);//takes from the user the sequence of the protein and its type
	void load_from_file(string codons_file_name);//load protein data from file
	void load_to_file(string codons_file_name);//load protein data to file
	~Protein();
};

