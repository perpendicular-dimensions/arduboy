#pragma once

#include "utility.h"
#include "worm.h"

class Level {
public:
  Level(Arduboy2 &arduboy, Tinyfont &tinyfont)
      : arduboy(arduboy), tinyfont(tinyfont), worm(arduboy) {}

  void init(uint8_t level);

  void update();
  void onInput(Direction dir);
  void render();
  uint8_t getCurrentLevel() { return currentLevel; }

private:
  void updateWorm(Cell newHead);

  Arduboy2 &arduboy;
  Tinyfont &tinyfont;
  Worm worm;

  // 8 rows of 16 elements each
  uint16_t rock[8];
  uint16_t soil[8];
  uint16_t food[8];
  uint16_t poop[8];

  Cell goal;
  const char *tutorial;
  uint8_t currentLevel = 0;

  struct {
    bool moving : 1;
    bool falling : 1;
  } is = {
      false, /* the worm is not moving */
      false  /* nothing is falling */
  };
};
