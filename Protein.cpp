#include "Protein.h"



Protein::Protein()
{
}

Protein::Protein(char *p, Protein_Type atype,int length):sequence(length)
{
	for (int i = 0;i < length;i++)
	{
		seq[i] = p[i];
	}
	type = atype;

}

DNA* Protein::get_DNAstrands_enoding_me( DNA&bigDNA)
{
	DNA*d = new DNA[100];
	char*temp = new char[100];
	int n = 0;
	for(int i=0;i<strlen(bigDNA.seq)-2;i++){
		int z = 0;
		for (int j = i;j < i + 3;j++) {
			temp[z] = bigDNA.seq[j];
			z++;
		}
		Codonstable c;
		for (int l = 0;l < 10;l++) {
			if (strcmp(c.codons[l].value, temp) == 0) {
				for (int m = 0;m < strlen(seq);a++) {
					if (c.codons[l].aminoacid == seq[m]) {
						strcpy(d[n].seq, temp);
							n++;
					}
				}
			}
		}
	}
}

void Protein::print()
{
	cout << "the strand is: ";
	for (int i = 0;i < length;i++)
	{
		cout << seq[i];
	}
	cout <<endl<< "the type is:";
	switch (type)
	{
	case hormon:
		cout << "hormon";
		break;
	case enzyme:
		cout << "enzyme";
		break;
	case TE:
		cout << "TE";
		break;
	case cellular_function:
		cout << "cellular_function";
		break;
	default:
		break;
	}

}
Protein Protein ::operator+(Protein &obj) {
	char *newseq;
	newseq = new char[length + obj.length];
	for (int i = 0;i < length;i++) {
		newseq[i] = seq[i];
	}
	for (int j = 0;j < obj.length;j++) {
		newseq[length + j] = obj.seq[j];
	}
	Protein rprotein(newseq, type, length + obj.length);
	return rprotein;
}

bool Protein ::operator==(Protein&obj) {
	if ((length == obj.length) && (type == obj.type))
	{

		for (int i = 0; i < length; i++)
		{
			if (seq[i] != obj.seq[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Protein::operator!=(Protein& obj) {
	if ((length == obj.length) && (type == obj.type))
	{
		for (int i = 0; i < length; i++)
		{
			if (seq[i] != obj.seq[i])
			{
				return true;
			}
		}

		return false;
	}
	else {
		return true;
	}
}

ostream&operator<<(ostream &out, Protein &obj)
{
	out << "the sequence is:";
	for (int i = 0; i < obj.length; i++)
	{

		out << obj.seq[i] << " ";
	}
	out << endl << "the type of sequence is:"; 
	switch (obj.type)
	{
	case hormon:
		out << "hormon";
		break;
	case enzyme:
		out << "enzyme";
		break;
	case TE:
		out << "TE";
		break;
	case cellular_function:
		out << "cellular_function";
		break;
	default:
		break;
	}
	return out;
}

istream& operator>> (istream&in, Protein& obj)
{
	cout << "enter the length of the sequence:";
	in >> obj.length;
	cout << "enter the sequence:" << endl;
	for (int i = 0; i < obj.length; i++)
	{
		in >> obj.seq[i];
	}
	cout << "enter the type of the Protein";
	//in >> obj.type;
	return in;
}
void Protein::load_to_file(string filename) {
	ofstream file(filename);
	file << "The sequence is:";
	for (int i = 0;i < length;i++) {
		file << seq[i] << " ";
	}
	file << endl;
	file <<"The type is:"<< type;
}
void Protein ::load_from_file(string filename) {
	char data;
	ifstream file(filename);
	int i = 0;
	int j = 0;
	while (file >> data) {
		i++;
	}
	length = i;
	//char *arr;
	//arr = new char[i];
	file.close();
	ifstream newfile(filename);
	while (newfile >> seq[j]) {
		j++;
	}
	cout << "the sequence is :";
	for (int j = 0;j < i;j++) {
		cout << seq[j] << "   ";
	}
}
Protein::~Protein()
{
}
