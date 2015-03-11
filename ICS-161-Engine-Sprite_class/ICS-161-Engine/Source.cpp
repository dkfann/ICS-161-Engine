//#include <iostream>
//#include <ostream>
//#include <string>
//#include <sstream>
//#include <Windows.h>
//#include <SDL.h>
//#include "res_path.h"
//#include "cleanup.h"
//#include "SDL_image.h"
//#include "Sprite.h"
//
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
///**
//* Log an SDL error with some error message to the output stream of our choice
//* @param os The output stream to write the message to
//* @param msg The error message to write, format will be msg error: SDL_GetError()
//*/
//void logSDLError(std::ostream &os, const std::string &msg){
//	os << msg << " error: " << SDL_GetError() << std::endl;
//	std::ostringstream errMsg;
//	errMsg << " error: " << SDL_GetError() << std::endl;
//	OutputDebugString(errMsg.str().c_str());
//}
//
///**
//* Loads an image into a texture on the rendering device
//* @param file The image file to load
//* @param ren The renderer to load the texture onto
//* @return the loaded texture, or nullptr if something went wrong.
//*/
//SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
//	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
//	if (texture == nullptr){
//		logSDLError(std::cout, "LoadTexture");
//	}
//	return texture;
//}
//
//
//int main(int argc, char **argv){
//
//	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
//		std::ostringstream debugMsg;
//		debugMsg << "SDL_Init Error: " << SDL_GetError() << std::endl;
//		OutputDebugString(debugMsg.str().c_str());
//		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
//		return 1;
//	}
//
//	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
//		logSDLError(std::cout, "IMG_Init");
//		SDL_Quit();
//		return 1;
//	}
//
//	SDL_Window *window = SDL_CreateWindow("Sprite Demo", 800, 100, SCREEN_WIDTH,
//		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//	if (window == nullptr){
//		logSDLError(std::cout, "CreateWindow");
//		SDL_Quit();
//		return 1;
//	}
//	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
//		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//	if (renderer == nullptr){
//		logSDLError(std::cout, "CreateRenderer");
//		cleanup(window);
//		SDL_Quit();
//		return 1;
//	}
//
//	//const std::string resPath = getResourcePath("SpriteDemo");
//	const std::string resPath = "C:\\Users\\Danny\\Desktop\\ICS_161_Sprite\\ICS-161-Engine-Sprite_class\\ICS-161-Engine\\Sprite\\Demo\\";
//
//	Sprite* spriteBG = new Sprite(0, 0, resPath + "Document1.txt", renderer);
//
//	int x = SCREEN_WIDTH / 2;
//	int y = SCREEN_HEIGHT / 2;
//
//	Sprite* sprite1 = new Sprite(x, y, resPath + "Lea.txt", renderer);
//	Sprite* sprite2 = new Sprite(x, y, resPath + "dot.txt", renderer);
//	Sprite* sprite3 = new Sprite(x + 50, y + 50, resPath + "fire.txt", renderer);
//	Sprite* sprite4 = new Sprite(0, 0, resPath + "number.txt", renderer);
//	SDL_Event e;
//	bool quit = false, left = false, right = false, up = false, down = false, shift = false, grounded = false;
//	bool fgrounded = false;
//	std::string spriteAction = "walk ";
//	std::string facing = "right";
//	int score = 0;
//	std::stringstream ss;
//	ss << score;
//	std::string num = ss.str();
//	//std::cout << num << std::endl;
//	sprite1->setAY(.4);
//	sprite3->setAY(.4);
//	sprite3->setAX(.1);
//	while (!quit){
//		while (SDL_PollEvent(&e)){
//			if (e.type == SDL_QUIT){
//				quit = true;
//			}
//			if (e.type == SDL_KEYDOWN) {
//				switch (e.key.keysym.sym)
//				{
//				case SDLK_RIGHT:
//					right = true;
//					break;
//				case SDLK_LEFT:
//					left = true;
//					break;
//				case SDLK_UP:
//					up = true;
//					break;
//				case SDLK_DOWN:
//					down = true;
//					break;
//				case SDLK_LSHIFT:
//				case SDLK_RSHIFT:
//					shift = true;
//					break;
//				}
//			}
//
//			if (e.type == SDL_KEYUP) {
//				switch (e.key.keysym.sym)
//				{
//				case SDLK_RIGHT:
//					right = false;
//					break;
//				case SDLK_LEFT:
//					left = false;
//					break;
//				case SDLK_UP:
//					up = false;
//					break;
//				case SDLK_DOWN:
//					down = false;
//					break;
//				case SDLK_LSHIFT:
//				case SDLK_RSHIFT:
//					shift = false;
//					break;
//				}
//			}
//		}
//		if (left)
//		{
//			sprite1->setVX(-2);
//			spriteAction = "walk ";
//			if (shift)
//			{
//				sprite1->setVX(-4);
//				spriteAction = "run ";
//			}
//			facing = "left";
//		}
//		else if (right)
//		{
//			sprite1->setVX(2);
//			spriteAction = "walk ";
//			if (shift)
//			{
//				sprite1->setVX(4);
//				spriteAction = "run ";
//			}
//			facing = "right";
//		}
//		else
//		{
//			sprite1->setVX(0);
//		}
//		if (up && grounded)
//		{
//			sprite1->setVY(-11);
//		}
//
//		if (sprite1->getVY() < 0)
//		{
//			spriteAction = "rise ";
//			grounded = false;
//		}
//
//		if (sprite1->getVY() >= 0 && !grounded)
//			spriteAction = "descend ";
//
//		sprite1->update();
//		sprite3->update();
//		if (collide(*sprite1, *spriteBG))
//		{
//			sprite1->setBottom(spriteBG->getBoundary().y);
//			sprite1->setVY(0);
//			grounded = true;
//		}
//
//		if (collide(*sprite1, *sprite3))
//		{
//			if (score < 9)
//			{
//				//sprite1->setAX(-.3);
//				score++;
//				//std::cout << score << std::endl;
//			}
//		}
//
//		if (collide(*sprite3, *spriteBG))
//		{
//			sprite3->setBottom(spriteBG->getBoundary().y);
//			sprite3->setVY(-6);
//		}
//		if (sprite3->getX() >= SCREEN_WIDTH)
//		{
//			sprite3->setVX(-3);
//			sprite3->setAX(-0.1);
//		}
//		if (sprite3->getX() <= 0)
//		{
//			sprite3->setVX(3);
//			sprite3->setAX(0.1);
//		}
//
//		if (sprite1->getVX() == 0 && grounded)
//		{
//			spriteAction = "stand ";
//		}
//		std::stringstream ss;
//		ss << score;
//		std::string num = ss.str();
//		//Render the scene
//		std::cout << num << std::endl;
//		SDL_RenderClear(renderer);
//		spriteBG->show("background", 1);
//		sprite1->show(spriteAction + facing, 1);
//		sprite2->show("dot", 0);
//		sprite3->show("fire", 1);
//		sprite4->show(num, 0);
//		SDL_RenderPresent(renderer);
//	}
//
//	cleanup(renderer, window);
//	IMG_Quit();
//	SDL_Quit();
//
//	SDL_Quit();
//	delete spriteBG;
//	delete sprite1;
//	delete sprite2;
//	delete sprite3;
//
//	return 0;
//}
