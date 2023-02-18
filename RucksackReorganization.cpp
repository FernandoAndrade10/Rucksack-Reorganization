//Fernando Israel Andrade
//Visual Studio 2019
//Advant of code Day 3
//https://adventofcode.com/2022/day/3

#include <iostream>
#include <fstream>
#include <string>
#include <malloc.h>
#define MAX_SIZE 16382
using namespace std;

int getPriorityTotal(string match[], int size) {
	int total = 0;
	string priorityKey[52][2] = {
		{"a", "1"},
		{"b", "2"},
		{"c", "3"},
		{"d", "4"},
		{"e", "5"},
		{"f", "6"},
		{"g", "7"},
		{"h", "8"},
		{"i", "9"},
		{"j", "10"},
		{"k", "11"},
		{"l", "12"},
		{"m", "13"},
		{"n", "14"},
		{"o", "15"},
		{"p", "16"},
		{"q", "17"},
		{"r", "18"},
		{"s", "19"},
		{"t", "20"},
		{"u", "21"},
		{"v", "22"},
		{"w", "23"},
		{"x", "24"},
		{"y", "25"},
		{"z", "26"},
		{"A", "27"},
		{"B", "28"},
		{"C", "29"},
		{"D", "30"},
		{"E", "31"},
		{"F", "32"},
		{"G", "33"},
		{"H", "34"},
		{"I", "35"},
		{"J", "36"},
		{"K", "37"},
		{"L", "38"},
		{"M", "39"},
		{"N", "40"},
		{"O", "41"},
		{"P", "42"},
		{"Q", "43"},
		{"R", "44"},
		{"S", "45"},
		{"T", "46"},
		{"U", "47"},
		{"V", "48"},
		{"W", "49"},
		{"X", "50"},
		{"Y", "51"},
		{"Z", "52"},
	};

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			if (match[i] == priorityKey[j][0])
			{
				total += stoi(priorityKey[j][1]);
			}
		}
	}

	return total;
}

int getSize(int x, int y, int z) {
	//Return the size of the smallest string
	if (x < y && x < z)
	{
		return x;
	}
	else if (x <= y && x < z)
	{
		return x;
	}
	else if (x < y && x <= z)
	{
		return x;
	}
	else if (y < x && y < z)
	{
		return y;
	}
	else if (y <= x && y < z)
	{
		return y;
	}
	else if (y < x && y <= z)
	{
		return y;
	}
	else
	{
		return z;
	}
}

string getSmallestString(string first, string second, string third, int size) {
	//return the string with the smallest size
	if (first.length() == size)
	{
		return first;
	}

	 else if (second.length() == size)
	{
		return second;
	}

	 else
	{
		return third;
	}
}

int getTriplesArray(string str[], int size, string triples[]) {
	string firstLine = {};
	string secondLine = {};
	string thirdLine = {};
	string smallestString = {};
	string hit = {};
	string first = {};
	string second = {};
	string third = {};
	string firstChar = {};
	string secondChar = {};
	string thirdChar = {};
	int smallestSize = 0;
	int k = 0;
	int q = 0;
	int secondSize = 0;

	for (int i = 0; i < size; i += 3)
	{
		firstLine = str[i];
		secondLine = str[i + 1];
		thirdLine = str[i + 2];

		smallestSize = getSize(firstLine.length(), secondLine.length(), thirdLine.length());
		smallestString = getSmallestString(firstLine, secondLine, thirdLine, smallestSize);


		if (smallestString == firstLine)
		{
			first = firstLine;
			second = secondLine;
			third = thirdLine;
		}
		else if (smallestString == secondLine)
		{
			first = secondLine;
			second = firstLine;
			third = thirdLine;
		}
		else if (smallestString == thirdLine)
		{
			first = thirdLine;
			second = secondLine;
			third = firstLine;
		}

		secondSize = second.length();

		for (int j = 0; j < smallestSize; j++)
		{
			firstChar = first.at(j);
			secondChar = second.at(k);

			//If First and Second string have a matching char, then check the Third string
			//And check that the char is not a repeat and store it in an array
			if (firstChar == secondChar && k < secondSize)
			{
				for (int l = 0; l < third.length(); l++)
				{
					thirdChar = third.at(l);
					if (thirdChar == firstChar && firstChar != hit)
					{
						triples[q] = firstChar;
						q++;

						hit = firstChar;
					}
				}

			}

			if (j == smallestSize - 1 && k < secondSize)
			{
				j = -1;

				if (k == secondSize - 1)
				{
					j = smallestSize;
				}
				else
				{
					k++;
				}
			}
		}
		k = 0;
		hit = " ";
	}

	cout << "q: " << q << endl;
	return q;
}

int getPriorityArray(string str[], int size, string match[]) {
	string first = {};
	string firstHalf = {};
	string second = {};
	string secondHalf = {};
	string hit = {};
	int q = 0;
	int j = 0;
	int halfSize = 0;
	int strSize = 0;

	for (int i = 0; i < size; i++)
	{
		//Get length of the split string
		strSize = str[i].length();
		halfSize = strSize / 2;

		//Split the string in two equal halves
		firstHalf = str[i].substr(0, halfSize);
		secondHalf = str[i].substr(halfSize, strSize);

		for (int k = 0; k < halfSize; k++)
		{
			//Compare each individual char in the list to find the common letter
			first = firstHalf.at(k);
			second = secondHalf.at(j);

			if (first == second && j < halfSize)
			{
				//Check and see if the letter is the same as a previous found
				//in that specific string. If it is a repeat, do not store it again.
				if (first != hit)
				{
					match[q] = first;
					hit = first;
					q++;
				}
				
			}

			//If the for loop index k reaches the end and the j index to check the second
			//string is still less than the string length then the loop index will be
			//-1 and it will bump up to 0 afterr the k++ resolves.
			if (k == halfSize - 1 && j < halfSize)
			{
				k = -1;
				//If the j index reaches the end of the string then no more comparisions are left.
				//set k = to the string length and exit the loop.
				if (j == halfSize - 1)
				{
					k = halfSize;
				}
				else
				{
					j++;
				}
			}
		}
		j = 0;
		hit = " ";
	}

	return q;
}

int main() {
	fstream in;
	in.open("Rucksack.txt");
	string* arr;
	arr = new string[MAX_SIZE];
	string line = {};
	string* match;
	match = new string[MAX_SIZE];
	string* triples;
	triples = new string[MAX_SIZE];
	int triplesSize = 0;
	int matchSize = 0;
	int total = 0;
	int triplesTotal = 0;
	int k = 0;

	if (in.is_open())
	{
		while (getline(in, line))
		{
			arr[k] = line;
			k++;
		}
	}

	in.close();


	matchSize = getPriorityArray(arr, k, match);
	total = getPriorityTotal(match, matchSize);

	triplesSize = getTriplesArray(arr, k, triples);
	triplesTotal = getPriorityTotal(triples, triplesSize);

	for (int i = 0; i < triplesSize; i++)
	{
		cout << triples[i] << endl;
	}

	cout << "Total: " << total << endl;
	cout << "Three elves total: " << triplesTotal << endl;

	return 0;
}


