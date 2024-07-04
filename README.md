# .bmp file header reader
[![GitHub Actions CI](https://github.com/kamendov-maxim/Summer_school_entry_task/actions/workflows/ci.yml/badge.svg)](https://github.com/kamendov-maxim/Summer_school_entry_task/actions/workflows/ci.yml)

CLI utility that prints .bmp file headers in a human readable format
Only .bmp files of versions 3, 4 and 5 are supported
# Requirements
- gcc
- riscv64-linux-gnu-gcc for cross building

# Build

To build with gcc for your system pass this to command line from the folder of repository :
```
make
```

To build for RISC-V:
```
make cross-build
```

# Usage

Pass path to image as an argument to the program:
```
./bmp_header_reader <path-to-image>
```

