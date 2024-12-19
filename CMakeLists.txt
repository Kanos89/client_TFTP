cmake_minimum_required(VERSION 3.30)
project(client_TFTP C)

set(CMAKE_C_STANDARD 11)

add_executable(client_TFTP main.c
        utilities.c
        utilities.h
        main.h
        gettftp.c
        gettftp.h
        puttftp.c
        puttftp.h)
