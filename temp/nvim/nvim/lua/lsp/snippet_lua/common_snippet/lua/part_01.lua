local A = require("lsp.snippet_lua.all")

local M = {
    lua01 = {
        A.s(A.tr(">pr",10), {
            A.t("print("),
            A.i(0),
            A.t(")")
        })
    }
}

return M
