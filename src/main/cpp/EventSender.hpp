#pragma once

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <typeinfo>
#include "EventGeneric.hpp"
#include "EventListener.hpp"

namespace Crisis {
    // Partial Credit: https://www.dreamincode.net/forums/topic/197421-the-listener-pattern/
    class EventSender {
    public:
        EventSender() = default;

        bool addListener(Crisis::EventListener *eventListener) {
            std::vector<Crisis::EventListener *>::iterator temp = find(
                    this->listenerVector[eventListener->type()].begin(),
                    this->listenerVector[eventListener->type()].end(),
                    eventListener);

            if (temp != this->listenerVector[eventListener->type()].end()) {
                return false;
            }

            this->listenerVector[eventListener->type()].push_back(eventListener);
            return true;
        }

        bool removeListener(Crisis::EventListener *eventListener) {
            std::vector<Crisis::EventListener *>::iterator temp = find(
                    this->listenerVector[eventListener->type()].begin(),
                    this->listenerVector[eventListener->type()].end(),
                    eventListener);

            if (temp == this->listenerVector[eventListener->type()].end()) {
                return false;
            }

            this->listenerVector[eventListener->type()].erase(
                    remove(this->listenerVector[eventListener->type()].begin(),
                           this->listenerVector[eventListener->type()].end(), eventListener));
            return true;
        }

        // Credit: https://stackoverflow.com/a/30687399
        template<typename T, typename std::enable_if<std::is_base_of<Crisis::EventGeneric, T>::value>::type* = nullptr>
        bool sendEvent(T *event) {
            for (auto listener : this->listenerVector[event->type()]) {
                auto _listener = reinterpret_cast<typeof(event->listenerType)> (listener);

                // _listener->performTask(event);
                this->performTask(_listener, event);
            }

            return !this->listenerVector.empty();
        }

    private:
        template<typename L, typename E>
        void performTask(L listener, E event);

        std::map<std::string, std::vector<Crisis::EventListener *>> listenerVector;
    };
}