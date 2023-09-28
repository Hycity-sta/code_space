local A = require("lsp.snippet_lua.all")
local M = {
    lua01 = {
        A.postfix(A.tr(".br",10), { 
            A.l("[[" .. A.l.POSTFIX_MATCH .. "]]") 
        })
    },

    lua02 = {
        A.postfix(A.tr(".xr",10), { 
            A.l("<<" .. A.l.POSTFIX_MATCH .. ">>") 
        })
    }
}

return M
