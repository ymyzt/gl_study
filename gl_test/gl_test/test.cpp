
#include "GLAD/glad.h"
#include "glfw3.h"
#include<iostream>
#include<string>
using namespace std;
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
int main()
{
	//��������
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//��ʼ��glad  ��ȡgl������ַ ʹ��gl����ǰ����
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, 800, 600);

	

	//���ûص�
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//������ɫ��Դ��
	char * vertexsrc = "#version 330 core \n\
					   	layout (location = 0 ) in vec3 vpos;\n	\
						void main()\n\
						{\n\
							gl_Position = vec4(vpos.x,vpos.y,vpos.z,1.0f); \
						}\n\
						";
	//����������ɫ��ID,������Դ��,����
	unsigned int vertexshader;
	vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexshader, 1, &vertexsrc, NULL);
	glCompileShader(vertexshader);
	//��ȡ����״̬
	int  success;
	char infoLog[512];
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexshader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	//ƬԪ��ɫ��Դ��
	char *fragmentsrc = "#version 330 core\n\
						out vec4 FragColor;\n\
						void main()\n\
							{\n\
							FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\
							}\n\
							";
	//����ƬԪ��ɫ��ID,������Դ��,����
	unsigned int fragmentshader;
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, &fragmentsrc, NULL);
	glCompileShader(fragmentshader);
	//��ȡ����״̬
	int  success2;
	char infoLog2[512];
	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success2);
	if (!success2)
	{
		glGetShaderInfoLog(fragmentshader, 512, NULL, infoLog2);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog2 << std::endl;
	}
	//������ɫ�����򣬸��Ŷ�����ɫ����ƬԪ��ɫ��������
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexshader);
	glAttachShader(shaderProgram, fragmentshader);
	glLinkProgram(shaderProgram);
	int  success3;
	char infoLog3[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success3);
	if (!success3)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog3);
		cout << "link error:" << infoLog3 << endl;
	}
	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);




	//��������
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};
	//float vertices2[] = {
	//	0.5f, 0.5f, 0.0f,   // ���Ͻ�
	//	0.5f, -0.5f, 0.0f,  // ���½�
	//	-0.5f, -0.5f, 0.0f, // ���½�
	//	-0.5f, 0.5f, 0.0f   // ���Ͻ�
	//};
	//unsigned int indices[] = { // ע��������0��ʼ! 
	//	0, 1, 3, // ��һ��������
	//	1, 2, 3  // �ڶ���������
	//};
	//������������
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	//���嶥�㻺�����   �󶨲���������
	/*unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);*/
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(0);
	
	

	
	//���
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	



	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		
		glUseProgram(shaderProgram);
		//��
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6,GL_UNSIGNED_INT, (void *)0);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		
		glBindVertexArray(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	//system("pause");
	return 0;
}
