-- cmp设置
return {
    "hrsh7th/nvim-cmp",

    ft= {
        "text",
        "txt",
        "c",
        "cpp",
        "java",
        "markdown",
        "csharp",
        "godotscript",
        "json",
        "lua",
        "asciidoc",
        "javascript",
        "html",
        "css",
        "plantuml"
    },

    dependencies = {
        "hrsh7th/cmp-nvim-lsp",
        "hrsh7th/cmp-buffer",
        "hrsh7th/cmp-cmdline",
        "saadparwaiz1/cmp_luasnip", -- 这个是引入片段,用cmp来显示

        {"L3MON4D3/LuaSnip",commit="8fdb06d4601c019a9ee880473646364bdbed3206"}, --片段补全引擎
    },

    config = function()
        require("lsp.self.cmp-config")
        require("lsp.self.luasnip-config")
    end
}
