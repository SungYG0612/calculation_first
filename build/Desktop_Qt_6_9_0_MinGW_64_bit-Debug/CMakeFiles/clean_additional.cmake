# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\lcd_first_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\lcd_first_autogen.dir\\ParseCache.txt"
  "lcd_first_autogen"
  )
endif()
