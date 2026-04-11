#include <X11/Xlib.h>


int main (){
	XEvent event;
	Display* display = XOpenDisplay(NULL);
	Window window = XCreateSimpleWindow(display,
			DefaultRootWindow(display),
			50, 50, 250, 250,
			1, BlackPixel(display, 0), WhitePixel(display, 0));


	XMapWindow(display, window);
	XSelectInput(display, window, ExposureMask);



	for (;;){
		XNextEvent(display, &event);
		if (event.type == Expose){
			XDrawString(display, window,
				DefaultGC(display, 0),
				100, 100, "it works", 8);
		};
	};

	return 0;
}
