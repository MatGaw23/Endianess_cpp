#include <cstdlib>
#include <iomanip>
#include <iostream>

void get_array_in_bigendianess(uint32_t value, uint8_t *array, size_t size)
{
    if (array == nullptr || size != 4)
        return;

    array[3] = value & 0xFF;
    array[2] = (value >> 8) & 0xFF;
    array[1] = (value >> 16) & 0xFF;
    array[0] = (value >> 24) & 0xFF;
}
 
int main(int argc, char *argv[])
{
    uint32_t data = 1122334455; // 0x42E576F7
    uint8_t dataArray[4] = { };

    get_array_in_bigendianess(data, dataArray, sizeof(dataArray));

    std::cout<<"First value of value in bigendian: "<< std::hex << static_cast<int>(dataArray[0]) << std::endl;// should always be 0x42 independed on machine

    uint32_t createUint = dataArray[0] |
                          dataArray[1] << 8 |
                          dataArray[2] << 16 |
                          dataArray[3] << 24; 


    std::cout << "Value: " << std::hex << createUint << std::endl;  // Value always should always be 0xf776e542

    uint8_t *memCreateUint = reinterpret_cast<uint8_t *>(&createUint);
    std::cout << "First byte in memory: "<< std::hex << static_cast<int>(*memCreateUint) << std::endl; // First byte will differ, all depends on platform endianess           
}