# once done this will define
# CATCH_FOUND
# CATCH_INCLUDE_DIR

find_path(CATCH_INCLUDE_DIR NAMES catch.hpp
    HINTS
    "${CATCH_ROOT}/include")
    
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(UnitTest++ DEFAULT_MSG UNITTEST++_INCLUDE_DIRS)