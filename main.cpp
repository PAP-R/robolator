#include <iostream>

#include <Oddity.h>

int main() {
    OddityEngine oe = OddityEngine();
    while (!glfwWindowShouldClose(oe.get_window())){
        oe.tracer->set_object({{0, 0, 0, 1}, {1, 0.7882, 0.1333, 1}, Tracer::transform(vec3(0), vec3(0), vec3(50)), SPHERE});
        oe.update();
    }
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