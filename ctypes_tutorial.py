#!/usr/bin/env python3
import ctypes

clib = ctypes.CDLL("clib.so")

# clib.display(b"John", 18)

display = clib.display
display.argtypes = [ctypes.c_char_p, ctypes.c_int]
display.restype = ctypes.c_char_p
display(b"John", 18)
