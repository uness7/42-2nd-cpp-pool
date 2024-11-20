#ifndef SERIALIZER_H
#define SERIALIZER_H

# include "data.h"
# include <iostream>
#include <cstddef>
#include <stdint.h>


class Serializer {
	private:
		Serializer(void);
		Serializer(Serializer const & other);
		Serializer& operator=(Serializer const & other);
		~Serializer(void);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
