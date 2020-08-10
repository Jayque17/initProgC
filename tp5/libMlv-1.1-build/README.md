# libMLV

This is a built version of libMLV.

To build a program, extract it in your project and use:

```bash
gcc -o executable_name src/*.c -I libMlv-1.1-build/include -L libMlv-1.1-build/lib -lMlv -lX11
```