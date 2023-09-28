local ls = require "luasnip"
local s = ls.snippet
local sn = ls.snippet_node
local isn = ls.indent_snippet_node
local t = ls.text_node
local i = ls.insert_node
local f = ls.function_node
local c = ls.choice_node
local d = ls.dynamic_node
local r = ls.restore_node
local events = require "luasnip.util.events"
local ai = require "luasnip.nodes.absolute_indexer"
local extras = require "luasnip.extras"
local fmt = extras.fmt
local m = extras.m
local l = extras.l
local postfix = require "luasnip.extras.postfix".postfix

local add = ls.add_snippets

add("asciidoc", {
    postfix("-br", {
        f(function(_, parent)
            return "{" .. parent.snippet.env.POSTFIX_MATCH .. "}"
        end, {}),
    })
})

add("asciidoc", {
    postfix("-bs", {
        f(
            function(_, parent)
                return '\\' .. parent.snippet.env.POSTFIX_MATCH
            end, {}
        ),
    })
})

add("asciidoc", {
    postfix("-and", {
        f(
            function(_, parent)
                return [[&]] .. parent.snippet.env.POSTFIX_MATCH
            end, {}
        ),
    })
})
