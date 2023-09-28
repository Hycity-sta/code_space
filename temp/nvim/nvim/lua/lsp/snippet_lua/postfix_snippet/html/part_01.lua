local A = require("lsp.snippet_lua.all")

local M = {
    html01 = {
        A.postfix(A.tr("-c",10), { 
            A.l("<" .. A.l.POSTFIX_MATCH .. ">"),
            A.i(0),
            A.l("</" .. A.l.POSTFIX_MATCH .. ">"),
        })
    },

}

return M
