from distutils.core import setup, Extension
import sys
print sys.version
setup(
    name='cSort',
    version='1.0',
    ext_modules=[
        Extension(
            'cSort',
            ['py_cSort.c'],
#            include_dirs=['sort'],
            extra_compile_args=['-std=gnu11'],
            )],

    )
