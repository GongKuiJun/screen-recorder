#include "ray_recorder.h"
#include "ray_remuxer.h"

#include "utils\ray_string.h"
#include "utils\ray_log.h"

namespace ray {
namespace recorder {

using namespace base;

rt_error RayRecorder::initialize(const RayRecorderConfiguration& config) {

	utils::InitLogImpl(config.logPath ? utils::strings::utf8_unicode(config.logPath).c_str() : nullptr);

	return ERR_NO;
}

void RayRecorder::release() {

}

void RayRecorder::setEventHandler(IRayRecorderEventHandler *handler) {
	_event_handler = handler;
}

rt_error RayRecorder::queryInterface(const RECORDER_INTERFACE_IID& iid, void **pp) {
	rt_error ret = ERR_NO;

	do {
		if (!pp) {
			ret = ERROR_INVALID_PARAMETER;
			break;
		}

		*pp = nullptr;

		switch (iid)
		{
			case RECORDER_IID_VIDEO_SOURCE_MGR:
				*pp = static_cast<void*>(remuxer::Remuxer::getInstance());
			break;
		default:
			ret = ERR_UNSUPPORT;
			break;
		}

	} while (0);

	return ret;
}

}
}