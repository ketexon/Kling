#pragma once

#include <string>
#include <variant>
#include <iostream>
#include <frozen/string.h>
#include <frozen/unordered_map.h>

namespace Kling {
	enum class PhoneType {
		Consonant,
		Vowel,
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

	using VowelQualities = std::variant<
		Monophthong,
		Diphthong,
		Triphthong
	>;

	struct Vowel {
		VowelQualities Qualities;

		constexpr static Vowel FromQualities(auto qualities){
			return Vowel {
				.Qualities = qualities
			};
		}

		constexpr static Vowel Monophthong(VowelQuality quality){
			return Vowel{
				.Qualities = Kling::Monophthong{quality}
			};
		}

		constexpr static Vowel Diphthong(VowelQuality first, VowelQuality second){
			return Vowel{
				.Qualities = Kling::Diphthong{first, second}
			};
		}

		constexpr static Vowel Triphthong(VowelQuality first, VowelQuality second, VowelQuality third){
			return Vowel{
				.Qualities = Kling::Triphthong{first, second, third}
			};
		}
	};

	using PhoneProperties = std::variant<Consonant, Vowel>;

	struct Phone {
		PhoneType Type;
		PhoneProperties Properties;
		std::string Transcription = "";

#pragma region Static Constructors
		constexpr static Phone Vowel(PhoneProperties properties){
			return Phone{
				.Type = PhoneType::Vowel,
				.Properties = properties,
			};
		}

		constexpr static Phone Vowel(Kling::Vowel vowel){
			return Phone{
				.Type = PhoneType::Vowel,
				.Properties = vowel,
			};
		}

		constexpr static Phone Vowel(auto qualities){
			return Phone{
				.Type = PhoneType::Vowel,
				.Properties = Vowel::FromQualities(qualities),
			};
		}

		constexpr static Phone Monophthong(VowelQuality quality){
			return Phone{
				.Type = PhoneType::Vowel,
				.Properties = Vowel::Monophthong(quality),
			};
		}

		constexpr static Phone Diphthong(VowelQuality first, VowelQuality second){
			return Phone{
				.Type = PhoneType::Vowel,
				.Properties = Vowel::Diphthong(first, second),
			};
		}

		constexpr static Phone Triphthong(VowelQuality first, VowelQuality second, VowelQuality third){
			return Phone{
				.Type = PhoneType::Vowel,
				.Properties = Vowel::Triphthong(first, second, third),
			};
		}
#pragma endregion

#pragma region Printing
		constexpr std::string ToString() const {
			using namespace std::string_literals;
			return "["s + std::string{Transcription.data()} + "]"s;
		}

		friend std::ostream& operator<<(std::ostream&, const Phone&);
#pragma endregion
	};
}