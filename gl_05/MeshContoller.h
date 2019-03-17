#pragma once
#include <GL/glew.h>
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include "EnumTypeOfObject.h"

using namespace std;

class MeshContoller {
public:
	MeshContoller() {}

	GLfloat* getVerticesArray(TypeOfObject type, unsigned int &size) {
		switch (type)
		{
			case ground:			return groundVertices(size);
			case annex:				return annexVertices(size);
			case millSecondFloor:	return millSecondFloorVertices(size);
			case annexRoof:			return annexRoofVertices(size);
			case millRoof:			return millRoofVertices(size);
			case wall:				return wallVertices(size);
			case windmillHandle:	return windmillHandleVertices(size);
			case windmill:			return windmillVertices(size);
			case millFloor:			return millFloorVertices(size);
			case millCeiling:		return millCeilingVertices(size);
			case millCeilingRoof:	return millCeilingRoofVertices(size);
			case stone:				return stoneVertices(size);
			default:				break;
		}
	}

	GLuint* getIndicesArray(TypeOfObject type, unsigned int &size) {
		switch (type)
		{
			case ground:			return groundIndices(size);
			case annex:				return annexIndices(size);
			case millSecondFloor:	return millSecondFloorIndices(size);
			case annexRoof:			return annexRoofIndices(size);
			case millRoof:			return millRoofIndices(size);
			case wall:				return wallIndices(size);
			case windmill:			return windmillIndices(size);
			case windmillHandle:	return windmillHandleIndices(size);
			case millFloor:			return millFloorIndices(size);
			case millCeiling:		return millCeilingIndices(size);
			case millCeilingRoof:	return millCeilingRoofIndices(size);
			case stone:				return stoneIndices(size);
			default:				break;
		}
	}

private:
	GLfloat* groundVertices(unsigned int &size) {
		static GLfloat vertices[] = {
			 // coordinates			// color				// texture			//normals
			 6.0f, 0.0f,  6.0f,		1.0f, 0.0f, 0.0f,		20.0f,  0.0f,	0.0f, 1.0f, 0.0f,
			-6.0f, 0.0f,  6.0f,		0.0f, 1.0f, 0.0f,		0.0f,  0.0f,	0.0f, 1.0f, 0.0f,
			-6.0f, 0.0f, -6.0f,		0.0f, 0.0f, 1.0f,		0.0f,  20.0f,	0.0f, 1.0f, 0.0f,
			 6.0f, 0.0f, -6.0f,		1.0f, 0.0f, 1.0f,		20.0f, 20.0f,	0.0f, 1.0f, 0.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* groundIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 2,
			0, 2, 3
		};
		size = sizeof(indices);
		return indices;
	}
	
	GLfloat* annexVertices(unsigned int &size) {
		static GLfloat vertices[] =
		{
			 // coordinates				// color				// texture		//normals
			 0.5f,  1.0f,  0.5f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	1.0f, 0.0f, 1.0f,
			-0.5f,  1.0f,  0.5f,	    0.0f, 1.0f, 0.0f,		0.0f,  0.0f,	-1.0f, 0.0f, 1.0f,
			-0.5f,  0.0f,  0.5f,	    0.0f, 0.0f, 1.0f,		0.0f,  1.0f,	-1.0f, 0.0f, 1.0f,
			 0.5f,  0.0f,  0.5f,		1.0f, 0.0f, 1.0f,		1.0f,  1.0f,	1.0f, 0.0f, 1.0f,

			 0.5f,  1.0f,  -0.5f,		1.0f, 0.0f, 0.0f,		0.0f,  0.0f,	1.0f, 0.0f, -1.0f,
			-0.5f,  1.0f,  -0.5f,		0.0f, 1.0f, 0.0f,		1.0f,  0.0f,	-1.0f, 0.0f, -1.0f,
			-0.5f,  0.0f,  -0.5f,		0.0f, 0.0f, 1.0f,		1.0f,  1.0f,	-1.0f, 0.0f, -1.0f,
			 0.5f,  0.0f,  -0.5f,		1.0f, 0.0f, 1.0f,		0.0f,  1.0f,	1.0f, 0.0f, -1.0f,

			-0.5f,  1.25f,  0.5f,		1.0f, 0.0f, 0.0f,		0.0f,  0.5f,	-1.0f, 0.0f, 1.0f,
			-0.5f,  1.25f, -0.5f,		1.0f, 0.0f, 0.0f,		1.0f,  0.5f,	-1.0f, 0.0f, -1.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* annexIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 2,
			0, 2, 3,

			0, 3, 7,
			0, 7, 4,

			4, 5, 6,
			4, 7, 6,

			0, 1, 8,
			5, 4, 9

		};
		size = sizeof(indices);
		return indices;
	}
	
	GLfloat* millSecondFloorVertices(unsigned int &size) {
		static GLfloat vertices[] =
		{
			 // coordinates				// color				// texture		//normals
			 0.55f,  0.75f, 0.65f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	1.0f, 0.0f, 1.0f,
			-0.55f,  0.75f, 0.65f,	    0.0f, 1.0f, 0.0f,		0.0f,  0.0f,	-1.0f, 0.0f, 1.0f,
			-0.55f,  0.0f,  0.65f,	    0.0f, 0.0f, 1.0f,		0.0f,  1.0f,	-1.0f, 0.0f, 1.0f,
			 0.55f,  0.0f,  0.65f,		1.0f, 0.0f, 1.0f,		1.0f,  1.0f,	1.0f, 0.0f, 1.0f,

			 0.55f,  0.75f, -0.65f,		1.0f, 0.0f, 0.0f,		0.0f,  0.0f,	1.0f, 0.0f, -1.0f,
			-0.55f,  0.75f, -0.65f,		0.0f, 1.0f, 0.0f,		1.0f,  0.0f,	-1.0f, 0.0f, -1.0f,
			-0.55f,  0.0f,  -0.65f,		0.0f, 0.0f, 1.0f,		1.0f,  1.0f,	-1.0f, 0.0f, -1.0f,
			 0.55f,  0.0f,  -0.65f,		1.0f, 0.0f, 1.0f,		0.0f,  1.0f,	1.0f, 0.0f, -1.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* millSecondFloorIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 2,
			0, 2, 3,

			0, 3, 7,
			0, 7, 4,

			4, 5, 6,
			4, 7, 6,

			1, 5, 6,
			1, 2, 6
		};
		size = sizeof(indices);
		return indices;
	}
	
	GLfloat* annexRoofVertices(unsigned int &size) {
		static GLfloat vertices[] =
		{
			 // coordinates				// color				// texture		//normals
			 0.5f,  1.0f,   0.5f,		1.0f, 0.0f, 0.0f,		0.0f,  1.0f,	0.0f, 1.0f, 0.0f,
			 0.5f,  1.0f,  -0.5f,		1.0f, 0.0f, 0.0f,		0.0f,  0.0f,	0.0f, 1.0f, 0.0f,
			-0.5f,  1.25f, -0.5f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	0.0f, 1.0f, 0.0f,
			-0.5f,  1.25f,  0.5f,		1.0f, 0.0f, 0.0f,		1.0f,  1.0f,	0.0f, 1.0f, 0.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* annexRoofIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 2,
			0, 2, 3
		};
		size = sizeof(indices);
		return indices;
	}

	GLfloat* millRoofVertices(unsigned int &size) {
		static GLfloat vertices[] =
		{
			 // coordinates				// color				// texture		//normals
			 0.75f,  0.0f,   0.85f,		1.0f, 0.0f, 0.0f,		0.0f,  0.0f,	1.0f, 0.0f, 1.0f,
			-0.75f,  0.0f,   0.85f,	    0.0f, 1.0f, 0.0f,		1.0f,  0.0f,	-1.0f, 0.0f, 1.0f,
			-0.75f,  0.0f,  -0.85f,	    0.0f, 0.0f, 1.0f,		0.0f,  0.0f,	-1.0f, 0.0f, -1.0f,
			 0.75f,  0.0f,  -0.85f,		1.0f, 0.0f, 1.0f,		1.0f,  0.0f,	1.0f, 0.0f, -1.0f,

			 0.0f,   0.7f,   0.0f,		1.0f, 0.0f, 1.0f,		0.5f,  1.0f,	0.0f, 1.0f, 0.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* millRoofIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 4,
			1, 2, 4,
			2, 3, 4,
			3, 0, 4
		};
		size = sizeof(indices);
		return indices;
	}

	GLfloat* wallVertices(unsigned int &size) {
		static GLfloat vertices[] =
		{
			 // coordinates				// color				// texture		//normals
			 0.5f,  1.6f,   0.05f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	1.0f, 0.0f, 1.0f,
			-0.5f,  1.6f,   0.05f,	    0.0f, 1.0f, 0.0f,		0.0f,  0.0f,	-1.0f, 0.0f, 1.0f,
			-0.5f,  0.0f,   0.05f,	    0.0f, 0.0f, 1.0f,		0.0f,  1.0f,	-1.0f, 0.0f, 1.0f,
			 0.5f,  0.0f,   0.05f,		1.0f, 0.0f, 1.0f,		1.0f,  1.0f,	1.0f, 0.0f, 1.0f,

			 0.5f,  1.6f,  -0.05f,		1.0f, 0.0f, 0.0f,		0.0f,  0.0f,	1.0f, 0.0f, -1.0f,
			-0.5f,  1.6f,  -0.05f,		0.0f, 1.0f, 0.0f,		1.0f,  0.0f,	-1.0f, 0.0f, -1.0f,
			-0.5f,  0.0f,  -0.05f,		0.0f, 0.0f, 1.0f,		1.0f,  1.0f,	-1.0f, 0.0f, -1.0f,
			 0.5f,  0.0f,  -0.05f,		1.0f, 0.0f, 1.0f,		0.0f,  1.0f,	1.0f, 0.0f, -1.0f,

			 //duplication for proper texturing
			 0.5f,  1.6f,   0.05f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	1.0f, 0.0f, 1.0f,
			-0.5f,  1.6f,   0.05f,	    0.0f, 1.0f, 0.0f,		0.9f,  0.0f,	-1.0f, 0.0f, 1.0f,
			-0.5f,  0.0f,   0.05f,	    0.0f, 0.0f, 1.0f,		0.9f,  1.0f,	-1.0f, 0.0f, 1.0f,
			 0.5f,  0.0f,   0.05f,		1.0f, 0.0f, 1.0f,		1.0f,  1.0f,	1.0f, 0.0f, 1.0f,

			 0.5f,  1.6f,  -0.05f,		1.0f, 0.0f, 0.0f,		0.9f,  0.0f,	1.0f, 0.0f, -1.0f,
			-0.5f,  1.6f,  -0.05f,		0.0f, 1.0f, 0.0f,		1.0f,  0.0f,	-1.0f, 0.0f, -1.0f,
			-0.5f,  0.0f,  -0.05f,		0.0f, 0.0f, 1.0f,		1.0f,  1.0f,	-1.0f, 0.0f, -1.0f,
			 0.5f,  0.0f,  -0.05f,		1.0f, 0.0f, 1.0f,		0.9f,  1.0f,	1.0f, 0.0f, -1.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* wallIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 2,
			0, 2, 3,

			8, 11, 15,
			8, 15, 12,

			4, 5, 6,
			4, 7, 6,

			9, 13, 14,
			9, 10, 14
		};
		size = sizeof(indices);
		return indices;
	}


	GLfloat* windmillVertices(unsigned int &size) {
		static GLfloat vertices[] =
		{
			// coordinates				// color				// texture				//normals
			0.32f,  0.93f,   0.005f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	1.0f, 1.0f, 1.0f,
		   -0.08f,  0.93f,   0.005f,	    0.0f, 1.0f, 0.0f,		0.0f,  0.0f,	-1.0f, 1.0f, 1.0f,
		   -0.08f,  0.13f,   0.005f,	    0.0f, 0.0f, 1.0f,		0.0f,  2.0f,	-1.0f, -1.0f, 1.0f,
			0.32f,  0.13f,   0.005f,		1.0f, 0.0f, 1.0f,		1.0f,  2.0f,	1.0f, -1.0f, 1.0f,

			0.32f,  0.93f,  -0.005f,		1.0f, 0.0f, 0.0f,		0.0f,  0.0f,	1.0f, 1.0f, -1.0f,
		   -0.08f,  0.93f,  -0.005f,		0.0f, 1.0f, 0.0f,		1.0f,  0.0f,	-1.0f, 1.0f, -1.0f,
		   -0.08f,  0.13f,  -0.005f,		0.0f, 0.0f, 1.0f,		1.0f,  2.0f,	-1.0f, -1.0f, -1.0f,
			0.32f,  0.13f,  -0.005f,		1.0f, 0.0f, 1.0f,		0.0f,  2.0f,	1.0f, -1.0f, -1.0f,

			//duplication for proper texturing
			0.32f,  0.93f,   0.005f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	1.0f, 1.0f, 1.0f,
		   -0.08f,  0.93f,   0.005f,	    0.0f, 1.0f, 0.0f,		0.9f,  0.0f,	-1.0f, 1.0f, 1.0f,
		   -0.08f,  0.13f,   0.005f,	    0.0f, 0.0f, 1.0f,		0.9f,  2.0f,	-1.0f, -1.0f, 1.0f,
			0.32f,  0.13f,   0.005f,		1.0f, 0.0f, 1.0f,		1.0f,  2.0f,	1.0f, -1.0f, 1.0f,

			0.32f,  0.93f,  -0.005f,		1.0f, 0.0f, 0.0f,		0.9f,  0.0f,	1.0f, 1.0f, -1.0f,
		   -0.08f,  0.93f,  -0.005f,		0.0f, 1.0f, 0.0f,		1.0f,  0.0f,	-1.0f, 1.0f, -1.0f,
		   -0.08f,  0.13f,  -0.005f,		0.0f, 0.0f, 1.0f,		1.0f,  1.0f,	-1.0f, -1.0f, -1.0f,
			0.32f,  0.13f,  -0.005f,		1.0f, 0.0f, 1.0f,		0.9f,  1.0f,	1.0f, -1.0f, -1.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* windmillIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 2,
			0, 2, 3,

			8, 11, 15,
			8, 15, 12,

			4, 5, 6,
			4, 7, 6,

			9, 13, 14,
			9, 10, 14
		};
		size = sizeof(indices);
		return indices;
	}

	GLfloat* windmillHandleVertices(unsigned int &size) {
		static GLfloat vertices[] =
		{
			// coordinates				// color				// texture		//normals
			0.04f,  0.8f,   0.02f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	1.0f, 1.0f, 1.0f,
		   -0.04f,  0.8f,   0.02f,	    0.0f, 1.0f, 0.0f,		0.0f,  0.0f,	-1.0f, 1.0f, 1.0f,
		   -0.04f,  0.0f,   0.02f,	    0.0f, 0.0f, 1.0f,		0.0f,  2.0f,	-1.0f, -1.0f, 1.0f,
			0.04f,  0.0f,   0.02f,		1.0f, 0.0f, 1.0f,		1.0f,  2.0f,	1.0f, -1.0f, 1.0f,

			0.04f,  0.8f,  -0.02f,		1.0f, 0.0f, 0.0f,		0.0f,  0.0f,	1.0f, 1.0f, -1.0f,
		   -0.04f,  0.8f,  -0.02f,		0.0f, 1.0f, 0.0f,		1.0f,  0.0f,	-1.0f, 1.0f, -1.0f,
		   -0.04f,  0.0f,  -0.02f,		0.0f, 0.0f, 1.0f,		1.0f,  2.0f,	-1.0f, -1.0f, -1.0f,
			0.04f,  0.0f,  -0.02f,		1.0f, 0.0f, 1.0f,		0.0f,  2.0f,	1.0f, -1.0f, -1.0f,

			//duplication for proper texturing
			0.04f,  0.8f,   0.02f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	1.0f, 1.0f, 1.0f,
		   -0.04f,  0.8f,   0.02f,	    0.0f, 1.0f, 0.0f,		0.9f,  0.0f,	-1.0f, 1.0f, 1.0f,
		   -0.04f,  0.0f,   0.02f,	    0.0f, 0.0f, 1.0f,		0.9f,  2.0f,	-1.0f, -1.0f, 1.0f,
			0.04f,  0.0f,   0.02f,		1.0f, 0.0f, 1.0f,		1.0f,  2.0f,	1.0f, -1.0f, 1.0f,

			0.04f,  0.8f,  -0.02f,		1.0f, 0.0f, 0.0f,		0.9f,  0.0f,	1.0f, 1.0f, -1.0f,
		   -0.04f,  0.8f,  -0.02f,		0.0f, 1.0f, 0.0f,		1.0f,  0.0f,	-1.0f, 1.0f, -1.0f,
		   -0.04f,  0.0f,  -0.02f,		0.0f, 0.0f, 1.0f,		1.0f,  1.0f,	-1.0f, -1.0f, -1.0f,
			0.04f,  0.0f,  -0.02f,		1.0f, 0.0f, 1.0f,		0.9f,  1.0f,	1.0f, -1.0f, -1.0f,

			0.04f,  0.8f,   0.02f,		1.0f, 0.0f, 0.0f,		0.9f,  0.0f,	1.0f, 1.0f, 1.0f,
		   -0.04f,  0.8f,   0.02f,	    0.0f, 1.0f, 0.0f,		0.0f,  0.0f,	-1.0f, 1.0f, 1.0f,
			0.04f,  0.8f,  -0.02f,		1.0f, 0.0f, 0.0f,		0.0f,  1.0f,	1.0f, 1.0f, -1.0f,
		   -0.04f,  0.8f,  -0.02f,		0.0f, 1.0f, 0.0f,		0.9f,  1.0f,	-1.0f, 1.0f, -1.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* windmillHandleIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 2,
			0, 2, 3,

			8, 11, 15,
			8, 15, 12,

			4, 5, 6,
			4, 7, 6,

			9, 13, 14,
			9, 10, 14,

			16, 17, 18,
			16, 18, 19
		};
		size = sizeof(indices);
		return indices;
	}
	
	GLfloat* millFloorVertices(unsigned int &size) {
		static GLfloat vertices[] =
		{
			 // coordinates				// color				// texture		//normals
			 0.5f,  0.0f,   0.5f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	0.0f, 1.0f, 0.0f,
			-0.5f,  0.0f,   0.5f,	    0.0f, 1.0f, 0.0f,		0.0f,  0.0f,	0.0f, 1.0f, 0.0f,
			-0.5f,  0.0f,  -0.5f,	    0.0f, 0.0f, 1.0f,		0.0f,  1.0f,	0.0f, 1.0f, 0.0f,
			 0.5f,  0.0f,  -0.5f,		1.0f, 0.0f, 1.0f,		1.0f,  1.0f,	0.0f, 1.0f, 0.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* millFloorIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 2,
			0, 2, 3
		};
		size = sizeof(indices);
		return indices;
	}

	GLfloat* millCeilingVertices(unsigned int &size) {
		static GLfloat vertices[] =
		{
			 // coordinates				// color				// texture		//normals
			 0.55f,  0.0f,   0.65f,		1.0f, 0.0f, 0.0f,		1.0f,  0.0f,	0.0f, -1.0f, 0.0f,
			-0.55f,  0.0f,   0.65f,	    0.0f, 1.0f, 0.0f,		0.0f,  0.0f,	0.0f, -1.0f, 0.0f,
			-0.55f,  0.0f,  -0.65f,	    0.0f, 0.0f, 1.0f,		0.0f,  1.0f,	0.0f, -1.0f, 0.0f,
			 0.55f,  0.0f,  -0.65f,		1.0f, 0.0f, 1.0f,		1.0f,  1.0f,	0.0f, -1.0f, 0.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* millCeilingIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 2,
			0, 2, 3
		};
		size = sizeof(indices);
		return indices;
	}

	
	GLfloat* millCeilingRoofVertices(unsigned int &size) {
		static GLfloat vertices[] =
		{
			 // coordinates				// color				// texture		//normals
			 0.75f,  0.0f,   0.85f,		1.0f, 0.0f, 0.0f,		0.0f,  1.0f,	0.0f, -1.0f, 0.0f,
			-0.75f,  0.0f,   0.85f,	    0.0f, 1.0f, 0.0f,		0.0f,  0.0f,	0.0f, -1.0f, 0.0f,
			-0.75f,  0.0f,  -0.85f,	    0.0f, 0.0f, 1.0f,		0.0f,  1.0f,	0.0f, -1.0f, 0.0f,
			 0.75f,  0.0f,  -0.85f,		1.0f, 0.0f, 1.0f,		0.0f,  0.0f,	0.0f, -1.0f, 0.0f,
			
			 0.0f,   0.0f,  -0.0f,		1.0f, 0.0f, 1.0f,		0.5f,  0.5f,	0.0f, -1.0f, 0.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* millCeilingRoofIndices(unsigned int &size) {
		static GLuint indices[] = {
			4, 0, 1,
			4, 1, 2,
			4, 2, 3,
			4, 3, 0
		};
		size = sizeof(indices);
		return indices;
	}


	GLfloat* stoneVertices(unsigned int &size) {
		GLfloat param = 0.9f;
		static GLfloat vertices[] =
		{
			// coordinates				// color				// texture														//normals
			-0.3f,  0.03f,   0.0f,		1.0f, 0.0f, 0.0f,		0.0f*param + 0.5*(1-param),  0.53f*param + 0.5*(1 - param),		0.0f, 1.0f, 0.0f,
			-0.18f,  0.03f,   0.25f,	    0.0f, 1.0f, 0.0f,	0.2f*param + 0.5*(1 - param),  0.98f*param + 0.5*(1 - param),	0.0f, 1.0f, 0.0f,
			0.18f,  0.03f,	0.26f,	    0.0f, 0.0f, 1.0f,		0.8f*param + 0.5*(1 - param),  1.0f*param + 0.5*(1 - param),	0.0f, 1.0f, 0.0f,
			0.27f,  0.03f,	0.16f,		1.0f, 0.0f, 1.0f,		0.96f*param + 0.5*(1 - param),  0.82f*param + 0.5*(1 - param),	0.0f, 1.0f, 0.0f,
			0.3f,  0.03f,	-0.1f,	    0.0f, 0.0f, 1.0f,		1.0f*param + 0.5*(1 - param),  0.36f*param + 0.5*(1 - param),	0.0f, 1.0f, 0.0f,
			0.15f,  0.03f,  -0.3f,		1.0f, 0.0f, 1.0f,		0.75f*param + 0.5*(1 - param),  0.0f*param + 0.5*(1 - param),	0.0f, 1.0f, 0.0f,
			-0.17f,  0.03f, -0.3f,		0.0f, 0.0f, 1.0f,		0.22f*param + 0.5*(1 - param),  0.0f*param + 0.5*(1 - param),	0.0f, 1.0f, 0.0f,

			- 0.3f,  0.0f,   0.0f,		1.0f, 0.0f, 0.0f,		0.0f,  0.53f,	0.0f, 0.0f, 0.0f,
			-0.18f,  0.0f,   0.25f,	    0.0f, 1.0f, 0.0f,		0.2f,  0.98f,	0.0f, 0.0f, 0.0f,
			0.18f,  0.0f,	0.26f,	    0.0f, 0.0f, 1.0f,		0.8f,  1.0f,	0.0f, 0.0f, 0.0f,
			0.27f,  0.0f,	0.16f,		1.0f, 0.0f, 1.0f,		0.96f,  0.82f,	0.0f, 0.0f, 0.0f,
			0.3f,  0.0f,	-0.1f,	    0.0f, 0.0f, 1.0f,		1.0f,  0.36f,	0.0f, 0.0f, 0.0f,
			0.15f,  0.0f,  -0.3f,		1.0f, 0.0f, 1.0f,		0.75f,  0.0f,	0.0f, 0.0f, 0.0f,
			-0.17f,  0.0f, -0.3f,		0.0f, 0.0f, 1.0f,		0.22f,  0.0f,	0.0f, 0.0f, 0.0f
		};

		size = sizeof(vertices);
		return vertices;
	}

	GLuint* stoneIndices(unsigned int &size) {
		static GLuint indices[] = {
			0, 1, 6,
			4, 5, 6,
			4, 2, 3,
			2, 4, 1,
			1, 4, 6,

			//side
			2, 1, 8,
			2, 8, 9,
			3, 2, 9,
			3, 9, 10,
			4, 3, 10,
			4, 10, 11,
			5, 4, 11,
			5, 11, 12,
			6, 5, 12,
			6, 12, 13,
			0, 6, 13,
			0, 13, 7,
			1, 0, 7,
			1, 7, 8,
		};
		size = sizeof(indices);
		return indices;
	}
};
#pragma once
