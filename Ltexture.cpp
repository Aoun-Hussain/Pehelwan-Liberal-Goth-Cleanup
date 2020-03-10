#include "Ltexture.h"

Ltexture::Ltexture()
{
    texture = NULL;  //initialized attributes
    width = 0;
    height = 0;
}

Ltexture::~Ltexture()
{
    Free();
}

bool Ltexture::LoadFromFile(string path, SDL_Renderer* gRenderer, bool flagColorKey, Uint8 redColorKey,
                             Uint8 greenColorKey, Uint8 blueColorKey)
{
    SDL_Surface* loadedSurface = NULL;
    SDL_Texture* newTexture = NULL;

    loadedSurface = IMG_Load(path.c_str());

    if(loadedSurface == NULL)
    {
        cout << "Unable to load image from " << path << ". SDL_image error"<< IMG_GetError() << endl;
    }
    else
    {
        SDL_SetColorKey(loadedSurface, flagColorKey, SDL_MapRGB(loadedSurface->format, 0, 255, 255));
        newTexture=SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

        if( newTexture != NULL)
        {
            width = loadedSurface -> w;
            height = loadedSurface -> h;
        }
        else
        {
            cout<< "Unable to create texture from surface from "<<path<< ". SDL_image error"<< IMG_GetError()<<endl;
        }

        SDL_FreeSurface(loadedSurface);
    }
    texture = newTexture;
    return texture != NULL;
}

void Ltexture::RenderTexture(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip,
                              SDL_RendererFlip flip, double angle, SDL_Point* center,float scale)
{
    SDL_Rect rectCoordinates = {x, y, width, height};

    if(clip != NULL)
    {
        rectCoordinates.w = clip -> w;
        rectCoordinates.h = clip -> h;
    }
    rectCoordinates.w *= scale;
    rectCoordinates.h *= scale;
    SDL_RenderCopyEx(gRenderer, texture, clip, &rectCoordinates, angle, center, flip);
}

void Ltexture::Free()
{
    if(texture != NULL)   //destroys the texture
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}

int Ltexture::GetWidth()
{
    return width;
}

int Ltexture::GetHeight()
{
    return height;
}


