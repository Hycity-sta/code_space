local A = require("lsp.snippet_lua.all")

local M = {
    cpp01 = {
        A.postfix(A.tr("-for",10), { 
            A.l("for (auto i : " .. A.l.POSTFIX_MATCH .. " ) {"),
            A.t({"","\t"}),A.i(0),
            A.t({"","}"})
        })
    },

    cpp02 = {
        A.postfix(A.tr("-class",10), { 
            A.l("class" .. A.l.POSTFIX_MATCH .. " {"),
            A.t({"","public:"}),
            A.t({"","\t"}),A.i(0),
            A.t({"","};"})
        })
    },

    cpp03 = {
        A.postfix(A.tr("-ic",10), { 
            A.l("#include <" .. A.l.POSTFIX_MATCH .. ">") 
        })
    },

    cpp04 = {
        A.postfix(A.tr("-is",10), { 
            A.l('#include "' .. A.l.POSTFIX_MATCH .. '"') 
        })
    }
}

return M
