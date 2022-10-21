set(KLING_INCLUDE_DIRECTORY "${PROJECT_SOURCE_DIR}/include/Kling")
set(
	KLING_SOURCE_FILES

	Src2.cpp

	Kling.hpp
		Phonetics.hpp
		Phonetics.cpp
			Phonetics/IPA.hpp
			Phonetics/Phone.hpp
			Phonetics/PhoneBuilder.hpp
)

# prepend the inclue directory to all HPP files
list(
	TRANSFORM
	KLING_SOURCE_FILES
	PREPEND
	${KLING_INCLUDE_DIRECTORY}/
	REGEX 
	.*\.hpp
)

add_library(
	Kling
	STATIC
	${KLING_SOURCE_FILES}
)

target_include_directories(
	Kling
	PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
	Kling
	PUBLIC frozen
)