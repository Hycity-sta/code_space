local A = require("lsp.snippet_lua.all")

local M = {
    html01 = {
        A.s(A.tr("start",10), {
            A.t({"<!DOCTYPE html>"}),
            A.t({"","<html>"}),
            A.t({"","\t<head>"}),
            A.t({"",'\t\t<meta charset="utf-8"/>'}),
            A.t({"","\t\t<title>"}),A.i(0),A.t({"</title>"}),
            A.t({"","\t</head>"}),
            A.t({"","\t<body>"}),
            A.t({"","\t</body>"}),
            A.t({"","</html>"})
        })
    },

    html02 = {
        A.s(A.tr("meta",10), {
            A.t({"<meta "}),
            A.i(0),
            A.t({" />"})
        })
    },

    html03 = {
        A.s(A.tr("link_css",10), {
            A.t({'<link rel="stylesheet" href="style/.css"'}),
            A.t({" />"}),
            A.i(0),
        })
    }

}

return M
