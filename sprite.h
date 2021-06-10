typedef struct {
	SDL_Texture* img;
	SDL_Rect texr;
}  Sprite;

void Sprite_LoadImage(SDL_Renderer* renderer, Sprite* sprite, char imgPath[]);
void Sprite_SetPosition(Sprite* sprite, int x, int y);
void Sprite_Dispose(Sprite* sprite);
