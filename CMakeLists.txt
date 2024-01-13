cmake_minimum_required(VERSION 3.5)
project(YourAllegroProject)

set(ALLEGRO_DIR "D:/AllegroLib_5.2.8/AllegroLib_5.2.8")

include_directories(${ALLEGRO_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

find_library(ALLEGRO_LIBRARY allegro PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_PRIMITIVES_LIBRARY allegro_primitives PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_IMAGE_LIBRARY allegro_image PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_AUDIO_LIBRARY allegro_audio PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_ACODEC_LIBRARY allegro_acodec PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_FONT_LIBRARY allegro_font PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_TTF_LIBRARY allegro_ttf PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_DIALOG_LIBRARY allegro_dialog PATHS ${ALLEGRO_DIR}/lib)

file(GLOB SOURCE_FILES "src/*.c")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(2048 ${SOURCE_FILES})

target_link_libraries(2048
                      ${ALLEGRO_LIBRARY} 
                      ${ALLEGRO_PRIMITIVES_LIBRARY} 
                      ${ALLEGRO_IMAGE_LIBRARY} 
                      ${ALLEGRO_AUDIO_LIBRARY} 
                      ${ALLEGRO_ACODEC_LIBRARY} 
                      ${ALLEGRO_FONT_LIBRARY} 
                      ${ALLEGRO_TTF_LIBRARY} 
                      ${ALLEGRO_DIALOG_LIBRARY})

