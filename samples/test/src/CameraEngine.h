#ifndef TestGame_H_
#define TestGame_H_

#include "gameplay.h"

using namespace gameplay;

/**
 * Main game class.
 */
class CameraEngine: public Game
{
public:

    /**
     * Constructor.
     */
    CameraEngine();

    /**
     * @see Game::keyEvent
     */
	void keyEvent(Keyboard::KeyEvent evt, int key);
	
    /**
     * @see Game::touchEvent
     */
    void touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex);

protected:

    /**
     * @see Game::initialize
     */
    void initialize();

    /**
     * @see Game::finalize
     */
    void finalize();

    /**
     * @see Game::update
     */
    void update(float elapsedTime);

    /**
     * @see Game::render
     */
    void render(float elapsedTime);
    
    
    //ov
//    void frame();
    

private:

    /**
     * Draws the scene each frame.
     */
    bool drawScene(Node* node);

    Scene* _scene;
    bool _wireframe;
    float _lastElapsedTime;
};

#endif
