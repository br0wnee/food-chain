#pragma once

#include "Prey.h"

class SmallerPrey : public Prey {
public:
  SmallerPrey(float x, float y);
  void Multiply(std::vector<std::unique_ptr<Animal>> &animals) override;
};
