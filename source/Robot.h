#ifndef ROBOLATOR_ROBOT_H
#define ROBOLATOR_ROBOT_H

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"
using namespace glm;

#include <vector>
using namespace std;

#include <Oddity.h>

class Robot {
public:
    /*
     * dh:
     * O: rotation um z
     * d: bewegung nach z
     * a: bewegung nach x
     * alpha: rotation um x
     */
    vector<vec4> dh;
    vec<2, uint32> mesh;
    float from = 1;

public:
    vec4 position = vec4(0, 0, 0, 1);
    vec3 rotation = radians(vec3(90, 0, 0));
    vec4 color = vec4(0.3, 0.3, 0.3, 1);
    vec4 emission = vec4(0);

    explicit Robot(vec<2, uint32> mesh);

    size_t add_part(vec4 dh);

    vec3 drive(size_t index, float amount);
    vec3 move(vec3 pos);
    vec3 move(vec3 pos, vec3 rot);

    vec3 joint_pos(size_t index);
    mat4 joint_dir(size_t index);
    vec3 tcp();

    vector<bufferobject> to_objects();

    mat4 transform(size_t index);

    mat4 transform_mid(size_t index, float size);

};


#endif //ROBOLATOR_ROBOT_H
