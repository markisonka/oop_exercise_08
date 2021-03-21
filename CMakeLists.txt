project(oop_exercise_08)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(oop_exercise_08 main.cpp
        Publisher.cpp Publisher.h
        Processor.h
        Processors/FileProcessor.cpp Processors/FileProcessor.h
        Processors/ConsoleProcessor.cpp Processors/ConsoleProcessor.h
        Figure.cpp Figure.h
        FigureFactory.cpp FigureFactory.h
        Figures/Pentagon.cpp Figures/Pentagon.h
        Figures/Trapeze.cpp Figures/Trapeze.h
        Figures/Rhombus.cpp Figures/Rhombus.h)