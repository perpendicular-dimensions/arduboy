#include "music.hpp"

/* MIDI score converted in bytes stored in PROGMEM. */
const byte western[] PROGMEM = {
    0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0x50, 0x2f, 0x20, 0x2f, 0x60, 0x2e,
    0x60, 0x4e, 0xa0, 0x2d, 0x60, 0x2d, 0x60, 0x2d, 0x60, 0x50, 0x40, 0x8f,
    0x80, 0x4e, 0xa0, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0x50, 0x2f, 0x20,
    0x2f, 0x60, 0x2e, 0x60, 0x4e, 0xa0, 0x2d, 0x60, 0x2d, 0x60, 0x2d, 0x60,
    0x50, 0x40, 0x8f, 0x80, 0x4e, 0xa0, 0x2d, 0x60, 0x4d, 0x4c, 0x8b, 0x8d,
    0xac, 0x4a, 0xc8, 0x2d, 0x60, 0x4d, 0x4c, 0x8b, 0x8d, 0xac, 0x4a, 0xc8,
    0x07, 0x40, 0x80, 0x47, 0x8b, 0x89, 0xc8, 0xc0, 0x49, 0x80, 0x49, 0x8d,
    0x8b, 0xcc, 0xa0, 0x2d, 0x2e, 0x0f, 0x40, 0x06, 0x20, 0x20, 0x4f, 0x26,
    0x20, 0x4f, 0x26, 0x20, 0x50, 0x2f, 0x20, 0x4f, 0x24, 0x20, 0x4e, 0x24,
    0x20, 0x4e, 0x24, 0x60, 0x24, 0x20, 0x4d, 0x23, 0x20, 0x4d, 0x23, 0x20,
    0x4d, 0x23, 0x20, 0x50, 0x23, 0x20, 0x4f, 0x24, 0x60, 0x24, 0x20, 0x4e,
    0x24, 0x60, 0x24, 0x20, 0x4f, 0x26, 0x20, 0x4f, 0x26, 0x20, 0x4f, 0x26,
    0x20, 0x50, 0x2f, 0x20, 0x4f, 0x24, 0x20, 0x4e, 0x24, 0x20, 0x4e, 0x24,
    0x60, 0x24, 0x20, 0x4d, 0x23, 0x20, 0x4d, 0x23, 0x20, 0x4d, 0x23, 0x20,
    0x50, 0x23, 0x20, 0x4f, 0x24, 0x60, 0x24, 0x20, 0x4e, 0x24, 0x60, 0x24,
    0x20, 0x2d, 0x20, 0x25, 0x20, 0x4d, 0x4c, 0x4b, 0x25, 0x20, 0x4d, 0x25,
    0x20, 0x4c, 0x22, 0x60, 0x4a, 0x48, 0x22, 0x60, 0x22, 0x20, 0x2d, 0x20,
    0x25, 0x20, 0x4d, 0x4c, 0x4b, 0x25, 0x20, 0x4d, 0x25, 0x20, 0x4c, 0x22,
    0x60, 0x4a, 0x48, 0x22, 0x60, 0x22, 0x20, 0x47, 0x21, 0x60, 0x47, 0x4b,
    0x21, 0x20, 0x49, 0x41, 0x48, 0x22, 0x60, 0x22, 0x60, 0x22, 0x60, 0x22,
    0x20, 0x49, 0x23, 0x60, 0x49, 0x4d, 0x23, 0x20, 0x4b, 0x23, 0x20, 0x4c,
    0x24, 0x60, 0x24, 0x60, 0x24, 0x60, 0x2d, 0x2e, 0x0f, 0x20, 0x60, 0x2f,
    0x60, 0x2f, 0x60, 0x50, 0x2f, 0x20, 0x2f, 0x60, 0x2e, 0x60, 0x4e, 0xa0,
    0x4d, 0x23, 0x20, 0x4d, 0x23, 0x20, 0x4d, 0x23, 0x20, 0x50, 0x23, 0x20,
    0x4f, 0x24, 0x60, 0x24, 0x20, 0x4e, 0x24, 0x60, 0x24, 0x20, 0x2f, 0x60,
    0x2f, 0x60, 0x2f, 0x60, 0x50, 0x2f, 0x20, 0x2f, 0x60, 0x2e, 0x60, 0x4e,
    0xa0, 0x4d, 0x23, 0x20, 0x4d, 0x23, 0x20, 0x4d, 0x23, 0x20, 0x50, 0x23,
    0x20, 0x4f, 0x24, 0x60, 0x24, 0x20, 0x4e, 0x24, 0x60, 0x24, 0x20, 0x2d,
    0x20, 0x25, 0x20, 0x4d, 0x4c, 0x4b, 0x25, 0x20, 0x4d, 0x25, 0x20, 0x4c,
    0x22, 0x60, 0x4a, 0x48, 0x22, 0x60, 0x22, 0x20, 0x2d, 0x20, 0x25, 0x20,
    0x4d, 0x4c, 0x4b, 0x25, 0x20, 0x4d, 0x25, 0x20, 0x4c, 0x22, 0x60, 0x4a,
    0x48, 0x22, 0x60, 0x22, 0x20, 0x47, 0x21, 0x60, 0x47, 0x4b, 0x21, 0x20,
    0x49, 0x41, 0x48, 0x22, 0x60, 0x22, 0x60, 0x22, 0x60, 0x22, 0x20, 0x49,
    0x23, 0x60, 0x49, 0x4d, 0x23, 0x20, 0x4b, 0x23, 0x20, 0x4c, 0x24, 0x60,
    0x24, 0x60, 0x24, 0x60, 0x2d, 0x2e, 0x0f, 0x20, 0x60, 0x2f, 0x60, 0x2f,
    0x60, 0x50, 0x2f, 0x20, 0x2f, 0x60, 0x2e, 0x60, 0x4e, 0xa0, 0x2d, 0x60,
    0x2d, 0x60, 0x2d, 0x60, 0x50, 0x40, 0x8f, 0x80, 0x4e, 0xa0, 0x2f, 0x60,
    0x2f, 0x60, 0x2f, 0x60, 0x50, 0x2f, 0x20, 0x2f, 0x60, 0x2e, 0x60, 0x4e,
    0xa0, 0x2d, 0x60, 0x2d, 0x60, 0x2d, 0x60, 0x50, 0x40, 0x8f, 0x80, 0x4e,
    0xa0, 0x4b, 0x4f, 0x4d, 0x4b, 0x4b, 0x4f, 0x4d, 0x4b, 0x48, 0x4e, 0x4d,
    0x4c, 0x48, 0x4c, 0x4b, 0x4a, 0x49, 0x4d, 0x4c, 0x4b, 0x49, 0x4d, 0x4c,
    0x4b, 0x4a, 0x4b, 0x4c, 0x4e, 0x4a, 0x4d, 0x4e, 0x4f, 0x0b, 0x40, 0x0f,
    0x40, 0x4d, 0x4b, 0x4b, 0x4f, 0x4d, 0x4b, 0x48, 0x4e, 0x4d, 0x4c, 0x48,
    0x4c, 0x4b, 0x4a, 0x49, 0x54, 0x53, 0x52, 0x49, 0x54, 0x53, 0x52, 0x4a,
    0x51, 0x52, 0x53, 0x4a, 0x54, 0x55, 0x56, 0x06, 0x40, 0x0e, 0x40, 0x4f,
    0x51, 0x46, 0x4e, 0x4f, 0x51, 0x44, 0x4d, 0x4e, 0x51, 0x44, 0x4d, 0x4e,
    0x51, 0x43, 0x4d, 0x4e, 0x4f, 0x43, 0x50, 0x4f, 0x4e, 0x44, 0x4e, 0x4d,
    0x4c, 0x44, 0x4a, 0x4b, 0x4c, 0x06, 0x40, 0x0e, 0x40, 0x4f, 0x51, 0x46,
    0x4e, 0x4f, 0x51, 0x44, 0x4d, 0x4e, 0x51, 0x44, 0x4d, 0x4e, 0x51, 0x43,
    0x4f, 0x50, 0x52, 0x43, 0x4f, 0x50, 0x52, 0x44, 0x52, 0x53, 0x54, 0x44,
    0x53, 0x51, 0x4e, 0x05, 0x40, 0x0b, 0x40, 0x4c, 0x4d, 0x45, 0x4b, 0x4c,
    0x4d, 0x42, 0x48, 0x4b, 0x4c, 0x42, 0x48, 0x4b, 0x4c, 0x45, 0x4b, 0x4c,
    0x4d, 0x45, 0x4b, 0x4c, 0x4d, 0x42, 0x48, 0x4b, 0x4c, 0x42, 0x48, 0x4b,
    0x4c, 0x01, 0x40, 0x07, 0x40, 0x49, 0x4b, 0x41, 0x47, 0x49, 0x4b, 0x42,
    0x48, 0x4a, 0x4c, 0x42, 0x48, 0x4a, 0x4c, 0x43, 0x49, 0x4b, 0x4d, 0x43,
    0x49, 0x4b, 0x4d, 0x44, 0x4a, 0x4c, 0x4e, 0x44, 0x4e, 0x4f, 0x50, 0};

void Music::init() {
  sound.initChannel(PIN_SPEAKER_1);
  sound.initChannel(PIN_SPEAKER_2);
};

void Music::play() {
  sound.playScore(western);
};
