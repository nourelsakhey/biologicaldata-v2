/*#include "Condonstable.h"



Condonstable::Condonstable()
{


}
void Condonstable::load_condons_from_file(string condons_file_name)
{
	file.open(condons_file_name);
	while (!file.eof())
	{


		for (int i = 0;i < 64;i++) {
			for (int j = 0;j < 3;j++) {
				file >> condons[i].value[j];
			}
			file >> condons[i].aminoacid;
		}


	}
}
condon Condonstable::get_aminoacid(char*value)
{
	bool check = true;
	for (int i = 0;i < 64;i++) {
		for (int j = 0;j < 3;j++) {
			if (condons[i].value[j] != value[j]) {
				break;
			}



		}


	}



}
void Condonstable:: set_condon(char*value, char aminoacid, int index)
{

}

Condonstable::~Condonstable()
{
	file.close();
}*/
#include"Condonstable.h"

Codonstable::Codonstable()
{

}
Codonstable::~Codonstable()
{

}

void Codonstable::load_codons_from_file(string codonsFileName)
{
	int i = 0;
	string reader;
	file.open(codonsFileName);
	while (file >> reader)
	{
		int i = 0;
		string reader;
		file.open(codonsFileName);
		while (file >> reader)
		{
			// cout <<reader<<endl;
			for (int j = 0; j < 3; j++)
			{
				codons[i].value[j] = reader[j];
			}
			if (reader.length() % 2 == 0)
				codons[i].aminoacid = reader[3];
			else
				codons[i].aminoacid = '*';
			codons[i].value[3] = '\0';
			cout << codons[i].value;
			cout << codons[i].aminoacid << endl;
			i++;


		}
	}
}

codon Codonstable::get_aminoacid(char * value)
{
	int count_ = 0, index = 0;
	bool check = true;
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 3; j++) {
			if (codons[i].value[j] != value[j]) {

				break;
			}
			else
				continue;
			count_++;
		}
		if (count_ == 3)
		{
			break;
			index = i;
		}

	}
	return codons[index];
}
void Codonstable::set_codon(char * value, char aminoacid, int index)
{
	codons[index].aminoacid = aminoacid;
	for (int i = 0; i < 3; i++)
	{
		codons[index].value[i] = value[i];
	}
	codons[index].value[3] = '\0';
}