#include "Game.h"
#include <iostream>


void Game::MouseMotion()  //called for mouse motion in the event loop of screens having buttons
{
    GameScreen -> mouseMotionEvents(x,y);
    MenuScreen -> mouseMotionEvents(x,y);
    PauseScreen -> mouseMotionEvents(x,y);
    QuitScreen -> mouseMotionEvents(x,y);
    OverScreen -> mouseMotionEvents(x,y);
    WinScreen -> mouseMotionEvents(x,y);
    ControlScreen -> mouseMotionEvents(x,y);
    ResumeScreen -> mouseMotionEvents(x,y);
}

void Game::MouseClick()  //if a screen is running then only it's buttons will respond to the mouse click
{
    if (GameScreenRunning)
        GameScreen -> mouseClickEvents(x,y,ButtonClickMusic);
    if (MenuScreenRunning)
        MenuScreen -> mouseClickEvents(x,y,ButtonClickMusic);
    if (PauseScreenRunning)
        PauseScreen -> mouseClickEvents(x,y,ButtonClickMusic);
    if (QuitScreenRunning)
        QuitScreen -> mouseClickEvents(x,y,ButtonClickMusic);
    if (GameOverScreenRunning)
        OverScreen -> mouseClickEvents(x,y,ButtonClickMusic);
    if (GameWinScreenRunning)
        WinScreen -> mouseClickEvents(x,y,ButtonClickMusic);
    if (ControlScreenRuning)
        ControlScreen -> mouseClickEvents(x,y,ButtonClickMusic);
    if (ResumeScreenRunning)
        ResumeScreen -> mouseClickEvents(x,y,ButtonClickMusic);
    Clicked = false;
}

void Game::Menu_Screen_1(long int& frame, long int& frame1)  //flow control of menu screen buttons
{
    Button* buttons = NULL;      //will hold button(s) on the screen
    if (MenuScreenRunning)
    {
        buttons = MenuScreen->getButtons();
        for (int i = 0; i < MenuScreen->getButtonCount(); i++)  //iterating on the buttons of the screen
        {
            if (buttons[i].getText() == " NEW GAME " && buttons[i].clicked())  //if new game is clicked
            {
                init_Game();     //initializes the game
                frame1 = frame;
                MenuScreenRunning = false;
                TransitionScreenRunning = true;
                break;
            }
            else if (buttons[i].getText() == "LOAD GAME" && buttons[i].clicked()) //if load game is clicked
            {
                LoadGame();
                MenuScreenRunning = false;
                GameScreenRunning = true;
                break;
            }
            else if (buttons[i].getText() == " CONTROLS " && buttons[i].clicked())  //if control button is pressed
            {
                ControlScreenRuning = true;
                MenuScreenRunning = false;
                break;
            }
            else if (buttons[i].getText() == "   EXIT   "  && buttons[i].clicked())
            {
                EndGame = true;
                break;
            }
        }
    }

}

void Game::Control_Screen_1(long int& frame, long int& frame1)
{
    Button* buttons = NULL;   //will hold button(s) on the screen
    if (ControlScreenRuning)
    {
        buttons = ControlScreen->getButtons();
        for (int i = 0; i < ControlScreen->getButtonCount(); i++)
        {
            if(buttons[i].getText() == "EXIT" && buttons[i].clicked())
            {
                GameMenuMusicRuniing = true;
                MenuScreenRunning = true;
                ControlScreenRuning = false;
                break;
            }
        }
    }
}

void Game::Game_Screen_1(long int& frame, long int& frame1)
{
    Button* buttons = NULL;
    if (GameScreenRunning)
    {
        buttons = GameScreen->getButtons();
        if(buttons[0].clicked())
        {
            PauseScreenRunning = true;
            GameScreenRunning =  false;
        }
    }
}

void Game::Pause_Screen_1(long int& frame, long int& frame1)
{
    Button* buttons = NULL;   //will hold button(s) on the screen
    if (PauseScreenRunning)
    {
        buttons = PauseScreen->getButtons();
        for(int i = 0; i < PauseScreen->getButtonCount(); i++)   //loop going through each button index
        {
            if(buttons[i].getText() == " RESUME " && buttons[i].clicked())
            {
                PauseScreenRunning = false;
                GameScreenRunning = true;
                break;
            }
            else if (buttons[i].getText() == "RESTART" && buttons[i].clicked())
            {
                game_Destroy();
                init_Game();
                PauseScreenRunning = false;
                GameScreenRunning = true;
                GameMusicRuning = true;
                break;
            }
            else if (buttons[i].getText() == "  QUIT  " && buttons[i].clicked())
            {
                PauseScreenRunning = false;
                QuitScreenRunning = true;

            }
        }
    }
}

void Game::Quit_Screen_1(long int& frame, long int& frame1)
{
    Button* buttons = NULL;
    if (QuitScreenRunning)
    {
        buttons = QuitScreen->getButtons();
        for(int i = 0; i < QuitScreen->getButtonCount(); i++)   //loop going through each button index
        {
            if(buttons[i].getText() == " YES " && buttons[i].clicked())
            {
                SaveGame();
                game_Destroy();
                QuitScreenRunning = false;
                MenuScreenRunning = true;
                GameMenuMusicRuniing = true;
            }
            else if (buttons[i].getText() == "  NO  " && buttons[i].clicked())
            {
                QuitScreenRunning = false;
                GameScreenRunning = false;
                ResumeScreenRunning = true;
                break;
            }
            else if (buttons[i].getText() == "CANCEL" && buttons[i].clicked())
            {
                QuitScreenRunning = false;
                GameScreenRunning = true;
                break;
            }
        }
    }
}

void Game::Resume_Screen_1(long int& frame, long int& frame1)
{
    Button* buttons = NULL;
    if (ResumeScreenRunning)
    {
        buttons = ResumeScreen -> getButtons();
        for (int i = 0; i < ResumeScreen->getButtonCount(); i++)
        {
            if ((buttons[i].getText() == "RESUME GAME") && (buttons[i].clicked()))
            {
                GameScreenRunning = true;
                ResumeScreenRunning = false;
                break;
            }
            else if ((buttons[i].getText() == " EXIT GAME ") && (buttons[i].clicked()))
            {
                game_Destroy();
                PauseScreenRunning = false;
                QuitScreenRunning = false;
                ResumeScreenRunning = false;
                MenuScreenRunning = true;
                GameMenuMusicRuniing = true;
                break;
            }
        }
    }
}

void Game::GameOver_Screen_1(long int& frame, long int& frame1)
{
    Button* buttons = NULL;
    if (GameOverScreenRunning)
    {
        game_Destroy();
        buttons = OverScreen -> getButtons();
        for(int i=0; i < OverScreen->getButtonCount(); i++)   //loop going through each button index
        {
            if(buttons[i].getText() == "MAIN MENU" && buttons[i].clicked())
            {
                GameOverScreenRunning = false;
                MenuScreenRunning = true;
                GameMenuMusicRuniing = true;
                break;
            }
            else if (buttons[i].getText() == "PLAY AGAIN" && buttons[i].clicked())
            {
                init_Game();
                GameOverScreenRunning = false;
                GameScreenRunning = true;
                GameMusicRuning = true;
                break;
            }
            else if (buttons[i].getText() == "  EXIT  " && buttons[i].clicked())
            {
                GameOverScreenRunning = false;
                MenuScreenRunning = true;
                GameMenuMusicRuniing = true;
                break;
            }
        }
    }
}

void Game::GameWin_Screen_1(long int& frame, long int& frame1)
{
    Button* buttons = NULL;
    if (GameWinScreenRunning)
    {
        game_Destroy();
        buttons = WinScreen->getButtons();
        for(int i=0; i < WinScreen->getButtonCount(); i++)   //loop going through each button index
        {
            if(buttons[i].getText() == "MAIN MENU" && buttons[i].clicked())
            {
                GameWinScreenRunning = false;
                MenuScreenRunning = true;
                GameMenuMusicRuniing = true;
                break;
            }
            else if (buttons[i].getText() == "PLAY AGAIN" && buttons[i].clicked())
            {
                init_Game();
                GameWinScreenRunning = false;
                GameScreenRunning = true;
                GameMusicRuning = true;
                break;
            }
            else if (buttons[i].getText() == "  EXIT  " && buttons[i].clicked())
            {
                GameWinScreenRunning = false;
                EndGame = true;
                break;
            }
        }
    }
}
void Game::control_Screens_One(long int& frame, long int& frame1)   //this function is called in the poll events loop
{
    Menu_Screen_1(frame, frame1);      //all screen functions regarding buttons and their control flow
    Control_Screen_1(frame, frame1);
    Game_Screen_1(frame, frame1);
    Pause_Screen_1(frame, frame1);
    Quit_Screen_1(frame, frame1);
    Resume_Screen_1(frame, frame1);
    GameOver_Screen_1(frame, frame1);
    GameWin_Screen_1(frame, frame1);
}

void Game::Menu_Screen_2(long int& frame, long int& frame1, SDL_Renderer* gRenderer)  //rendering menu screen
{
    if ((MenuScreenRunning) && (!ControlScreenRuning))     //checks if Main Menu Screen is running
    {
        if (GameMenuMusicRuniing)     //if menu music is true then play the music and then turn it false
        {
            Mix_PlayMusic(GameMenuMusic,0);
            GameMenuMusicRuniing = false;
        }
        MenuScreen -> Render(frame, frame1, gRenderer);    //render main menu
    }
}

void Game::Intro_Screen(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (IntroductionScreenRunning)
    {
        IntroductionScreen->Render(frame, frame1, gRenderer);   //Rendering Splash Screen

        if (frame - frame1 == 100)
        {
            IntroductionScreenRunning = false;               //indicates the end of splash screen run
            MenuScreenRunning = true;
            GameMenuMusicRuniing = true;
            frame = frame - 100;
            frame1 = frame;
        }
    }
}

void Game::Story_Screen(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (StoryScreenRunning)
    {
        if (StoryMusicRuning)
        {
            Mix_HaltMusic();
            Mix_PlayMusic(StoryMusic,0);
            StoryMusicRuning = false;
        }
        StorScreen->Render(frame, frame1, gRenderer);
        if (frame - frame1 == 2500)    //frame delay of story screens to render 5 backgrounds with different texts
        {
            StoryScreenRunning = false;
            GameScreenRunning = true;
            GameMusicRuning = true;
            frame = frame - 2500;
            frame1 = frame;
        }
    }
}

void Game::Transit_Screen(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (TransitionScreenRunning)
    {
        TransitScreen->Render(frame, frame1, gRenderer);
        if (frame - frame1 == 750)  //frame delay of transit screen to render 6 backgrounds with LOAING text
        {
            TransitionScreenRunning = false;
            StoryScreenRunning = true;
            StoryMusicRuning = true;
            frame = frame - 750;
            frame1 = frame;
        }
    }
}

void Game::GameWin_Screen_2(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (GameWinScreenRunning)
    {
        if (GameWinMusicRuning)
        {
            Mix_HaltMusic();
            Mix_PlayChannel(-1,GameWinMusic,0);
            GameWinMusicRuning = false;
        }
        WinScreen -> Render(frame, frame1, gRenderer);
    }
}

void Game::Control_Screen_2(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (ControlScreenRuning)
        ControlScreen -> Render(frame, frame1, gRenderer);
}

void Game::Resume_Screen_2(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (ResumeScreenRunning)
        ResumeScreen->Render(frame, frame1, gRenderer);
}

void Game::Game_Screen_2(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (GameScreenRunning)
    {
        if (GameMusicRuning)  //if game music is running start the music, turn the flag false
        {
            Mix_HaltMusic();   //stops all music and chunks and plays game music
            Mix_HaltChannel(0);
            Mix_PlayMusic(GameMusic,0);
            GameMusicRuning = false;
        }
        if (!PauseScreenRunning && !QuitScreenRunning)
            game_Render(frame, frame1, gRenderer);        //render game on the game screen
    }
}

void Game::Pause_Screen_2(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (PauseScreenRunning)
    {
        Mix_HaltMusic();
        PauseScreen->Render(frame, frame1, gRenderer);
    }
}

void Game::Quit_Screen_2(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (QuitScreenRunning)
    {
        QuitScreen->Render(frame, frame1, gRenderer);
    }
}

void Game::GameOver_Screen_2(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (GameOverScreenRunning)
    {
        if (GameOverMusicRuniing)
        {
            Mix_HaltMusic();
            Mix_PlayChannel(-1,GameOverMusic,0);
            GameOverMusicRuniing = false;
        }
        OverScreen->Render(frame, frame1, gRenderer);
    }
}

void Game::control_Screens_Two(long int& frame, long int& frame1, SDL_Renderer* gRenderer) //called after poll event to render screen
{
    Intro_Screen(frame, frame1, gRenderer);  //functions to render screen continuously, called before render present
    Menu_Screen_2(frame, frame1, gRenderer);
    Transit_Screen(frame, frame1, gRenderer);
    Story_Screen(frame, frame1, gRenderer);
    Control_Screen_2(frame, frame1, gRenderer);
    Resume_Screen_2(frame, frame1, gRenderer);
    Game_Screen_2(frame, frame1, gRenderer);
    Pause_Screen_2(frame, frame1, gRenderer);
    Quit_Screen_2(frame, frame1, gRenderer);
    GameOver_Screen_2(frame, frame1, gRenderer);
    GameWin_Screen_2(frame, frame1, gRenderer);
}

void Game::Run(SDL_Renderer* gRenderer)     //this is poll event loop which calls the screens and game
{
    long int frame = 0;
    long int frame1 = 0;

    SDL_Event e;
    while( !EndGame )
    {
        while( SDL_PollEvent( &e ) != 0 )  //main poll events loop
        {
            SDL_GetMouseState(&x,&y);
            if( e.type == SDL_QUIT )
                EndGame = true;

            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                Clicked = true;

            if (e.type == SDL_MOUSEMOTION) //to handle all mouse motion events for all screens
                MouseMotion();

            if(e.type == SDL_MOUSEBUTTONUP && Clicked) //tp handle all mouse click events for all screens
                MouseClick();

            control_Screens_One(frame, frame1);
        }

        SDL_SetRenderDrawColor( gRenderer,  0, 0, 0, 0 );
        SDL_RenderClear( gRenderer );

        control_Screens_Two(frame, frame1, gRenderer);

        SDL_RenderPresent( gRenderer );
        frame++;
    }
}



Game::Game(Ltexture& FontTexture, Ltexture& IntroductionScreenTexture, Ltexture& GameMenuScreenTexture,
          Ltexture& ResumeScreenTexture, Ltexture& GameOverScreenTexture, Ltexture& GameWinScreenTexture,
          Ltexture& QuitGameScreenTexture, Ltexture& SmallScreenTexture,Ltexture& MenuPictureOneTexture,
          Ltexture& MenuPictureTwoTexture,Ltexture& MenuPictureThreeTexture, Ltexture& ButtonTexture,
          Ltexture& ControlScreenTexture, Ltexture& gSpriteSheetTexture, Ltexture& CollisionRectangle,
          Ltexture&  startBackground, Ltexture& transitBackground, Ltexture& bossBackground, Ltexture& bossSprite,
          Ltexture& StatusbarTexture2,Ltexture& SmallScreenTexture1, Ltexture& LoadImage1,
          Ltexture& LoadImage2, Ltexture& LoadImage3, Ltexture& BumpImage1 , Ltexture& BumpImage2, Ltexture& BumpImage3,
          Ltexture& BumpImage4, Ltexture& BumpImage5, Mix_Music* GameMusic, Mix_Chunk* ButtonClickMusic,
          Mix_Music* StoryMusic, Mix_Music* GameMenuMusic, Mix_Chunk* GameOverMusic, Mix_Chunk* GameWinMusic)
{
    this -> ResumeScreen =  new ResumeGameScreen(&ResumeScreenTexture,&FontTexture, &ButtonTexture);  //allocate 11 screens
    this -> IntroductionScreen = new IntroScreen(&IntroductionScreenTexture,&FontTexture);
    this -> MenuScreen = new GameMenuScreen(&GameMenuScreenTexture,&ButtonTexture,&FontTexture,&SmallScreenTexture,
                               &MenuPictureOneTexture, &MenuPictureTwoTexture, &MenuPictureThreeTexture);
    this -> ControlScreen = new ControlsScreen(&ControlScreenTexture,&ButtonTexture,&FontTexture);
    this -> GameScreen = new GamePlayScreen(&ButtonTexture,&FontTexture,&StatusbarTexture2);
    this -> OverScreen = new GameOverScreen(&GameOverScreenTexture,&ButtonTexture,&FontTexture);
    this -> WinScreen = new GameWinScreen(&GameWinScreenTexture,&ButtonTexture,&FontTexture);
    this -> PauseScreen = new PauseGameScreen(&SmallScreenTexture1, &ButtonTexture,&FontTexture);
    this -> QuitScreen = new QuitGameScreen(&QuitGameScreenTexture,&ButtonTexture,&FontTexture);
    this -> TransitScreen = new TransitionScreen(&LoadImage1, &LoadImage2, &LoadImage3, &FontTexture);
    this -> StorScreen = new StoryScreen(&BumpImage1, &BumpImage2, &BumpImage3, &BumpImage4, &BumpImage5, &FontTexture);

    this -> GameMenuMusic = GameMenuMusic;  //assign music
    this -> GameMusic = GameMusic;
    this -> GameOverMusic = GameOverMusic;
    this -> ButtonClickMusic = ButtonClickMusic;
    this -> StoryMusic = StoryMusic;
    this -> GameWinMusic = GameWinMusic;

    this -> gSpriteSheetTexture = gSpriteSheetTexture;  //assign game play sprites
    this -> CollisionRectangle = CollisionRectangle;
    this -> startBackground = startBackground;
    this -> transitBackground = transitBackground;
    this -> bossBackground = bossBackground;
    this -> bossSprite = bossSprite;
}


void Game::SaveGame()
{
    aliveUnits = objectList->returnAliveUnits();    //writes all the alive units in the file to save them
    std::ofstream file;
    file.open("GameData.csv");
    file << "Pehelwan Liberal Goth : Cleanup" << "\n";

    if (boss == false)                       //saving game states
        file << "False" << "\n";
    else
        file << "True" << "\n";
    if (transit == false)
        file << "False" << "\n";
    else
        file << "True" << "\n";
    if (fin == false)
        file << "False" << "\n";
    else
        file << "True" << "\n";

    file << "Player" << "\n";                      //writes player position, health, and score
    file << score << "\n";
    file << plane->GetX() << "\n";
    file << plane->GetY() << "\n";
    file << plane->getLives() << "\n";
    for (int i = 0; i < objectList->getLength(); i++) //writing all units
    {
        file << aliveUnits[i]->getName() << "\n";
        file << aliveUnits[i]->GetX() << "\n";
        file << aliveUnits[i]->GetY() << "\n";
        file << aliveUnits[i]->getLives() << "\n";
    }
    file.close();
}

void Game::LoadGame()
{
    plane = Player::get_instance(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
    objectList = new Queue;

    ifstream file ("GameData.csv");   //reading all units and then loading them into queue to render it on screen
    string line;
    getline(file, line);
    getline(file, line);
    if (line == "False")          //loading game state flags
        boss = false;
    else
        boss = true;
    getline(file, line);
    if (line == "False")
        transit = false;
    else
        transit = true;
    getline(file, line);
    if (line == "False")
        fin = false;
    else
        fin = true;

    while (!file.eof())
    {
        getline(file, line);
        if (line == "Player")
        {
            getline(file, line);
            score = stoi(line);    //setting saved score
            getline(file, line);
            plane->SetX(stof(line));
            getline(file, line);
            plane->SetY(stof(line));
            getline(file, line);
            plane->setLives(stoi(line));
        }
        else if (line == "Enemy")
        {
            enemy = enemies.GetEnemies(&gSpriteSheetTexture, 0, 0, 0, 0.0f, NULL); //making enemy
            getline(file, line);
            enemy->SetX(stof(line));
            getline(file, line);
            enemy->SetY(stof(line));
            getline(file, line);
            enemy->setLives(stoi(line));
            objectList->Enqueue(enemy);
        }
        else if (line == "Boss")
        {
            enemy = enemies.GetEnemies(&bossSprite, 0, 0, 1, 0.0f, plane);
            getline(file, line);
            enemy->SetX(stof(line));
            getline(file, line);
            enemy->SetY(stof(line));
            getline(file, line);
            enemy->setLives(stoi(line));
            objectList->Enqueue(enemy);
        }
        else if (line == "Bullet")
        {
            bullet = new Bullet(&gSpriteSheetTexture, 0, 0, 1);
            getline(file, line);
            bullet->SetX(stof(line));
            getline(file, line);
            bullet->SetY(stof(line));
            getline(file, line);
            bullet->setLives(stoi(line));
            objectList->Enqueue(bullet);
        }
    }
    file.close();
}

void Game::move_Player(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );   //this controls the movement of player and collisions

    if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
    {
        if (plane->GetAlive() == true)
        {
            plane->Move(RIGHT);
            objectList->Collision(&CollisionRectangle, plane, score, gRenderer, 1);
        }
    }

    if(currentKeyStates[ SDL_SCANCODE_LEFT ])
    {
        if (plane->GetAlive() == true)
        {
            plane->Move(LEFT);
            objectList->Collision(&CollisionRectangle, plane, score, gRenderer, 1);
        }
    }

    if(currentKeyStates[ SDL_SCANCODE_UP ])
    {
        if (plane->GetAlive() == true)
        {
            plane->Move(UP);
            objectList->Collision(&CollisionRectangle, plane, score, gRenderer, 1);
        }
    }

    if(currentKeyStates[ SDL_SCANCODE_DOWN ])
    {
        if (plane->GetAlive() == true)
        {
            plane->Move(DOWN);
            objectList->Collision(&CollisionRectangle, plane, score, gRenderer, 1); //collision detection of plane
        }
    }

    if(currentKeyStates[ SDL_SCANCODE_SPACE ])
    {
        if (plane->GetAlive() == true)
        {
            if(bulletDelay > 20)  //fires after every 20 frames
            {
                bullet = new Bullet(&gSpriteSheetTexture,plane->GetX(), plane->GetY() - plane->GetHeight()/2, 0);
                objectList->Enqueue(bullet);
                bulletDelay = 0;
                objectList->Collision(&CollisionRectangle, bullet, score, gRenderer, 0); //collision detection of bullet
            }
        }
    }
}

void Game::final_Battle(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    if (plane->GetAlive() == true)
    {
        if (((frame - frame1) % 30)==0)
        {
            for (int i = 0; i < 4; i++)   //for four bullets from boss enemy
            {
                bullet = new Bullet(&gSpriteSheetTexture, enemy->GetX() + i*50, enemy->GetY() + enemy->GetHeight()/2, 2);
                objectList->Enqueue(bullet);
            }
        }
        objectList->Move();
        objectList->Render(frame, gRenderer);
        objectList->Collision(&CollisionRectangle, plane, score, gRenderer, 1);  //collision detection of plane

        if (enemy->GetAlive() == false)
        {
            GameWinScreenRunning = true;
            GameWinMusicRuning = true;
            GameScreenRunning = false;
        }
    }
}


void Game::game_Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    objectList->Clean();  //deleting all the dead objects
    int random = 0;
    if ((frame % 30 == 0) && (!boss))  //make regular enemies
    {
        random = rand() % SCREEN_WIDTH;
        enemy = enemies.GetEnemies(&gSpriteSheetTexture,random, -100,0,0.0f,NULL);
        objectList->Enqueue(enemy);
        bullet = new Bullet(&gSpriteSheetTexture,enemy->GetX(), enemy->GetY() + enemy->GetHeight()/2, 1);
        objectList->Enqueue(bullet);
    }

    if ((score >= 1000 ) && (boss) && (!fin))  //making a boss if score exceeds 1000
    {
        random = rand() % SCREEN_WIDTH;
        enemy = enemies.GetEnemies(&bossSprite,random, -100,1,0.0f,plane);
        objectList->Enqueue(enemy);
        frame1 = frame;
        fin = true;
    }

    if ((boss == false) && (transit == false))  //to render game background
    {
        startBackground.RenderTexture(0 , 0, gRenderer, NULL);
        if (score >= 1000)
        {
            transit = true;
            frame1 = frame;
        }
    }

    move_Player(frame, frame1, gRenderer);  //player movement controls

    if ((score >= 1000) && (transit))      //to render transition between regular enemies and boss
    {
        transitBackground.RenderTexture(0 , 0, gRenderer, NULL);
        if ((frame - frame1) > 100)
        {
            boss = true;
            transit = false;
        }
    }
    if (boss)
        bossBackground.RenderTexture(0 , 0, gRenderer, NULL);

    if ((!transit) && (!fin))    //if final battle and transition screen is not there, then render regular enemies, bullets
    {
        objectList->Render(frame, gRenderer);
        objectList->Move();
    }

    if ((boss) && (fin))   //if the final battle between boss and player is going on
        final_Battle(frame, frame1, gRenderer);


    if (plane->GetAlive() == true)
    {
        plane->Render(frame, gRenderer);
        plane->Move();
    }
    else if (plane->GetAlive() == false)
    {
        GameOverScreenRunning = true;
        GameOverMusicRuniing = true;
        GameScreenRunning = false;
    }
    bulletDelay ++;
    display_Status(frame, frame1, gRenderer);
}

void Game::display_Status(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    GameScreen->setLives(plane->getLives());  //displays player health and score
    GameScreen->setScore(score);
    GameScreen->Render(frame, frame1, gRenderer);
}


Game::~Game()
{
    delete IntroductionScreen;  //deallocating all the screen pointers of game class
    IntroductionScreen = NULL;
    delete MenuScreen;
    MenuScreen = NULL;
    delete ResumeScreen;
    ResumeScreen = NULL;
    delete ControlScreen;
    ControlScreen = NULL;
    delete GameScreen;
    GameScreen = NULL;
    delete OverScreen;
    OverScreen = NULL;
    delete WinScreen;
    WinScreen = NULL;
    delete PauseScreen;
    PauseScreen = NULL;
    delete QuitScreen;
    QuitScreen = NULL;
    delete TransitScreen;
    TransitScreen = NULL;
    delete StorScreen;
    StorScreen = NULL;
}

void Game::game_Destroy()  //destroys the game, player, and delete alive units
{
    Player::destroy_Instance();
    if (aliveUnits != NULL)   //delete alive units
        delete[] aliveUnits;
    aliveUnits = NULL;
    enemy = NULL;
    bullet = NULL;     //making sure the pointer don't point towards deleted objects
}

void Game::init_Game()
{
    plane = Player::get_instance(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);  //gets player
    objectList = new Queue;  //initializes the queue
    boss = false;           //to track when boss arrives
    transit = false;        //to track background changing
    fin = false;            //to track the final battle between player and boss
    score = 0;              //score is set to 0 again
    aliveUnits = NULL;
    enemy = NULL;
    bullet = NULL;          //making sure the pointer don't point towards deleted objects
}


