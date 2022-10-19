#pragma once

#include "IPA.hpp"

#include <string>
#include <variant>
#include <array>
#include <frozen/string.h>
#include <frozen/unordered_map.h>

namespace Ket {
	enum class PhoneType {
		Consonant,
		Vowel,
		Diphthong,

	};

	struct Consonant {

	};

	enum class VowelHeight {
		Close, High = Close,
		NearClose, NearHigh = NearClose,
		CloseMid, HighMid = CloseMid,
		Mid,
		OpenMid, LowMid = OpenMid,
		NearOpen, NearLow = NearOpen,
		Open, Low = Open,
	};

	enum class VowelBackness {
		Front,
		Central,
		Back
	};

	enum class VowelRoundedness {
		None = -1,
		Unrounded = 0,
		Rounded
	};

	enum class VowelNasalization {
		Oral,
		Nasal,
	};

	enum class VowelTenseness {
		None = -1,
		Lax = 0,
		Tense
	};

	struct VowelQuality {
		VowelHeight Height;
		VowelBackness Backness;
		VowelRoundedness Roundedness;
		VowelNasalization Nasalization = VowelNasalization::Oral;
	};

	struct Monophthong {
		VowelQuality First;
	};

	struct Diphthong {
		VowelQuality First;
		VowelQuality Second;
	};

	struct Triphthong {
		VowelQuality First;
		VowelQuality Second;
		VowelQuality Third;
	};

	struct Vowel {
		std::variant<
			Monophthong,
			Diphthong,
			Triphthong
		> Qualities;

		constexpr static Vowel Monophthong(VowelQuality quality){
			return Vowel{
				.Qualities = Ket::Monophthong{quality}
			};
		}
	};

	struct Phone {
		PhoneType Type;
		std::variant<Consonant, Vowel> Properties;
		frozen::string Transcription = "";

		constexpr static Phone Monophthong(VowelQuality quality){
			return Phone{
				.Type = PhoneType::Vowel,
				.Properties = Vowel::Monophthong(quality),
			};
		}
	};

	class PhoneBuilder {
private:
		Phone phone;

public:
		constexpr PhoneBuilder() : phone{} {
		}

		constexpr PhoneBuilder& Monophthong(VowelQuality quality){
			phone = Phone::Monophthong(quality);
			return *this;
		}

		constexpr PhoneBuilder& WithTranscription(frozen::string transcription){
			phone.Transcription = transcription;
			return *this;
		}

		constexpr Phone Build(){
			return phone;
		}
	};

#define KET_PHONE_MAKE_ORAL_VOWEL(HEIGHT, BACKNESS, ROUNDEDNESS, TRANSCRIPTION) \
	constexpr Phone height##backness##roundedness##Vowel = \
		PhoneBuilder() \
		.Monophthong({ \
			.Height = VowelHeight::HEIGHT, \
			.Backness = VowelBackness::BACKNESS, \
			.Roundedness = VowelRoundedness::ROUNDEDNESS, \
		}) \
		.WithTranscription(#TRANSCRIPTION) \
		.Build(); \

	KET_PHONE_MAKE_ORAL_VOWEL(Close, Front, Unrounded, i)
	KET_PHONE_MAKE_ORAL_VOWEL(NearClose, Front, Unrounded, ɪ)

	constexpr Phone FrontCloseUnroundedVowel =
		PhoneBuilder()
		.Monophthong({
			.Height = VowelHeight::Close,
			.Backness = VowelBackness::Front,
			.Roundedness = VowelRoundedness::Unrounded,
		})
		.WithTranscription("i")
		.Build();

	constexpr Phone FrontNearCloseUnroundedVowel =
		PhoneBuilder()
		.Monophthong({
			.Height = VowelHeight::NearClose,
			.Backness = VowelBackness::Front,
			.Roundedness = VowelRoundedness::Unrounded,
		})
		.WithTranscription("i")
		.Build();

	// namespace IPA {
	// 	constexpr auto IPAToPhoneMap = frozen::make_unordered_map<frozen::string, Phone>({
	// 		{"i", FrontCloseUnroundedVowel},
	// 		{"ɪ", FrontNearCloseUnroundedVowel},
	// 	});
	// }


	// constexpr Phone StringToPhone(frozen::string string){
	// 	using namespace IPA;
	// 	if(IPAAliasMap.find(string) != IPAAliasMap.end()){
	// 		return IPAToPhoneMap.at(IPAAliasMap.at(string));
	// 	}
	// 	else{
	// 		return IPAToPhoneMap.at(string);
	// 	}
	// }
}