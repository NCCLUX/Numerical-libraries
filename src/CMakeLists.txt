###
# Add external libraries

set( LOCAL_OPT_DIR "$ENV{HOME}/.local" )

add_library( matrix-market SHARED IMPORTED )
set_target_properties( matrix-market PROPERTIES
  IMPORTED_LOCATION "${LOCAL_OPT_DIR}/matrix-market/lib/libmatrixmarket.so"
  INTERFACE_INCLUDE_DIRECTORIES "${LOCAL_OPT_DIR}/matrix-market/include"
  POSITION_INDEPENDENT_CODE ON
)

add_library( blas SHARED IMPORTED )
set_target_properties( blas PROPERTIES
  IMPORTED_LOCATION "${LOCAL_OPT_DIR}/netlib/lib/libblas.so"
  INTERFACE_INCLUDE_DIRECTORIES "${LOCAL_OPT_DIR}/netlib/include"
  POSITION_INDEPENDENT_CODE ON
)
add_library( cblas SHARED IMPORTED )
set_target_properties( cblas PROPERTIES
  IMPORTED_LOCATION "${LOCAL_OPT_DIR}/netlib/lib/libcblas.so"
  INTERFACE_INCLUDE_DIRECTORIES "${LOCAL_OPT_DIR}/netlib/include"
  POSITION_INDEPENDENT_CODE ON
)

###
# Create utility library

set(UTILS_SRC_FILES "${CMAKE_SOURCE_DIR}/${SRC_FILES}/utils.c")
add_library(utils STATIC "${UTILS_SRC_FILES}")
target_link_libraries( utils PRIVATE m )

###
# Create example executables

set( 00_EXAMPLE_SRC_FILES "${CMAKE_SOURCE_DIR}/${SRC_FILES}/00_example_ddot.c")
add_executable(00_example_ddot "${00_EXAMPLE_SRC_FILES}")
target_include_directories(00_example_ddot PRIVATE
  "${CMAKE_SOURCE_DIR}/${INCLUDE_FILES}"
)
target_link_libraries( 00_example_ddot PRIVATE utils cblas blas )

set(READ_MATRIX_SRC_FILES "${CMAKE_SOURCE_DIR}/${SRC_FILES}/read_matrix.c")
add_executable(read_matrix "${READ_MATRIX_SRC_FILES}")
target_include_directories(read_matrix PRIVATE
  "${CMAKE_SOURCE_DIR}/${INCLUDE_FILES}"
)
target_link_libraries( read_matrix PRIVATE matrix-market )

set(READ_AND_EXECUTE_SRC_FILES
  "${CMAKE_SOURCE_DIR}/${SRC_FILES}/read_and_execute.c"
)
add_executable(read_and_execute "${READ_AND_EXECUTE_SRC_FILES}")
target_include_directories(read_and_execute PRIVATE
  "${CMAKE_SOURCE_DIR}/${INCLUDE_FILES}"
)
target_link_libraries( read_and_execute PRIVATE matrix-market utils cblas blas )

set(EXAMPLE_EXECUTE_SRC_FILES
  "${CMAKE_SOURCE_DIR}/${SRC_FILES}/example_execute.c"
)
add_executable(example_execute "${EXAMPLE_EXECUTE_SRC_FILES}")
target_include_directories(example_execute PRIVATE
  "${CMAKE_SOURCE_DIR}/${INCLUDE_FILES}"
)
target_link_libraries( example_execute PRIVATE cblas blas utils )

##target_link_directories( read_matrix PRIVATE "$ENV{HOME}/opt/matrix-market/lib")
#find_library( MM NAME matrixmarket 
#  HINTS "$ENV{HOME}/opt/matrix-market/lib/"
#)
#set_target_properties( read_matrix PROPERTIES
#  INCLUDE_DIRECTORIES "$ENV{HOME}/opt/matrix-market/include"
#)
