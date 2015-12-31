

#include "stdafx.h"
#include"Shader_Loader.h"
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
using namespace core;

core::shader_loader::shader_loader(){}
core::shader_loader::~shader_loader(){}


string core::shader_loader::ReadShader(char* filename)
{

	string shaderCode;
	ifstream file(filename, ios::in);

	if(!file.good())
	{
		cout<<"File can't be read"<<endl;
		terminate();
	}

	file.seekg(0,ios::end);
	shaderCode.resize((unsigned int)file.tellg());
	file.seekg(0,ios::beg);
	file.read(&shaderCode[0],shaderCode.size());
	file.close();

	return shaderCode;



}

GLuint core::shader_loader::CreateShader(GLenum ShaderType, string source, char* Shadername)
{
	int compile_result =0;

	GLuint shader = glCreateShader(ShaderType);
	const char* shader_code_ptr = source.c_str();
	const int shader_code_size = source.size();

	glShaderSource(shader,1,&shader_code_ptr,&shader_code_size);
	glCompileShader(shader);
	glGetShaderiv(shader,GL_COMPILE_STATUS,&compile_result);

	if(compile_result == GL_FALSE)
	{
		int info_log_length =0;

		glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&info_log_length);
		vector<char> shader_log(info_log_length);
		glGetShaderInfoLog(shader,info_log_length,nullptr,&shader_log[0]);
		cout<<"Error compiling"<<Shadername<<endl;
		for (auto itr : shader_log)
		{
			cout << itr ;
		}
		cout << endl;
		return 0;
			}

	return shader;

}


GLuint core::shader_loader::CreateProgram(char* VertexShaderFilename, char* FragmentShaderFilename)
{

	string vertex_shader_code = ReadShader(VertexShaderFilename);
	string fragment_shader_code = ReadShader(FragmentShaderFilename);


	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER,vertex_shader_code,"Vertex shader");
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER,fragment_shader_code,"Fragment shader");

	int link_result = 0;

	GLuint program = glCreateProgram();

	glAttachShader(program,vertexShader);
	glAttachShader(program,fragmentShader);


	glLinkProgram(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glGetProgramiv(program,GL_LINK_STATUS,&link_result);

	if(link_result == GL_FALSE)
	{
		int info_log_length = 0;
		glGetProgramiv(program,GL_INFO_LOG_LENGTH,&info_log_length);
		vector<char> program_log(info_log_length);
		glGetProgramInfoLog(program,info_log_length,nullptr,&program_log[0]);
		cout<<"Link error"<<&program_log[0];

		return 0;
	}

	return program;

}

