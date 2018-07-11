#version 330 core
layout (location = 0 ) in vec3 vpos;
layout (location = 1 ) in vec3 color;
layout (location = 2 ) in vec2 intextrue;
out vec2 outtextrue;
uniform mat4 trans;
//uniform vec4 color;
out vec4 vFcolor;
out float mixvalue;
uniform float mixValue;
void main()
{
	gl_Position = trans*vec4(vpos,1.0f);
	//gl_Position = vec4(vpos,1.0f);
	outtextrue = intextrue;
	vFcolor = vec4(color,1.0f);
	mixvalue = mixValue;
}