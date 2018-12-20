cmake_minimum_required(VERSION 3.13)
project(crisis_src CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(crisis_src
        main/cpp/EventGeneric.hpp

        main/cpp/EventListener.hpp

        main/cpp/EventSender.hpp
        )

set_target_properties(crisis_src PROPERTIES LINKER_LANGUAGE CXX)