# Temperature Converter — C++

A console-based application written in **C++17** that converts temperatures between **Celsius (°C), Fahrenheit (°F), and Kelvin (K)**. The application also includes an interactive menu and conversion history management.

This is an educational project focused on C++ fundamentals: functions, arrays, loops, conditional statements, input handling, and numerical calculations.

## Features

- All six conversion directions: C ↔ F, C ↔ K, and F ↔ K.
- Validation against temperatures below absolute zero.
- In-memory conversion history, with filtering by the source unit.
- Editing and deleting previous conversions.
- Generation of random conversion records for demonstration and testing.
- A text-based menu for navigating the application.

## Requirements

- **Windows** (the current application clears the console using `system("cls")`).
- **C++17 compiler**; tested development setup: GCC/G++ from **MSYS2 UCRT64**.
- Visual Studio Code with the Microsoft C/C++ extension is optional.

No additional C++ libraries are required.

## Build and run (PowerShell + MSYS2/G++)

Clone the repository and open it:

```powershell
git clone https://github.com/werner2011/KonwerterTemperatur.git
cd KonwerterTemperatur
```

Check that the C++ compiler is available:

```powershell
g++ --version
```

Compile from the **repository root**:

```powershell
g++ -std=c++17 -Wall -Wextra .\ConsoleApplication1\ConsoleApplication1.cpp -o .\KonwerterTemperatur.exe
```

Run the program:

```powershell
.\KonwerterTemperatur.exe
```

In VS Code, the `.vscode/` configuration can also be used for building and debugging, provided that the MSYS2 installation path matches your machine.

## Example conversions

| Input | Expected output |
|---|---|
| 0 °C | 32 °F |
| 100 °C | 373.15 K |
| 32 °F | 0 °C |
| 273.15 K | 0 °C |
| 0 K | −459.67 °F |

Absolute zero is **0 K = −273.15 °C = −459.67 °F**. Values below this temperature should be rejected.

## Conversion history

The application stores conversions in **memory only**. History is lost when the application exits; it is **not saved to a file**.

The current implementation uses fixed arrays of 100 elements, with two elements per conversion. Therefore, the maximum history size is **50 conversions**.

## Unit tests

The `tests/test_conversions.cpp` file checks all six conversion functions, values around absolute zero, and round-trip conversions. The tests use a numerical tolerance when comparing `double` values.

**One small source-code change is required:** wrap the existing `main()` function in `ConsoleApplication1/ConsoleApplication1.cpp`:

```cpp
#ifndef TEMPERATURE_CONVERTER_TEST
int main()
{
    // Keep the existing main() implementation unchanged.
}
#endif
```

The `#ifndef` line goes **immediately before** the real `int main()`; `#endif` goes **after the final closing brace** of that function. Do not replace its body with the illustrative comment above.

Then compile the tests from the repository root:

```powershell
g++ -std=c++17 -Wall -Wextra -DTEMPERATURE_CONVERTER_TEST .\ConsoleApplication1\ConsoleApplication1.cpp .\tests\test_conversions.cpp -o .\tests\test_conversions.exe
```

Run them:

```powershell
.\tests\test_conversions.exe
```

A successful run ends with `All 18 tests passed.` and exits with code `0`.

## Current limitations

- History is not persistent and has a 50-conversion limit.
- The random history generator needs improved capacity checking and Fahrenheit lower-bound handling.
- Some input paths need stricter validation (for example, invalid units and non-finite values).
- Console clearing is currently Windows-specific.

## Project structure

```text
KonwerterTemperatur/
├── ConsoleApplication1/
│   ├── ConsoleApplication1.cpp
│   └── ConsoleApplication1.vcxproj
├── tests/
│   └── test_conversions.cpp
├── .vscode/
│   ├── tasks.json
│   └── launch.json
├── ConsoleApplication1.sln
├── .gitignore
└── README.md
```

## Project status

Educational project under maintenance and incremental improvement.
