#pragma once

#include "bitmaps.hpp"
#include "buildings.hpp"
#include "events.hpp"
#include "utility.hpp"

class Level {
 public:
  Level(Arduboy2Base& arduboy, Tinyfont& tinyfont)
      : arduboy(arduboy), tinyfont(tinyfont), drawing(arduboy.sBuffer) {}

  void init();
  bool isInProgress() { return inProgress; };

  void update();
  void onInput(Input dir);
  void render();
  bool gameOver() { return (earnings <= maintenance) && (money < 100); };
  void pause() { inProgress = false; };

 private:
  Arduboy2Base& arduboy;
  Tinyfont& tinyfont;
  Drawing drawing;

  /* For each building we need know if it's enabled and if has been built. */
  Building::Status buildings[(uint8_t)Building::IDs::count] = {};

  /* Camera position and scrolling status. */
  uint16_t camera = 0;
  uint8_t camera_off = 0;
  uint8_t camera_sign = 0;
  uint8_t camera_scrolls = 0;

  /* Number of buildable tiles in the level. Should be a power of two to avoid
   * expensive division operations. */
  static const uint16_t size = 512;

  /* Use bit array to pack more fields in a byte. */
  struct {
    Building::IDs building;
  } tiles[size] = {};

  uint16_t river_in = 0;  /*  X coordinate where the river goes into the lake */
  uint16_t river_out = 0; /* X coordinate where the river leaves the lake */

  uint16_t housing;
  uint16_t jobs;
  uint16_t food;
  uint16_t earnings;
  uint16_t maintenance;
  uint16_t exports;

  uint8_t happiness;
  uint8_t safety;
  uint8_t spirituality;
  uint8_t environment;

  // x coordinates for moving objects
  static const uint8_t npc_count = 16;
  uint16_t flying[npc_count];
  uint16_t walking[npc_count];

  // Currently selected object
  Building::IDs currBuil = Building::IDs::house;

  uint16_t money = 999;
  uint8_t ticks = 0;
  uint8_t lastPressed = 0;

  unsigned long timeLastUpdate = 0;
  unsigned long timeLastEvent = 0;

  EventState tutorials[Events::count] = {
      EventState::untriggered,
  };

  static const uint8_t tutorLen = 128; /* 5% of total RAM! */
  bool tutorVisible = false;
  uint8_t tutorChars = 0;
  char tutor[tutorLen] = {};

  uint16_t population = 0;
  bool inProgress = false;
  bool inStats = false;

  void findFirstAvailableSpot(int8_t dir);
  bool canBuild();
};
