from distutils.core import setup, Extension
setup(
    name='cSort',
    version='1.0',
    ext_modules=[
        Extension(
            'cSort',
            ['py_cSort.c'],
            extra_compile_args=['-std=gnu11'],
            )],

    )
