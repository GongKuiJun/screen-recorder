#pragma once

namespace ray {
namespace recorder {

class IAudioDeviceCollection {
protected:
	virtual ~IAudioDeviceCollection() {};
};

class IAudioDeviceManager {
protected:
	virtual ~IAudioDeviceManager() {};
};

} // namespace recorder
} // namespace ray