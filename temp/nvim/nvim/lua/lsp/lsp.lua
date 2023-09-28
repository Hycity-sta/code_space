return {
    {
        "neovim/nvim-lspconfig",

        dependencies = {
            "williamboman/mason.nvim"
        },

        config = function()
            require("mason").setup(require("lsp.self.mason-config"))
            require("lsp.self.lsp-config")
            require("lsp.self.lsp-handlers")
        end,
    },
}




