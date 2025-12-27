
#if 1

#include <string_view>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>

#include "Save.h"

void save(std::string_view fileName)
{
	std::ifstream in{ fileName.data() };
	if (not in) {
		std::cout << fileName << " - 파일 열기 실패" << std::endl;
		exit(0);
	}

	std::ofstream out{
		"2025 C++ CT.txt",
		std::ios::app
	};

	out << std::endl << std::endl;

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	time_t time = std::chrono::system_clock::to_time_t(now);

	tm* localTime = localtime(&time);
	std::locale oldLocale = out.imbue(std::locale("ko_KR"));

	out << "================================================" << std::endl;
	out << fileName << std::put_time(localTime, ", 저장시간 : %x %A %X") << std::endl;
	out << "================================================" << std::endl;
	out.imbue(oldLocale);

	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };

	for (char c : v) {
		out << c;
	}
}


#endif