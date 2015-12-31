
#pragma once

#include<string>
#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;

namespace core
{


	class shader_loader
	{
		private:
		string ReadShader(char *filename);
		GLuint CreateShader(GLenum Shadertype, string source, char* shadername);

		public:
			shader_loader(void);
			~shader_loader(void);
			GLuint CreateProgram(char* VertexShaderFilename, char* FragmentShaderFilename);
			
	};
}