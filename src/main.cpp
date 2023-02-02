#include "GlRenderer.h"
#include "GuiApp.h"
#include "GuiWindow.h"

float view[] = {
    1, 0, 0, 0, //
    0, 1, 0, 0, //
    0, 0, 1, 0, //
    0, 0, 0, 1, //
};
float projection[] = {
    1, 0, 0, 0, //
    0, 1, 0, 0, //
    0, 0, 1, 0, //
    0, 0, 0, 1, //
};

int main(int, char **) {

  GuiWindow gui;
  auto window = gui.Create();
  if (!window) {
    return 1;
  }

  GuiApp app(window, gui.GlslVersion());
  GlRenderer renderer;

  // Main loop
  int display_w, display_h;
  while (gui.NewFrame(&display_w, &display_h)) {
    app.UpdateGui();
    float clear_color[4] = {
        app.clear_color[0] * app.clear_color[3],
        app.clear_color[1] * app.clear_color[3],
        app.clear_color[2] * app.clear_color[3],
        app.clear_color[3],
    };
    renderer.BeginFrame(display_w, display_h, clear_color);
    renderer.RenderScene(view, projection);
    app.RenderGui();
    gui.EndFrame();
  }

  return 0;
}
