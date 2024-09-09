#include "Animal.h"
#include <cmath>
#include <raylib.h>

Animal::Animal(float x, float y, float r, Color c, float s, int t)
    : position{x, y}, radius(r), color(c), speed(s), foodThreshold(t),
      hunger(0), foodEaten(0), direction{0, 0} {}

void Animal::Move() {
  position = Vector2Add(position, Vector2Scale(direction, speed));

  if (position.x - radius <= 0 || position.x + radius >= GetScreenWidth())
    direction.x *= -1;

  if (position.y - radius <= 0 || position.y + radius >= GetScreenHeight())
    direction.y *= -1;

  IncreaseHunger();
}

void Animal::Draw() const { DrawCircleV(position, radius, color); }

bool Animal::CheckCollision(const std::unique_ptr<Animal> &other) const {
  return CheckCollisionCircles(position, radius, other->position,
                               other->radius);
}

void Animal::Eat() {
  hunger = 0;
  foodEaten++;
}

void Animal::IncreaseHunger() { hunger++; }

bool Animal::IsDead() const { return hunger > 500; }

float Animal::GetRadius() const { return radius; }

Vector2 Animal::GetPosition() const { return position; }

void Animal::NormalizeDirection() { direction = Vector2Normalize(direction); }
