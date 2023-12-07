#define EEPROM_TEMP_LIMIT_ADDRESS 0x00 // EEPROM address to store temperature limit
const void* temperatureLimitPtr = (const void*)&temperatureLimit;
eeprom_write_block(temperatureLimitPtr, (void*)EEPROM_TEMP_LIMIT_ADDRESS, sizeof(float));
eeprom_write_block(temperatureLimitPtr, (void*)EEPROM_TEMP_LIMIT_ADDRESS, sizeof(float));
