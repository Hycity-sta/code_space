return { 
    "catppuccin/nvim",
    name = "catppuccin",
    priority = 1000,
    config = function()
        require("config/theme")
        vim.cmd([[hi @lsp.type.typeParameter guifg=#6b81ff gui=Italic]])
    end
}
