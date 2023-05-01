
/**  
* @file mainMenu.c  
* @brief Testing Program.  
* @author WAEL 
* @version 1
* @date Apr 28, 2022  
*  
* Testing program *  
*/





#include "utilityFunctions.c"
#define MOUSE_OVER 0

void mainMenuMusic(Game* game) {
  Mix_VolumeMusic(game->bgMusicVolume);
  if(game->musicPlaying == 0) {
    Mix_PlayMusic(game->bgMusic, -1);
    game->musicPlaying = 1;
  }
}

void mainMenu(Game* game) {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN: {
        int key = event.key.keysym.sym;
        handleKeyDownMenu(game, key);
      }
      case SDL_MOUSEMOTION: {
        handleMouseMotion(game);
      }
      break;
      case SDL_MOUSEBUTTONDOWN: {
        handleMouseButtonDown(game);
      }
      case SDL_MOUSEBUTTONUP: 
        handleMouseButtonUp(game);
        break;
    }
  }
}

void renderMainMenuButtons(Game game) {
 for(int i=0; i<3; i++) {
    int currentButtonState = game.mainMenu.buttons[i].state;
    SDL_Surface* currentButton = game.mainMenu.buttons[i].button[currentButtonState];
    SDL_Rect currentBtnPos = game.mainMenu.buttons[i].pos;
    SDL_BlitSurface(currentButton, NULL, game.screen, &currentBtnPos);
  }
}

// void renderText(Game game) {
//   TTF_Font* font = TTF_OpenFont("Fonts/Blakestone.otf", 70);
//   game.font = font;
//   SDL_Color foregroundColor = { 255, 255, 255 };
//   SDL_Color backgroundColor = { 0, 0, 0 };
//   SDL_Surface* textSurface = TTF_RenderText_Shaded(game.font, "Could Be Better", foregroundColor, backgroundColor);
//   SDL_Rect textLocation = { 300,60, 0, 0 };
//   SDL_BlitSurface(textSurface, NULL, game.screen, &textLocation);
// }

void mainMenuRender(Game game) {
  SDL_FillRect(game.screen, NULL, SDL_MapRGB(game.screen->format, 0,0,0));
  startTimer = SDL_AddTimer(100, animateBg, &game);
  SDL_BlitSurface(game.mainMenu.bg[game.mainMenu.currentBg], &game.mainMenu.bgPosition, game.screen, 0);
  renderMainMenuButtons(game);
  SDL_BlitSurface(game.mainMenu.logo.logo, NULL, game.screen, &game.mainMenu.logo.posLogo);
  // renderCursor(&game);
  SDL_Flip(game.screen);
  // renderText(game);
}

