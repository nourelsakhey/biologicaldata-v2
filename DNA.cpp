#include "DNA.h"



DNA::DNA()
{
}
DNA::DNA(char*aseq, DNA_type atype,int length):sequence(length)
{
	for (int i = 0;i < length;i++)
	{
		seq[i]=aseq[i]  ;

	}
	type = atype;
}

DNA::DNA(DNA&rhs)
{
	type = rhs.type;
	this->seq = rhs.seq;

}
void DNA::print()
{	cout << "the strand is: " ;
	for (int i = 0;i < length;i++) {
		cout << seq[i];
	}
cout << endl;
cout << "the type of the strand is:";
switch (type)
{ 
case promoter:
	cout << "promoter";
	break;
case motif:
	cout << "motif";
case tail:
	cout << "tail";
case noncoding:
	cout << "noncoding";
default:
	break;
}

}

/*void DNA:: sett() {

	if ((get_endchar() - get_startchar()) > length) {
		throw 1 ;
	}
}*/

RNA DNA::convert_to_RNA()
{
	bool check=true;
	int x, y;
	cout << "enter the star char and the end char";
	cin >> x >> y;
	set_startchar(x);
	set_endchar(y);
	char* arr;
		arr = new char[end_char-start_char];
	for (int i = 0;i < end_char;i++) 
	{
		if (this->seq[i] == 'T') 
		{
			arr[i] = 'U';
		}
		else 
		{
			arr[i] = seq[i];
		}
	}
	RNA_type type= pre_mRNA;
	RNA R1(arr, type,get_endchar()-get_startchar());
	cout << "the RNA from the DNA is:" << endl;
	R1.print();
	return R1;

}

void DNA::build_complemantary_strand()
{
	complemantary_strand = new DNA;
	complemantary_strand->seq = new char[length];
	for (int i = 0;i < length;i++) {
		
		if (seq[i] == 'A')
		{
			complemantary_strand->seq[i] = 'T';
		}
		else if (seq[i] == 'T')
		{
			complemantary_strand->seq[i] = 'A';
		}
		else if (seq[i] == 'C')
		{
			complemantary_strand->seq[i] = 'G';
		}
		else if (seq[i] == 'G')
		{
			complemantary_strand->seq[i] = 'C';
		}
		else
		{
			complemantary_strand->seq[i] = seq[i];
		}


	}
	cout << "the sequence of the complemantary strand is:";
	for (int i = 0 ; i < length; i++) {
			cout << complemantary_strand->seq[i];
	}
	
	for (int i = 0; i < (length/2); i++)
	{
		char temp;
		temp = complemantary_strand->seq[i];
		complemantary_strand->seq[i] = complemantary_strand->seq[length-1 - i];
		complemantary_strand->seq[length-1 - i] = temp;
		cout << complemantary_strand->seq[i]<<endl;
		cout << complemantary_strand->seq[length - 1 - i] << endl;

		
		
	}
	
	
}

void DNA::set_endchar(int x) {
	end_char = x;
}
void DNA::set_startchar(int y) {
	start_char = y;
}

int DNA::get_endchar() {
	return end_char;
}
int DNA::get_startchar() {
	return start_char;
}
DNA DNA ::operator+(DNA &obj) {
		char *newseq;
	newseq = new char[length + obj.length];
	for (int i = 0;i < length;i++) {
		newseq[i] = seq[i];
	}
	for (int j = 0;j < obj.length;j++) {
		newseq[length + j] = obj.seq[j];
	}
	DNA rdna(newseq, type, length + obj.length);
		return rdna;
}

bool DNA ::operator==(DNA&obj) {
	if ((length == obj.length) )
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

bool DNA::operator!=(DNA& obj) {
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

ostream&operator<<(ostream &out, DNA &obj)
{
	int x=0;
	out << "the sequence is:";
	while (x<obj.length)
	{
		
			out << obj.seq[x] << " ";
			x++;
	}
	out << endl << "the type of sequence is:";
	switch (obj.type)
	{
	case promoter:
		out << "promoter";
		break;
	case motif:
		out << "motif";
	case tail:
		out << "tail";
	case noncoding:
		out << "noncoding";
	default:
		break;
	}

	return out;
}

istream& operator>> (istream&in, DNA & obj)
{
	cout << "enter the length of the sequence:";
	in >> obj.length;
	obj.type = promoter;
	obj.seq = new char[obj.length];
	cout << "enter the sequence:" << endl;
	for (int i = 0; i < obj.length; i++)

	{
		
		in >> obj.seq[i];
	}
	
	return in;
}
void DNA::load_to_file(string filename) {
	ofstream file(filename);
	file << "The squence is: ";
	for (int i = 0;i < length;i++) {
		file <<seq[i];
	}
	file << endl;
	file <<"The type is:"<< type;
	file.close();
}
void DNA::load_from_file(string filename) {
	char data;

    ifstream file(filename);
	int i = 0;
	int j = 0;
	while (file >> data) {
		i++;
	}
	length = i;
	file.close();
	ifstream newfile(filename);
	while (newfile >> seq[j]) {
		j++;
	}
	cout << "the sequence is :";
	for (int j = 0;j< length;j++) {
		cout << seq[j] << "   ";
	}


}

DNA::~DNA()
{
}
