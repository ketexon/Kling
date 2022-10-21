#include <catch2/catch_test_macros.hpp>
#include <Kling/Kling.hpp>

TEST_CASE( "All major vowels have right transcriptions", "[ipa]" ){
    using namespace Kling;
    SECTION("Close Vowels"){
        REQUIRE(CloseFrontUnroundedVowel.ToString() == "[i]");
        REQUIRE(CloseFrontRoundedVowel.ToString() == "[y]");

        REQUIRE(CloseCentralUnroundedVowel.ToString() == "[ɨ]");
        REQUIRE(CloseCentralRoundedVowel.ToString() == "[ʉ]");

        REQUIRE(CloseBackUnroundedVowel.ToString() == "[ɯ]");
        REQUIRE(CloseBackRoundedVowel.ToString() == "[u]");
    }
    SECTION("Near-Close Vowels"){
        REQUIRE(NearCloseFrontUnroundedVowel.ToString() == "[ɪ]");
        REQUIRE(NearCloseFrontRoundedVowel.ToString() == "[ʏ]");

        REQUIRE(NearCloseBackRoundedVowel.ToString() == "[ʊ]");
    }
}