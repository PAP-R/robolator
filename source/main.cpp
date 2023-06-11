#include <iostream>

#include "Oddity.h"

#include "Robot.h"

int main() {
    OddityEngine oe = OddityEngine();

    auto cube = oe.tracer->vertexbuffer.add(Tracer::obj_to_vert(Loader::obj("models/cube.obj")));
    auto env = oe.tracer->objectbuffer.add({
        {{0, 0, 0, 1}, {1, 1, 1, 1}, Tracer::transform(vec3(0), vec3(0), vec3(50)), 1, SPHERE},
//        {{0, 0, 0, 1}, {1, 0.7882, 0.1333, 1}, Tracer::transform(vec3(0), vec3(0), vec3(50)), 1, SPHERE},
//        {{0.2, 0.2, 0.2, 1}, {1, 1, 1, 0}, Tracer::transform(vec3(0, -1, 0), radians(vec3(90, 0, 0)), vec3(50, 50, 0)), 0.5, MESH, cube[0], cube[1]},
    });

    Robot robo(cube);
    robo.add_part({0, 0, 0, radians(90.0f)});
    robo.add_part({0, 0, 1.1, 0});
    robo.add_part({radians(90.0f), 0, 1, radians(90.0f)});
    robo.add_part({0, 0, 0, radians(-90.0f)});
    robo.add_part({0, 0, 0, radians(90.0f)});
    robo.add_part({0, 0.4, 0, 0});
//    robo.add_part({radians(90.0f), 0, 1, radians(90.0f)});

    do {
        auto time = oe.get_time();
        vec3 goal = vec3(1 + 0 * sin(time), 1 + 1 * sin(time), 1 * cos(time));
        robo.move(goal, vec3(0, 0, radians(90.0f)));
//        robo.drive(4, sin(time));
//        robo.drive(5, cos(time));
//        robo.drive(1, time);
//        robo.drive(2, sin(time));
//        robo.drive(3, -sin(time));
        oe.tracer->objectbuffer.add_dynamic(robo.to_objects());
        oe.tracer->objectbuffer.add_dynamic({{0, 0, 0, 1}, {0, 0.5, 1, 1}, Tracer::transform(vec3(robo.tcp()), vec3(0), vec3(0.15)), 0, SPHERE});
        oe.tracer->objectbuffer.add_dynamic({{0, 1, 0.5, 0.5}, {0, 0, 0, 0}, Tracer::transform(vec3(goal), vec3(0), vec3(0.2)), 0, SPHERE});
//        printf("%f\t", distance(vec3(transpose(Tracer::rotate(robo.rotation)) * vec4(goal, 1)), robo.joint_pos(2)));
    } while (oe.update());
}



//vector<bufferobject> objects = {
//        {{0, 0, 0, 1}, {1, 0.7882, 0.1333, 1}, transform(vec3(0), vec3(0), vec3(50)), SPHERE},
////
//        {{0.9, 0.9, 0.9, 1}, {1, 1, 1, 0.5}, transform(vec3(-2, 0, 0), vec3(0, 90, 0), vec3(2)), MESH, 0, 6},
//        {{0.9, 0.9, 0.9, 1}, {1, 1, 1, 0.5}, transform(vec3(2, 0, 0), vec3(0, 90, 0), vec3(2)), MESH, 0, 6},
//        {{0.9, 0.9, 0.9, 1}, {1, 1, 1, 0.5}, transform(vec3(0, -2, 0), vec3(90, 0, 0), vec3(2)), MESH, 0, 6},
//        {{0.9, 0.9, 0.9, 1}, {1, 1, 1, 0.5}, transform(vec3(0, 2, 0), vec3(90, 0, 0), vec3(2)), MESH, 0, 6},
////            {{1, 1, 1, 1}, {1, 1, 1, 0.3}, {0, -1, 5, 0}, {1, 1, 1, 0}, MESH, 12, 6},
////            {{0.5, 0.5, 0.5, 1}, {1, 1, 1, 1}, {0, 0, 10, 0}, {2, 1, 1, 0}, SPHERE},
////            {{1, 1, 1, 0}, {0, 0, 0, 0}, {1, 0, 8, 0}, {0.5, 1, 1, 0}, SPHERE},
////            {{1, 1, 1, 1}, {0, 0, 0, 0}, {-1, 0, 8, 0}, {0.5, 1, 1, 0}, SPHERE},
//
////            {{0, 0.9, 0, 1}, {0, 1, 0, 0.5}, {0, 1, 10 + cos(this->time) * 5, 0}, {0.5, 0.5, 0.5, 0}, SPHERE, 12, 6},
////            {{0, 0, 0.9, 1}, {0, 0, 1, 0.5}, {-2, -1, 10 + cos(this->time) * 5, 0}, {0.5, 0.5, 0.5, 0}, MESH, 12, 6},
//
////            {{1, 0, 1, 0.1}, {0, 0, 0, 0}, {0, 0, 3 + cos(this->time) * 2, 0}, {1, 1, 1, 0}, MESH, 12, 6},
//
////            {{0.9, 0, 0, 1}, {1, 0, 0, 0.5}, {sin(this->time) * 1, cos(this->time) * 1, 4, 0}, {0.5, 1, 1, 0}, SPHERE},
////            {{1, 0, 0, 1}, {1, 0, 0, 1}, {sin(this->time + radians(90.0f)) * 1.5, 0, 7 + cos(this->time + radians(90.0f)) * 1.5, 0}, {0.5, 1, 1, 0}, SPHERE},
////            {{1, 0, 0, 1}, {1, 0, 0, 1}, {sin(this->time + radians(180.0f)) * 2, 0, 5 + cos(this->time + radians(180.0f)) * 2, 0}, {0.5, 1, 1, 0}, SPHERE},
////            {{1, 0, 0, 1}, {1, 0, 0, 1}, {sin(this->time + radians(270.0f)) * 2, 0, 5 + cos(this->time + radians(270.0f)) * 2, 0}, {0.5, 1, 1, 0}, SPHERE},
//};

//objectbuffer.set_data(objects, 1);