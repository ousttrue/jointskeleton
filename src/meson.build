glimmer_dep = dependency('glimmer')
glfw_dep = dependency('glfw3', default_options: ['install=true'])
cc = meson.get_compiler('c')
gl_dep = cc.find_library('OpenGL32')
imgui_dep = dependency('imgui', default_options: ['default_library=static'])

executable(
    'jointskeleton',
    [
        'main.cpp',
    ],
    install: true,
    include_directories: include_directories('../include'),
    dependencies: [glfw_dep, glimmer_dep, gl_dep, imgui_dep],
)
