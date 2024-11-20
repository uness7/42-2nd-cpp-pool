# include "Serializer.h"

int	main(int, char **) {
	Data originalData;
	originalData.name = "younes";
	originalData.age = 23;
	Data* originalPtr = &originalData;
	uintptr_t serializedValue = Serializer::serialize(originalPtr);
	Data* reconstructedPtr = Serializer::deserialize(serializedValue);
	if (originalPtr == reconstructedPtr)
	{
		std::cout << "Serialization successful!" << std::endl;
		std::cout << "Name: " << reconstructedPtr->name << std::endl;
		std::cout << "Age: " << reconstructedPtr->age << std::endl;
	}
	else
		std::cout << "Serialization failed!" << std::endl;

	return 0;
}

