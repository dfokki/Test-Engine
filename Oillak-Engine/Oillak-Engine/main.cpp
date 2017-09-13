//#include "Dependencies\glew\glew.h"
////#include "SDLwindow.h"
//#include <iostream>
//
//int main(int argc, char **argv)
//{
//	
//	
//	 //SDLwindow m_window(640, 480);
//	
//	
//	return 0;
//}

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include <time.h>
#include "Dependencies\glm\glm\glm.hpp"
#include <chrono>
#include "GLShaders.h"

static double t = 0;

void render(void)
{
		double dt = 1.0 / 60.0;

		const GLfloat color[]{ (float)sin(t)*0.5f + 0.5f,
								(float)cos(t) * 0.5f + 0.5f,
								0.0f,
								1.0f };
		static const GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, color);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	glClearColor(0.0, 0.0, 0.0, 1.0);//clear red
		GLuint program = LoadShader("shader.vert", "shader.frag");
		glUseProgram(program);
		glDrawArrays(GL_POINTS, 0, 1);
		//glPointSize(0.f);
		t += dt;

		glutSwapBuffers();
	
}

int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL First Window");

	glewInit();
	if(glewIsSupported("GL_VERSION_4_5"))
	{
		std::cout << " GLEW Version is 4.5\n ";
	}
	else
	{
		std::cout << "GLEW 4.5 not supported\n ";
	}

	glEnable(GL_DEPTH_TEST);

	GLuint program = LoadShader("shader.vert", "shader.frag");
	glUseProgram(program);
	glDrawArrays(GL_POINTS, 0, 1);
	glPointSize(40.f);

	// register callbacks
	glutDisplayFunc(render);
	
	// idle func registration
	glutIdleFunc(render);

	// Function that gets the application in a never ending loop, always waiting for the next event to process
	glutMainLoop();

	return 0;
}

