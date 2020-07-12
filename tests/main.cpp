#include <iostream>
//
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
//
#include <glm/gtc/matrix_transform.hpp>
//
#include <glm/gtx/string_cast.hpp>

glm::mat4 camera(float Translate, glm::vec2 const& Rotate) {
  glm::mat4 Projection =
      glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
  glm::mat4 View =
      glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
  View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
  View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
  glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
  return Projection * View * Model;
}

int main() {
  glm::mat4 cam = camera(1.0f, glm::vec2{1.0f, 2.0f});
  std::cout << glm::to_string(cam) << '\n';
}