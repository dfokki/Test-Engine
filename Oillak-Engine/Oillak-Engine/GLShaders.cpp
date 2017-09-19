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

std::string readShaderFile(const char *filename) {
	std::ifstream fileIn(filename);
	if(!fileIn.good())
	{
		std::cout << "Failed to load file " << filename << "!" << std::endl;
		exit(1);
	}

	return std::string(std::istreambuf_iterator<char>(fileIn), std::istreambuf_iterator<char>(0));
	fileIn.close();
}


GLuint LoadShader(const char *vertex_path, const char *fragment_path) {
	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Read shaders
	std::string vertShaderStr = readShaderFile(vertex_path);
	std::string fragShaderStr = readShaderFile(fragment_path);
	const char *vertShaderSrc = vertShaderStr.c_str();
	const char *fragShaderSrc = fragShaderStr.c_str();

	GLint result = GL_FALSE;
	int logLength;

	// Compile vertex shader
	std::cout << "Compiling vertex shader." << std::endl;
	glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
	glCompileShader(vertShader);

	// Check vertex shader
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
	std::cout << &vertShaderError[0] << std::endl;

	// Compile fragment shader
	std::cout << "Compiling fragment shader." << std::endl;
	glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
	glCompileShader(fragShader);

	// Check fragment shader
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
	std::cout << &fragShaderError[0] << std::endl;

	std::cout << "Linking program" << std::endl;
	GLuint program = glCreateProgram();
	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> programError((logLength > 1) ? logLength : 1);
	glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
	std::cout << &programError[0] << std::endl;

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	return program;
}

GLuint LoadShader(const char *vertex_path, const char *tessControl_path, const char *tessEvaluation_path, const char *fragment_path)
{
	GLuint vao;

	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	GLuint tesscontShader = glCreateShader(GL_TESS_CONTROL_SHADER);
	GLuint tessevShader = glCreateShader(GL_TESS_EVALUATION_SHADER);
	// Read shaders
	std::string vertShaderStr = readShaderFile(vertex_path);
	std::string tesscontShaderStr = readShaderFile(tessControl_path);
	std::string tessevShaderStr = readShaderFile(tessEvaluation_path);
	std::string fragShaderStr = readShaderFile(fragment_path);
	const char *vertShaderSrc = vertShaderStr.c_str();
	const char *tesscontShaderSrc = tesscontShaderStr.c_str();
	const char *tessevShaderSrc = tessevShaderStr.c_str();
	const char *fragShaderSrc = fragShaderStr.c_str();

	GLint result = GL_FALSE;
	int logLength;

	// Compile vertex shader
	std::cout << "Compiling vertex shader." << std::endl;
	glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
	glCompileShader(vertShader);

	// Check vertex shader
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
	std::cout << &vertShaderError[0] << std::endl;


	// Compile Tesselation control shader
	std::cout << "Compiling Tesselation control shader." << std::endl;
	glShaderSource(tesscontShader, 1, &tesscontShaderSrc, NULL);
	glCompileShader(tesscontShader);

	// Check vertex shader
	glGetShaderiv(tesscontShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(tesscontShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> tesscontShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(tesscontShader, logLength, NULL, &tesscontShaderError[0]);
	std::cout << &tesscontShaderError[0] << std::endl;

	// Compile Tesselation evaluation shader
	std::cout << "Compiling Tesselation evaluation shader." << std::endl;
	glShaderSource(tessevShader, 1, &tessevShaderSrc, NULL);
	glCompileShader(tessevShader);

	// Check Tess evaluation shader
	glGetShaderiv(tessevShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(tessevShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> tessevShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(tessevShader, logLength, NULL, &tessevShaderError[0]);
	std::cout << &tessevShaderError[0] << std::endl;


	// Compile fragment shader
	std::cout << "Compiling fragment shader." << std::endl;
	glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
	glCompileShader(fragShader);

	// Check fragment shader
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
	std::cout << &fragShaderError[0] << std::endl;

	std::cout << "Linking program" << std::endl;
	GLuint program = glCreateProgram();
	glAttachShader(program, vertShader);
	glAttachShader(program, tesscontShader);
	glAttachShader(program, tessevShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> programError((logLength > 1) ? logLength : 1);
	glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
	std::cout << &programError[0] << std::endl;

	glDeleteShader(vertShader);
	glDeleteShader(tesscontShader);
	glDeleteShader(tessevShader);
	glDeleteShader(fragShader);

	return program;
}