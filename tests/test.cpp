#include <catch2/catch_test_macros.hpp>

void get_array_in_bigendianess(uint32_t value, uint8_t *array, size_t size)
{
    if (array == nullptr || size != 4)
        return;

    array[3] = value & 0xFF;
    array[2] = (value >> 8) & 0xFF;
    array[1] = (value >> 16) & 0xFF;
    array[0] = (value >> 24) & 0xFF;
}

TEST_CASE( "First byte in BigEndian array") {
    uint32_t data = 1122334455; // 0x42E576F7
    uint8_t dataArray[4] = { };

    get_array_in_bigendianess(data, dataArray, sizeof(dataArray));

    REQUIRE( dataArray[0] == 0x42 );
}

TEST_CASE( "Value in uint is always reversed indepenced from platform endianness") {
    uint32_t data = 1122334455; // 0x42E576F7
    uint8_t dataArray[4] = { };

    get_array_in_bigendianess(data, dataArray, sizeof(dataArray));

    uint32_t createdUint = dataArray[0] |
                          dataArray[1] << 8 |
                          dataArray[2] << 16 |
                          dataArray[3] << 24; 
    
    REQUIRE( createdUint == 0xF776E542);
}

TEST_CASE( "First byte in memory is not always bigendian (this is platform depended, should fail on bigendian machine)") {
    uint32_t data = 1122334455; // 0x42E576F7
    uint8_t dataArray[4] = { };

    get_array_in_bigendianess(data, dataArray, sizeof(dataArray));

    uint32_t createdUint = dataArray[0] |
                          dataArray[1] << 8 |
                          dataArray[2] << 16 |
                          dataArray[3] << 24; 
    
    uint8_t *memCreateUint = reinterpret_cast<uint8_t *>(&createdUint);  

    REQUIRE( *memCreateUint == 0x42);
}