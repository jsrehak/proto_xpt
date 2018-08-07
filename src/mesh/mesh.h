#ifndef PROTO_XPT_MESH_MESH_H_
#define PROTO_XPT_MESH_MESH_H_

#include <stdexcept>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "node.h"

namespace xpt {

namespace mesh {

class Mesh {
 public:
  //Cartesian Mesh

  explicit Mesh() {};
  explicit Mesh(float x_min, float x_max, float y_min, float y_max) :
      x_min_(x_min), x_max_(x_max), y_min_(y_min), y_max_(y_max) {};
  ~Mesh() = default;
  
  // Nodes
  const std::unordered_map<int, std::unique_ptr<Node>> &nodes() const { return nodes_; };
  void AddNode(int index, std::unique_ptr<Node> node);
  
  // Mesh Parameters
  float x_min() const {return x_min_;};
  float x_max() const {return x_max_;};
  float y_min() const {return y_min_;};
  float y_max() const {return y_max_;};
  Mesh &set_x_min(float x_min) { x_min_ = x_min; return *this;};
  Mesh &set_x_max(float x_max) { x_max_ = x_max; return *this;};
  Mesh &set_y_min(float y_min) { y_min_ = y_min; return *this;};
  Mesh &set_y_max(float y_max) { y_max_ = y_max; return *this;};

 
 private:
  std::unordered_map<int, std::unique_ptr<Node>> nodes_;
  float x_min_ = 0;
  float x_max_ = 0;
  float y_min_ = 0;
  float y_max_ = 0;
};

//std::unique_ptr<Mesh> ImportMeshFromStream(std::istream &input_stream);
//std::string to_string(const Mesh &mesh);

} //namespace mesh

} //namespace xpt

#endif
