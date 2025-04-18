#pragma once

#include <string>

namespace Hazel {
	// 这个类过滤器作用主要类似于 文件夹中的All Files功能，选择不同类型的文件
	class FileDialogs
	{
	public:
		// 如果取消，则返回空字符串
		static std::string OpenFile(const char* filter);
		static std::string SaveFile(const char* filter);

	private:

	};

}