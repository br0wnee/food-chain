#pragma once

#include <memory>
#include <raylib.h>
#include <raymath.h>
#include <vector>

class Animal {
protected:
  Vector2 position;
  Vector2 direction;
  float radius;
  Color color;
  int hunger;
  float speed;
  int foodThreshold;
  int foodEaten;

public:
  Animal(float x, float y, float r, Color c, float s, int t);
  virtual ~Animal() = default;

  float GetRadius() const;
  Vector2 GetPosition() const;

  virtual void Draw() const;
  virtual bool IsDead() const;

protected:
  void NormalizeDirection();
  bool CheckCollision(const std::unique_ptr<Animal> &other) const;
  virtual void Eat();
  void IncreaseHunger();
  virtual void Multiply(std::vector<std::unique_ptr<Animal>> &animals) = 0;
  virtual void Move();
};
