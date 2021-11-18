#pragma once

#include <Arduino.h>
#include <cstdint>

class FM62429
{
private:
    const std::uint8_t num_bits = 11;
    std::uint8_t _data_pin, _clock_pin;

public:
    enum class Channel
    {
        Both = 0,
        Ch1,
        Ch2
    };

    const std::uint8_t min_atten = 0;
    const std::uint8_t max_atten = 83;

    FM62429(std::uint8_t data_pin, std::uint8_t clock_pin) 
        :_data_pin(data_pin), _clock_pin(clock_pin){}
    ~FM62429();
    void set_volume(std::uint8_t atten, Channel chan);
};



FM62429::~FM62429()
{
}


void FM62429::set_volume(std::uint8_t atten, Channel chan)
{
    std::uint16_t data = 0x00;

    switch (chan)
    {
    case Channel::Both:
        data &= ~0x02;
        break;
    case Channel::Ch1:
        data |= 0x02;
        break;
    case Channel::Ch2:
        data |= 0x03;
        break;
    }

    digitalWrite(_data_pin, 0);
    digitalWrite(_clock_pin, 0);

    for(std::uint8_t bit = 0; bit < num_bits; ++bit)
    {
        digitalWrite(_clock_pin, 0);

        digitalWrite(_clock_pin, 1);
    }

}
