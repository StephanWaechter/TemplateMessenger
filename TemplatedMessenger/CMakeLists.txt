# CMakeList.txt : CMake project for VariantMessageQueue, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library (TemplatedMessenger INTERFACE "Recipient.hpp" "Messenger.hpp")

target_include_directories(TemplatedMessenger INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TemplatedMessenger PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
