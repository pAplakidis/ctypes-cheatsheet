#!/usr/bin/env python3
import ctypes

# [ https://www.youtube.com/playlist?list=PLHwXkLexR9MCqqr5hD_8o5rbSXYHtfFiB ]

clib = ctypes.CDLL("clib.so")

# clib.display(b"John", 18)

# Simple print
display = clib.display
display.argtypes = [ctypes.c_char_p, ctypes.c_int]
display.restype = ctypes.c_char_p
res = display(b"John", 18)
print(res)

# Simple return
add = clib.add
add.argtypes = [ctypes.c_int, ctypes.c_int]
add.restype = ctypes.c_int
res = add(2, 2)
print(res)

# Pointers and memory allocation
alloc_mem = clib.alloc_mem
alloc_mem.restype = ctypes.POINTER(ctypes.c_char_p)
ptr = alloc_mem()
cstring = ctypes.c_char_p.from_buffer(ptr)
print(cstring.value)

free_mem = clib.free_mem
free_mem.argtypes = [ctypes.POINTER(ctypes.c_char_p)]
free_mem(ptr)

# Arrays
values = (ctypes.c_int * 10)()  # int values[10];
for i in range(len(values)):
  values[i] = i
res = clib.sum(values, len(values))
print(res)

# NOTE: always do this when returning a pointer
clib.inc_array.restype = ctypes.POINTER(ctypes.c_int)
res = clib.inc_array(values, len(values))
print(res.contents) # print(*ptr)

# NOTE: we cannot get the size from C, need to keep it somehow
# print the whole array
for i in range(10):
  print(res[i])

clib.get_array.restype = ctypes.POINTER(ctypes.c_int)
res = clib.get_array()
for i in range(10):
  print(res[i])
free_array = clib.free_array()

# Structs
class Point(ctypes.Structure):
  # tuples of (variable_name, data_type)
  _fields_ = [("x", ctypes.c_int),
              ("y", ctypes.c_int)]

p = Point(5, 6)
print(p.x, p.y)
clib.print_point(p)

clib.get_point.restype =  ctypes.POINTER(Point)
p = clib.get_point()
print(p.contents.x, p.contents.y)
clib.free_ptr(ctypes.cast(p, ctypes.c_void_p))

class Student(ctypes.Structure):
  _fields_ = [("name", ctypes.c_char_p)]

name = "Test"
s = Student(bytes(name, "utf-8"))
clib.print_student_details(s)

clib.get_student.restype =  ctypes.POINTER(Student)
s = clib.get_student()
print(s.contents.name.decode("utf-8"))
clib.free_ptr(ctypes.cast(s, ctypes.c_void_p))
