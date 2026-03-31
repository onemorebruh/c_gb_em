#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int SCREEN_WIDTH = 854;
int SCREEN_HEIGHT = 480;

class RenderWindow {
	public:
		RenderWindow( const char* title, int width, int height);
		SDL_Renderer* GetRenderer();
		void close();
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
};

void main (){
}
