//
//  TestNode.hpp
//  test-ios
//
//  Created by Naver on 2018. 1. 21..
//

#ifndef TestNode_hpp
#define TestNode_hpp

class TestNode : public Node
{
    friend class Camera;
    
    
    public:
        TestNode(const char* id = NULL);
        static TestNode* create(const char* id = NULL);
        void render(float elapsedTime);
        void loadGBP();
    
    private:
//      Camera* _camera;
        gameplay::Effect *_effect;
        gameplay::Material *_material;
        gameplay::Model *_drawingModel;
        gameplay::Uniform *_transUniform;
        float _elapsedSum;
};




#endif /* TestNode_hpp */
