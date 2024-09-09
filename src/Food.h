#pragma once

#include "Animal.h"

class Food : public Animal {
public:
  Food(float x, float y);
  bool IsDead() const override;
  void Eat() override;
  void Multiply(std::vector<std::unique_ptr<Animal>> &animals) override;
};
