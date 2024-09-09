#include "SmallerPrey.h"

SmallerPrey::SmallerPrey(float x, float y) : Prey(x, y) {
  radius = 8.0f;
  color = RED;
  speed = 3.0f;
}

void SmallerPrey::Multiply(std::vector<std::unique_ptr<Animal>> &animals) {
  float newX = GetPosition().x + static_cast<float>(GetRandomValue(1, 20));
  float newY = GetPosition().y + static_cast<float>(GetRandomValue(1, 20));

  newX = fmin(newX, static_cast<float>(GetScreenWidth()));
  newY = fmin(newY, static_cast<float>(GetScreenHeight()));

  animals.push_back(std::make_unique<SmallerPrey>(newX, newY));
  foodEaten = 0;
}
