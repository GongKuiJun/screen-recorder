#pragma once

#include "ray_base.h"

namespace ray {
namespace recorder {

class IVideoFrame;
class IAudioFrame;

/**
* Recorder event handler
*/
class IRayRecorderEventHandler {
public:
	virtual ~IRayRecorderEventHandler() {};

	/**
	* Muxe duration callback function
	* @param duration
	*/
	virtual void onDuration(uint64_t duration) {}

	/*
	* Error code callback function
	* @param code error code
	* @param reason error reason
	*/
	virtual void onError(ErrorCode code, ErrorReason reason) {}

	/**
	* Device change callback function
	* @param isAudio audio or video device
	*/
	virtual void onDeviceChanged(bool isAudio) {}

	/**
	* Raw video data callback function
	* @param frame video frame
	*/
	virtual void onRawVideoData(IVideoFrame &frame) {}

	/**
	* Raw audio data callback function
	* @param frame audio frame
	*/
	virtual void onRawAudioData(IAudioFrame &frame) {}

	/**
	* Audio volume callback function
	* @param uid    specified audio source
	* @param volume
	*/
	virtual void onAudioVolume(const rt_uid uid, int volume) {}
};

/**
* Define all interfaces of Recorder
*/
class IRayRecorder {
protected:
	virtual ~IRayRecorder() {};

public:
	
	struct RayRecorderConfiguration {
		const char *logPath = nullptr;
	};

	enum RECORDER_INTERFACE_IID {
		RECORDER_IID_UNKNOWN = 0,

		RECORDER_IID_VIDEO_DEVICE_MGR,
		RECORDER_IID_VIDEO_SOURCE_MGR,
		RECORDER_IID_VIDEO_ENCODER_MGR,

		RECORDER_IID_AUDIO_DEVICE_MGR,
		RECORDER_IID_AUDIO_SOURCE_MGR,
		RECORDER_IID_AUDIO_ENCODER_MGR,

		RECORDER_IID_MUXER,
	};

	/**
	* Initialize recorder with configuration
	* @param config    configuration
	* @return          0 for success, other for error code
	*/
	virtual rt_error initialize(const RayRecorderConfiguration& config) = 0;

	/**
	* Release recorder
	* This will stop all tasks include capturing, encoding, muxing and remuxing
	*/
	virtual void release() = 0;

	/**
	* Set recorder event handler
	* @param handler
	*/
	virtual void setEventHandler(IRayRecorderEventHandler *handler) = 0;

	/**
	* Query interface by iid
	* @param iid         Interface IID
	* @param interface   A pointer pointed to interface's pointer,
	*					 nullptr will be set when get error, otherwise none-nullptr value will be set
	* @return            0 for success, other for error code
	*/
	virtual rt_error queryInterface(const RECORDER_INTERFACE_IID& iid, void **pp) = 0;
};

} // namespace recorder
} // namespace ray

/**
* Create a ray::recorder::IRecorder object and return its pointer
* @return A non-nullptr pointer on success, nullptr on failure
*/
RAY_API ray::recorder::IRayRecorder* RAY_CALL createRecorder();

