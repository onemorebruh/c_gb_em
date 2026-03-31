
window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);


if(window == NULL){
	printf("SDL could not create window!. SDL Error: %s\n", SDL_GetError());
};

