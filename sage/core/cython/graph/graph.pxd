"""Graph database.

   @author
     Victor I. Afolabi
     Artificial Intelligence Expert & Researcher.
     Email: javafolabi@gmail.com | victor.afolabi@zephyrtel.com
     GitHub: https://github.com/victor-iyiola

   @project
     File: graph.pyd
     Created on 20 February, 2019 @ 11:56.

   @license
     MIT License
     Copyright (c) 2019. Victor I. Afolabi. All rights reserved.
"""

cimport node

cdef class Graph:
    cdef readonly node.Scope root

    cpdef void load(self, node.Scope base, data)

cpdef Graph newGraph(str path)
