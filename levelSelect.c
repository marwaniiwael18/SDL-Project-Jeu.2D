

/**  
* @file levelSelect.c  
* @brief Testing Program.  
* @author WAEL 
* @version 1
* @date Apr 28, 2022  
*  
* Testing program *  
*/





void handleKeyDownLevelSelect(Game* game, int key) {
  switch(key) {
    case SDLK_ESCAPE: 
      game->done = 1;
    case SDLK_m:
      game->currentMenu = MAIN_MENU;
  }
}

void handleMouseMotionLevelSelect(Game* game) {
  int mouseX, mouseY;
  SDL_GetMouseState(&mouseX, &mouseY);
  for(int i=0; i<3; i++) {
    SDL_Rect pos = game->levelSelect.btn[i].pos;
    int mouseInside = checkMouseInside(pos, mouseX, mouseY);
    game->levelSelect.btn[i].state = mouseInside ? MOUSE_HOVER : MOUSE_OUTSIDE;
    if(mouseInside) {
      Mix_VolumeChunk(game->hoverSFX, game->sfxVolume);
      Mix_PlayChannel(-1, game->hoverSFX, 0);
    }
  }
}

void handleMouseButtonDownLevelSelect(Game* game) {
  int mouseX, mouseY;
  SDL_GetMouseState(&mouseX, &mouseY);

  SDL_Rect pos0 = game->levelSelect.btn[0].pos;
  SDL_Rect pos1 = game->levelSelect.btn[1].pos;
  SDL_Rect pos2 = game->levelSelect.btn[2].pos;

  int mouseInside0 = checkMouseInside(pos0, mouseX, mouseY);
  int mouseInside1 = checkMouseInside(pos1, mouseX, mouseY);
  int mouseInside2 = checkMouseInside(pos2, mouseX, mouseY);

  if (mouseInside0) {
    Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
    Mix_PlayChannel(-1, game->clickSFX, 0);
    //game->currentMenu = LEVELONE;
    //SDL_Delay(400);
  }
  if (mouseInside1) {
    Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
    Mix_PlayChannel(-1, game->clickSFX, 0);
    //game->currentMenu = LEVELTWO;
    //SDL_Delay(400);
  }
  if (mouseInside2) {
    Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
    Mix_PlayChannel(-1, game->clickSFX, 0);
    //game->currentMenu = LEVELTHREE;
    //SDL_Delay(400);
  }
}

void levelSelect(Game* game) {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN: {
        int key = event.key.keysym.sym;
        handleKeyDownLevelSelect(game, key);
        break;
      }
      case SDL_MOUSEMOTION: {
        handleMouseMotionLevelSelect(game);
        break;
      }
      case SDL_MOUSEBUTTONDOWN: {
        handleMouseButtonDownLevelSelect(game);
        break;
      }
    }
  }
}

void levelSelectRenderBtns(Game game) {
  for (int i=0; i<3; i++) {
    int state = game.levelSelect.btn[i].state;
    //printf("%d\n",game.levelSelect.btn[i].state);
    SDL_BlitSurface(game.levelSelect.btn[i].button[state], 0, game.screen, &game.levelSelect.btn[i].pos);
  }
}

void levelSelectRender(Game game) {
  SDL_FillRect(game.screen, 0, SDL_MapRGB(game.screen->format, 0,0,0));
  SDL_BlitSurface(game.levelSelect.bg, &game.levelSelect.bgPosition, game.screen, 0);
  levelSelectRenderBtns(game);
  SDL_Flip(game.screen);
}

