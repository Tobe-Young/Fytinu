#include<iostream>
#include<string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengles2.h>

using  namespace std;

int32_t main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }
    SDL_SetHint(SDL_HINT_OPENGL_ES_DRIVER, "1");

    SDL_Window* window = SDL_CreateWindow(
                    "An SDL3 window",                  // window title
                    640,                               // width, in pixels
                    480,                               // height, in pixels
                    SDL_WINDOW_OPENGL                  // flags - see below
                    );
    if (!window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        return -1;
    }

    bool running = true;
    SDL_Event event;
    while (running) {
        // 处理所有在事件队列中的事件
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    // 处理键盘事件
                    if (event.key.key == SDLK_ESCAPE) {
                        running = false;
                    }
                    break;
                    // 可以添加更多事件处理逻辑
            }
        }

        glViewport(0, 0, 640, 480);
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DestroyContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}