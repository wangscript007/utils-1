#pragma once

#include <mutex>
#include <condition_variable>
#include <atomic>
namespace EduMediaScreen {
  class EduEvent
  {
  public:
	enum WaitResult
	{
	  WAIT_RESULT_SET,
	  WAIT_RESULT_TIMEOUT
	};
	EduEvent(bool initialStatus);
	~EduEvent();

	void Wait();
	EduEvent::WaitResult WaitFor(unsigned int ms);

	void notifyOne();
	void notifyAll();

	void reset();

  private:
	std::mutex m_mutex;
	std::condition_variable m_cv;
	std::atomic_bool m_setState;
  };
}
