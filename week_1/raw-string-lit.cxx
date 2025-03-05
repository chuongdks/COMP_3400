// NOTE: None of the raw strings below have any escape characters in them.
//       Everything in the raw string is as-is.
char const* s1 = R"(This some as-is text.\nNo newlines here!)";
wchar_t const* s2 = LR"(Some more \t\v\n\r as-is text.)";
char8_t const* s3 = u8R"nice(Another raw string \x0A\x0D as-is.)nice";
char16_t const* s4 = uR"okay(More stuff.)okay";
char32_t const* s5 = UR"qwerty(Even more stuff.)qwerty";
