#include <GL/freeglut.h>
#include <glm/vec4.hpp>
#include <vector>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <list>
#include <iterator>
#include <iostream>

using namespace glm;
using namespace std;

class Glock
{
public :
	vector<vector<vec4>> glock;
	vec4 glock_centar;
	vec4 centar_cevke;

public:	Glock()
	{

		glock_centar = vec4(0, 0, 0, 1);
		centar_cevke = vec4(0, 0.5, 3,1);
		glock.resize(4);
		glock[0].resize(8);
		glock[0][0] = vec4(0.5, 0, 3, 1);
		glock[0][1] = vec4(0.5, 0, -3, 1);
		glock[0][2] = vec4(-0.5, 0, -3, 1);
		glock[0][3] = vec4(-0.5, 0, 3, 1);
		glock[0][4] = vec4(0.5, 1, 3, 1);
		glock[0][5] = vec4(0.5, 1, -3, 1);
		glock[0][6] = vec4(-0.5, 1, -3, 1);
		glock[0][7] = vec4(-0.5, 1, 3, 1);
		glock[3].resize(12);
		glock[3][0] = vec4(0.25, 0, 0, 1);
		float ugao = 2 * 3.14 / 12;
		mat4 rotate12 = glm::rotate(mat4(1.0f), ugao, vec3(0, 0, 1));
		for (int i = 1; i < 12; i++)
		{
			glock[3][i] = rotate12 * glock[3][i - 1];
		}
		for (int i = 0; i < 12; i++)
			glock[3][i] = glock[3][i] + centar_cevke;



		glock[1].resize(8);
		glock[1][0] = vec4(0.4, -0.3, 3, 1);
		glock[1][1] = vec4(0.4, -0.3, -3, 1);
		glock[1][2] = vec4(-0.4, -0.3, -3, 1);
		glock[1][3] = vec4(-0.4, -0.3, 3, 1);
		glock[1][4] = vec4(0.4, 0, 3, 1);
		glock[1][5] = vec4(0.4, 0, -3, 1);
		glock[1][6] = vec4(-0.4,0, -3, 1);
		glock[1][7] = vec4(-0.4, 0, 3, 1);

		glock[2].resize(10);
		glock[2][0] = vec4(-0.4, -0.3, -1, 1);
		glock[2][1] = vec4(0.4, -0.3, -1, 1);
		glock[2][2] = vec4(0.4, -0.3, -3, 1);
		glock[2][3] = vec4(-0.4, -0.3, -3, 1);
		glock[2][4] = vec4(-0.4, -0.4, -1, 1);
		glock[2][5] = vec4(0.4, -0.4, -1, 1);
		glock[2][6] = vec4(-0.4, -4, -1.5, 1);
		glock[2][7] = vec4(0.4, -4, -1.5, 1);
		glock[2][8] = vec4(0.4, -4, -4.5, 1);
		glock[2][9] = vec4(-0.4, -4, -4.5, 1);
	}

};