#pragma once
#define SeededXorshift128_API __declspec(dllexport)
#include <cstdint>

extern "C" SeededXorshift128_API    inline void init(unsigned int seed);
extern "C" SeededXorshift128_API 	inline int64_t nextRand();
