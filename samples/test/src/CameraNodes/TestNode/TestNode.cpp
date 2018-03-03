//
//  TestNode.cpp
//  test-ios
//
//  Created by Naver on 2018. 1. 21..
//

#include "CameraEngine.h"
#include "TestNode.hpp"

TestNode::TestNode(const char* id) : Node(id)
{
    _camera = Camera::createPerspective(45.0, 1.0, 0.1, 1000.0);
    

 //   Mesh *mesh = Mesh::createQuad(-1.0, -1.0, 2.0, 2.0);
//    Mesh *mesh = Mesh::createCubeModel();
    Mesh *mesh = Mesh::createCubeModelWithNormal();
    
    Texture* texture = Texture::create("res/test/lena.png");
    Texture::Sampler* sampler = Texture::Sampler::create(texture);
    
    _material = Material::create("res/shaders/test/test.vert", "res/shaders/test/test.frag");
    _material->getParameter("u_texture")->setValue(sampler);
    
    _drawingModel = Model::create(mesh);
    _drawingModel->setMaterial(_material);
    
    _elapsedSum = 0.0;
}


//Scene::load("res/demo.scene");
void TestNode::loadGBP()
{
    _scene->load("res/demo.scene");
//    _scene->load(filePath);
    
}

TestNode* TestNode::create(const char* id)
{
    return new TestNode(id);
}

void Node::draw()
{
    print("----draw----");
    //_drawingModel->draw();
}

void TestNode::render(float elapsedTime)
{
    float aspect = 16.0 / 9.0;
    
    _elapsedSum = _elapsedSum + (elapsedTime / 10.0);
    if(_elapsedSum > 360.0) {
        _elapsedSum = 0.0;
    }
    
    Matrix modelViewMat;
    Matrix look;
    Matrix::createLookAt( 0.0, 0.0, 0.0,
                          0.0, 0.0, -1.0,
                          0.0, 1.0, 0.0, &look);
    Matrix transform = Matrix::identity();
//    transform.rotateZ(45.0 * M_PI / 180.0);
    transform.translate(0.0, 0.0, -10.5);
    transform.rotateX(_elapsedSum * M_PI / 180.0);
    transform.rotateY(_elapsedSum * M_PI / 180.0);
//    transform.scale(1.0, 1.0, 1.0);
    
    Matrix::multiply(transform, look, &modelViewMat);
    
    Matrix proj;
 //   Matrix::createOrthographicOffCenter(-aspect, aspect, -1, 1, -1, 1, &proj);
    Matrix::createPerspective(45.0, aspect, 0.1, 100.0, &proj);
//      Matrix::createPerspective(27.0, 1.6, 0.25, 100.0, &proj);
    
    _drawingModel->getMaterial()->getParameter("u_worldViewMat")->setMatrix(modelViewMat);
    _drawingModel->getMaterial()->getParameter("u_projMat")->setMatrix(proj);
    _drawingModel->getMaterial()->getStateBlock()->setDepthTest(true);
    _drawingModel->getMaterial()->getStateBlock()->setCullFace(true);
    
    _drawingModel->draw();
}


