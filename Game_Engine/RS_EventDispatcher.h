#pragma once

#include "RS_Listener.h"
#include <vector>

class RS_EventDispatcher {
public:
	void AddListener(RS_Listener* listener);
	void RemoveListener(RS_Listener* listener);

protected:
	std::vector<RS_Listener*> listeners;
	virtual void DispatchEvent();
};