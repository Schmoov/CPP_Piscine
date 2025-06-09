#pragma once
#include <stdint.h>
#include "Data.hpp"

class Serializer {
public:
	virtual ~Serializer() = 0;
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
