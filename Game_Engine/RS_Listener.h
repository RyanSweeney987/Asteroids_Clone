#pragma once

class RS_Listener {
public:
	int eventValue;
	virtual void HandleEvent();
	virtual void HandleEvent(int id);
};