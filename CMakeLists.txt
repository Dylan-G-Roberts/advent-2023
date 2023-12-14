cmake_minimum_required(VERSION 3.27)
project(advent_2023 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(c-lang)
include_directories(c-lang/ds)
include_directories(days)

add_executable(advent_2023
        c-lang/ds/list.c
        c-lang/samplemain.c
        c-lang/ds/simplestack.c
        c-lang/atoi.c
        c-lang/helloworld.c
        c-lang/pointer_args.c
        c-lang/pointerplay.c
        c-lang/sqeeze.c
        c-lang/tempCodeRunnerFile.c
        days/day10.c
        days/day3.c
        days/day4.c
        days/day6.c
        days/day6part2.c
        days/day8.c
        days/day_1.c
        days/day_1_part_2.c
        days/day_2.c
        days/day_2_part2.c)
