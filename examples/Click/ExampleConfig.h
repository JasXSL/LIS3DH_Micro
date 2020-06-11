#ifndef __lis3dh_config
#define __lis3dh_config

// G range to measure
#define LIS3DH_RANGE_16_G 0b11 // +/- 16g
#define LIS3DH_RANGE_8_G 0b10  // +/- 8g
#define LIS3DH_RANGE_4_G 0b01  // +/- 4g
#define LIS3DH_RANGE_2_G 0b00   // +/- 2g (default value)

// Datarate to use
#define LIS3DH_DATARATE_400_HZ 0b0111 //  400Hz
#define LIS3DH_DATARATE_200_HZ 0b0110 //  200Hz
#define LIS3DH_DATARATE_100_HZ 0b0101 //  100Hz
#define LIS3DH_DATARATE_50_HZ 0b0100  //   50Hz
#define LIS3DH_DATARATE_25_HZ 0b0011  //   25Hz
#define LIS3DH_DATARATE_10_HZ 0b0010  // 10 Hz
#define LIS3DH_DATARATE_1_HZ 0b0001   // 1 Hz
#define LIS3DH_DATARATE_POWERDOWN 0
#define LIS3DH_DATARATE_LOWPOWER_1K6HZ 0b1000
#define LIS3DH_DATARATE_LOWPOWER_5KHZ 0b1001

// Divider to calculate Gs represented as 1/1000th G. Should match whatever you set G range to.
#define DIVIDER_16_G 1365
#define DIVIDER_8_G 4096
#define DIVIDER_4_G 8190
#define DIVIDER_2_G 16380

/*

	You can override the defaults here if you want.

*/
#define SENSOR_RANGE LIS3DH_RANGE_2_G 		// 2G
#define SENSOR_DIVIDER DIVIDER_2_G			// 2G - Needs to match the Gs you set as SENSOR_RANGE above
#define SENSOR_RATE LIS3DH_DATARATE_LOWPOWER_1K6HZ		// 1k6hz datarate


#endif
