from distutils.core import setup, Extension
fiboM = Extension('fibo_test',sources = ['fibo.c'])
setup(name = 'MathExtension',version='1.0',description = 'This is a test',ext_modules = [fiboM])
