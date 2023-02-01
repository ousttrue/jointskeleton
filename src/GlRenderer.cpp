#include "GlRenderer.h"
#include <Windows.h>
#include <iostream>

#include <GL/GL.h>

GlRenderer::GlRenderer() { std::cout << glGetString(GL_VERSION) << std::endl; }

GlRenderer::~GlRenderer() {}

void GlRenderer::BeginFrame(int display_w, int display_h,
                            const float clear_color[4]) {
  glViewport(0, 0, display_w, display_h);
  glClearColor(clear_color[0], clear_color[1], clear_color[2], clear_color[3]);
  glClear(GL_COLOR_BUFFER_BIT);
}

void GlRenderer::RenderScene() {}