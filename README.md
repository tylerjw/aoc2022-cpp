# AOC 2022 in C++

## Build Instructions

Install conan 2.0
```bash
pip install conan
```

Install dependencies of this project
```bash
conan install . --output-folder=build --build=missing
```

Activate conan build enviroment
```bash
source build/conanbuild.sh
```

Build the project
```bash
cmake --build --preset conan-release
```
