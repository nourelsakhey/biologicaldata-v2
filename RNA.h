#pragma once
#include"sequence.h"
#include"DNA.h"
#include"Protein.h"
#include"Condonstable.h"
#include<iostream>
#include<string>
using namespace std;

class DNA;
enum RNA_type{mRNA,tRNA,uRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA:public sequence
{
private:
	RNA_type type;
	
public:
	RNA();//defult constructor
	RNA(char *seq, RNA_type atype,int length);//constructor that takes a pointer arr, type of DNA and a the length 
	RNA(RNA&rhs);//copy constructor
	void print();//print the sequence of the RNA and its type
	Protein convert_to_Protien(Codonstable &table);//convert the RNA to Protein
	DNA convert_to_DNA();//convert RNA to protein
	RNA operator+(RNA &obj);//operator takes two sequences and return a new sequence 
	bool operator==(RNA &obj);//see if the two sequences are equal
	bool operator!=(RNA &obj);//see if the two sequences are not equal
	friend ostream& operator<< (ostream&, RNA&);//print a RNA data
	friend istream& operator>> (istream&, RNA&);//takes RNA data from the user
	void load_to_file(string codons_file_name);//load RNA data to file
	void load_from_file(string codons_file_name);//load RNA data from file
	~RNA();//destructor
};

