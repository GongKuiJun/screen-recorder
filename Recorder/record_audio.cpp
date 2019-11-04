#include "record_audio.h"

namespace am {
	record_audio::record_audio()
	{
		_running = false;
		_inited = false;

		_sample_rate = 48000;
		_bit_rate = 3072000;
		_channel_num = 2;
		_bit_per_sample = _bit_rate / _sample_rate / _channel_num;
		_fmt = AF_AUDIO_FLT;
		_on_data = nullptr;
		_on_error = nullptr;

		_device_name = "";
	}

	record_audio::~record_audio()
	{

	}
}