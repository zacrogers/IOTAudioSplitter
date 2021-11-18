#include "main.hh"


FM62429 vol_outputs[num_channels] = {
	FM62429(0,0),
	FM62429(0,0),
	FM62429(0,0),
	FM62429(0,0)
};

const char *topic[] = {
	"splitter/vol/1",
	"splitter/vol/2",
	"splitter/vol/3",
	"splitter/vol/4"
};

std::uint8_t vols[num_channels] = {vol_outputs[0].max_atten};

void setup() 
{
}

void loop() 
{
  // put your main code here, to run repeatedly:
}

void set_vol_all()
{
	for(auto output : vol_outputs)
	{
		output.set_volume(0, FM62429::Channel::Both);
	}
}