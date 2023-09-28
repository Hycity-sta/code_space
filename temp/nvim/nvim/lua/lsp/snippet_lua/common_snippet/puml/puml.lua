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

add("plantuml", {
    s("start2", {
        t("@startuml test"),
        t({"","!theme toy"}),
        t({"","set separator #"}),
        t({"","skinparam defaultFontName Maple Mono NF"}),
        t({"","skinparam defaultFontSize 16"}),
        t({"",""}),
        t({"",""}),i(0),
        t({"",""}),
        t({"","hide empty members"}),
        t({"","@enduml"}),
    })
})

add("plantuml", {
    s("start", {
        t("@startuml test"),
        t({"",""}),
        t({"",""}),i(0),
        t({"",""}),
        t({"","@enduml"}),
    })
})

add("plantuml", {
    s("comment", {
        t({"/'"}),
        i(0),
        t({"'/"})
    })
})
