#include<iostream>
#include"sequence.h"
#include"DNA.h"
#include"Protein.h"
#include"Condonstable.h"
#include"RNA.h"
#include <exception>
using namespace std;

class MyException :public exception {
public:
	virtual const char* what() const throw() {
		return "This character is not available\n enter the character again\n";
	}
};
class MyException2 :public exception {
public:
	virtual const char* what() const throw() {
		return "This character is not available enter the character again\n";
	}
};
class MyException3 :public exception {
public:
	virtual const char* what() const throw() {
		return "This character is not available enter the character again";
	}
};
bool charSequenceDNA(char &z) {//cheks if the char the user entered is not valid
	MyException e;
	bool check = true;
	try {
		if ((z != 'A') && (z != 'T') && (z != 'C') && (z != 'G')) {
			throw e;
			check = true;
		}
	}
	catch (MyException &e) {
		cout<<e.what();
		check = false;
		}
	return check;
}
bool charSequenceRNA(char &z) {//cheks if the char the user entered is not valid
	MyException2 e;
	bool check = true;
	try {
		if ((z != 'A') && (z != 'U') && (z != 'C') && (z != 'G')) {
			throw e;
			check = true;
		}
	}
	catch (MyException2 &e) {
		cout << e.what();
		check = false;
	}
	return check;
}
bool charSequenceProtein(char &z) {//cheks if the char the user entered is not valid
	MyException3 e;
	bool check = true;
	try {
		if ((z == 'B') || (z == 'J') || (z == 'O') || (z == 'U')||(z=='X') || (z == 'Z')) {
			throw e;
			check = true;
		}
	}
	catch (MyException3 &e) {
		cout << e.what();
		check = false;
	}
	return check;
}
DNA_type add_DNA_type(int x) {//takes a DNA type from the user
	DNA_type atype;
	if (x == 1) {
		atype = promoter;
	}
	else if (x == 2) {
		atype = motif;
	}
	else if (x == 3) {
		atype = tail;
	}
	else if (x == 4) {
		atype = noncoding;
	}
	return atype;
}
RNA_type add_RNA_type(int x) {//takes a RNA type from the user
	RNA_type atype;
	if (x == 1) {
		atype = mRNA;
	}
	else if (x == 2) {
		atype = tRNA;
	}
	else if (x == 3) {
		atype = pre_mRNA;
	}
	else if (x == 4) {
		atype = mRNA;
	}
	else if (x == 5) {
		atype = mRNA_exon;
	}
	else if (x == 6) {
		atype = mRNA_intron;
	}
	return atype;
}
Protein_Type add_Protein_type(int x) {//takes a Protein type from the user
	Protein_Type atype; 
	if (x == 1) {
		atype = hormon;
	}
	else if (x == 2) {
		atype = enzyme;
	}
	else if (x == 3) {
		atype = TE;
	}
	else if (x == 4) {
		atype = cellular_function;
	}
	return atype;
}

int main() {


	int choise,x,y,z;
	cout << "welcome to the biological data program" << endl;
	cout << "what type of biological data you want to enter" << endl << "1-DNA  2-RNA  3-Protein  0-end" << endl;
		cin >> choise;
		while (choise != 0) {
			if (choise == 1) {
				cout << "enter the size of the sequence" << endl;
				cin >> x;
				char*ARR;
				ARR = new char[x];
				for (int i = 0;i < x;i++) {
					do {
						cin >> ARR[i];
						//charSequence(ARR[i]);

					} while (!charSequenceDNA(ARR[i]));

				}

				cout << "Enter the type of dna you want: 1-promoter 2-motif 3-tail 4-noncoding";
				cin >> z;
				cout << endl;
				DNA d1(ARR, add_DNA_type(z), x);
				cout << "what operation you want to do" << endl << "1-print the strand   2-built the complement strand   3-convert to RNA   4-load a DNA data from file  5-load DNA data to file  6-Find LCS Align" << endl;
				cin >> y;
				if (y == 1) {
					d1.print();
					cout << endl;
				}
				else if (y == 2) {
					d1.build_complemantary_strand();
					cout << endl;
				}
				else if (y == 3) {
					d1.convert_to_RNA();
					cout << endl;
				}
				else if (y == 5) {
					string name;
					cout << "Enter the file name";
					cin >> name;
					d1.load_to_file(name);
				}
				else if (y == 4) {
					string name;
					cout << "Enter the file name";
					cin >> name;
					d1.load_from_file(name);
					//d1.print();
				}
				else if (y == 6)
				{
					sequence* s1;
					s1 = new DNA(ARR, add_DNA_type(z), x);
					sequence* s2;
					s2 = new DNA(ARR, add_DNA_type(z), x);
					cout << Align(s1, s2);
				}

			}
		else if (choise == 2) {
			cout << "enter the size of the sequence"<<endl;
			cin >> x;
			char*ARR;
			ARR = new char[x];
			for (int i = 0;i < x;i++) {
				do {
					cin >> ARR[i];

				} while (!charSequenceRNA(ARR[i]));

			}
			cout << "Enter the type of RNA you want: 1-mRNA 2-tRNA 3-uRNA 4-pre_mRNA 5-mRNA_exon 6-mRNA_intron";
			cin >> y;
			cout << endl;
			RNA r1(ARR, add_RNA_type(y), x);
			cout << "what operation you want to do" << endl << "1-print the strand   2-convert to DNA   3-convert to Protein   4-load a RNA data from file  5-load RNA data to file" << endl;
			cin >> y;
			if (y == 1) {
				r1.print();
				cout << endl;
			}
			else if (y == 2) {
				r1.convert_to_DNA();
				cout << endl;
			}
			else if (y == 3) {
				Codonstable c1;
				r1.convert_to_Protien(c1);
				cout << endl;
			}
			else if (y == 5) {
				string name;
				cout << "Enter the file name";
				cin >> name;
				r1.load_to_file(name);
			}
			else if (y == 4) {
				string name;
				cout << "Enter the file name";
				cin >> name;
				r1.load_from_file(name);
			}
		}
		else if (choise == 3) {
			cout << "enter the size of the sequence";
			cin >> x;
			cout << endl;
			char*ARR;
			ARR = new char[x];
			for (int i = 0;i < x;i++) {
				do {
					cin >> ARR[i];

				} while (!charSequenceProtein(ARR[i]));

			}
			cout << "Enter the type of Protein yo want: 1-hormon 2-enzyme 3-TE 4-cellular_function" << endl;
			cin >> y;
			Protein p1(ARR, add_Protein_type(y), x);
			p1.print();
			cout << "what operation you want to do" << endl << "1-print the strand    2-convert to DNA   3-load a Protein data from file  4-load Protein data to file" << endl;
			cin >> y;
			if (y == 1) {
				p1.print();
				cout << endl;
			}
			else if (y == 4) {
				string name;
				cout << "Enter the file name";
				cin >> name;
				p1.load_to_file(name);
			}
			else if (y == 3) {
				string name;
				cout << "Enter the file name";
				cin >> name;
				p1.load_from_file(name);
				//p1.print();
			}


		}
			

		cin >> choise;

	    }

		cout << endl;
	int sizee;
	cout << "enter the size of the sequence";
	cin >> sizee;
	char*ARR;
	ARR = new char[sizee];
	char*arr;
	arr = new char[6];
	char ARR1[] = { 'A', 'C', 'G', 'G', 'G', 'T' };
	arr = ARR1;
	for (int i = 0;i < sizee;i++) {
		do {
			cin >> ARR[i];
			//charSequence(ARR[i]);

		} while (!charSequenceDNA(ARR[i]));
	}
	DNA d2(arr, promoter,sizee);
	d2.print();
	cout << endl << endl;
	DNA d3(ARR, promoter, sizee);
	d3.print();
	cout << endl << endl;
	DNA d4(ARR1,promoter,sizee);
	d4.print();
	cout << endl << endl;
	bool check;
	
	check = (d3 == d2);
	cout <<check<<endl<<endl;
	
	check=(d2 != d3);
	cout <<check<< endl << endl;
	check = (d2 != d4);
	cout<<check<<endl <<endl;
	check = (d2 == d4);
	cout << check << endl << endl;
	cin >> sizee;
	

	


	return 0;
}