#pragma once
#include "Dependencies\glew\glew.h"
#include <vector>


GLuint LoadShader(const char *vertex_path, const char *fragment_path);

GLuint LoadShader(const char *vertex_path, const char *tessControl_path, const char *tessEvaluation_path, const char *fragment_path);
GLuint LoadShader(const char *vertex_path, const char *tessControl_path, const char *tessEvaluation_path, const char *geometry_path, const char *fragment_path);