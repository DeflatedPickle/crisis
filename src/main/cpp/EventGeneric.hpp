#pragma once

#include "EventListener.hpp"

namespace Crisis {
    class EventGeneric {
    public:
        static std::string type() {
            return "generic";
        }

        typeof(Crisis::EventListener*) listenerType;
    };
}