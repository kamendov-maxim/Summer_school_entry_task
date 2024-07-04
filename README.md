# .bmp file header reader
CLI utility that prints .bmp file headers in a human readable format
Only .bmp files of versions 3, 4 and 5 are supported
# Requirements
- gcc
- riscv64-linux-gnu-gcc for cross building

# Build

To build with gcc for your system from the folder of repository pass this to command line:
```make```

To build for RISC-V:
```make cross-build```

# Usage

Pass path to image as an argument to the program:
```./bmp_header_reader <path-to-image>```

