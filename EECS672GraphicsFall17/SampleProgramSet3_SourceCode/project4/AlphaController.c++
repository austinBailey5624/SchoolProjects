#include "AlphaController.h"

AlphaController::AlphaController(const std::string& theWindow, int Flags): GLFWController(theWindow, Flags), shaderIF(nullptr)
{

}

AlphaController::~AlphaController()
{

}

void AlphaController::setShader(ShaderIF* sIF)
{
    shaderIF = sIF;
}

void AlphaController::handleDisplay()
{
    //taken from GLFWController::handleDisplay
    if(theWindow == nullptr)
    {
        return;
    }
    glfwMakeContextCurrent(theWindow);
    int width, height;
    glfwGetFramebufferSize(theWindow, &width, &height);
    glViewport(0,0,width,height);
    glClear(glClearFlags);

    glUseProgram(shaderIF->getShaderPgmID());

    //taken from https://people.eecs.ku.edu/~jrmiller/Courses/672/InClass/TranslucentObjectRendering/TranslucentObjects_GPU.html
    glDepthMask(GL_TRUE);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // glClear(glClearFlags);
glUseProgram(shaderIF->getShaderPgmID());
glUniform1i(shaderIF->ppuLoc("sceneHasTranslucentObjects"), 1);

// draw opaque objects
glDisable(GL_BLEND);
glUniform1i(shaderIF->ppuLoc("drawingOpaqueObjects"), 1);
drawAllObjects();

// draw translucent objects
glDepthMask(GL_FALSE);
glEnable(GL_BLEND);
glUniform1i(shaderIF->ppuLoc("drawingOpaqueObjects"), 0);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
drawAllObjects();

}

void AlphaController::drawAllObjects()
{
    for (std::vector<ModelView*>::iterator modelIterator=models.begin() ; modelIterator<models.end() ; modelIterator++)
  (*modelIterator)->render();
glfwSwapBuffers(theWindow);
}
