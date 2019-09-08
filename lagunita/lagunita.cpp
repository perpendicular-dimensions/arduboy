#include "lagunita.hpp"

void Lagunita::init() {
  // initiate arduboy instance
  arduboy.begin();

  // set the framerate to 32 FPS
  arduboy.setFrameRate(32);

  // start the music
  arduboy.audio.begin();
}

void Lagunita::loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame())) {
    return;
  }
  // update the scene
  update();
  // render the scene
  render();
}

void Lagunita::update() {
  arduboy.pollButtons();

  // keep the music in a loop
  if (!music.isPlaying()) {
    music.play();
  }

  switch (currentMenu) {
    case Menus::main:
      if (arduboy.justPressed(UP_BUTTON)) {
        switch (currentMainSelection) {
          case MainSelections::play:
            currentMainSelection = MainSelections::audio;
            break;
          case MainSelections::credits:
            currentMainSelection = MainSelections::play;
            break;
          case MainSelections::help:
            currentMainSelection = MainSelections::credits;
            break;
          case MainSelections::audio:
            currentMainSelection = MainSelections::help;
            break;
        }
      }
      if (arduboy.justPressed(DOWN_BUTTON)) {
        switch (currentMainSelection) {
          case MainSelections::play:
            currentMainSelection = MainSelections::credits;
            break;
          case MainSelections::credits:
            currentMainSelection = MainSelections::help;
            break;
          case MainSelections::help:
            currentMainSelection = MainSelections::audio;
            break;
          case MainSelections::audio:
            currentMainSelection = MainSelections::play;
            break;
        }
      }
      if (arduboy.justPressed(A_BUTTON)) {
        switch (currentMainSelection) {
          case MainSelections::play:
            if (!level.isInProgress()) {
              level.init();
            }
            currentMenu = Menus::game;
            break;
          case MainSelections::credits:
            currentMenu = Menus::credits;
            break;
          case MainSelections::help:
            currentMenu = Menus::help;
            break;
          case MainSelections::audio:
            arduboy.audio.toggle();
            break;
        }
      }

      break;
    case Menus::game:
      level.update();
      if (level.gameOver()) {
        currentMenu = Menus::lost;
        level.pause();
        break;
      }
      if (arduboy.justPressed(UP_BUTTON)) {
        level.onInput(Input::up);
      }
      if (arduboy.justPressed(DOWN_BUTTON)) {
        level.onInput(Input::down);
      }
      if (arduboy.justPressed(A_BUTTON)) {
        level.onInput(Input::a);
      }
      if (arduboy.justPressed(B_BUTTON)) {
        level.onInput(Input::b);
      }
      break;
    case Menus::credits:
      if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) {
        currentMenu = Menus::main;
      }
      break;
    case Menus::help:
      if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) {
        currentMenu = Menus::main;
      }
      if (arduboy.justPressed(RIGHT_BUTTON)) {
        help_page++;
      }
      if (arduboy.justPressed(LEFT_BUTTON)) {
        help_page--;
      }
      break;
    case Menus::lost:
      if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) {
        currentMenu = Menus::main;
      }
      break;
  }
}

void Lagunita::render() {
  // clear the whole screen to black
  arduboy.clear();

  // render the menus
  switch (currentMenu) {
    case Menus::main: {
      static uint8_t frame = 0;
      frame++;
      const uint8_t bl_y = 24;
      const uint8_t bl_x = 2;
      arduboy.drawBitmap((128 - 105) / 2, 4 * 8, bmp_lagunita, 105, 16);
      arduboy.drawBitmap(0, 5 * 8, bmp_cactus, 8, 8);
      arduboy.drawBitmap(128 - 8, 5 * 8, bmp_weed, 8, 8);
      drawing.waterReflection(frame / 2);
      tinyfont.setCursor(bl_x + 10, bl_y - 6 * 3);
      if (level.isInProgress()) {
        tinyfont.print(F("RESUME"));
      } else {
        tinyfont.print(F("PLAY"));
      }
      tinyfont.setCursor(bl_x + 10, bl_y - 6 * 2);
      tinyfont.print(F("CREDITS"));
      tinyfont.setCursor(bl_x + 10, bl_y - 6 * 1);
      tinyfont.print(F("HELP"));
      tinyfont.setCursor(bl_x + 10, bl_y - 6 * 0);
      if (arduboy.audio.enabled()) {
        tinyfont.print(F("AUDIO: ON"));
      } else {
        tinyfont.print(F("AUDIO: OFF"));
      }
      switch (currentMainSelection) {
        case MainSelections::play:
          arduboy.drawBitmap(bl_x, bl_y - 2 - 6 * 3, bmp_bullet, 8, 8);
          break;
        case MainSelections::credits:
          arduboy.drawBitmap(bl_x, bl_y - 2 - 6 * 2, bmp_bullet, 8, 8);
          break;
        case MainSelections::help:
          arduboy.drawBitmap(bl_x, bl_y - 2 - 6 * 1, bmp_bullet, 8, 8);
          break;
        case MainSelections::audio:
          arduboy.drawBitmap(bl_x, bl_y - 2 - 6 * 0, bmp_bullet, 8, 8);
          break;
      }
      break;
    }
    case Menus::game:
      level.render();
      break;
    case Menus::lost:
      tinyfont.setCursor(2, 0);
      tinyfont.print(F(                              /**/
                       "                         \n" /**/
                       "      UNFORTUNATELY      \n" /**/
                       "      YOU RUN OUT        \n" /**/
                       "      OF MONEY.          \n" /**/
                       "                         \n" /**/
                       "      REMEMBER TO        \n" /**/
                       "      CHECK THE          \n" /**/
                       "      STATISTICS         \n" /**/
                       "      WHILE PLAYING      \n" /**/
                       "                         \n" /**/
                       "      TRY AGAIN!         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       ));
      break;
    case Menus::credits:
      tinyfont.setCursor(2, 0);
      tinyfont.print(F(                              /**/
                       "                         \n" /**/
                       "LAGUNITA WAS CREATED BY  \n" /**/
                       "    RENATO GROTTESI      \n" /**/
                       "                         \n" /**/
                       "PROGRAMMING              \n" /**/
                       "    RENATO GROTTESI      \n" /**/
                       "    GUUS SLIEPEN         \n" /**/
                       "                         \n" /**/
                       "MUSIC BY                 \n" /**/
                       "    JOAKIM SIMONSSON     \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       ));
      break;
    case Menus::help:
      tinyfont.setCursor(2, 0);
      switch (help_page) {
        case 0:
          tinyfont.print(F(                              /**/
                           "BUILD A WILD WEST TOWN   \n" /**/
                           "ON THE SHORE OF LAKE     \n" /**/
                           "LAGUNITA WITH AS MANY    \n" /**/
                           "CITIZENS AS POSSIBLE.    \n" /**/
                           "                         \n" /**/
                           "INCREASE YOUR PROFIT TO  \n" /**/
                           "KEEP UNLOCKING NEW AND   \n" /**/
                           "EXCITING BUILDINGS.      \n" /**/
                           "                         \n" /**/
                           "PRESS THE RIGHT ARROW    \n" /**/
                           "FOR MORE INSTRUCTIONS    \n" /**/
                           "OR B TO GO BACK.         \n" /**/
                           "                         \n" /**/
                           ));
          break;
        case 1:
          tinyfont.print(F(                              /**/
                           "YOU CAN MOVE AROUND THE  \n" /**/
                           "LEVEL WITH THE LEFT AND  \n" /**/
                           "RIGHT ARROWS. LONG PRESS \n" /**/
                           "FOR FAST SCROLLING.      \n" /**/
                           "DOUBLE CLICK TO MOVE TO  \n" /**/
                           "NEXT AVAILABLE SPOT TO   \n" /**/
                           "BUILD THE CURRENTLY      \n" /**/
                           "SELECTED BUILDING.       \n" /**/
                           "PRESS BOTH TO RECENTER.  \n" /**/
                           "                         \n" /**/
                           "PRESS THE RIGHT ARROW    \n" /**/
                           "FOR MORE INSTRUCTIONS.   \n" /**/
                           "                         \n" /**/
                           ));
          break;
        case 2:
          tinyfont.print(F(                              /**/
                           "PRESS THE UP AND DOWN    \n" /**/
                           "ARROWS TO CHANGE THE     \n" /**/
                           "CURRENTLY SELECTED ACTION\n" /**/
                           "OR BUILDING.             \n" /**/
                           "                         \n" /**/
                           "PRESS A TO DO THE ACTION \n" /**/
                           "OR BUILD THE BUILDING.   \n" /**/
                           "                         \n" /**/
                           "PRESS B TO CHECK THE     \n" /**/
                           "STATISTICS.              \n" /**/
                           "                         \n" /**/
                           "PRESS B TO GO BACK.      \n" /**/
                           "                         \n" /**/
                           ));
          break;
        default:
          help_page = 0;
          currentMenu = Menus::main;
      }
      break;
  }

  // tell the arduboy to swap buffers
  arduboy.display();
}
