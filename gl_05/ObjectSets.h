#pragma once

#include <GL/glew.h>
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include "EnumTypeOfObject.h"
#include "Object.h"
#include "Camera.h"

using namespace std;

class Fence {
	Object *pillar1, *pillar2, *bar1, *bar2;

public:
	Fence(GLfloat length, GLfloat height, GLfloat x, GLfloat y, GLfloat z, GLfloat x_rot, GLfloat y_rot, GLfloat z_rot) {
		//x, y, z						rot x y z
		pillar1 = new Object(cylinder, "woodBark.jpg", 18, 0.05f, height, -length / 5 + x, 0.0f + y, -0.1f + z, 0.0f, 0.0f, 0.0f);
		pillar2 = new Object(cylinder, "woodBark.jpg", 18, 0.05f, height, (-length / 5) * 4 + x, 0.0f + y, -0.1f + z, 0.0f, 0.0f, 0.0f);
		bar1 = new Object(cylinder, "woodBark.jpg", 18, 0.04f, length, 0.0f + x, 0.45f + y, 0.0f + z, 0.0f, 0.0f, 90.0f);
		bar2 = new Object(cylinder, "woodBark.jpg", 18, 0.04f, length, 0.0f + x, 0.25f + y, 0.0f + z, 0.0f, 0.0f, 90.0f);

	}

	~Fence() {
		delete pillar1;
		delete pillar2;
		delete bar1;
		delete bar2;
	}

	void draw(int progid, Camera camera, int SCREEN_WIDTH, int SCREEN_HEIGHT)
	{
		pillar1->draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
		pillar2->draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
		bar1->draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
		bar2->draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
	}
};

class Tree {
	Object *branch1, *branch2, *branch3, *branch4, *trunk;

public:
	Tree(GLfloat radius, GLfloat height, GLfloat x, GLfloat y, GLfloat z, GLfloat x_rot, GLfloat y_rot, GLfloat z_rot) {
		//x, y, z					  rot x y z
		branch1 = new Object(cone,	 "tree.jpg",	6,	radius*0.4,			height*0.2,		0.0f + x, height*0.8 + y, 0.0f + z,			0.0f, 0.0f, 0.0f);
		branch2 = new Object(cone,	 "tree.jpg",	6,	radius*0.6,			height*0.28,	0.0f + x, height*0.6 + y, 0.0f + z,			0.0f, 0.0f, 0.0f);
		branch3 = new Object(cone,	 "tree.jpg",	6,	radius*0.8,			height*0.34,	0.0f + x, height*0.4 + y, 0.0f + z,			0.0f, 0.0f, 0.0f);
		branch4 = new Object(cone,	 "tree.jpg",	6,	radius,				height*0.4,		0.0f + x, height*0.2 + y, 0.0f + z,			0.0f, 0.0f, 0.0f);
		trunk = new Object(cylinder, "woodBark.jpg",18, radius*0.15,		height*0.2,		0.0f + x, 0.0f + y, 0.0f + z,				0.0f, 0.0f, 0.0f);
	}

	~Tree() {
		delete branch1;
		delete branch2;
		delete branch3;
		delete branch4;
		delete trunk;
	}

	void draw(int progid, Camera camera, int SCREEN_WIDTH, int SCREEN_HEIGHT)
	{
		branch1->draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
		branch2->draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
		branch3->draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
		branch4->draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
		trunk->draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
	}
};

#pragma once