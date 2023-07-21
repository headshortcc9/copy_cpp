# Clip Library
# Copyright (c) 2015-2021 David Capello

cmake_minimum_required(VERSION 3.1.2)

project(clip_custom LANGUAGES CXX)


set(CLIP_SOURCES clip_custom/clip.cpp)
  # include(CheckIncludeFiles)
  # check_include_files(xcb/xcb.h HAVE_XCB_XLIB_H)

if(HAVE_XCB_XLIB_H)
    add_definitions(-DHAVE_XCB_XLIB_H)

    list(APPEND CLIP_SOURCES clip_custom/clip_x11.cpp)

endif()

add_library(clip ${CLIP_SOURCES})

if(HAVE_XCB_XLIB_H)
    target_link_libraries(clip xcb pthread)
endif()


add_executable(copy copy.cpp)
target_link_libraries(copy clip)
target_include_directories(copy PUBLIC clip_custom)
