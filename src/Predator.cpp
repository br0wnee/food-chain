#include "Predator.h"
#include "Food.h"
#include <algorithm>
#include <cfloat>

Predator::Predator(float x, float y) : Animal(x, y, 15.0f, RED, 1.0f, 5) {}

void Predator::Multiply(std::vector<std::unique_ptr<Animal>> &animals) {
  float newX = GetPosition().x + static_cast<float>(GetRandomValue(1, 20));
  float newY = GetPosition().y + static_cast<float>(GetRandomValue(1, 20));

  newX = fmin(newX, static_cast<float>(GetScreenWidth()));
  newY = fmin(newY, static_cast<float>(GetScreenHeight()));

  animals.push_back(std::make_unique<Predator>(newX, newY));
  foodEaten = 0;
}

void Predator::Hunt(std::vector<std::unique_ptr<Animal>> &animals) {
  Animal *target = nullptr;
  float closestDistance = FLT_MAX;

  for (const auto &animal : animals) {
    if (animal.get() != this && animal->GetRadius() < radius &&
        !dynamic_cast<Food *>(animal.get())) {
      float distance = Vector2Distance(position, animal->GetPosition());
      if (distance < closestDistance) {
        closestDistance = distance;
        target = animal.get();
      }
    }
  }

  if (target != nullptr && closestDistance < 200.0f) {
    Vector2 huntDirection = Vector2Subtract(target->GetPosition(), position);
    direction = Vector2Add(direction, huntDirection);
    NormalizeDirection();
  }

  for (auto it = animals.begin(); it != animals.end();) {
    if (it->get() != this && (*it)->GetRadius() < radius &&
        CheckCollision(*it) && !dynamic_cast<Food *>(it->get())) {
      Eat();
      it = animals.erase(it);
    } else {
      ++it;
    }
  }
}

void Predator::Move(std::vector<std::unique_ptr<Animal>> &animals) {
  Hunt(animals);
  Animal::Move();
}
