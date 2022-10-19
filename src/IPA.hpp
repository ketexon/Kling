#include <frozen/string.h>
#include <frozen/unordered_map.h>

namespace Ket {
	namespace IPA {
		constexpr auto IPAAliasMap = frozen::make_unordered_map<frozen::string, frozen::string>({
			{"I", "ɪ"},
			{"i=", "ɪ"},
		});
	}
}