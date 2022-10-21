#pragma once

#include <Kling/Phonetics/Phone.hpp>
#include <frozen/string.h>

namespace Kling {
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
			phone.Transcription = std::string{transcription.data()};
			return *this;
		}

		constexpr Phone Build() {
			return phone;
		}
	};
}