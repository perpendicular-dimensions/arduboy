#pragma once

#include <stdint.h>
#include "utility.hpp"

/* Types of ground. */
enum class Grounds : uint8_t { empty, ground, river, bridge };

/* Types of objects that walk around the level. */
enum class Walkers : uint8_t { man, bird };

/* Type of building that can be constructed by the player. */
class Building {
 public:
  enum class IDs : uint8_t {
    empty,
    house,
    water,
    saloon,
    farm,
    mill,
    mine,
    church,
    sheriff,
    bank,
    weed,
    cactus,
    tree,
    count
  };

  /* Copies the building's name from PROGMEM to the destination string. */
  static void strncpyName(char dest[8], const uint8_t id);
  static void strncpyName(char dest[8], Building::IDs id) {
    return strncpyName(dest, (uint8_t)id);
  };
  /* How many jobs the building offer. */
  static const uint8_t jobs(const uint8_t id);
  static const uint8_t jobs(Building::IDs id) { return jobs((uint8_t)id); };
  /* How much does it cost to construct the building. */
  static const uint8_t cost(const uint8_t id);
  static const uint8_t cost(Building::IDs id) { return cost((uint8_t)id); };
  /* Width in tiles (8px). */
  static const uint8_t width(const uint8_t id);
  static const uint8_t width(Building::IDs id) { return width((uint8_t)id); };
  /* Height in tiles (8px). */
  static const uint8_t height(const uint8_t id);
  static const uint8_t height(Building::IDs id) { return height((uint8_t)id); };
  /* Cost to maintain the building in $/sec. */
  static const uint8_t maintenance(const uint8_t id);
  static const uint8_t maintenance(Building::IDs id) {
    return maintenance((uint8_t)id);
  };
  /* Money generated by the building at full capacity. */
  static const uint8_t profit(const uint8_t id);
  static const uint8_t profit(Building::IDs id) { return profit((uint8_t)id); };
  /* Pointer to the bitmap. */
  static const uint8_t* bitmap(const uint8_t id);
  static const uint8_t* bitmap(Building::IDs id) {
    return bitmap((uint8_t)id);
  };

  static const uint8_t count() { return (uint8_t)Building::IDs::count; }

 private:
  /* Private empty constructor. */
  Building() {}
};
