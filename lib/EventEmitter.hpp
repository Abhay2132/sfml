#ifndef _EVENT_EMITTER_H_
#define _EVENT_EMITTER_H_

#include <iostream>
#include <functional>
#include <map>
#include <vector>

#include "util.hpp"

class EventEmitter {
public:
    // Subscribe to an event
    void on(const std::string& eventName, const std::function<void()>& callback) {
        eventListeners[eventName].push_back(callback);
    }

    // Emit an event
    void emit(const std::string& eventName) {
        if (eventListeners.find(eventName) != eventListeners.end()) {
            for (const auto& callback : eventListeners[eventName]) {
                callback();
            }
        }
    }

    // Remove a specific callback from an event
    void off(const std::string& eventName, const std::function<void()>& callback) {
        if (eventListeners.find(eventName) != eventListeners.end()) {
            auto& callbacks = eventListeners[eventName];
            // callbacks.erase(std::remove(callbacks.begin(), callbacks.end(), callback), callbacks.end());
            for(int i=0; i<callbacks.size(); i++){
                if(getAddress(callbacks[i]) == getAddress(callback)){
                    callbacks.erase(callbacks.begin() + i);
                    return;
                }
            }
        }
    }

    // Remove all callbacks for an event
    void removeAllListeners(const std::string& eventName) {
        eventListeners.erase(eventName);
    }

private:
    std::map<std::string, std::vector<std::function<void()>>> eventListeners;
};

void hello(){
    std::cout<<"HELLO";
}

#endif