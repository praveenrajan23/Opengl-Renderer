#version 430 core
void main()
{
	const vec4 vert[3] = vec4[3](vec4(0.25, -0.25, 0.5, 1.0), 
		vec4(-0.25,-0.25, 0.5, 1.0),
		vec4(0.25, 0.25, 0.5, 1.0));

	gl_Position = vert[gl_VertexID];
}