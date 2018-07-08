#ifndef _SHADER_H_
#define  _SHADER_H_
#include "glad/glad.h"
#include "glfw3.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
enum shaderType {
	shader,
	program
};
class Shader
{
private:
	shaderType Type;
	GLuint shaderid;
public:
	//GLuint CreateShader(char * fileName, GLenum shadertype);
	GLuint  CreateShader(const char * fileName, GLenum shadertype);//vshader   fshader
	Shader(const char * vshaderpath,const char * fshaderpath);
	GLuint getShaderID();
	void Use();
	void setFloatToUnifrom(const char *,float);
	void setIntToUnifrom(const char *, int);
	void setMaT4ToUnifrom(const char *, glm::mat4 );
	int  LinkProgram();
	~Shader();

};




#endif