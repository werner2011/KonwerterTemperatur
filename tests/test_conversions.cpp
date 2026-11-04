#include <cmath>
#include <iostream>

// Functions implemented in ConsoleApplication1.cpp.
double FtoC(double fahrenheit);
double FtoK(double fahrenheit);
double CtoF(double celsius);
double CtoK(double celsius);
double KtoF(double kelvin);
double KtoC(double kelvin);
int check(double temperature, char unit);

int failures = 0;

void expectNear(const char* name, double actual, double expected, double tolerance = 1e-9)
{
    if (!std::isfinite(actual) || std::abs(actual - expected) > tolerance)
    {
        std::cerr << "[FAIL] " << name
                  << " | expected: " << expected
                  << ", actual: " << actual << '\n';
        ++failures;
    }
    else
    {
        std::cout << "[PASS] " << name << '\n';
    }
}

void expectEqual(const char* name, int actual, int expected)
{
    if (actual != expected)
    {
        std::cerr << "[FAIL] " << name
                  << " | expected: " << expected
                  << ", actual: " << actual << '\n';
        ++failures;
    }
    else
    {
        std::cout << "[PASS] " << name << '\n';
    }
}

int main()
{
    // All six temperature conversion directions.
    expectNear("F to C: 32 F = 0 C",       FtoC(32.0),      0.0);
    expectNear("F to K: 32 F = 273.15 K",  FtoK(32.0),    273.15);
    expectNear("C to F: 0 C = 32 F",       CtoF(0.0),       32.0);
    expectNear("C to K: 100 C = 373.15 K",CtoK(100.0),   373.15);
    expectNear("K to F: 273.15 K = 32 F", KtoF(273.15),    32.0);
    expectNear("K to C: 273.15 K = 0 C",  KtoC(273.15),     0.0);

    // Absolute-zero boundary values (valid) and just below (invalid).
    expectNear("0 K = -273.15 C", KtoC(0.0), -273.15);
    expectNear("0 K = -459.67 F", KtoF(0.0), -459.67);
    expectNear("-273.15 C = 0 K", CtoK(-273.15), 0.0);
    expectNear("-459.67 F = 0 K", FtoK(-459.67), 0.0);

    expectEqual("0 K is valid",              check(0.0, 'K'),         0);
    expectEqual("-1 K is invalid",           check(-1.0, 'K'),     -999);
    expectEqual("-273.15 C is valid",        check(-273.15, 'C'),    0);
    expectEqual("Below -273.15 C invalid",  check(-273.16, 'C'), -999);
    expectEqual("-459.67 F is valid",        check(-459.67, 'F'),    0);
    expectEqual("Below -459.67 F invalid",  check(-459.68, 'F'), -999);

    // Round-trip checks (allowing for floating-point rounding).
    expectNear("Round trip C -> F -> C", FtoC(CtoF(36.6)), 36.6);
    expectNear("Round trip K -> C -> K", CtoK(KtoC(310.2)), 310.2);

    if (failures == 0)
    {
        std::cout << "\nAll 18 tests passed.\n";
        return 0;
    }

    std::cerr << "\nFailed tests: " << failures << '\n';
    return 1;
}
