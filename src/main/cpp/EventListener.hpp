#pragma once

#include "EventGeneric.hpp"

namespace Crisis {
    class EventGeneric;

    class EventListener {
    public:
        EventListener(std::string eventType) {
            this->eventType = eventType;
        }

        virtual std::string type() {
            return eventType;
        }

        template<typename T, typename std::enable_if<std::is_base_of<Crisis::EventGeneric, T>::value>::type* = nullptr>
        T* performTask(T* event) {
        };

    private:
        std::string eventType;
    };
}