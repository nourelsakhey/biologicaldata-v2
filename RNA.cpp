#include "RNA.h"



RNA::RNA()
{
}

RNA::RNA(char *aseq, RNA_type atype,int length) :sequence(length)
{
	for (int i = 0;i < length;i++)
	{
		seq[i] = aseq[i];

	}
	type = atype;
	
	
}

RNA::RNA(RNA&rhs)
{
	rhs.seq = seq;
	rhs.type = type;
}

void RNA::print()
{
	cout << "the strand is: ";
	for (int i = 0;i < length;i++) {
		cout << seq[i];
	}
	cout << endl;
	cout << "its type is: ";
		switch (type)
		{
		case mRNA:
			cout << "mRNA";
			break;
		case tRNA:
			cout << "tRNA";
			break;
		case uRNA:
			cout << "uRNA";
			break;
		case pre_mRNA:
			cout << "pre_mRNA";
			break;
		case mRNA_exon:
			cout << "mRNA_exon";
			break;
		case mRNA_intron:
			cout << "mRNA_intron";
			break;
		default:
			break;
		}

	
}
Protein RNA::convert_to_Protien( Codonstable &table)
{
	//table.load_codons_from_file("RNA_codon_table.txt");out << "KKK";
	char*arr;
	char*arr2;
	arr2 = new char[length / 3];
	int index = 0;
	
	for (int i = 0;i < length;i=i+3) {
		for (int j = 0;j < 3;j=j+3) {
			arr = new char[4];
			arr[j] = seq[i];
			arr[j + 1] = seq[i + 1];
			arr[j + 2] = seq[i + 2];
			arr[j + 3] = '\0';
		}
		
		arr2[index] = table.get_aminoacid(arr).aminoacid;
		cout << arr2[index];
		index++;
	}
	Protein_Type type = hormon;
	Protein p1(arr2, type, length / 3);
	p1.print();
	
	return p1;
	
}


DNA RNA::convert_to_DNA()
{
	char* arr;
	arr = new char;
	for (int i = 0;i<length;i++)
	{
		if (seq[i] == 'U')
		{
			arr[i] = 'T';
		}
		else
		{
			arr[i] = seq[i];
		}
	}
	DNA_type type = promoter;
	DNA D1(arr, type, length);
	cout << "the DNA from the RNA is:";
	cout<<endl;
	D1.print();
	return D1;

}

RNA RNA::operator+(RNA &obj) {
	char *newseq;
	newseq = new char[length + obj.length];
	for (int i = 0;i < length;i++) {
		newseq[i] = seq[i];
	}
	for (int j = 0;j < obj.length;j++) {
		newseq[length + j] = obj.seq[j];
	}
	RNA rRna(newseq, type, length + obj.length);
	return rRna;
}
bool RNA ::operator==(RNA&obj) {
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
	bool RNA::operator!=(RNA& obj) {
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

   ostream&operator<<(ostream &out, RNA &obj)
   {
		int x = 0;
		out << "the sequence is:";
		while (x < obj.length)
		{

			out << obj.seq[x] << " ";
			x++;
		}
		out << endl << "the type of sequence is:";
		switch (obj.type)
		{
		case mRNA:
			out << "mRNA";
			break;
		case tRNA:
			out << "tRNA";
			break;
		case uRNA:
			out << "uRNA";
			break;
		case pre_mRNA:
			out << "pre_mRNA";
			break;
		case mRNA_exon:
			out << "mRNA_exon";
			break;
		case mRNA_intron:
			out << "mRNA_intron";
			break;
		default:
			break;
		}
		return out;
   }


istream& operator>> (istream&in, RNA& obj)
{
	cout << "enter the length of the sequence:";
	in >> obj.length;
	cout << "enter the sequence:" << endl;
	for (int i = 0; i < obj.length; i++)
	{
		in >> obj.seq[i];
	}
	cout << "enter the type of the RNA";
	//in >> obj.type;
	return in;
}
void RNA::load_to_file(string filename) {
	ofstream file(filename);
	file << "The sequence is:";
	for (int i = 0;i < length;i++) {
		file << seq[i] << " ";
	}
	file << endl;
	file <<"The type is"<< type;
}
void RNA::load_from_file(string filename) {
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
	for (int j = 0;j < length;j++) {
		cout << seq[j] << "   ";
	}
}



RNA::~RNA()
{
}