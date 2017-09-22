#include "GLShaders.h"
//Source: http://www.nexcius.net/2012/11/20/how-to-load-a-glsl-shader-in-opengl-using-c/


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//This is loaded by calling the following code :
//GLuint program = LoadShader("shader.vert", "shader.frag");
//glUseProgram(program);
//It can also be used to load multiple shaders by calling glUseProgram on different GLuints or 0 as the parameter to disable.

//std::string readFile(const char *filePath) {
//	std::string content;
//	std::ifstream fileStream(filePath, std::ios::in);
//
//	if (!fileStream.is_open()) {
//		std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
//		return "";
//	}
//
//	std::string line = "";
//	while (!fileStream.eof()) {
//		std::getline(fileStream, line);
//		content.append(line + "\n");
//	}
//
//	fileStream.close();
//	return content;
//}
std::string readShaderFile(const char *filename)
{
	std::ifstream fileIn(filename);
	if(!fileIn.good())
	{
		std::cout << "Failed to load file " << filename << "!" << std::endl;
		exit(1);
	}

	return std::string(std::istreambuf_iterator<char>(fileIn), std::istreambuf_iterator<char>(0));
	fileIn.close();
}

GLuint ShaderSetUp(const char *shader_path, const int type)
{

	GLuint shader = glCreateShader(type);
	std::string shaderStr = readShaderFile(shader_path);
	const char *shaderSrc = shaderStr.c_str();
	std::cout << "Compiling " << type << " shader." << std::endl;
	glShaderSource(shader, 1, &shaderSrc, NULL);
	glCompileShader(shader);

	GLint result = GL_FALSE;
	int logLength;
	// Check Tess evaluation shader
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> shaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(shader, logLength, NULL, &shaderError[0]);
	std::cout << &shaderError[0] << std::endl;

	return shader;

}



GLuint LoadShader(const char *vertex_path, const char *fragment_path) {
	GLuint vao;

	GLint result = GL_FALSE;
	int logLength;

	std::cout << "Linking program" << std::endl;
	GLuint program = glCreateProgram();

	GLuint vShader = ShaderSetUp(vertex_path, GL_VERTEX_SHADER);
	GLuint fShader = ShaderSetUp(fragment_path, GL_FRAGMENT_SHADER);

	glAttachShader(program, vShader);
	glAttachShader(program, fShader);

	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> programError((logLength > 1) ? logLength : 1);
	glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
	std::cout << &programError[0] << std::endl;

	glDeleteShader(vShader);
	glDeleteShader(fShader);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	return program;
}

GLuint LoadShader(const char *vertex_path, const char *tessControl_path, const char *tessEvaluation_path,const char *geometry_path, const char *fragment_path)
{

	GLuint vao;

	GLint result = GL_FALSE;
	int logLength;

	std::cout << "Linking program" << std::endl;
	GLuint program = glCreateProgram();

	GLuint vShader = ShaderSetUp(vertex_path, GL_VERTEX_SHADER);
	GLuint tcShader = ShaderSetUp(tessControl_path, GL_TESS_CONTROL_SHADER);
	GLuint teShader = ShaderSetUp(tessEvaluation_path, GL_TESS_EVALUATION_SHADER);
	GLuint gShader = ShaderSetUp(geometry_path, GL_GEOMETRY_SHADER);
	GLuint fShader = ShaderSetUp(fragment_path, GL_FRAGMENT_SHADER);

	glAttachShader(program,vShader);
	glAttachShader(program, tcShader);
	glAttachShader(program, teShader);
	glAttachShader(program, gShader);
	glAttachShader(program, fShader);

	glLinkProgram(program);
		
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> programError((logLength > 1) ? logLength : 1);
	glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
	std::cout << &programError[0] << std::endl;

	glDeleteShader(vShader);
	glDeleteShader(tcShader);
	glDeleteShader(teShader);
	glDeleteShader(gShader);
	glDeleteShader(fShader);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	return program;
}


