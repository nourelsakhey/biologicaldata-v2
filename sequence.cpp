#include "sequence.h"


sequence::sequence()
{
}

sequence::sequence(int alength)
{
	length = alength;
	seq = new char[alength];
}

sequence::sequence(sequence & rhs)
{
	rhs.seq = new char;
	rhs.seq = seq;
}

char* Align(sequence *s1, sequence *s2)
{
	int** arr;
	char** arr_1;
	arr = new int*[s1->length + 1];

	for (int i = 0; i < s1->length + 1; i++)
		arr[i] = new int[s2->length + 1];
	arr_1 = new char*[s1->length + 1];

	for (int i = 0; i < s1->length + 1; i++)
		arr_1[i] = new char[s2->length + 1];
	for (int i = 0; i < s1->length + 1; i++)
	{
		for (int j = 0; j < s2->length + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				arr_1[i][j] = '/';
				arr[i][j] = 0;
			}
			else if (s1->seq[i - 1] == s2->seq[j - 1])
			{
				arr_1[i][j] = '@';
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				if (arr[i - 1][j] > arr[i][j - 1])
				{
					arr[i][j] = arr[i - 1][j];
					arr_1[i][j] = '#';
				}
				else
				{
					arr[i][j] = arr[i][j - 1];
					arr_1[i][j] = '!';
				}
			}
		}
	}
	/*for (int i = s1->length ; i >= 0; i--)
	{
		for (int j = s2->length ; j >= 0;j--)
		{
			cout << arr_1[i][j] << " ";
		}
		cout << endl;
	}*/

	int index = 0;
	char* arr_2;
	arr_2 = new char[arr[s1->length][s2->length]];
	//return arr_2;
	for (int i = s1->length; i >= 0; )
	{
		for (int j = s2->length; j >= 0;)
		{
			if (i == 0 || j == 0)
			{
				return arr_2;
			}
			else if (arr_1[i][j] == '@')
			{	//diagonal arrow, MATCH
				i -= 1;
				j -= 1;
				arr_2[index] = s1->seq[i];
				arr_2[index + 1] = '\0';
				index++;
			}
			else if (arr_1[i][j] == '#')
			{	//up arrow
				i -= 1;
			}
			else
			{	//left arrow
				j -= 1;
			}
		}
	}
}

sequence::~sequence()
{
}