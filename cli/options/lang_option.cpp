#include "lang_option.h"

const std::array<std::string_view, 86> cli::options::lang_option::available_languages = {
        "af", "ak", "ar", "as", "ast", "be", "bg", "bn-BD", "bn-IN", "br", "bs", "ca", "cs", "csb", "cy", "da", "de",
        "el", "en-GB", "en-US", "en-ZA", "eo", "es-AR", "es-CL", "es-ES", "es-MX", "et", "eu", "fa", "fi", "fr",
        "fy-NL", "ga-IE", "gd", "gl", "gu-IN", "he", "hi-IN", "hr", "hu", "hy-AM", "id", "is", "it", "ja", "kk", "kn",
        "ko", "ku", "lg", "lt", "lv", "mai", "mk", "ml", "mr", "nb-NO", "nl", "nn-NO", "nso", "or", "pa-IN", "pl",
        "pt-BR", "pt-PT", "rm", "ro", "ru", "si", "sk", "sl", "son", "sq", "sr", "sv-SE", "ta-LK", "ta", "te", "th",
        "tr", "uk", "vi", "xpi", "zh-CN", "zh-TW", "zu"
};

bool cli::options::lang_option::is_valid() {
    return utils::array::in_array(get_option_value(), available_languages);
}
