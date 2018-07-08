#include"Shader.h"
#include <fstream>
#include <iostream>
using namespace std;
GLuint Shader::CreateShader(const char * fileName, GLenum shadertype)
{
	fstream f;
	f.open(fileName, ios::in|ios::ate);
	if (!f.is_open())
	{
		cout << "open file fail!!" << endl;
		//exit(0);
	}
	int size = f.tellg();
	cout<< "fileName:"<<fileName<<"  size:" <<size << endl;
	f.seekg(0, ios::beg);
	char *buffer = new char [size+1];
	f.read(buffer, size);
	buffer[size] = '\0';
	f.close();
	//cout << "buffer  :"<< buffer << endl;
	GLuint  shid = glCreateShader(shadertype);
	glShaderSource(shid, 1, &buffer, NULL);
	glCompileShader(shid);
	GLint success;
	glGetShaderiv(shid, GL_COMPILE_STATUS, &success);
	cout << "success:  " << success << endl;
	if (!success)
	{
		cout << fileName << "  Complie Shader Fail!" << endl;
		char info[512];
		glGetShaderInfoLog(shid, 512, NULL, info);
		cout << "info : " << info << endl;
		//exit(0);
	}
	return shid;
}
Shader::Shader(const char *vshaderpath, const char *fshaderpath)
{
	GLuint vshaderID = CreateShader(vshaderpath, GL_VERTEX_SHADER);
	GLuint fshaderID = CreateShader(fshaderpath, GL_FRAGMENT_SHADER);
	
	shaderid = glCreateProgram();
	glAttachShader(shaderid, vshaderID);
	glAttachShader(shaderid, fshaderID);
	LinkProgram();
	glDeleteShader(vshaderID);
	glDeleteShader(fshaderID);
}
int Shader::LinkProgram()
{

	glLinkProgram(shaderid);
	int success;
	glGetProgramiv(shaderid,GL_LINK_STATUS, &success);
	if (!success)
	{
		cout << " Link  Fail!" << endl;
		char info[512];
		glGetProgramInfoLog(shaderid, 512, NULL, info);
		cout << "info : " << info << endl;
		return -1;
	}
	return 1;
}
GLuint Shader::getShaderID()
{
	return shaderid;
}
void Shader::Use()
{
	glUseProgram(shaderid);
}
void Shader::setFloatToUnifrom(const char *key, float value)
{
	GLint addr = glGetUniformLocation(shaderid, key);
	glUniform1f(addr, value);
}
void Shader::setMaT4ToUnifrom(const char *key, glm::mat4 trans)
{
	GLint addr = glGetUniformLocation(shaderid, key);
	glUniformMatrix4fv(addr, 1, GL_FALSE, glm::value_ptr(trans));
}
void Shader::setIntToUnifrom(const char *key, int value)
{
	GLint addr = glGetUniformLocation(shaderid, key);
	glUniform1i(addr, value);
}
Shader::~Shader()
{
	
}