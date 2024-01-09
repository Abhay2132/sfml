#ifndef _EVENT_EMITTER_H_
#define _EVENT_EMITTER_H_

#include <iostream>
#include <functional>
#include <map>
#include <vector>

namespace _ee_
{
    template <typename T, typename... U>
    size_t getAddress(std::function<T(U...)> f)
    {
        typedef T(fnType)(U...);
        fnType **fnPointer = f.template target<fnType *>();
        return (size_t)*fnPointer;
    };
}

class EventListener
{
public:
    // Subscribe to an event
    void on(const std::string &eventName, const std::function<void()> &callback)
    {
        eventListeners[eventName].push_back(callback);
    }


    // Remove a specific callback from an event
    void off(const std::string &eventName, const std::function<void()> &callback)
    {
        if (eventListeners.find(eventName) != eventListeners.end())
        {
            auto &callbacks = eventListeners[eventName];
            callbacks.erase(std::remove_if(callbacks.begin(), callbacks.end(), [callback](const auto &cb)
                                           { return _ee_::getAddress(cb) == _ee_::getAddress(callback); }),
                            callbacks.end());
        }
    }

    // Remove all callbacks for an event
    void removeAllListeners(const std::string &eventName)
    {
        eventListeners.erase(eventName);
    }

protected:
    // Emit an event
    void emit(const std::string &eventName)
    {
        if (eventListeners.find(eventName) != eventListeners.end())
        {
            for (const auto &callback : eventListeners[eventName])
            {
                callback();
            }
        }
    }

private:
        std::map<std::string, std::vector<std::function<void()>>> eventListeners;

};

class EventEmitter : public EventListener{
    public:
        void emit(const std::string &eventName){
            EventListener::emit(eventName);
        }
};

void hello()
{
    std::cout << "HELLO";
}

#endif