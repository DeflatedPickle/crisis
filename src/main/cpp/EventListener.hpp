#pragma once

#include "EventGeneric.hpp"

namespace Crisis {
    class EventListener {
    public:
        EventListener(std::string eventType) {
            this->eventType = eventType;
        }

        virtual Crisis::EventGeneric performTask() = 0;

        virtual std::string type() {
            return eventType;
        }

    private:
        std::string eventType;
    };
}