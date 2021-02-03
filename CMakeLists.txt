cmake_minimum_required(VERSION 3.17)
project(WordBook_Vol2 C)

set(CMAKE_C_STANDARD 99)

add_executable(WordBook_Vol2 src/main/c/com/aquarius0715/wordbook/Main.c src/main/c/com/aquarius0715/wordbook/Data.h src/main/c/com/aquarius0715/wordbook/Util.h src/main/c/com/aquarius0715/wordbook/Command.h src/main/c/com/aquarius0715/wordbook/System.h src/main/c/com/aquarius0715/wordbook/File.h)