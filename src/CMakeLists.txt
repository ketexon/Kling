add_executable(
	PhonemicAnalyzer
	main.cpp
	Phone.hpp
)

target_link_libraries(
	PhonemicAnalyzer
	PRIVATE frozen
)