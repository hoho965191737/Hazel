#include "hzpch.h"
#include "Renderer.h"


namespace Hazel {
	// 这样处理是 为了方便运行时进行处理
	RendererAPI Renderer::s_RendererAPI = RendererAPI::OpenGL;
}