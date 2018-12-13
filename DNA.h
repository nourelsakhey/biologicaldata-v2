#pragma once
#include"sequence.h"
#include"RNA.h"
#include<iostream>
#include <fstream>
using namespace std;


class RNA;
enum DNA_type { promoter, motif, tail, noncoding };

class DNA:public sequence
{
private:
	DNA_type type;
	DNA *complemantary_strand;
	int start_char;
	int end_char;

public:
	class notEqualSize{};
	DNA();//defult constructor
	DNA(char *aseq,DNA_type atype,int length);//constructor takes ponter arr ,type of the sequence and the length of the sequence
	DNA(DNA &rhs);//copy constructor 
	void print();//print the sequence of the DNA and its type
	RNA convert_to_RNA();//convert the DNA sequence to RNA 
	void build_complemantary_strand();//build the complemantery of the DNA
	void set_endchar(int x);//set the end char takes from the user the end char
	void set_startchar(int y);//set the start char takes from the user the start char
	int get_endchar();//print the end char
	int get_startchar();//print the start char
	DNA operator+(DNA &obj);//operator add the two sequences of DNA 
	bool operator==(DNA &obj);//see if the two DNA are the same
	bool operator!=(DNA &obj);//see if the two DNA are the diffrent
	friend ostream& operator<< (ostream&, DNA&);//print a DNA to the user
	friend istream& operator>> (istream&, DNA&);//take a DNA from the user
	void load_to_file(string codons_file_name);//load DNA data to a file
	void load_from_file(string codons_file_name);//load DNA data from a file

	

	~DNA();//destructor
};

