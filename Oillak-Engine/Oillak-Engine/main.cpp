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

void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0);//clear red

	glutSwapBuffers();
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL First Window");

	glEnable(GL_DEPTH_TEST);

	// register callbacks
	glutDisplayFunc(renderScene);

	glutMainLoop();

	return 0;
}