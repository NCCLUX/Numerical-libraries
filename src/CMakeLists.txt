set(READ_MATRIX_SRC_FILES "${CMAKE_SOURCE_DIR}/${SRC_FILES}/read_matrix.c")

add_executable(read_matrix "${READ_MATRIX_SRC_FILES}")

target_include_directories(read_matrix PRIVATE
  "${CMAKE_SOURCE_DIR}/${INCLUDE_FILES}"
)



add_library( matrix-market SHARED IMPORTED )
set_target_properties( matrix-market PROPERTIES
  IMPORTED_LOCATION "$ENV{HOME}/opt/matrix-market/lib/libmatrixmarket.so"
  INTERFACE_INCLUDE_DIRECTORIES "$ENV{HOME}/opt/matrix-market/include"
  POSITION_INDEPENDENT_CODE ON
)

#target_link_directories( read_matrix PRIVATE "$ENV{HOME}/opt/matrix-market/lib")

#find_library( MM NAME matrixmarket 
#  HINTS "$ENV{HOME}/opt/matrix-market/lib/"
#)
#set_target_properties( read_matrix PROPERTIES
#  INCLUDE_DIRECTORIES "$ENV{HOME}/opt/matrix-market/include"
#)

target_link_libraries( read_matrix PRIVATE matrix-market )
