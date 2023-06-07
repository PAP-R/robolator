#version 460 core

in vec3 fragmentpos;

out vec4 color;

uniform float TIME;


struct bufferobject {
    vec4 color;
    vec4 emission;
    mat4 transform;
    uint type;
    uint vertexstart;
    uint vertexcount;
};

struct buffervertex {
    vec4 pos;
    vec4 color;
    vec4 normal;
    vec2 uv;
};

struct Ray {
    vec3 origin;
    vec3 dir;
    bool hit;
    vec3 pos;
    vec3 normal;
    float len;
    uint count;
    vec4 color;
    vec4 emission;
};

layout(std140, std430, binding = 3) buffer objectbuffer {
    bufferobject objects[];
};

layout(std140, std430, binding = 4) buffer verticexbuffer {
    buffervertex vertices[];
};

void main() {
    color = abs(vec4(fragmentpos, 1));
}