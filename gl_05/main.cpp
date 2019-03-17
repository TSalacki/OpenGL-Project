// Std. Includes
#include <string>
#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// GL includes
#include "shprogram.h"
#include "Camera.h"
#include "Object.h"
#include "EnumTypeOfObject.h"
#include "MeshContoller.h"
#include "SolidMeshContoller.h"
#include "ObjectSets.h"

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other Libs
#include "SOIL.h"

#define ROTATE_SPEED	24.0f
#define GEAR_TEETH		24

using namespace std;

// Properties
const GLuint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Function prototypes
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
void ScrollCallback(GLFWwindow *window, double xOffset, double yOffset);
void MouseCallback(GLFWwindow *window, double xPos, double yPos);
void DoMovement();

// Camera
Camera  camera(glm::vec3(0.0f, 1.5f, 3.5f));
GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;
bool keys[1024];
bool firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

// The MAIN function, from here we start our application and run our Game loop
int main()
{
	// Init GLFW
	if (glfwInit() != GL_TRUE)
	{
		cout << "GLFW initialization failed" << endl;
		return -1;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	try
	{
		GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "GKOM - Mlyn", nullptr, nullptr); // Windowed

		if (window == nullptr)
			throw exception("GLFW window not created");

		glfwMakeContextCurrent(window);

		glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

		// Set the required callback functions
		glfwSetKeyCallback(window, KeyCallback);
		glfwSetCursorPosCallback(window, MouseCallback);
		glfwSetScrollCallback(window, ScrollCallback);

		// Options, removes the mouse cursor for a more immersive experience
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
		glewExperimental = GL_TRUE;
		// Initialize GLEW to setup the OpenGL Function pointers
		if (glewInit() != GLEW_OK)
			throw exception("GLEW Initialization failed");

		// Define the viewport dimensions
		glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		// Setup some OpenGL options
		glEnable(GL_DEPTH_TEST);

		// Let's check what are maximum parameters counts
		GLint nrAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
		cout << "Max vertex attributes allowed: " << nrAttributes << std::endl;
		glGetIntegerv(GL_MAX_TEXTURE_COORDS, &nrAttributes);
		cout << "Max texture coords allowed: " << nrAttributes << std::endl;

		// enable alpha support
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Setup and compile our shaders
		//ShaderProgram ourShader("core.vert", "core.frag");
		ShaderProgram ourShader("light.vert", "light.frag");


		/*Aby dodac obiekt z nowa siatka nalezy:
		- dodac jego typ w EnumTypeOfObject.h
		- w pliku MeshController
			*dodac funkcje zwracajace odpowiednie siatki
			*dodac ich wywolanie do funkcji getIndicesArray i getVerticesArray jako opcje switch
		
		Rozwiazanie wydaje sie karkolomne, ale ma sens - pozwala wszystkie tablice przeniesc do oddzielnego pliku
		i zachowac wzgledny porzadek oraz przygotowuje interfejsy na potrzeby funkcji generujacych siatki
		*/

		//mesh constructor: type from Enum...,   texture path,			 x,y,z position		x,y,z rotation
		Object annex(annex, "woodBoards.png",							1.0f,  0.0f,   0.0f,		0.0f, 0.0f, 0.0f);
		Object ground(ground, "grass.jpg",								0.0f,  0.0f,   0.0f,		0.0f, 0.0f, 0.0f);
		
		Object millSecondFloor(millSecondFloor, "woodBoards.png",		0.0f,  1.5f,   0.0f,		0.0f, 0.0f, 0.0f);
		Object annexRoof(annexRoof, "roof.jpg",							1.0f,  0.0f,   0.0f,		0.0f, 0.0f, 0.0f);
		Object millRoof(millRoof, "roof.jpg",							0.0f,  2.25f,  0.0f,		0.0f, 0.0f, 0.0f);
		Object wall1(wall, "brick.jpg",									0.0f,  0.0f,   0.55f,		0.0f, 0.0f, 0.0f);
		Object wall2(wall, "brick.jpg",									0.0f,  0.0f,  -0.55f,		0.0f, 0.0f, 0.0f);
		Object wall3(wall, "brick.jpg",									0.45f, 0.0f,   0.0f,		0.0f, 90.0f, 0.0f);
		Object millFloor(millFloor, "woodFloor.jpg",					0.0f,  0.001f, 0.0f,		0.0f, 0.0f, 0.0f);
		Object millCeiling(millCeiling, "woodFloor.jpg",				0.0f,  1.5f,   0.0f,		0.0f, 0.0f, 0.0f);
		Object millCeilingRoof(millCeilingRoof, "woodFloor.jpg",		0.0f,  2.25f,  0.0f,		0.0f, 0.0f, 0.0f);
		/*
		Object windmill1(windmill, "woodWindmill1.jpg",					0.13f,  1.87f,  0.93f,		0.0f, 0.0f, 0.0f);
		Object windmill2(windmill, "woodWindmill1.jpg",					-0.13f,  1.87f,  1.0f,		0.0f, 0.0f, 90.0f);
		Object windmill3(windmill, "woodWindmill1.jpg",					-0.13f,  1.62f,  0.93f,		0.0f, 0.0f, 180.0f);
		Object windmill4(windmill, "woodWindmill1.jpg",					0.13f,  1.62f,  1.0f,		0.0f, 0.0f, 270.0f);
		*/
		Object windmill1(windmill, "woodWindmill1.jpg",					0.0f, 1.75f, 0.93f,			0.0f, 0.0f, 0.0f);
		Object windmill2(windmill, "woodWindmill1.jpg",					0.0f, 1.75f, 1.0f,			0.0f, 0.0f, 90.0f);
		Object windmill3(windmill, "woodWindmill1.jpg",					0.0f, 1.75f, 0.93f,			0.0f, 0.0f, 180.0f);
		Object windmill4(windmill, "woodWindmill1.jpg",					0.0f, 1.75f, 1.0f,			0.0f, 0.0f, 270.0f);

		Object windmillHandle1(windmillHandle, "woodWindmill2.jpg",		0.0f,  1.75f,  0.93f,		0.0f, 0.0f, 0.0f);
		Object windmillHandle2(windmillHandle, "woodWindmill2.jpg",		0.0f,  1.75f,  1.0f,		0.0f, 0.0f, 90.0f);
		Object windmillHandle3(windmillHandle, "woodWindmill2.jpg",		0.0f,  1.75f,  0.93f,		0.0f, 0.0f, 180.0f);
		Object windmillHandle4(windmillHandle, "woodWindmill2.jpg",		0.0f,  1.75f,  1.0f,		0.0f, 0.0f, 270.0f);
		
		//stones
		Object stone1(stone, "rock.jpg",							0.1f, 0.0f, 1.1f,			0.0f, 0.0f, 0.0f);
		Object stone2(stone, "rock.jpg",							-0.2f, 0.0f, 1.7f,			0.0f, 65.0f, 0.0f);
		Object stone3(stone, "rock.jpg",							0.1f, 0.0f, 2.3f,			0.0f, 20.0f, 0.0f);
		Object stone4(stone, "rock.jpg",							0.0f, 0.0f, 2.9f,			0.0f, 90.0f, 0.0f);
		Object stone5(stone, "rock.jpg",							0.1f, 0.0f, 3.6f,			0.0f, 120.0f, 0.0f);
		Object stone6(stone, "rock.jpg",							-0.1f, 0.0f, 4.3f,			0.0f, 10.0f, 0.0f);
		Object stone7(stone, "rock.jpg",							0.8f, 0.0f, 1.0f,			0.0f, 150.0f, 0.0f);
		
		//cylinder constructor:			type,			texture,		number of side faces,	radius, height			x,y,z position				x,y,z rotation
		Object shaftHorizontal (		cylinder,		"woodBark.jpg",	18,						0.10f,	0.25f,			0.0f, 1.75f, 0.8f,			90.0f, 0.0f, 0.0f);
		Object smallerShaftHorizontal(	cylinder,		"woodBark.jpg", 18,						0.08f,	0.5f,			0.0f, 1.75f, 0.4f,			90.0f, 0.0f, 0.0f);
		Object shaftVertical(			cylinder,		"woodBark.jpg",	18,						0.08f,	1.25f,			0.0f, 0.25f, 0.0f,			0.0f, 0.0f, 0.0f);
		
		Object gearHorizontal(			gear,			"woodBark.jpg", GEAR_TEETH,				0.40f,  0.1f,			0.0f, 1.75f, 0.4f,			90.0f, 15.0f, 0.0f);
		Object gearVertical(			gear,			"woodBark.jpg", GEAR_TEETH,				0.40f,	0.1f,			0.0f, 1.25f, 0.0f,			 0.0f, 0.0f, 0.0f);

		Object millingStone(			cylinder,		"stone.jpg",	18,						0.40f, 0.1f,			0.0f, 0.25f, 0.0f,			0.0f, 0.0f, 0.0f);
		Object millingBasin(			cylinder,		"rock.jpg",		18,						0.50f, 0.25f,			0.0f, 0.0f, 0.0f,			0.0f, 0.0f, 0.0f);
										
					//radius, height
		Fence fence1(1.5f, 0.5f,											-0.8f, 0.0f, 2.0f,			0.0f, 0.0f, 90.0f);
		Fence fence2(2.0f, 0.5f,											2.8f, 0.0f, 2.0f,			0.0f, 0.0f, 90.0f);
		
		//my privet forest
		Tree tree1	(0.7f, 1.8f,											2.2f, 0.0f, 0.1f,			0.0f, 0.0f, 0.0f);
		Tree tree2	(1.2f, 2.9f,											-1.6f, 0.0f, -2.2f,			0.0f, 0.0f, 0.0f);
		Tree tree3	(0.6f, 2.5f,											-2.7f, 0.0f, -1.3f,			0.0f, 0.0f, 0.0f);
		Tree tree4	(1.0f, 3.1f,											1.3f, 0.0f, -1.5f,			0.0f, 0.0f, 0.0f);
		Tree tree5	(0.5f, 1.6f,											2.0f, 0.0f, -1.0f,			0.0f, 0.0f, 0.0f);
		Tree tree6	(0.3f, 0.5f,											-1.3f, 0.0f, -0.6f,			0.0f, 0.0f, 0.0f);
		
		int progid = ourShader.get_programID();



		// main event loop
		while (!glfwWindowShouldClose(window))
		{
			// Set frame time
			GLfloat currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
			DoMovement();

			// Clear the colorbuffer
			glClearColor(0.2f, 0.6f, 0.9f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Draw our first triangle
			ourShader.Use();

			//light color
			glUniform3f(glGetUniformLocation(progid, "lightColor"), 1.0f, 1.0f, 1.0f);
			//light position
			glUniform3f(glGetUniformLocation(progid, "lightPos"), -2.0f, 4.0f, 3.0f);

			annex.draw(progid, camera,SCREEN_WIDTH, SCREEN_HEIGHT);
			ground.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			
			millSecondFloor.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			annexRoof.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			millRoof.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			wall1.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			wall2.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			wall3.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			millFloor.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			millCeiling.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			millCeilingRoof.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			
			windmill1.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			windmill2.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			windmill3.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			windmill4.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			
			windmillHandle1.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			windmillHandle2.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			windmillHandle3.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			windmillHandle4.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			
			fence1.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			fence2.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			
			shaftHorizontal.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			smallerShaftHorizontal.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			shaftVertical.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			gearHorizontal.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT); 
			gearVertical.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			millingStone.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			millingBasin.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);

			gearHorizontal.rotate(progid, 5.0f, ROTATE_SPEED, VERTICAL);
			shaftHorizontal.rotate(progid, 5.0f, ROTATE_SPEED, VERTICAL);
			smallerShaftHorizontal.rotate(progid, 5.0f, ROTATE_SPEED, VERTICAL);

			gearVertical.rotate(progid, 5.0f, ROTATE_SPEED, VERTICAL);
			shaftVertical.rotate(progid, 5.0f, ROTATE_SPEED, VERTICAL);
			millingStone.rotate(progid, 5.0f, ROTATE_SPEED, VERTICAL);
			
			windmillHandle1.rotate(progid, 5.0f, ROTATE_SPEED, HORIZONTAL);
			windmillHandle2.rotate(progid, 5.0f, ROTATE_SPEED, HORIZONTAL);
			windmillHandle3.rotate(progid, 5.0f, ROTATE_SPEED, HORIZONTAL);
			windmillHandle4.rotate(progid, 5.0f, ROTATE_SPEED, HORIZONTAL);

			windmill1.rotate(progid, 5.0f, ROTATE_SPEED, HORIZONTAL);
			windmill2.rotate(progid, 5.0f, ROTATE_SPEED, HORIZONTAL);
			windmill3.rotate(progid, 5.0f, ROTATE_SPEED, HORIZONTAL);
			windmill4.rotate(progid, 5.0f, ROTATE_SPEED, HORIZONTAL);
			
			//stones
			stone1.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			stone2.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			stone3.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			stone4.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			stone5.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			stone6.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			stone7.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			
			//forest
			tree1.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			tree2.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			tree3.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			tree4.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			tree5.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			tree6.draw(progid, camera, SCREEN_WIDTH, SCREEN_HEIGHT);
			
			// Swap the buffers
			glfwSwapBuffers(window);
		}
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	glfwTerminate();
	//system("PAUSE");

	return 0;
}

// Moves/alters the camera positions based on user input
void DoMovement()
{
	// Camera controls
	if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])
	{
		camera.ProcessKeyboard(FORWARD, deltaTime);
	}

	if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])
	{
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	}

	if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])
	{
		camera.ProcessKeyboard(LEFT, deltaTime);
	}

	if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT])
	{
		camera.ProcessKeyboard(RIGHT, deltaTime);
	}
}

// Is called whenever a key is pressed/released via GLFW
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			keys[key] = false;
		}
	}
}

void MouseCallback(GLFWwindow *window, double xPos, double yPos)
{
	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	GLfloat xOffset = xPos - lastX;
	GLfloat yOffset = lastY - yPos;  // Reversed since y-coordinates go from bottom to left

	lastX = xPos;
	lastY = yPos;

	camera.ProcessMouseMovement(xOffset, yOffset);
}

void ScrollCallback(GLFWwindow *window, double xOffset, double yOffset)
{
	camera.ProcessMouseScroll(yOffset);
}