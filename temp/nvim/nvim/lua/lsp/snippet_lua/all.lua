local ls = require "luasnip"
local extras = require "luasnip.extras"

local M = {
    s = ls.snippet,
    sn = ls.snippet_node,
    isn = ls.indent_snippet_node,
    t = ls.text_node,
    i = ls.insert_node,
    f = ls.function_node,
    c = ls.choice_node,
    d = ls.dynamic_node,
    r = ls.restore_node,

    events = require "luasnip.util.events",
    ai = require "luasnip.nodes.absolute_indexer",

    fmt = extras.fmt,
    m = extras.m,
    l = extras.l,
    postfix = require "luasnip.extras.postfix".postfix,

    add = ls.add_snippets,
    tr = function(a,b)
        return {
            trig=a,
            priority=b
        }
    end
}

return M
