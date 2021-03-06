#pragma once

#include <SDL.h>
#include "../Sprite/Sprite.h"

class Camera{
public:
	Camera(SDL_Renderer* renderer,SDL_Rect rect);
	~Camera();

	//return camera dimensions;
	int getWidth();
	int getHeight();
	int getX();
	int getY();

	//scrolls through a level by the x axis
	void scrollX(int incr, int levelW);
	//scrolls through a level by the y axis
	void scrollY(int incr, int levelH);

	//moves the camera by x and y pixels
	void move(int deltax, int deltay);
	//sets coordinates of camera at x and y
	void setPos(int x, int y);

	//render the background
	void render(int x, int y, SDL_Texture* texture);

	//keeps from going outside the level
	void fixCameraPosition(int levelwidth, int levelheight);

private:
	SDL_Renderer* renderer;
	SDL_Rect camera;
};
