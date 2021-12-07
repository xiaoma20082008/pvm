#!/usr/bin/python
# -*- coding: utf-8 -*-

import dis
import marshal
import struct
import sys
import time
import types


def show_file(filename):
    """
    https://nedbatchelder.com/blog/200804/the_structure_of_pyc_files.html
    """
    with open(filename, "rb") as f:
        magic = f.read(4)
        mod_date = f.read(4)
        mod_time = time.asctime(time.localtime(struct.unpack('L', mod_date)[0]))
        print("magic %s" % (magic.encode('hex')))
        print("moddate %s (%s)" % (mod_date.encode('hex'), mod_time))
        code = marshal.load(f)
        show_code(code)


def show_code(code, indent=''):
    print("%scode" % indent)
    indent += '   '
    print("%sargcount %d" % (indent, code.co_argcount))
    print("%snlocals %d" % (indent, code.co_nlocals))
    print("%sstacksize %d" % (indent, code.co_stacksize))
    print("%sflags %04x" % (indent, code.co_flags))
    show_hex("code", code.co_code, indent=indent)
    dis.disassemble(code)
    print("%sconsts" % indent)
    for const in code.co_consts:
        if isinstance(type(const), types.CodeType):
            show_code(const, indent + '   ')
        else:
            print("   %s%r" % (indent, const))
    print("%snames %r" % (indent, code.co_names))
    print("%svarnames %r" % (indent, code.co_varnames))
    print("%sfreevars %r" % (indent, code.co_freevars))
    print("%scellvars %r" % (indent, code.co_cellvars))
    print("%sfilename %r" % (indent, code.co_filename))
    print("%sname %r" % (indent, code.co_name))
    print("%sfirstlineno %d" % (indent, code.co_firstlineno))
    show_hex("lnotab", code.co_lnotab, indent=indent)


def show_hex(label, h, indent):
    h = h.encode('hex')
    if len(h) < 60:
        print("%s%s %s" % (indent, label, h))
    else:
        print("%s%s" % (indent, label))
        for i in range(0, len(h), 60):
            print("%s   %s" % (indent, h[i:i + 60]))


if __name__ == '__main__':
    show_file(sys.argv[1])
