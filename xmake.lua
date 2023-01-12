add_requires("libsdl", "fmt")
set_languages("c++17")

target("test-hotas")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("libsdl", "fmt")