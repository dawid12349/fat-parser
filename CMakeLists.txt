#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2020-12-12 15:28:38.434419
#

cmake_minimum_required(VERSION 3.17)
project(project1 C)

# Przyjmij standard C11
set(CMAKE_C_STANDARD 11)

# Ustaw opcje kompilatora (z raportu Dante)
add_compile_options(
      "-pedantic"
      "-ggdb3"
      "-Wextra"
      "-fdiagnostics-color"
      "-fmax-errors=5"
      "-Wno-error=implicit-fallthrough"
      "-Wno-error=parentheses"
      "-D_GNU_SOURCE"
      "-DINSIDE_DANTE"
      "-Wno-error=unused-parameter"
      "-std=c11"
      "-Wall"
      "-Wno-parentheses"
      "-D_ANSI_OUTPUT"
      "-xc"
      "-Werror"
      "-Werror=vla"

)

# Ustaw opcje konsolidatora (z raportu Dante)
add_link_options(
        "-Wl,-Map=main.map"
        "-ggdb3"
        "-Wl,-cref"
        "-Wl,-wrap,main"
)

# Utwórz target 'project1' i dodaj do niego pliki źródlowe:
add_executable(project1
        "main.c"
        "file_reader.c"
        "unit_helper_v2.c"
        "unit_test_v2.c"
        "rdebug.c"
)

# Dołącz niezbędne biblioteki
target_link_libraries(project1
        "m"
)