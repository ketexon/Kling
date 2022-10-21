add_executable(
    KlingTests
    PhoneTests.cpp
)

target_link_libraries(
    KlingTests
    PRIVATE Catch2::Catch2WithMain
    PRIVATE Kling
)

catch_discover_tests(KlingTests)