#ifndef LEARN_SDL_INPUTHANDLER_H
#define LEARN_SDL_INPUTHANDLER_H

#include <SDL.h>
#include <vector>

#include "Vector2D.h"

enum mouse_buttons {
    LEFT = 0,
    MIDDLE,
    RIGHT
};

class InputHandler {
public:
    static InputHandler* instance();

    void initialiseJoysticks();
    bool isJoysticksInitialised() const;

    bool getMouseButtonState(int buttonNumber);

    bool isKeyDown(SDL_Scancode key);

    Vector2D* getMousePosition();

    void update();
    void clean();

    void reset();

private:
    InputHandler();
    ~InputHandler();

    static InputHandler* s_pInstance;

    std::vector<SDL_Joystick *> m_joysticks;
    bool m_bJoysticksInitialised;
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
    std::vector<std::vector<bool>> m_buttonStates;
    int xvalue(int joy, int stick);
    int yvalue(int joy, int stick);

    const int m_joystickDeadZone = 10000;

    std::vector<bool> m_mouseButtonStates;

    const Uint8* m_keystates;

    Vector2D* m_mousePosition;

    // handle keyboard events
    void onKeyDown();
    void onKeyUp();

    // handle mouse events
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);

    // handle joystick events
    void onJoystickAxisMove(SDL_Event& event);
    void onJoystickButtonDown(SDL_Event& event);
    void onJoystickButtonUp(SDL_Event& event);
};

typedef InputHandler TheInputHandler;

#endif //LEARN_SDL_INPUTHANDLER_H
