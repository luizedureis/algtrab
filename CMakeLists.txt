cmake_minimum_required(VERSION 3.23)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        utils.c
        readProcess.c
        mangaSecundaryIndexManege.c
        mangaPrimaryIndexManage.c
        mangaDataFileManage.c)
