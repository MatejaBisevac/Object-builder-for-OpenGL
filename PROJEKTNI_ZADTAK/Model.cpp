#include<iostream>
#include<fstream>
#include<string>
#include <stdlib.h>
#include<math.h>
#include<vector>
#include<glm/vec4.hpp>
#include "ImportOBJ.cpp"
using namespace std;
using namespace glm;

class Model
{
public:
	int pos_n;
	int face_n;
	vec4 centar;
	vector<vec4> positions;
	vector<vec4> faces;

public: Model() {}
public: Model(char* putanja)
	{
	this->centar = vec4(0, 0, 0, 1);
	ImportOBJ* ucitano = new ImportOBJ();
	
	this->pos_n = ucitano->pos_n;
	this->face_n = ucitano->face_n;
	this->positions.resize(10);
	this->faces.resize(10);
	for (int i = 0; i < 10;i++)
	{
		positions[i] = vec4(ucitano->positions[i][0], ucitano->positions[i][1], ucitano->positions[i][2], 1);
	}
	for (int i = 0; i < 10; i++)
	{
		positions[i] = vec4(ucitano->faces[i][0], ucitano->faces[i][1], ucitano->faces[i][2], ucitano->faces[i][3]);
	}

	}
};