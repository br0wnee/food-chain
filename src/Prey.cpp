#include "Prey.h"
#include "Food.h"
#include "Predator.h"

Prey::Prey(float x, float y) : Animal(x, y, 10.0f, GREEN, 2.0f, 2) {}

void Prey::Multiply(std::vector<std::unique_ptr<Animal>> &animals) {
  float newX = GetPosition().x + static_cast<float>(GetRandomValue(1, 20));
  float newY = GetPosition().y + static_cast<float>(GetRandomValue(1, 20));

  newX = fmin(newX, static_cast<float>(GetScreenWidth()));
  newY = fmin(newY, static_cast<float>(GetScreenHeight()));

  animals.push_back(std::make_unique<Prey>(newX, newY));
  foodEaten = 0;
}

void Prey::FleeAndHunt(std::vector<std::unique_ptr<Animal>> &animals) {
  for (const auto &animal : animals) {
    if (Predator *predator = dynamic_cast<Predator *>(animal.get())) {
      float distance = Vector2Distance(position, predator->GetPosition());
      if (distance < 100.0f) {
        Vector2 fleeDirection =
            Vector2Subtract(position, predator->GetPosition());
        direction = Vector2Add(direction, fleeDirection);
        NormalizeDirection();
      }
    } else if (Food *food = dynamic_cast<Food *>(animal.get())) {
      float distance = Vector2Distance(position, food->GetPosition());
      if (distance < 300.0f) {
        Vector2 huntDirection = Vector2Subtract(food->GetPosition(), position);
        direction = Vector2Add(direction, huntDirection);
        NormalizeDirection();
      }
    }
  }
}

void Prey::Move(std::vector<std::unique_ptr<Animal>> &animals) {
  FleeAndHunt(animals);
  Animal::Move();

  for (auto it = animals.begin(); it != animals.end();) {
    if (dynamic_cast<Food *>(it->get()) && CheckCollision(*it)) {
      Eat();
      if (foodEaten >= foodThreshold) {
        Multiply(animals);
      }
      it = animals.erase(it);
    } else {
      ++it;
    }
  }
}
