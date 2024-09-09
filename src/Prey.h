#pragma once

#include "Animal.h"

class Prey : public Animal {
public:
  Prey(float x, float y);
  void Multiply(std::vector<std::unique_ptr<Animal>> &animals) override;
  void FleeAndHunt(std::vector<std::unique_ptr<Animal>> &animals);
  void Move(std::vector<std::unique_ptr<Animal>> &animals);
};
