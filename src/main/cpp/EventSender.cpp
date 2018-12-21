#include "EventSender.hpp"

template<typename L, typename E>
void Crisis::EventSender::performTask(L listener, E event) {
    listener->performTask(event);
}
