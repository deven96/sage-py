"""Node declaration file.

   @author
     Victor I. Afolabi
     Artificial Intelligence Expert & Researcher.
     Email: javafolabi@gmail.com | victor.afolabi@zephyrtel.com
     GitHub: https://github.com/victor-iyiola

   @project
     File: node.pxd
     Created on 20 February, 2019 @ 09:19 PM.

   @license
     MIT License
     Copyright (c) 2019. Victor I. Afolabi. All rights reserved.
"""

cdef class Node:
    cdef:
        public value
        readonly str key
        readonly bint is_scope

cdef class Scope(Node):
    cdef:
        readonly str id

    cdef str __print(self, Node base, str so_far= *)
    cdef void add_scope(self, Scope scope)
    cdef void add_node(self, Node node)

cpdef Node newNode(str key, value= *)
cpdef Scope newScope(str key, value= *)
