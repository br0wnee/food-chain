#pragma once

#include "Animal.h"

class Predator : public Animal {
public:
  Predator(float x, float y);
  void Multiply(std::vector<std::unique_ptr<Animal>> &animals) override;
  void Hunt(std::vector<std::unique_ptr<Animal>> &animals);
  void Move(std::vector<std::unique_ptr<Animal>> &animals);
};
