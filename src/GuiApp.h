#pragma once

class GuiApp {
  // Our state
  bool show_demo_window = true;
  bool show_another_window = false;

public:
  float clear_color[4] = {0.45f, 0.55f, 0.60f, 1.00f};
  GuiApp(struct GLFWwindow *window, const char *glsl_version);
  ~GuiApp();
  void UpdateGui();
  void RenderGui();
};
