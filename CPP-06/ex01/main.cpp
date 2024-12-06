#include "Serializer.hpp" 

int main(void)
{
	struct Data data = {42};
	std::cout << "Value before cast: " << data.val << std::endl;
	uintptr_t data_ptr = Serializer::serialize(&data);
	std::cout << "uintptr_t pointer: " << data_ptr << std::endl;
	Data* data2 = Serializer::deserialize(data_ptr);
	std::cout << "Value after cast: " << data2->val << std::endl;
	if (Serializer::deserialize(data_ptr) != &data)
		std::cout << "Error\n";
	return 0;
}
