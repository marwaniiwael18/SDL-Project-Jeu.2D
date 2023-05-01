


/**  
* @file main.c  
* @brief Testing Program.  
* @author WAEL 
* @version 1
* @date Apr 28, 2022  
*  
* Testing program *  
*/










#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "types.h"
#include "game.h"
#include "mainMenu.c"
#include "settingsMenu.c"
#include "levelSelect.c"





void main() {
  Game game = gameInit();
  
  while(!game.done) {
    if(game.currentMenu == MAIN_MENU) {
      mainMenuMusic(&game);
      mainMenu(&game);
      mainMenuRender(game);
    } else if(game.currentMenu == SETTINGS_MENU) {
      settingsMenuMusic(&game);
      settingsMenu(&game);
      settingsMenuRender(game);
    } else if(game.currentMenu == LEVELSELECT) {
      levelSelect(&game);
      levelSelectRender(game);
    }
  }
  SDL_RemoveTimer(startTimer);
  SDL_Quit();
}