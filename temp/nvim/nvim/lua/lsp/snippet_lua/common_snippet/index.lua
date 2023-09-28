local cpp = require("lsp/snippet_lua/common_snippet/cpp/all")
local lua = require("lsp/snippet_lua/common_snippet/lua/all")
local html = require("lsp/snippet_lua/common_snippet/html/all")

local A = require("lsp/snippet_lua/all")

---- lua ----
for key,value in pairs(lua) do
    for key_b, value_b in pairs(value) do
        A.add("lua", value_b)
    end
end
---- lua ----


---- cpp ----
for key,value in pairs(cpp) do
    for key_b, value_b in pairs(value) do
        A.add("cpp", value_b)
    end
end
---- cpp ----

---- html ----
for key,value in pairs(html) do
    for key_b, value_b in pairs(value) do
        A.add("html", value_b)
    end
end
---- html ----
