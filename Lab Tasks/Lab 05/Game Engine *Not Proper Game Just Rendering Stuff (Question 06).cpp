#include <iostream>

using namespace std;

class GraphicsEngine {
public:
    GraphicsEngine() {
        cout << "Graphics Engine Initialized.\n";
    }
    void render() {
        cout << "Rendering graphics...\n";
    }
};

class InputHandler {
public:
    InputHandler() {
        cout << "Input Handler Initialized.\n";
    }
    void processInput() {
        cout << "Processing user input...\n";
    }
};

class PhysicsEngine {
public:
    PhysicsEngine() {
        cout << "Physics Engine Initialized.\n";
    }
    void updatePhysics() {
        cout << "Updating physics simulation...\n";
    }
};

class GameEngine {
private:
    GraphicsEngine graphics;
    InputHandler input;
    PhysicsEngine physics;

public:
    GameEngine() {
        cout << "Game Engine Initialized.\n";
    }
    void runGameLoop() {
        cout << "Game Loop Started.\n";
        input.processInput();
        physics.updatePhysics();
        graphics.render();
        cout << "Game Loop Completed.\n";
    }
};

int main() {
    GameEngine game;
    game.runGameLoop();
    return 0;
}
