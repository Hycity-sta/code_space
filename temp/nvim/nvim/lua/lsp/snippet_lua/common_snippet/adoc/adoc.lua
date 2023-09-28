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


--初始化模板
ls.add_snippets("asciidoc", {
    s("init", { t({ ":toc:", ":highlightjsdir: highlight", ":source-highlighter: highlight.js", ":highlightjs-theme: vs2015", "" }) })
})

-- source cpp
ls.add_snippets("asciidoc", {
    s("socpp", {
        t({ "[source, cpp]", "----","",""}),
        i(0),
        t({ "","","----" })
    })
})

-- source adoc
ls.add_snippets("asciidoc", {
    s("soadoc", {
        t({ "[source, asciidoc]", "----","",""}),
        i(0),
        t({ "","","----" })
    })
})

ls.add_snippets("asciidoc", {
    s("exam", {
        t({"===="}),
        t({"",""}),i(0),
        t({"","====" })
    })
})

ls.add_snippets("asciidoc", {
    s("lit", {
        t({"----"}),
        t({"",""}),i(0),
        t({"","----" })
    })
})
