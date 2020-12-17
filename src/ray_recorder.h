#ifndef RAY_RECORDER_H
#define RAY_RECORDER_H

#include "include\ray_base.h"
#include "include\iray_recorder.h"

#include "base\ray_macro.h"
#include "base\ray_singleton.h"


namespace ray {
namespace recorder {

class RayRecorder :
	public IRayRecorder,
	public base::Singleton<RayRecorder>
{

private:
	RayRecorder() :_event_handler(nullptr) {}
	~RayRecorder() { release(); }

	SINGLETON_FRIEND(RayRecorder);

public:
	rt_error initialize(const RayRecorderConfiguration& config) override;

	void release() override;

	void setEventHandler(IRayRecorderEventHandler *handler) override;

	rt_error queryInterface(const RECORDER_INTERFACE_IID& iid, void **pp) override;

private:
	DISALLOW_COPY_AND_ASSIGN(RayRecorder);

private:

	IRayRecorderEventHandler *_event_handler;
};
}
}

#endif // !RAY_RECORDER_H