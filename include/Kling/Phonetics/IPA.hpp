#pragma once

#include <Kling/Phonetics/PhoneBuilder.hpp>

#include <string>
#include <frozen/string.h>
#include <frozen/unordered_map.h>

namespace Kling {
	namespace IPA {
#define KLING_MAKE_IPA_ALIAS(ALIAS, TRANSCRIPTION) \
	inline const std::string ALIAS { #TRANSCRIPTION };
#define KLING_MAKE_IPA_NICK(NICK, ORIGINAL) \
	inline const std::string NICK = ORIGINAL;

		KLING_MAKE_IPA_ALIAS(CFUV, i)
		KLING_MAKE_IPA_ALIAS(CFRV, y)

		KLING_MAKE_IPA_ALIAS(CCUV, ɨ)
		KLING_MAKE_IPA_ALIAS(CCRV, ʉ)

		KLING_MAKE_IPA_ALIAS(CBUV, ɯ)
		KLING_MAKE_IPA_ALIAS(CBRV, u)


		KLING_MAKE_IPA_ALIAS(NcFUV, ɪ)
		KLING_MAKE_IPA_ALIAS(NcFRV, ʏ)

		KLING_MAKE_IPA_ALIAS(NcBRV, ʊ)


		KLING_MAKE_IPA_ALIAS(CmFUV, e)
		KLING_MAKE_IPA_ALIAS(CmFRV, ø)

		KLING_MAKE_IPA_ALIAS(CmCUV, ɘ)
		KLING_MAKE_IPA_ALIAS(CmCRV, ɵ)

		KLING_MAKE_IPA_ALIAS(CmBUV, ɤ)
		KLING_MAKE_IPA_ALIAS(CmBRV, o)


		KLING_MAKE_IPA_ALIAS(MCUV, ə)
		KLING_MAKE_IPA_ALIAS(MCV, ə)
		KLING_MAKE_IPA_NICK(Schwa, MCUV)


		KLING_MAKE_IPA_ALIAS(OmFUV, ɛ)
		KLING_MAKE_IPA_ALIAS(OmFRV, œ)

		KLING_MAKE_IPA_ALIAS(OmCUV, ɜ)
		KLING_MAKE_IPA_ALIAS(OmCRV, ɞ)

		KLING_MAKE_IPA_ALIAS(OmBUV, ʌ)
		KLING_MAKE_IPA_ALIAS(OmBRV, ɔ)


		KLING_MAKE_IPA_ALIAS(NoFUV, æ)

		KLING_MAKE_IPA_ALIAS(NoCUV, ɐ)


		KLING_MAKE_IPA_ALIAS(OFUV, a)
		KLING_MAKE_IPA_ALIAS(OFRV, ɶ)
		
		KLING_MAKE_IPA_ALIAS(OCUV, ä)


		constexpr auto IPAAliasMap = frozen::make_unordered_map<frozen::string, frozen::string>({
			{"I", "ɪ"},
			{"i=", "ɪ"},
		});

		constexpr auto IPAToXSAMPA = frozen::make_unordered_map<frozen::string, frozen::string>({
			{"ɨ", "1"},
			{"ʉ", "}"},
			{"ɯ", "M"},

			{"ɪ", "I"},
			{"ʏ", "Y"},
		});
	}

#define KLING_PHONETICS_MAKE_ORAL_VOWEL(HEIGHT, BACKNESS, ROUNDEDNESS, TRANSCRIPTION) \
	inline const Phone HEIGHT##BACKN/ESS##ROUNDEDNESS##Vowel = \
		PhoneBuilder() \
		.Monophthong({ \
			.Height = VowelHeight::HEIGHT, \
			.Backness = VowelBackness::BACKNESS, \
			.Roundedness = VowelRoundedness::ROUNDEDNESS, \
		}) \
		.WithTranscription(#TRANSCRIPTION) \
		.Build(); \

#pragma region Close vowels
	KLING_PHONETICS_MAKE_ORAL_VOWEL(Close, Front, Unrounded, IPA::CFUV)
	KLING_PHONETICS_MAKE_ORAL_VOWEL(Close, Front, Rounded, IPA::CFRV)

	KLING_PHONETICS_MAKE_ORAL_VOWEL(Close, Central, Unrounded, IPA::CCUV)
	KLING_PHONETICS_MAKE_ORAL_VOWEL(Close, Central, Rounded, IPA::CCRV)

	KLING_PHONETICS_MAKE_ORAL_VOWEL(Close, Back, Unrounded, IPA::CBUV)
	KLING_PHONETICS_MAKE_ORAL_VOWEL(Close, Back, Rounded, IPA::CBRV)
#pragma endregion
#pragma region Near Close vowels
	KLING_PHONETICS_MAKE_ORAL_VOWEL(NearClose, Front, Unrounded, ɪ)
	KLING_PHONETICS_MAKE_ORAL_VOWEL(NearClose, Front, Rounded, ʏ)

	KLING_PHONETICS_MAKE_ORAL_VOWEL(NearClose, Back, Rounded, ʊ)
#pragma endregion
}