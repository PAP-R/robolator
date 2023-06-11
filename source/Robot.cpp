#include "Robot.h"

vector<bufferobject> Robot::to_objects() {
    vector<bufferobject> objects;

    mat4 transform = mat4(1) * Tracer::rotate(rotation);
//    mat4 transform = mat4(1);

    for (size_t i = 1; i < dh.size(); i++) {
        transform = transform * this->transform(i - 1);
        objects.emplace_back(color, emission, transform * this->transform_mid(i, 0.2), 0.5, MESH, this->mesh[0], this->mesh[1]);
    }

    return objects;
}

Robot::Robot(vec<2, uint32> mesh) : mesh(mesh) {
    dh.emplace_back(0);
}

vec3 Robot::drive(size_t index, float amount) {
    dh[index][0] = amount;
    return tcp();
}

vec3 Robot::tcp() {
    return joint_pos(dh.size() - 1);
}

size_t Robot::add_part(vec4 dh) {
    this->dh.emplace_back(dh);
    return this->dh.size() - 1;
}

vec3 Robot::joint_pos(size_t index) {
    mat4 transform = Tracer::rotate(rotation);
//    mat4 transform = mat4(1);

    for (size_t i = 0; i <= index; i++) {
        transform = transform * this->transform(i);
    }
    return position + transform * vec4(0, 0, 0, 1);
}

mat4 Robot::joint_dir(size_t index) {
    mat4 rotation = Tracer::rotate(this->rotation);
//    mat4 rotation = mat4(1);

    for (size_t i = 1; i <= index; i++) {
        rotation = rotation * Tracer::rotate(vec3(dh[i][3], 0, dh[i][0]));
    }
    return rotation;
}

vec3 Robot::move(vec3 pos) {
    pos = vec4(pos, 1) - this->position;
    pos = transpose(Tracer::rotate(rotation)) * vec4(pos, 1);

    if (length(pos) > (dh[1][2] + dh[2][2] + dh[3][2])) {
        throw std::invalid_argument("Position out of robot range");
    }

    float q1 = atan2(pos.y, pos.x);
    drive(1, q1);

    vec3 nextpos = transpose(Tracer::rotate({dh[1][3], 0, dh[1][0]})) * vec4(pos, 1);

    float alpha = atan2(nextpos.y, nextpos.x);
    float beta = acos((pow(dh[2][2], 2) + pow(length(nextpos), 2) - pow(dh[3][2], 2)) / (2 * (dh[2][2]) * length(nextpos)));

    float q2 = alpha -from * beta;
    drive(2, q2);

    float D = (pow(dh[2][2], 2) + pow(dh[3][2], 2) - pow(length(nextpos), 2)) / (2 * dh[2][2] * dh[3][2]);
    float q3 = pi<float>() - atan2(from * sqrt(1 - pow(D, 2)), D);
    drive(3, q3);

    return tcp();
}

vec3 Robot::move(vec3 pos, vec3 rot) {
    mat4 r06 = Tracer::rotate(rot) * joint_dir(0);
    move(pos + vec3(r06 * vec4(0, 0, -(dh[6][1] + dh[6][2]), 1)));

    mat4 r36 = transpose(joint_dir(3)) * r06;

    r36 = transpose(r36);

    float q4, q5, q6;

    if (r36[0][2] != 0 && r36[0][2] != 0) {
        q4 = atan2(from * r36[1][2], from * r36[0][2]);
        q5 = atan2(from * sqrt(1 - pow(r36[2][2], 2)), r36[2][2]);
        q6 = atan2(from * r36[2][1], -from * r36[2][0]);
    }
    else {
        q4 = atan2(-r36[0][1], from * r36[0][0]);
        q5 = half_pi<float>() - from * half_pi<float>();
        q6 = 0;
    }

    drive(4, q4);
    drive(5, q5);
    drive(6, q6);

    return tcp();
}

mat4 Robot::transform(size_t index) {
    return Tracer::transform(Tracer::rotate(vec3(dh[index][3], 0, dh[index][0])) * vec4(dh[index][2], 0, dh[index][1], 1), vec3(dh[index][3], 0, dh[index][0]));
}

mat4 Robot::transform_mid(size_t index, float size) {
    return Tracer::transform(Tracer::rotate(vec3(dh[index][3], 0, dh[index][0])) * vec4(dh[index][2] / 2, 0, dh[index][1] / 2, 1), vec3(dh[index][3], 0, dh[index][0]), vec3(dh[index][2] + size, size, dh[index][1] + size));
}

