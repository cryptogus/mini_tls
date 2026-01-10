# mini_tls

## Development PC Information
```shell
CPU: quad core 11th Gen Intel Core i7-1165G7 (-MT MCP-) speed: 2803 MHz
Kernel: 6.6.87.2-microsoft-standard-WSL2 x86_64 Up: 13m
Shell: Bash inxi: 3.3.13
```
## Install ubutu package
```bash
$ sudo apt install libjsoncpp-dev libgmp-dev nettle-dev
```

- `libjsoncpp-dev` is used for decoding DER format, [jsoncpp](https://github.com/open-source-parsers/jsoncpp)
- `nettle-dev` is used for using crypto functions
- `libgmp-dev` is used for Big Number in C++ [gmp](https://gmplib.org/)