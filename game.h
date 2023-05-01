void initializeSDL() {
  SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER );
  atexit(SDL_Quit);
  SDL_WM_SetCaption("Game", NULL);
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 0);
  TTF_Init();
}



void initializeMainMenu(Game* game) {
  
  game->bgMusic = Mix_LoadMUS("Audio/BgMusic/bgMusic.mp3");
  game->musicPlaying = 0;
  game->bgMusicVolume = 128;
  game->sfxVolume = 128;
  game->hoverSFX = Mix_LoadWAV("Audio/ButtonsSound/soundButton.wav");
  game->clickSFX = Mix_LoadWAV("Audio/ButtonsSound/soundButtonClicked.wav");
  
  MainMenu mainMenu = game->mainMenu;

  char bgpath[30]="Images/Bg/background";
  for(int k=0; k<4; k++) {
      char path[30];
      sprintf(path, "%s%i.png", bgpath, k+1);
      mainMenu.bg[k] = IMG_Load(path);
    }

  mainMenu.bgPosition.x = 0;
  mainMenu.bgPosition.y = 0;
  mainMenu.bgPosition.h = game->screen->h;
  mainMenu.bgPosition.w = game->screen->w;

  mainMenu.currentBg = 0;

  char PLAY_BTN_PATH[100]     = "Images/Buttons/PlayB";
  char SETTINGS_BTN_PATH[100] = "Images/Buttons/SettingsB";
  char QUIT_BTN_PATH[100]     = "Images/Buttons/QuitB";
  char* paths[3] = { PLAY_BTN_PATH, SETTINGS_BTN_PATH, QUIT_BTN_PATH };
    int padding = 30;

  for(int i=0; 3>i; i++) {
    mainMenu.buttons[i].state = MOUSE_OUTSIDE;
    for(int k=0; 3>k; k++) {
      char path[100];
      sprintf(path, "%s%i.png", paths[i], k+1);
      mainMenu.buttons[i].button[k] = IMG_Load(path);
    }

    
  }

  SDL_Surface* btn = mainMenu.buttons[PLAY_BTN].button[0]; 
  SDL_Rect pos = { 420, 340, btn->w, btn->h};
  mainMenu.buttons[0].pos = pos;
  for(int i=1; 3>i; i++) {
    SDL_Surface* currentBtn = mainMenu.buttons[i].button[0];
    SDL_Rect posPreviousBtn = mainMenu.buttons[i-1].pos;
    SDL_Rect currentBtnPos = { 
      posPreviousBtn.x,
      posPreviousBtn.y + posPreviousBtn.h,
      currentBtn->w,
      currentBtn->h
    }; 
    mainMenu.buttons[i].pos = currentBtnPos;
  }

  mainMenu.logo.logo = IMG_Load ("Images/Titles/Logo.png");

  mainMenu.logo.posLogo.x = 230;
  mainMenu.logo.posLogo.y = 135;
  mainMenu.logo.posLogo.w = mainMenu.logo.logo->w;
  mainMenu.logo.posLogo.h = mainMenu.logo.logo->h;

  game->mainMenu = mainMenu;
}

void initializeSettingsMenu(Game* game) {
  SettingsMenu settingsMenu = game->settingsMenu;
  settingsMenu.bg = IMG_Load("Images/Bg/backgroundSettings.png");
  settingsMenu.bgPosition.x = 0;
  settingsMenu.bgPosition.y = 0;
  settingsMenu.bgPosition.h = settingsMenu.bg->h;
  settingsMenu.bgPosition.w = settingsMenu.bg->w;

  char Slider[100] = "Images/Slider/slider";

  for(int k=0; k<5; k++) {
    char path[100];
    sprintf(path, "%s%i.png", Slider, k+1);
    settingsMenu.sliders1[k].slider = IMG_Load(path);
  }
  for(int k=0; k<5; k++) {
    settingsMenu.sliders1[k].pos.x = 340;
    settingsMenu.sliders1[k].pos.y = 10;
    settingsMenu.sliders1[k].pos.h = settingsMenu.sliders1[k].slider->h;
    settingsMenu.sliders1[k].pos.w = settingsMenu.sliders1[k].slider->w;
  }


  for(int k=0; k<5; k++) {
    char path[100];
    sprintf(path, "%s%i.png", Slider, k+1);
    settingsMenu.sliders2[k].slider = IMG_Load(path);
  }
  for(int k=0; k<5; k++) {
    settingsMenu.sliders2[k].pos.x = 340;
    settingsMenu.sliders2[k].pos.y = 190;
    settingsMenu.sliders2[k].pos.h = settingsMenu.sliders2[k].slider->h;
    settingsMenu.sliders2[k].pos.w = settingsMenu.sliders2[k].slider->w;
  }

  settingsMenu.state1 = settingsMenu.state2 = 4;

  settingsMenu.buttons[0].button[0] = IMG_Load("Images/Buttons/plusbtn.png");


  settingsMenu.buttons[0].pos.x = 930;
  settingsMenu.buttons[0].pos.y = 170;
  settingsMenu.buttons[0].pos.h = settingsMenu.buttons[0].button[0]->h;
  settingsMenu.buttons[0].pos.w = settingsMenu.buttons[0].button[0]->w;

  settingsMenu.buttons[1].button[0] = IMG_Load("Images/Buttons/minusbtn.png");

  settingsMenu.buttons[1].pos.x = 290;
  settingsMenu.buttons[1].pos.y = 170;
  settingsMenu.buttons[1].pos.h = settingsMenu.buttons[1].button[0]->h;
  settingsMenu.buttons[1].pos.w = settingsMenu.buttons[1].button[0]->w;

  settingsMenu.buttons[2].button[0] = IMG_Load("Images/Buttons/plusbtn.png");


  settingsMenu.buttons[2].pos.x = 930;
  settingsMenu.buttons[2].pos.y = 370;
  settingsMenu.buttons[2].pos.h = settingsMenu.buttons[2].button[0]->h;
  settingsMenu.buttons[2].pos.w = settingsMenu.buttons[2].button[0]->w;

  settingsMenu.buttons[3].button[0] = IMG_Load("Images/Buttons/minusbtn.png");

  settingsMenu.buttons[3].pos.x = 290;
  settingsMenu.buttons[3].pos.y = 370;
  settingsMenu.buttons[3].pos.h = settingsMenu.buttons[2].button[0]->h;
  settingsMenu.buttons[3].pos.w = settingsMenu.buttons[2].button[0]->w;

  

  game->settingsMenu = settingsMenu;
}

void initializeLevelOne(Game* game) {
  LevelSelect levelSelect = game->levelSelect;

  levelSelect.bg = IMG_Load("Images/Bg/Level Select.png");
  levelSelect.bgPosition.x = 0;
  levelSelect.bgPosition.y = 0;
  levelSelect.bgPosition.h = levelSelect.bg->h;
  levelSelect.bgPosition.w = levelSelect.bg->w;

  char btn[30] = "Images/Buttons/";

  for(int k=0; k<3; k++) {
      char path[30];
      levelSelect.btn[k].state = 0;
      sprintf(path, "%s%i.png", btn, k+1);
      levelSelect.btn[k].button[0] = IMG_Load(path);
    }

  char btn1[30] = "Images/Buttons/";

  for (int k=0; k<3; k++) {
    char path[30];
    sprintf(path, "%s%i.png", btn1, k+4);
    levelSelect.btn[k].button[1] = IMG_Load(path);
  }
  
  levelSelect.btn[0].pos.x = 228;
  levelSelect.btn[0].pos.y = 138;
  levelSelect.btn[0].pos.w = levelSelect.btn[0].button[0]->w;
  levelSelect.btn[0].pos.h = levelSelect.btn[0].button[0]->h;

  levelSelect.btn[1].pos.x = 538;
  levelSelect.btn[1].pos.y = 272;
  levelSelect.btn[1].pos.w = levelSelect.btn[1].button[0]->w;
  levelSelect.btn[1].pos.h = levelSelect.btn[1].button[0]->h;

  levelSelect.btn[2].pos.x = 805;
  levelSelect.btn[2].pos.y = 416;
  levelSelect.btn[2].pos.w = levelSelect.btn[2].button[0]->w;
  levelSelect.btn[2].pos.h = levelSelect.btn[2].button[0]->h;

  game->levelSelect = levelSelect;
}

Game initializeGame() {
  Game game;
  game.done = 0;
  game.currentMenu = MAIN_MENU;
  game.screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  // game.cursor.cursor = IMG_Load ("Images/cursor.png");
  initializeMainMenu(&game);
  initializeSettingsMenu(&game);
  initializeLevelOne(&game);
  return game;
}


Game gameInit() {
  initializeSDL();
  Game game = initializeGame();
  return game;
}