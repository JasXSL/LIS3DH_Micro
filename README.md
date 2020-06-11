# LIS3DH_Micro
A minimal fork of Adafruit LIS3DH that can run on an ATTINY402

This is an extremely minimal library based on the [Adafruit LIS3DH library](https://github.com/adafruit/Adafruit_LIS3DH).

It's just a header file. If you want to change defaults you can do that in an #include above the library include.


# Pros:

* ~80% less memory used
* Can use on an attiny402 with 4KB flash or higher.

# Cons:

* Only supports I2C
* Is just a header file with a namespace. You can only run one accelerometer.
* Doesn't have ADC support
* Doesn't use floats. Instead, LIS3DH_Lite::x/y/z are int32_t with the acceleration in G-force measured in 1000ths. This is because floats are memory intensive on these devices.
* Datarate and sensor range can only be defined at compile time.

# Usage

See examples.

