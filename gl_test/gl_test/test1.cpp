#include "glad/glad.h"
#include "glfw3.h"
#include<iostream>
#include"Shader.h"
#include "stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
using namespace std;
void releaseSelf()
{
	glfwTerminate();
	exit(-1);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow *window =  glfwCreateWindow(800, 600, "test1", 0, 0);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		releaseSelf();
	}
	glfwMakeContextCurrent(window);
	
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to getaddress!" << std::endl;
		releaseSelf();
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, 800, 600);


	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	GLfloat  vertices[] = { 
		//位置               //颜色          //纹理
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		//0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
		//0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f
		
	};
	//GLuint index[] = {
	//	0, 1, 2,
	//	1, 2, 3
	//};
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//GLuint EBO;
	//glGenBuffers(1, &EBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);

	//GLuint texture1, texture2;

	//glGenTextures(1, &texture1);
	//glBindTexture(GL_TEXTURE_2D, texture1);
	////设置环绕、和过滤方式
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//int width, height, nrChannels;
	//stbi_set_flip_vertically_on_load(true);
	//unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
	//if (!data)
	//{
	//	cout << "loadTextrue fail!!!" << endl;
	//}
	//else
	//{
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//}
	//stbi_image_free(data);


	//glGenTextures(1, &texture2);
	//glBindTexture(GL_TEXTURE_2D, texture2);
	////设置环绕、和过滤方式
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//stbi_set_flip_vertically_on_load(true);
	//data = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);

	//if (!data)
	//{
	//	cout << "loadTextrue fail!!!" << endl;
	//}
	//else
	//{
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//}
	//stbi_image_free(data);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void *)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void *)(3*sizeof(GL_FLOAT)));
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void *)(6 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	//glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	//
	Shader program = Shader("vshader.vshader", "fshader.fshader");
	GLuint programID = program.getShaderID();
	//glm::mat4 trans(1);
	/*trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));*/
	
	


	
	
	//program.setIntToUnifrom("ourTexture1", 0);
	//program.setIntToUnifrom("ourTexture2", 1);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glUseProgram(programID);
		//double time = glfwGetTime();
		//float greenvalue = (float)sin(time) / 2 + 0.5f;
		//GLuint fc = glGetUniformLocation(programID, "color");
		//float v[] = { 0.0f, greenvalue, 0.0f, 1.0f };
		//program.setFloatToUnifrom("color", 4, v);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES,0,3);
		glUseProgram(0);
		glBindVertexArray(0);
		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, texture1);
		//glActiveTexture(GL_TEXTURE1);
		//glBindTexture(GL_TEXTURE_2D, texture2);
		//glm::mat4 trans(1);
		//trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		//trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
		//
		//



		//program.Use();
		////program.setMaT4ToUnifrom("trans", trans);
		//program.setMaT4ToUnifrom("trans", trans);

		//glUseProgram(programID);
		//glUniform4f(fc, 0.0, greenvalue, 0.0, 1.0);

		//glBindTexture(GL_TEXTURE_2D, texture);
		//glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES,0,3);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);



		//glm::mat4 trans2(1);
		//trans = glm::rotate(trans2, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		//trans2 = glm::translate(trans2, glm::vec3(-0.5f, +0.5f, 0.0f));
		//float scalen = 0.5*(sin(glfwGetTime()) + 1);
		//trans2 = glm::scale(trans2, glm::vec3(scalen, scalen, scalen));
		//program.setMaT4ToUnifrom("trans", trans2);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glBindVertexArray(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);
	//glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}