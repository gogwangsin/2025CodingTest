#pragma once

#if 1
// Visual Studio 17.9.0 이상, Release/x64
// Project 속성/std::c++latest, 프로젝트 속성->C++->SDL검사-no

void save(std::string_view);
// == const string& 읽기만 한다는 것: 16바이트

#endif