#include"Shader.h"
#include <fstream>
#include <iostream>
using namespace std;
GLuint Shader::CreateShader(const char * fileName, GLenum shadertype)
{
	fstream f;
	f.open(fileName, ios::in);
	if (!f.is_open())
	{
		cout << "open file fail!!" << endl;
		//exit(0);
	}
	//int size = f.tellg();
	//cout<< "fileName:"<<fileName<<"  size:" <<size << endl;
	f.seekg(0, ios::beg);
	char *buffer = new char [1024];
	string str;
	while (!f.eof())
	{
		f.getline(buffer, 1024);
		str.append(buffer);
		str.append(1, '\n');
	}
	//buffer[size] = '\0';
	f.close();
	const char * buf = str.c_str();
	cout << "str  :"<< str.c_str() << endl;
	GLuint  shid = glCreateShader(shadertype);
	glShaderSource(shid, 1,&buf, NULL);
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
void Shader::setFloatToUnifrom(const char *key,int n ,float * value)//n :1~4
{
	GLint addr = glGetUniformLocation(shaderid, key);
	switch (n)
	{
	case 1:
		glUniform1f(addr, value[0]);
		break;
	case 2:
		glUniform2f(addr, value[0], value[1]);
		break;
	case 3:
		glUniform3f(addr, value[0], value[1],value[2]);
		break;
	case 4:
		glUniform4f(addr, value[0], value[1],value[2],value[3]);
		break;
	default:
		cout << "n(1~4) count err!" << endl;
	}
}
void Shader::setMaT4ToUnifrom(const char *key, glm::mat4 trans)
{
	GLint addr = glGetUniformLocation(shaderid, key);
	glUniformMatrix4fv(addr, 1, GL_FALSE, glm::value_ptr(trans));
}
void Shader::setIntToUnifrom(const char *key, int n,int *value)
{
	GLint addr = glGetUniformLocation(shaderid, key);
	switch (n)
	{
	case 1:
		glUniform1i(addr, value[0]);
		break;
	case 2:
		glUniform2i(addr, value[0], value[1]);
		break;
	case 3:
		glUniform3i(addr, value[0], value[1], value[2]);
		break;
	case 4:
		glUniform4i(addr, value[0], value[1], value[2], value[3]);
		break;
	default:
		cout << "n(1~4) count err!" << endl;
	}
}
Shader::~Shader()
{
	
}