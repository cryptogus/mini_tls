# BUILD_SHARED_LIBS
Can be set to ON or OFF. When ON, liboqs is built as a shared library.

Default: OFF.

```bash
$ cmake -B build -S . -DBUILD_SHARED_LIBS=ON
```

CMake에서 add_library()를 쓸 때 STATIC이나 SHARED를 명시하지 않고 그냥:
`add_library(mylib ${SOURCES})`


라고 하면, 이 라이브러리의 타입은 전역 변수 BUILD_SHARED_LIBS 값에 따라 자동으로 결정됩니다.
