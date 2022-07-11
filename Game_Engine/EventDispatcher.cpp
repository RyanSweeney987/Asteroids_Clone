#include "RS_EventDispatcher.h"

void RS_EventDispatcher::AddListener(RS_Listener* listener)
{
	listeners.push_back(listener);
	listener->eventValue = listeners.size();
}

void RS_EventDispatcher::RemoveListener(RS_Listener* listener)
{
	int index = -1;
	for (int i = 0; i < listeners.size(); i++) {
		if (listeners[i]->eventValue == listener->eventValue) {
			index = i;
			break;
		}
	}

	listeners.erase(listeners.begin() + index);
}

void RS_EventDispatcher::DispatchEvent()
{
	for (std::vector<RS_Listener*>::iterator l = listeners.begin(); l != listeners.end(); ++l)
	{
		(*l)->HandleEvent();
	}
}
