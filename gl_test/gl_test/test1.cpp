#include "glad/glad.h"
#include "glfw3.h"
#include<iostream>
#include"Shader.h"
#include "stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
using namespace std;
float mixValue = 0.2;
float ChangValue =100.0f;
void releaseSelf()
{
	glfwTerminate();
	exit(-1);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		ChangValue = 100.0f;
		cout<<"ChangValue:"<<ChangValue<<endl;
		mixValue += 0.001f; // change this value accordingly (might be too slow or too fast based on system hardware)
		if (mixValue >= 1.0f)
			mixValue = 1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{	
		ChangValue =120.0f;
		mixValue -= 0.001f; // change this value accordingly (might be too slow or too fast based on system hardware)
		if (mixValue <= 0.0f)
			mixValue = 0.0f;
	}
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


	GLuint VAO ;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
//----------三角
	//GLfloat  vertices[] = { 
	//	//位置               //颜色          //纹理
	//	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	//	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
	//	0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 1.0f,
	//};
//----------矩形
	/*GLuint index[] = {
		0, 1, 2,
		0, 2, 3
	};*/
	//GLfloat  vertices[] = { 
	//	//位置               //颜色          //纹理
	//	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	//	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
	//	0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
	//	-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
	//};
	//GLfloat  vertices2[] = {
	//	//位置               //颜色          //纹理
	//	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	//	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f,
	//	0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 2.0f,
	//	-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f,
	//};
//----------
	GLfloat  vertices3[] = {
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
	};
//---------
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);
	/*GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);*/

	/*GLuint VAO2;
	glGenVertexArrays(1, &VAO2);
	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
*/

	GLuint texture1, texture2;

	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	//设置环绕、和过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
	if (!data)
	{
		cout << "loadTextrue fail!!!" << endl;
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	stbi_image_free(data);


	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	////设置环绕、和过滤方式
	float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameterfv(GL_TEXTURE_2D, GL_CLAMP_TO_BORDER, borderColor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//stbi_set_flip_vertically_on_load(true);
	data = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);

	if (!data)
	{
		cout << "loadTextrue fail!!!" << endl;
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	stbi_image_free(data);


	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void *)0);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void *)(3*sizeof(GL_FLOAT)));
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void *)(6 * sizeof(GL_FLOAT)));
	//glEnableVertexAttribArray(0);
	//glEnableVertexAttribArray(1);
	//glEnableVertexAttribArray(2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void *)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void *)(3 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	//glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	//
	Shader program = Shader("vshader.vshader", "fshader.fshader");
	GLuint programID = program.getShaderID();
	/*glm::mat4 trans(1.0f);
	trans = glm::rotate(trans, 90.0f, glm::vec3(0.0, 0.0, 1.0));
	trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));*/
	
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(2.0f, 5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f, 3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f, 2.0f, -2.5f),
		glm::vec3(1.5f, 0.2f, -1.5f),
		glm::vec3(-1.3f, 1.0f, -1.5f)
	};


	
	int a1[] = { 0 };
	int a2[] = { 1 };
	glUseProgram(programID);
	program.setIntToUnifrom("ourTexture1", 1,a1);
	program.setIntToUnifrom("ourTexture2", 1, a2);
	//program.setMaT4ToUnifrom("trans", trans);
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		processInput(window);
		//double time = glfwGetTime();
		//float greenvalue = (float)sin(time) / 2 + 0.5f;
		//GLuint fc = glGetUniformLocation(programID, "color");
		//float v[] = { 0.0f, greenvalue, 0.0f, 1.0f };
		//program.setFloatToUnifrom("color", 4, v);
		glBindVertexArray(VAO);
		//glBindTexture(GL_TEXTURE_2D, texture1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		//glDrawArrays(GL_TRIANGLES,0,3);
		float a[] = { mixValue };
		program.setFloatToUnifrom("mixValue", 1, a);


		//glm::mat4 model(1);
		//trans2 = glm::translate(trans2, glm::vec3(-0.5f, +0.5f, 0.0f));
		//trans2 = glm::rotate(trans2, (float)glfwGetTime()*50.0f, glm::vec3(0.0f, 0.0f, 1.0f));
		//model = glm::rotate(model, -55.0f, glm::vec3(1.0f, 0.0f, 0.0f));
		//model = glm::rotate(model, (float)glfwGetTime()*50.0f, glm::vec3(0.5f, 0.5f, 0.0f));
		//program.setMaT4ToUnifrom("model", model);
		glm::mat4 view(1);
		// 注意，我们将矩阵向我们要进行移动场景的反方向移动。
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.0f));
		program.setMaT4ToUnifrom("view", view);
		glm::mat4 projection;
		projection = glm::perspective(45.0f,800.0f/600.0f, 0.1f, 100.0f);
		program.setMaT4ToUnifrom("projection", projection);
		for (int i = 0; i < 10;i++)
		{
			glm::mat4 model(1);
			model = glm::translate(model, cubePositions[i]);
			if (i % 3 == 0||i == 0)
				model = glm::rotate(model, (float)glfwGetTime()*50.0f, glm::vec3(0.5f, 1.0f, 0.0f));
			else
				model = glm::rotate(model, 20.0f*i, glm::vec3(1.0f, 0.0f, 0.0f));
			program.setMaT4ToUnifrom("model", model);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glm::mat4 trans3(1);
		//trans3 = glm::translate(trans3, glm::vec3(0.5f, -0.5f, 0.0f));
		//trans3 = glm::rotate(trans2, (float)glfwGetTime()*50.0f, glm::vec3(0.0f, 0.0f, 1.0f));
		//float scale = sin((float)glfwGetTime())*0.5+0.5;
		//trans3 = glm::scale(trans3, glm::vec3(scale, scale, 0.0f));
		//program.setMaT4ToUnifrom("trans", trans3);

		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);



		
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glBindVertexArray(0);
	glUseProgram(0);
	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);
	//glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}