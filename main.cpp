#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Game.h"
#include <time.h>

using namespace std;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

const int SCREEN_WIDTH =  1024;
const int SCREEN_HEIGHT = 700;

//declaring textures for 11 screens
Ltexture FontTexture, IntroductionScreenTexture, GameMenuScreenTexture, GameOverScreenTexture;
Ltexture GameWinScreenTexture, QuitGameScreenTexture, SmallScreenTexture, SmallScreenTexture1;
Ltexture MenuPictureOneTexture, MenuPictureTwoTexture, MenuPictureThreeTexture, ButtonTexture;
Ltexture ControlScreenTexture, ResumeScreenTexture, StatusbarTexture2, LoadImage1;
Ltexture LoadImage2, LoadImage3, BumpImage1, BumpImage2, BumpImage3, BumpImage4, BumpImage5;

// declaring textures for game play
Ltexture gSpriteSheetTexture, CollisionRectangle, startBackground, transitBackground, bossBackground, bossSprite;

// declaring music for screen and game play
Mix_Music* GameMusic = NULL;
Mix_Chunk* ButtonClickMusic = NULL;
Mix_Music* StoryMusic = NULL;
Mix_Music* GameMenuMusic = NULL;
Mix_Chunk* GameOverMusic = NULL;
Mix_Chunk* GameWinMusic = NULL;

int main(int argv, char** args)
{
    //Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
		    srand (time(NULL));     //initialize time seeding
            Game* game = new Game(FontTexture, IntroductionScreenTexture,GameMenuScreenTexture, ResumeScreenTexture,
                                  GameOverScreenTexture, GameWinScreenTexture, QuitGameScreenTexture, SmallScreenTexture,
                                  MenuPictureOneTexture, MenuPictureTwoTexture, MenuPictureThreeTexture, ButtonTexture,
                                  ControlScreenTexture, gSpriteSheetTexture, CollisionRectangle, startBackground,
                                  transitBackground, bossBackground, bossSprite, StatusbarTexture2, SmallScreenTexture1,
                                  LoadImage1, LoadImage2, LoadImage3, BumpImage1, BumpImage2, BumpImage3, BumpImage4, BumpImage5,
                                  GameMusic, ButtonClickMusic, StoryMusic, GameMenuMusic, GameOverMusic, GameWinMusic);
            game -> Run(gRenderer);  //runs the poll event

            delete game;
		}
	}
	close();
    return 0;
}

bool init()
{
	///Initialization flag
	bool success = true;

	///Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		///Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		///Create window
		gWindow = SDL_CreateWindow( "Pehelwan Liberal Goth : Cleanup", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}

		else
		{
			///Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				///Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
                //Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
			}
		}
	}
	return success;
}

bool loadMedia()
{
	bool success = true; ///Loading success flag
	if ( !FontTexture.LoadFromFile( "Images/XiroidFinal2.png", gRenderer) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	if ( !ButtonTexture.LoadFromFile( "Images/XiroidFinal22.png", gRenderer) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	if ( !GameMenuScreenTexture.LoadFromFile( "Images/MenuScreen.jpg", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

    if ( !GameOverScreenTexture.LoadFromFile( "Images/OVER.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}


    if ( !GameWinScreenTexture.LoadFromFile( "Images/WIN.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}


    if (!QuitGameScreenTexture.LoadFromFile( "Images/QuitScreen.jpg", gRenderer))
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

    if (!SmallScreenTexture.LoadFromFile( "Images/PauseScreen.png", gRenderer ))
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

    if (!SmallScreenTexture1.LoadFromFile( "Images/PauseScreen1.jpg", gRenderer ))
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

    if (!MenuPictureOneTexture.LoadFromFile( "Images/menupicture1.png", gRenderer))
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

    if (!MenuPictureTwoTexture.LoadFromFile("Images/menupicture2.png", gRenderer))
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

    if (!MenuPictureThreeTexture.LoadFromFile( "Images/menupicture3.png", gRenderer))
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}


    if (!IntroductionScreenTexture.LoadFromFile( "Images/Intro.PNG", gRenderer))
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

    if (!ControlScreenTexture.LoadFromFile( "Images/Control_Screen.jpg", gRenderer))
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

    if (!ResumeScreenTexture.LoadFromFile("Images/ResumeScreen.jpg", gRenderer))
    {
        printf("Failed to load Resume Screen Texture!\n");
        success = false;
    }
    if (!StatusbarTexture2.LoadFromFile("Images/Health.PNG", gRenderer))
    {
        printf("Failed to load Status bar Texture!\n");
        success = false;
    }

    if (!LoadImage1.LoadFromFile("Images/LoadScreen1.jpg", gRenderer))
    {
        printf("Failed to load Goal Texture!\n");
        success = false;
    }

    if (!LoadImage2.LoadFromFile("Images/LoadScreen2.jpg", gRenderer))
    {
        printf("Failed to load Goal Texture!\n");
        success = false;
    }

    if (!LoadImage3.LoadFromFile("Images/LoadScreen3.jpg", gRenderer))
    {
        printf("Failed to load Goal Texture!\n");
        success = false;
    }

    if (!BumpImage1.LoadFromFile("Images/Bump1.jpg", gRenderer))
    {
        printf("Failed to load Goal Texture!\n");
        success = false;
    }

    if (!BumpImage2.LoadFromFile("Images/Bump2.jpg", gRenderer))
    {
        printf("Failed to load Goal Texture!\n");
        success = false;
    }

    if (!BumpImage3.LoadFromFile("Images/Bump3.jpg", gRenderer))
    {
        printf("Failed to load Goal Texture!\n");
        success = false;
    }

    if (!BumpImage4.LoadFromFile("Images/Bump4.jpg", gRenderer))
    {
        printf("Failed to load Goal Texture!\n");
        success = false;
    }

    if (!BumpImage5.LoadFromFile("Images/Bump5.jpg", gRenderer))
    {
        printf("Failed to load Goal Texture!\n");
        success = false;
    }

    if( !gSpriteSheetTexture.LoadFromFile( "Images/1948.PNG", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if ( !CollisionRectangle.LoadFromFile("Images/CollisionRectangle.png", gRenderer))
    {
        printf( "Failed to load collision rectangle texture!\n" );
		success = false;
    }
    if (!startBackground.LoadFromFile("Images/1.jpg", gRenderer))
    {
        printf("Failed to load startBackground texture!\n");
        success = false;
    }
    if (!transitBackground.LoadFromFile("Images/2.jpg", gRenderer))
    {
        printf("Failed to load transitBackground texture!\n");
        success = false;
    }
    if (!bossBackground.LoadFromFile("Images/3.jpg", gRenderer))
    {
        printf("Failed to load bossBackground texture!\n");
        success = false;
    }
    if (!bossSprite.LoadFromFile("Images/double_trouble_3.png", gRenderer))
    {
        printf("Failed to load bossSprite texture!\n");
        success = false;
    }

    ButtonClickMusic = Mix_LoadWAV( "Sounds/Button_Click.ogg" ); //Loading sound effects
    if( ButtonClickMusic == NULL )
    {
        printf( "Failed to load buttonClick sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    GameMenuMusic = Mix_LoadMUS( "Sounds/Menu_Music.ogg" );
    if( GameMenuMusic == NULL )
    {
        printf( "Failed to load game menu sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    GameMusic = Mix_LoadMUS( "Sounds/Game_Music.ogg" );
    if(GameMusic == NULL)
    {
        printf( "Failed to load game play music sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    StoryMusic = Mix_LoadMUS( "Sounds/Story_Music.ogg" );
    if( StoryMusic == NULL )
    {
        printf( "Failed to load Story Music. SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    GameOverMusic = Mix_LoadWAV( "Sounds/lose_music.ogg" );
    if( GameOverMusic == NULL )
    {
        printf( "Failed to Game Over Music. SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    GameWinMusic = Mix_LoadWAV( "Sounds/win_music.ogg" );
    if( GameWinMusic == NULL )
    {
        printf( "Failed to Game Win Music. SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    return success;
}
void close()
{
    //freeing all textures, Ltexture is not composed in any class, rather aggregated
    FontTexture.Free();
    GameMenuScreenTexture.Free();
    GameOverScreenTexture.Free();
    QuitGameScreenTexture.Free();
    SmallScreenTexture.Free();
    MenuPictureOneTexture.Free();
    MenuPictureTwoTexture.Free();
    MenuPictureThreeTexture.Free();
    IntroductionScreenTexture.Free();
    GameWinScreenTexture.Free();
    ButtonTexture.Free();
    ControlScreenTexture.Free();
    gSpriteSheetTexture.Free();
    CollisionRectangle.Free();
    startBackground.Free();
    transitBackground.Free();
    bossBackground.Free();
    bossSprite.Free();
    StatusbarTexture2.Free();
    ResumeScreenTexture.Free();
    LoadImage1.Free();  //fpr loadscreen
    LoadImage2.Free();
    LoadImage3.Free();
    BumpImage1.Free();  //for story screen
    BumpImage2.Free();
    BumpImage3.Free();
    BumpImage4.Free();
    BumpImage5.Free();

    //freeing all music and chunks
    Mix_FreeChunk( ButtonClickMusic );
    ButtonClickMusic = NULL;
    Mix_FreeMusic( StoryMusic );
    StoryMusic = NULL;
    Mix_FreeMusic( GameMenuMusic);
    GameMenuMusic = NULL;
    Mix_FreeMusic(GameMusic);
    GameMusic = NULL;
    Mix_FreeChunk( GameOverMusic );
    GameOverMusic = NULL;
    Mix_FreeChunk( GameWinMusic );
    GameWinMusic = NULL;

	///Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	///Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}
