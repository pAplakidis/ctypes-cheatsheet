#!/usr/bin/env python3
import ctypes

clib = ctypes.CDLL("clib.so")

# clib.display(b"John", 18)

display = clib.display
display.argtypes = [ctypes.c_char_p, ctypes.c_int]
display.restype = ctypes.c_char_p
res = display(b"John", 18)
print(res)

add = clib.add
add.argtypes = [ctypes.c_int, ctypes.c_int]
add.restype = ctypes.c_int
res = add(2, 2)
print(res)
