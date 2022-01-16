#include "pch.h"
#include "SeededXorshift128.h"

static unsigned long x;
static unsigned long y;
static unsigned long z;
static unsigned long w;

inline void init(const unsigned int seed) {
	int v2; // r12
	int v3; // r3
	unsigned int v4; // lr
	unsigned int v5; // r2
	int v7; // r5
	v2 = 0x159A55E5;
	x = 123456789;
	y = 362436069;
	z = 521288629;
	w = 88675123;
	v3 = 521288629;
	v4 = 88675123;
	v5 = seed ^ 0xAC9365;
	for (size_t i = 0; i < 100; i++) {
		v7 = v2;
		v2 = v3;
		v3 = v4;
		v5 ^= (0x65AC9365u >> (v5 & 3)) ^ ((v5 ^ (0x65AC9365u >> (v5 & 3))) >> 3) ^
			((v5 ^ (0x65AC9365u >> (v5 & 3))) >> 4) ^ (8 * (v5 ^ (0x65AC9365u >> (v5 & 3)))) ^
			(16 * (v5 ^ (0x65AC9365u >> (v5 & 3))));
		v4 ^= v5 ^ (v5 << 15) ^ ((v5 ^ (v5 << 15)) >> 4) ^ (v4 >> 21);
	}
	x = v7;
	y = v2;
	z = v3;
	w = v4;
}

inline int64_t nextRand() {
	int t = x ^ (x << 15);
	x = y;
	y = z;
	z = w;
	w = t ^ w ^ ((t ^ (w >> 17)) >> 4);
	return w;
}