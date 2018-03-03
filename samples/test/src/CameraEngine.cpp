#include "CameraEngine.h"
#include "CameraNodes/TestNode/TestNode.hpp"

// Declare our game instance
CameraEngine cameraEngine;

CameraEngine::CameraEngine() //Camera Engine
    : _scene(NULL), _wireframe(false)
{
}


void CameraEngine::initialize()
{
    _scene = Scene::create("CameraScene");

    TestNode *testNode = TestNode::create(NULL);

    _scene->addNode(testNode);

    _scene->getActiveCamera()->setAspectRatio(getAspectRatio());
}




void CameraEngine::finalize()
{
    SAFE_RELEASE(_scene);
}

void CameraEngine::update(float elapsedTime)
{
    // Rotate model
//    _scene->findNode("box")->rotateY(MATH_DEG_TO_RAD((float)elapsedTime / 1000.0f * 180.0f));
}

void CameraEngine::render(float elapsedTime)
{
    // Clear the color and depth buffers
    clear(CLEAR_COLOR_DEPTH, Vector4::zero(), 1.0f, 0);
    _lastElapsedTime = elapsedTime;

    // Visit all the nodes in the scene for drawing
    _scene->visit(this, &CameraEngine::drawScene);
    
    
}

bool CameraEngine::drawScene(Node* node)
{
    TestNode *testNode = dynamic_cast<TestNode *>(node);
    testNode->render(_lastElapsedTime);
}

void CameraEngine::keyEvent(Keyboard::KeyEvent evt, int key)
{
    if (evt == Keyboard::KEY_PRESS)
    {
        switch (key)
        {
        case Keyboard::KEY_ESCAPE:
            exit();
            break;
        }
    }
}

void CameraEngine::touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex)
{
    switch (evt)
    {
    case Touch::TOUCH_PRESS:
        _wireframe = !_wireframe;
        break;
    case Touch::TOUCH_RELEASE:
        break;
    case Touch::TOUCH_MOVE:
        break;
    };
}
