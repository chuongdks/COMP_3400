struct si_metre  { long double value; }; // type representing the SI unit metre
si_metre operator""_mm(long double value) { return si_metre{value / 1000.L}; }
si_metre operator""_cm(long double value) { return si_metre{value / 100.L}; }
si_metre operator""_m(long double value) { return si_metre{value}; }
si_metre operator""_km(long double value) { return si_metre{value * 1000.L}; }

si_metre m1 = 29.5_mm; // 29.5 / 1000 so it is in metres
si_metre m2 = 55.321_cm; // 55.321 / 100 so it is in metres
si_metre m3 = 22.1234e17_m; // 22.1234e17 metres
si_metre m4 = 3156.23e4_km; // 3156.23e4 * 1000 so it is in metres
