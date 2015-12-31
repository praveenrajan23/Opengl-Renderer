// Opengl1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<GL\glew.h>
#include<GL\freeglut.h>
#include<iostream>
#include<conio.h>
#include"Shader_Loader.h"
#include<glm\glm.hpp>
#include<sys/timeb.h>
#include <math.h>
#include <random>

using namespace std;
using namespace core;
using namespace glm;
GLuint program;

void RenderScene(void)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*struct timeb t1;
	ftime(&t1);*/
	cout << "h"<<endl;
		const float color[] = { ((float)sin(rand() % 10)*0.5 + 0.5), (0.5), ((float)cos(rand() % 10)*0.5 + 0.3f), 1.0f };
		glClearBufferfv(GL_COLOR, 0, color);
	

//	glClearColor(1.0, 1.0, 0.0, 1.0);

	glUseProgram(program);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 3);

	glutSwapBuffers();
}

void Init()
{
	glEnable(GL_DEPTH_TEST);

	shader_loader shaderLoader;

	program = shaderLoader.CreateProgram("Vertex_Shader.glsl","Fragment_Shader.glsl");

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int _tmain(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500,500);
	glutInitWindowSize(400,200);

	glutCreateWindow("Praveen's first graphics....!");
	

	
	glewInit();

	Init();

	if(glewIsSupported("GL_VERSION_4_3"))
	{
		cout<<"GL_VERSION_4_3"<<endl;
	}
	else
	{
		cout<<"nope!!"<<endl;
	}

	glutDisplayFunc(RenderScene);

	glutMainLoop();
	glDeleteProgram(program);

	return 0;
}

