#ifndef ALPHACONTROLLER_H
#define ALPHACONTROLLER_H
#include "SceneElement.h"
#include "GLFWController.h"
#include <string>
class AlphaController : public GLFWController
{
public:
    AlphaController(const std::string& title, int Flags = 0);
    ~AlphaController();
    void setShader(ShaderIF* sIF);
    void handleDisplay();
private:
    void drawAllObjects();
    ShaderIF* shaderIF;
};

#endif
