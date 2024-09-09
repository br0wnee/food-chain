#include "Animal.h"
#include "Food.h"
#include "Predator.h"
#include "Prey.h"
#include "SmallerPrey.h"
#include <ctime>
#include <memory>
#include <raylib.h>
#include <vector>

const int screenWidth = 800;
const int screenHeight = 600;
const int targetFPS = 60;

struct InitialAnimals {
  const int amountPredators = 1;
  const int amountPreys = 10;
  const int amountSmallerPreys = 5;
  const int amountInitialFood = 20;
};

void spawnInitialAnimals(InitialAnimals ia,
                         std::vector<std::unique_ptr<Animal>> &a) {

  for (int i = 0; i < ia.amountPreys; i++) {
    a.push_back(std::make_unique<Prey>(GetRandomValue(0, screenWidth),
                                       GetRandomValue(0, screenHeight)));
  }

  for (int i = 0; i < ia.amountPredators; ++i) {
    a.push_back(std::make_unique<Predator>(GetRandomValue(0, screenWidth),
                                           GetRandomValue(0, screenHeight)));
  }

  for (int i = 0; i < ia.amountInitialFood; i++) {
    a.push_back(std::make_unique<Food>(GetRandomValue(0, screenWidth),
                                       GetRandomValue(0, screenHeight)));
  }

  for (int i = 0; i < ia.amountSmallerPreys; i++) {
    a.push_back(std::make_unique<SmallerPrey>(GetRandomValue(0, screenWidth),
                                              GetRandomValue(0, screenHeight)));
  }
};

void removeDeadAnimals(std::vector<std::unique_ptr<Animal>> &a) {

  for (auto it = a.begin(); it != a.end();) {
    if ((*it)->IsDead()) {
      a.erase(it);
    } else {
      ++it;
    }
  }
}

void updateAnimals(std::vector<std::unique_ptr<Animal>> &a) {

  for (auto &animal : a) {
    if (auto predator = dynamic_cast<Predator *>(animal.get()))
      predator->Move(a);
    else if (auto prey = dynamic_cast<Prey *>(animal.get()))
      prey->Move(a);
    else if (auto smallerPrey = dynamic_cast<SmallerPrey *>(animal.get()))
      smallerPrey->Move(a);
  }
}

void drawAnimals(std::vector<std::unique_ptr<Animal>> &a) {
  for (auto &animal : a) {
    animal->Draw();
  }
}

int spawnFood(int &frameCounter, int spawnInterval,
              std::vector<std::unique_ptr<Animal>> &a) {

  if (frameCounter >= spawnInterval) {
    a.push_back(std::make_unique<Food>(GetRandomValue(0, screenWidth),
                                       GetRandomValue(0, screenHeight)));
    frameCounter = 0;
    return frameCounter;
  }

  return frameCounter;
}

int main() {

  InitWindow(screenWidth, screenHeight, "Simple Food Chain Simulation");
  SetTargetFPS(targetFPS);
  const InitialAnimals ia;
  std::vector<std::unique_ptr<Animal>> animals;
  int frameCounter = 0;
  const int spawnInterval = static_cast<int>(4.0f * targetFPS);

  srand(static_cast<unsigned>(time(0)));
  spawnInitialAnimals(ia, animals);

  while (!WindowShouldClose()) {
    updateAnimals(animals);
    frameCounter = spawnFood(frameCounter, spawnInterval, animals);
    removeDeadAnimals(animals);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawFPS(10, 10);
    drawAnimals(animals);
    frameCounter++;
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
