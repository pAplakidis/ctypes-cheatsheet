#!/usr/bin/env python3
import ctypes

clib = ctypes.CDLL("clib.so")
clib.display(b"John", 18)
