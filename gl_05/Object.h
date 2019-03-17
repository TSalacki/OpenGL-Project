#pragma once
#include <GL/glew.h>
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "EnumTypeOfObject.h"
#include "MeshContoller.h"
#include "SolidMeshContoller.h"

#include <iostream>

using namespace std;

class Object {
	public:
		GLuint texture0;
		GLuint VBO, EBO, VAO, indices_counter;
		GLfloat x_position, y_position, z_position;
		GLfloat x_rotation, y_rotation, z_rotation;
		
		Object(TypeOfObject type, string textureName, GLfloat x, GLfloat y, GLfloat z, GLfloat x_rot, GLfloat y_rot, GLfloat z_rot) {
			x_position = x;
			y_position = y;
			z_position = z;
			x_rotation = x_rot;
			y_rotation = y_rot;
			z_rotation = z_rot;
			
			MeshContoller mesh;
			
			unsigned int verticesSize, indicesSize;
			GLfloat *vertices = mesh.getVerticesArray(type, verticesSize);
			GLuint *indices = mesh.getIndicesArray(type, indicesSize);

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glGenBuffers(1, &EBO);

			// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
			glBindVertexArray(VAO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
			
			// Position attribute
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid *)0);
			glEnableVertexAttribArray(0);

			// Color attribute
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
			glEnableVertexAttribArray(1);

			// TexCoord attribute
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid *)(6 * sizeof(GLfloat)));
			glEnableVertexAttribArray(2);

			// normal attribute
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid *)(8 * sizeof(GLfloat)));
			glEnableVertexAttribArray(3);
			
			glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

			glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
		
			// --== TEXTURE == --

			// prepare textures 
			GLuint texture;
			glGenTextures(1, &texture); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
			
			// Set our texture parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			
			// Set texture filtering
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			
			// Load, create texture and generate mipmaps
			cout << "Nazwa tekstury: " << textureName.c_str() << endl;
			int width, height;
			unsigned char* image = SOIL_load_image(textureName.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
			if (image == nullptr) {
				throw exception("Failed to load texture file");
			}
			
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture);
			
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
			
			glGenerateMipmap(GL_TEXTURE_2D);
			
			SOIL_free_image_data(image);
			
			glBindTexture(GL_TEXTURE_2D, 0);
			
			texture0 = texture;

			indices_counter = indicesSize/(sizeof(GLfloat));
		}





		Object(SolidTypeOfObject type, string textureName, int numberOfFaces, GLfloat objectRadius,
			GLfloat objectHeight, GLfloat x, GLfloat y, GLfloat z, GLfloat x_rot, GLfloat y_rot, GLfloat z_rot) {
			x_position = x;
			y_position = y;
			z_position = z;
			x_rotation = x_rot;
			y_rotation = y_rot;
			z_rotation = z_rot;

			SolidMeshContoller mesh;

			unsigned int verticesSize, indicesSize;
			GLfloat *vertices = mesh.getVerticesArray(type, numberOfFaces, objectRadius, objectHeight, verticesSize);
			GLuint *indices = mesh.getIndicesArray(type, numberOfFaces, indicesSize);

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glGenBuffers(1, &EBO);

			// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
			glBindVertexArray(VAO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

			// Position attribute
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid *)0);
			glEnableVertexAttribArray(0);

			// Color attribute
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
			glEnableVertexAttribArray(1);

			// TexCoord attribute
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid *)(6 * sizeof(GLfloat)));
			glEnableVertexAttribArray(2);

			// normal attribute
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid *)(8 * sizeof(GLfloat)));
			glEnableVertexAttribArray(3);

			glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

			glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

			// prepare textures 
			GLuint texture;
			glGenTextures(1, &texture); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

										// Set our texture parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			// Set texture filtering
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			// Load, create texture and generate mipmaps
			cout << "Nazwa tekstury: " << textureName.c_str() << endl;
			int width, height;
			unsigned char* image = SOIL_load_image(textureName.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
			if (image == nullptr) {
				throw exception("Failed to load texture file");
			}

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

			glGenerateMipmap(GL_TEXTURE_2D);

			SOIL_free_image_data(image);

			glBindTexture(GL_TEXTURE_2D, 0);

			texture0 = texture;

			indices_counter = indicesSize / (sizeof(GLfloat));
		}



		~Object() {
			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			glDeleteBuffers(1, &EBO);
		}

		void draw(int progid, Camera camera, int screen_width, int screen_height)
		{
			// Bind Textures using texture units
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture0);
			glUniform1i(glGetUniformLocation(progid, "Texture0"), 0);

			glm::mat4 projection;
			projection = glm::perspective(camera.GetZoom(), (GLfloat)screen_width / (GLfloat)screen_height, 0.1f, 100.0f);

			// Create camera transformation
			glm::mat4 view;
			view = camera.GetViewMatrix();

			// Get the uniform locations
			GLint modelLoc = glGetUniformLocation(progid, "model");
			GLint viewLoc = glGetUniformLocation(progid, "view");
			GLint projLoc = glGetUniformLocation(progid, "projection");

			// Pass the matrices to the shader
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

			glBindVertexArray(VAO);
			
			// Calculate the model matrix for each object and pass it to shader before drawing
			glm::mat4 model;
			glm::mat4 translation;
			glm::mat4 rotationX;
			glm::mat4 rotationY;
			glm::mat4 rotationZ;
			glm::mat4 constRot;

			translation = glm::translate(translation, glm::vec3(x_position, y_position, z_position));
			rotationX = glm::rotate(rotationX, glm::radians(x_rotation), glm::vec3(1.0f, 0.0f, 0.0f));
			rotationY = glm::rotate(rotationY, glm::radians(y_rotation), glm::vec3(0.0f, 1.0f, 0.0f));
			rotationZ = glm::rotate(rotationZ, glm::radians(z_rotation), glm::vec3(0.0f, 0.0f, 1.0f));
			constRot =  glm::rotate(constRot, glm::radians(5.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			
		/*	if(rotating)
				x_rotation += 1.0f;
			if (x_rotation > 360.0f)
				x_rotation -= 360.0f; */


			model = translation * rotationX * rotationY * rotationZ;


			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawElements(GL_TRIANGLES, indices_counter, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}

		void rotate(int progid, float anglePS, float FPS, RotationType type) {

			if (type == VERTICAL) {
				this->y_rotation += (anglePS / FPS);
				if (this->y_rotation > 360.0f)
					this->y_rotation -= 360.0f;
			}
			else if (type == HORIZONTAL) {
				this->z_rotation += (anglePS / FPS);
				if (this->z_rotation > 360.0f)
					this->z_rotation -= 360.0f;
			}

		}

};
