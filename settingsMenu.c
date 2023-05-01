


/**  
* @file settingMenu.c  
* @brief Testing Program.  
* @author WAEL 
* @version 1
* @date Apr 28, 2022  
*  
* Testing program *  
*/





void settingsMenuMusic(Game* game) {
  Mix_VolumeMusic(game->bgMusicVolume);
  if(game->musicPlaying == 0) {
    Mix_PlayMusic(game->bgMusic, -1);
    game->musicPlaying = 1;
  }
}

void settingsMenu(Game* game) {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN: {
        int key = event.key.keysym.sym;
        handleKeyDownSettingsMenu(game, key);
      }
      case SDL_MOUSEMOTION: {
        handleMouseMotionSettingsMenu(game);
      }
      break;
      case SDL_MOUSEBUTTONDOWN: {
        handleMouseButtonDownSettingsMenu(game);
      }
      case SDL_MOUSEBUTTONUP: 
        handleMouseButtonUpSettingsMenu(game);
        break;
    }
  }
}


void settingsMenuRender(Game game) {
  SDL_FillRect(game.screen, 0, SDL_MapRGB(game.screen->format, 0,0,0));
  SDL_BlitSurface(game.settingsMenu.bg, &game.settingsMenu.bgPosition, game.screen, 0);
  int state1 = game.settingsMenu.state1;
  int state2 = game.settingsMenu.state2;
  SDL_BlitSurface(game.settingsMenu.sliders1[state1].slider, 0, game.screen, &game.settingsMenu.sliders1[state1].pos);
  SDL_BlitSurface(game.settingsMenu.sliders2[state2].slider, 0, game.screen, &game.settingsMenu.sliders2[state2].pos);
  for (int i=0; i<4; i++) {
    SDL_BlitSurface(game.settingsMenu.buttons[i].button[0], 0, game.screen, &game.settingsMenu.buttons[i].pos);
  }
  SDL_Flip(game.screen);
}
