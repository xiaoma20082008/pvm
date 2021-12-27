set(SRCS
        code/codeObject.cc code/codeObject.hh code/binaryFileParser.cc code/binaryFileParser.hh
        memory/heap.cc memory/heap.hh
        object/klass.cc object/klass.hh object/pyDict.cc object/pyDict.hh object/pyFloat.cc object/pyFloat.hh object/pyFunc.cc object/pyFunc.hh object/pyInt.cc object/pyInt.hh object/pyList.cc object/pyList.hh object/pyObject.cc object/pyObject.hh object/pyString.cc object/pyString.hh object/pyType.cc object/pyType.hh
        runtime/frameObject.cc runtime/frameObject.hh runtime/universe.cc runtime/universe.hh runtime/interpreter.cc runtime/interpreter.hh
        utils/arrayList.cc utils/arrayList.hh utils/bufferedInputStream.cc utils/bufferedInputStream.hh utils/map.cc utils/map.hh utils/map.cc utils/map.hh utils/slice.cc utils/slice.hh)
add_library(pvm SHARED ${SRCS})

if (UNIX)
    set_property(TARGET pvm PROPERTY PREFIX "lib")
    set_property(TARGET pvm PROPERTY OUTPUT_NAME "pvm.so")
    set_property(TARGET pvm PROPERTY SUFFIX "")
    set_property(TARGET pvm PROPERTY SOVERSION "${CMAKE_PROJECT_VERSION}")
elseif (WIN32)
    set_property(TARGET pvm PROPERTY PREFIX "lib")
    set_property(TARGET pvm PROPERTY OUTPUT_NAME "pvm.dll")
    set_property(TARGET pvm PROPERTY SUFFIX "")
    set_property(TARGET pvm PROPERTY SOVERSION "${CMAKE_PROJECT_VERSION}")
endif ()

target_include_directories(pvm PRIVATE .)
target_link_directories(pvm PRIVATE .)

add_executable(python main.cc)
target_link_libraries(python pvm)
target_include_directories(python PRIVATE .)
target_link_directories(python PRIVATE .)
