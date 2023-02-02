#pragma once
#include <stdint.h>

class GlRenderer {
  uint32_t vertex_buffer = 0;
  uint32_t vertex_shader = 0;
  uint32_t fragment_shader = 0;
  uint32_t program = 0;
  uint32_t mvp_location = -1;
  uint32_t vpos_location = -1;
  uint32_t vcol_location = -1;

public:
  GlRenderer();
  ~GlRenderer();
  void BeginFrame(int display_w, int display_h, const float clear_color[4]);
  void RenderScene(const float view[], const float projection[]);
};
