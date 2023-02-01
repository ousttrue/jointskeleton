#pragma once

class GlRenderer {
public:
  GlRenderer();
  ~GlRenderer();
  void BeginFrame(int display_w, int display_h, const float clear_color[4]);
  void RenderScene();
};
