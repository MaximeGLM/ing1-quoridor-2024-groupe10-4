cmake_minimum_required(VERSION 3.29)
project(ing1_quoridor_2024_groupe10_4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ing1_quoridor_2024_groupe10_4
    main.c
        sousprogramme.h
        PartieGraphique.c
        Barrieres.c
        MenuPrincipal.c
        Deplacements.c
        DeroulementPartie.c
        MenuPause.c)
