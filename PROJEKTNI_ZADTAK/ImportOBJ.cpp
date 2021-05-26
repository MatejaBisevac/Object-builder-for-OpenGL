#include<iostream>
#include<fstream>
#include<string>
#include <stdlib.h>
#include<math.h>
using namespace std;

class ImportOBJ
{
public: int face_n;
public:	int pos_n;
public:	float positions[500][3];    // XYZ
public:	int faces[500][4];

public: ImportOBJ() {
	ifstream inOBJ;
	inOBJ.open("puska.txt");

	while (!inOBJ.eof())
	{
		string line;
		cout << line << endl;
		getline(inOBJ, line);
		string type = line.substr(0, 2);


		if (type.compare("v ") == 0)
			this->pos_n++;

		else if (type.compare("f ") == 0)
			this->face_n++;
	}


	inOBJ.close();
	inOBJ.open("puska.txt");



	int p = 0;
	int f = 0;

	string line;
	char proba[] = " ";
	char* context = proba;
	while (!inOBJ.eof())
	{

		string line;
		cout << line << endl;
		getline(inOBJ, line);
		string type = line.substr(0, 2);

		if (type.compare("v ") == 0)
		{

			char* l = new char[line.size() + 1];
			memcpy(l, line.c_str(), line.size() + 1);

			strtok_s(l, " ", &context);

			for (int i = 0; i < 3; i++)
			{
				this->positions[p][i] = atof(strtok_s(NULL, " ", &context));
			}

			delete[] l;
			p++;
		}


		else if (type.compare("f ") == 0)
		{

			char* l = new char[line.size() + 1];
			memcpy(l, line.c_str(), line.size() + 1);


			strtok_s(l, " ", &context);
			for (int i = 0; i < 4; i++)
			{
				this->faces[f][i] = atoi(strtok_s(NULL, " ", &context));
			}

			delete[] l;
			f++;
		}

	}
	inOBJ.close();

}


	
};