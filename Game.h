#pragma once
#include "SDL.h"
#include "SDL_Image.h"
#include "SDL_Mixer.h"
#include "Alphabet.h"
#include "Text.h"
#include "Button.h"
#include "GameMenuScreen.h"
#include "GamePlayScreen.h"
#include "PauseGameScreen.h"
#include "QuitGameScreen.h"
#include "GameOverScreen.h"
#include "ControlsScreen.h"
#include "ResumeGameScreen.h"
#include "GameWinScreen.h"
#include <time.h>
#include "IntroScreen.h"
#include "StoryScreen.h"
#include "TransitionScreen.h"
#include "Ltexture.h"
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <tuple>
#include <cmath>
#include "Screen.h"
#include "Queue.h"
#include "Unit.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "EnemyFactory.h"
#include "Boss.h"
#include <iostream>
#include "string"

class Game
{
private:
    int x,y;                //mouse position co-ordinates
    int score = 0;          //game score
    int SCREEN_WIDTH = 1024;
    int SCREEN_HEIGHT = 700;
    int bulletDelay = 0;    //bullet delay incremented every frame
    Queue* objectList;       //queue that has enemy, boss enemy and bullets
    Unit* plane = NULL;     //game object pointer
    Unit* enemy = NULL;
    Unit* bullet = NULL;
    EnemyFactory enemies;    //enemy factory that returns regular enemies and boss enemies
    bool boss = false;       //to track when boss arrives
    bool transit = false;    //to track background changing
    bool fin = false;        //to track the final battle between player and boss
    Unit** aliveUnits = NULL;//used for load game when alive units are rendered after read from the csv file

    Ltexture gSpriteSheetTexture; //game play textures
    Ltexture CollisionRectangle;
    Ltexture startBackground;
    Ltexture transitBackground;
    Ltexture bossBackground;
    Ltexture bossSprite;

    bool MenuScreenRunning = false;  //bool variables to keep track of if a screen is running
    bool GameScreenRunning = false;
    bool PauseScreenRunning = false;
    bool QuitScreenRunning = false;
    bool GameOverScreenRunning = false;
    bool GameWinMusicRuning = false;
    bool GameOverMusicRuniing = false;
    bool GameMusicRuning = false;
    bool StoryMusicRuning = false;
    bool GameMenuMusicRuniing = false;
    bool IntroductionScreenRunning = true;  //introduction screen is true in the beginning
    bool ControlScreenRuning = false;
    bool ResumeScreenRunning = false;
    bool GameWinScreenRunning = false;
    bool TransitionScreenRunning = false;
    bool StoryScreenRunning = false;

    bool Clicked = false;  //if mouse was clicked
    bool EndGame = false;  //if game end is true

    Screen* IntroductionScreen = NULL;   //screen abstract pointer to store 11 screen objects
    Screen* MenuScreen = NULL;
    Screen* ResumeScreen = NULL;
    Screen* ControlScreen = NULL;
    Screen* GameScreen = NULL;
    Screen* OverScreen = NULL;
    Screen* WinScreen = NULL;
    Screen* PauseScreen = NULL;
    Screen* QuitScreen = NULL;
    Screen* TransitScreen = NULL;
    Screen* StorScreen = NULL;


    Mix_Music* GameMusic = NULL;         //music pointer to store music and chunks
    Mix_Chunk* ButtonClickMusic = NULL;
    Mix_Music* StoryMusic = NULL;
    Mix_Music* GameMenuMusic = NULL;
    Mix_Chunk* GameOverMusic = NULL;
    Mix_Chunk* GameWinMusic = NULL;


public:
    void Run(SDL_Renderer*);            //runs all the events
    Game(Ltexture& , Ltexture& , Ltexture&,  Ltexture& , Ltexture& , Ltexture& ,Ltexture& , Ltexture& ,Ltexture& ,
         Ltexture& , Ltexture& ,Ltexture& , Ltexture& , Ltexture& ,Ltexture& , Ltexture& , Ltexture& , Ltexture& ,
         Ltexture& , Ltexture&, Ltexture& , Ltexture& , Ltexture& , Ltexture& , Ltexture& , Ltexture& , Ltexture& ,
         Ltexture& , Ltexture& , Mix_Music* , Mix_Chunk* , Mix_Music* , Mix_Music* , Mix_Chunk*, Mix_Chunk*);
    virtual ~Game();

    void SaveGame();  //saves the alive units in a csv file
    void LoadGame();  //loads the alive units from a csv file
    void move_Player(long int&, long int&, SDL_Renderer*);  //controls movement of player
    void final_Battle(long int&, long int&, SDL_Renderer*);  //final battle between the boss and the player
    void display_Status(long int&, long int&, SDL_Renderer*); //displays player health and score
    void game_Render(long int&,long int&, SDL_Renderer*); //renders the game
    void game_Destroy();  //destroys the game
    void init_Game();     //initializes game play settings
    void control_Screens_One(long int&, long int&); //control for buttons screens
    void control_Screens_Two(long int&, long int&, SDL_Renderer*);  //control for rendering screens
    void MouseClick();                            //mouse click events for each screen
    void MouseMotion();                           //mouse motion events for each screen

    void Menu_Screen_1(long int&, long int&);     //functions related to screen buttons and their controls
    void Control_Screen_1(long int&, long int&);
    void Game_Screen_1(long int&, long int&);
    void Pause_Screen_1(long int&, long int&);
    void Quit_Screen_1(long int&, long int&);
    void Resume_Screen_1(long int&, long int&);
    void GameOver_Screen_1(long int&, long int&);
    void GameWin_Screen_1(long int&, long int&);

    void Menu_Screen_2(long int&, long int&, SDL_Renderer*);  //function related to screen textures and their rendering
    void Control_Screen_2(long int&, long int&, SDL_Renderer*);
    void Game_Screen_2(long int&, long int&, SDL_Renderer*);
    void Pause_Screen_2(long int&, long int&, SDL_Renderer*);
    void Quit_Screen_2(long int&, long int&, SDL_Renderer*);
    void Resume_Screen_2(long int&, long int&, SDL_Renderer*);
    void GameOver_Screen_2(long int&, long int&, SDL_Renderer*);
    void GameWin_Screen_2(long int&, long int&, SDL_Renderer*);
    void Transit_Screen(long int&, long int&, SDL_Renderer*);
    void Story_Screen(long int&, long int&, SDL_Renderer*);
    void Intro_Screen(long int&, long int&, SDL_Renderer*);
};

