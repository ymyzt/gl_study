#version 330 core 
layout (location = 0 ) in vec3 vpos;
layout (location = 1 ) in vec3 color;
layout (location = 2 ) in vec2 intextrue;
out vec2 outtextrue;
uniform mat4 trans; 
void main()
{
	gl_Position = trans*vec4(vpos,1.0f);
	outtextrue = intextrue; 
}