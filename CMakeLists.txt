cmake_minimum_required(VERSION 3.27)
project(ProjektAIZO2)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjektAIZO2 main.cpp
        Data.h
        Data.cpp
        MacierzInc.h
        MacierzInc.cpp
        ListaKraw.h
        ListaKraw.cpp
        InitTab.h
        InitTab.cpp
        WczytTab.h
        WczytTab.cpp
        Kruskal.h
        Kruskal.cpp
        Prima.h
        Prima.cpp
        Dijkstra.h
        Dijkstra.cpp
        BellmanFord.h
        BellmanFord.cpp
        Menu.h
        Menu.cpp)
