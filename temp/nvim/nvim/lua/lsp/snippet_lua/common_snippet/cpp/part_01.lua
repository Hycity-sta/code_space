local A = require("lsp.snippet_lua.all")

local M = {
    cppa = {
        A.s(A.tr("main",10), {
            A.t({"int main(int argc, char *argv[]) {"}),
            A.t({"","\t"}), A.i(0),
            A.t({"","\treturn 0;"}),
            A.t({"","}"})
        })
    },

    cppb = {
        A.s(A.tr("q-main",10), {
            A.t({"#include <iostream>"}),
            A.t({"","#include <string>"}),
            A.t({"",""}),
            A.t({"","int main(int argc, char *argv[]) {"}),
            A.t({"","\t"}),A.i(0),
            A.t({"","\treturn 0;"}),
            A.t({"","}"})
        })
    },

    cppc = {
        A.s(A.tr("out",20), {
            A.t({"std::cout<< "}),
            A.i(0),
            A.t({' <<"\\n";'}),
        })
    },

    cppcc = {
        A.s(A.tr("outs",10), {
            A.t({"std::cout<< "}),
            A.i(0),
            A.t({' <<std::endl;'}),
        })
    },

    cppd = {
        A.s(A.tr("myprint",10), {
            A.t({'std::printf("'}),
            A.i(0),
            A.t({'\\n");'})
        })
    },

    cppe = {
        A.s(A.tr("q__main2",10),{
            A.t({"#include <cstdio>"}),
            A.t({"","#include <string>"}),
            A.t({"",""}),
            A.t({"","int main(int argc, char *argv[]) {"}),
            A.t({"","\t"}),A.i(0),
            A.t({"","\treturn 0;"}),
            A.t({"","}"})
        })
    },

    cppf = {
        A.s(A.tr("in_<vector",10), {
            A.t({'#include <vector>'}),
            A.t({"",""}),A.i(0)
        })
    },

    cppg = {
        A.s(A.tr("in_<array",15), {
            A.t({'#include <array>'}),
            A.t({"",""}),A.i(0)
        })
    },

    cpph = {
        A.s(A.tr("in_<deque",14), {
            A.t({'#include <deque>'}),
            A.t({"",""}),A.i(0)
        })
    },

    cppi = {
        A.s(A.tr("in_<map",13), {
            A.t({'#include <map>'}),
            A.t({"",""}),A.i(0)
        })
    },

    cppj = {
        A.s(A.tr("in_<start",12), {
            A.t({'#include "start.hpp"'}),
            A.t({"",""}),A.i(0)
        })
    },

    cppk = {
        A.s(A.tr("startalgo",12), {
            A.t({'#include "algostuff.hpp"'}),
            A.t({'',''}),
            A.t({'','void start_a() {'}),
            A.t({'','\t'}),A.i(0),
            A.t({'','}'}),
            A.t({'',''}),
            A.t({'',"int main(int argc, char *argv[]) {"}),
            A.t({"","\tset_cn();"}),
            A.t({"","\tstart_a();"}),
            A.t({"","\treturn 0;"}),
            A.t({"","}"})
        })
    }
}

return M

-- 不能使用"\n"来表示换行, 但是可以使用"\t"来表示缩进
-- 但是要输入\n这个字符串的话, 要用\\n来表示
