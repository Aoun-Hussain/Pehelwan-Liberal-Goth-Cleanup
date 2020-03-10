#include "StoryScreen.h"

StoryScreen::StoryScreen(Ltexture* bgImage1, Ltexture* bgImage2, Ltexture* bgImage3, Ltexture* bgImage4, Ltexture* bgImage5,
                                    Ltexture* fontSprite) : Screen(fontSprite)
{
    this -> texture1 = bgImage1;
    this -> texture2 = bgImage2;
    this -> texture3 = bgImage3;
    this -> texture4 = bgImage4;
    this -> texture5 = bgImage5;
    this -> x = 0;
    this -> y = 0;
}

void StoryScreen::Render(long int& frame, long int& frame1, SDL_Renderer* gRenderer)
{
    //rendering story on the screen
    if ((frame - frame1 > 0) && (frame - frame1 < 500))
    {
        word = new Text("With the rise of neo liberalism",fontSprite,x + 520, y + 200,1);
        texture1 -> RenderTexture( x, y,gRenderer,NULL );
        word -> Render(gRenderer);
        delete word;
        word = new Text("a contiguous virus is spreading",fontSprite,x + 500, y + 250,1);
        word -> Render(gRenderer);
        delete word;
        word = new Text("from a new born institution of",fontSprite,x + 490, y + 300,1);
        word -> Render(gRenderer);
        delete word;
        word = new Text("Karachi Habib University",fontSprite,x + 420, y + 350,1);
        word -> Render(gRenderer);

    }

    else if ((frame - frame1 > 500) && (frame - frame1 < 1000))
    {
        word = new Text("Good citizens of Karachi have",fontSprite,x + 520, y + 200,1);
        texture2 -> RenderTexture( x, y,gRenderer,NULL );
        word -> Render(gRenderer);
        delete word;
        word = new Text("taken the initiative to counter",fontSprite,x + 520, y + 250,1);
        word -> Render(gRenderer);
        delete word;
        word = new Text("this virus by killing all the",fontSprite,x + 520, y + 300,1);
        word -> Render(gRenderer);
        delete word;
        word = new Text("the aerial germs",fontSprite,x + 420, y + 350,1);
        word -> Render(gRenderer);
    }

    else if ((frame - frame1 > 1000) && (frame - frame1 < 1500))
    {
        word = new Text("Hence a plane fighter from ",fontSprite,x + 520, y + 200,1);
        texture3 -> RenderTexture( x, y,gRenderer,NULL );
        word -> Render(gRenderer);
        delete word;
        word = new Text("Masjid Siddiq e Akbar has been",fontSprite,x + 520, y + 250,1);
        word -> Render(gRenderer);
        delete word;
        word = new Text("chosen as the messiah to save",fontSprite,x + 520, y + 300,1);
        word -> Render(gRenderer);
        delete word;
        word = new Text("city Karachi",fontSprite,x + 300, y + 350,1);
        word -> Render(gRenderer);
    }

    else if ((frame - frame1 > 1500) && (frame - frame1 < 2000))
    {
        word = new Text("Kill the planes by shooting",fontSprite,x + 520, y + 200,1);
        texture4 -> RenderTexture( x, y,gRenderer,NULL );
        word -> Render(gRenderer);
        delete word;
        word = new Text("missiles at them and reach",fontSprite,x + 520, y + 250,1);
        word -> Render(gRenderer);
        delete word;
        word = new Text("Habib University to kill the",fontSprite,x + 520, y + 300,1);
        word -> Render(gRenderer);
        delete word;
        word = new Text("boss aerial germ",fontSprite,x + 520, y + 350,1);
        word -> Render(gRenderer);

    }
    else if ((frame - frame1 > 2000) && (frame - frame1 < 2500))
    {
        word = new Text("Goodluck!",fontSprite,x + 450, y + 200,1);
        texture5 -> RenderTexture( x, y,gRenderer,NULL );
        word -> Render(gRenderer);
        delete word;
        word = new Text("May the force be with you!",fontSprite,x + 420, y + 250,1);
        word -> Render(gRenderer);
    }
}

StoryScreen::~StoryScreen()
{}

