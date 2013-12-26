#include "SDL_gpu_OpenGL_2.h"


#if defined(SDL_GPU_DISABLE_OPENGL) || defined(SDL_GPU_DISABLE_OPENGL_2)

// Dummy implementations
GPU_Renderer* GPU_CreateRenderer_OpenGL_2(GPU_RendererID request) {return NULL;}
void GPU_FreeRenderer_OpenGL_2(GPU_Renderer* renderer) {}

#else

// Most of the code pulled in from here...
#define SDL_GPU_USE_OPENGL
#define SDL_GPU_USE_GL_TIER2
#define RENDERER_DATA RendererData_OpenGL_2
#define IMAGE_DATA ImageData_OpenGL_2
#define TARGET_DATA TargetData_OpenGL_2
#include "../GL_common/SDL_gpu_GL_common.inl"
#include "../GL_common/SDL_gpuShapes_GL_common.inl"


GPU_Renderer* GPU_CreateRenderer_OpenGL_2(GPU_RendererID request)
{
    GPU_Renderer* renderer = (GPU_Renderer*)malloc(sizeof(GPU_Renderer));
    if(renderer == NULL)
        return NULL;

    memset(renderer, 0, sizeof(GPU_Renderer));

    renderer->id = request;
	renderer->id.id = GPU_RENDERER_OPENGL_2;
    
    renderer->current_target = NULL;

    renderer->data = (RENDERER_DATA*)malloc(sizeof(RENDERER_DATA));
    memset(renderer->data, 0, sizeof(RENDERER_DATA));

    SET_COMMON_FUNCTIONS(renderer);

    return renderer;
}

void GPU_FreeRenderer_OpenGL_2(GPU_Renderer* renderer)
{
    if(renderer == NULL)
        return;

    free(renderer->data);
    free(renderer);
}


#endif
