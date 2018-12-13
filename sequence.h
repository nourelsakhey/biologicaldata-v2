#pragma once
#include<string>
#include<iostream>
using namespace std;

class sequence
{
protected:
	char* seq;
	int length;


public:
	
	sequence();//constructor 
	sequence(int length);//constructor that takes the length
	sequence(sequence& rhs);//copy constructor
	virtual void print() = 0;
	virtual void load_to_file(string codons_file_name) = 0;
	virtual void load_from_file(string codons_file_name) = 0;
	friend char* Align(sequence * s1, sequence *s2);//print the common letters in two sequence

	virtual ~sequence();
};

