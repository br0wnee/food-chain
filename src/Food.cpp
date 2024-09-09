#include "Food.h"
#include "Animal.h"
#include <memory>
#include <vector>

Food::Food(float x, float y) : Animal(x, y, 5.0f, BLUE, 0.0f, 0) {}

bool Food::IsDead() const { return false; }

void Food::Eat() {}

void Food::Multiply(std::vector<std::unique_ptr<Animal>> &animals) {}
