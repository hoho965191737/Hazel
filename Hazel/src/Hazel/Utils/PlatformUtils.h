#pragma once

#include <string>

namespace Hazel {
	// ����������������Ҫ������ �ļ����е�All Files���ܣ�ѡ��ͬ���͵��ļ�
	class FileDialogs
	{
	public:
		// ���ȡ�����򷵻ؿ��ַ���
		static std::string OpenFile(const char* filter);
		static std::string SaveFile(const char* filter);

	private:

	};

}