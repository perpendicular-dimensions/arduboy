#pragma once

#include <avr/pgmspace.h>
#include <stdint.h>
#include "utility.hpp"

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
    stable,
    weed,
    cactus,
    tree,
    count
  };

  struct Status {
    bool enabled : 1;
    bool built : 1;
  };

  /* Convenience functions for reading from PROGMEM */
  const __FlashStringHelper* name() const;
  const uint8_t jobs() const;
  const uint8_t cost() const;
  const uint8_t width() const;
  const uint8_t height() const;
  const uint8_t maintenance() const;
  const uint8_t profit() const;
  const uint8_t* bitmap() const;

  /* Copies the building's name from PROGMEM to the destination string. */
  static const __FlashStringHelper* name(const uint8_t id);
  static const __FlashStringHelper* name(IDs id) { return name(static_cast<uint8_t>(id)); };
  /* How many jobs the building offer. */
  static const uint8_t jobs(const uint8_t id);
  static const uint8_t jobs(IDs id) { return jobs(static_cast<uint8_t>(id)); };
  /* How much does it cost to construct the building. */
  static const uint8_t cost(const uint8_t id);
  static const uint8_t cost(IDs id) { return cost(static_cast<uint8_t>(id)); };
  /* Width in tiles (8px). */
  static const uint8_t width(const uint8_t id);
  static const uint8_t width(IDs id) { return width(static_cast<uint8_t>(id)); };
  /* Height in tiles (8px). */
  static const uint8_t height(const uint8_t id);
  static const uint8_t height(IDs id) { return height(static_cast<uint8_t>(id)); };
  /* Cost to maintain the building in $/sec. */
  static const uint8_t maintenance(const uint8_t id);
  static const uint8_t maintenance(IDs id) { return maintenance(static_cast<uint8_t>(id)); };
  /* Money generated by the building at full capacity. */
  static const uint8_t profit(const uint8_t id);
  static const uint8_t profit(IDs id) { return profit(static_cast<uint8_t>(id)); };
  /* Pointer to the bitmap. */
  static const uint8_t* bitmap(const uint8_t id);
  static const uint8_t* bitmap(IDs id) { return bitmap(static_cast<uint8_t>(id)); };

  static const uint8_t count() { return static_cast<uint8_t>(IDs::count); }

  const char _name[8];
  const uint8_t* const _bitmap;
  const uint8_t _jobs;
  const uint8_t _cost;
  const uint8_t _width;
  const uint8_t _height;
  const uint8_t _maintenance;
  const uint8_t _profit;
};
