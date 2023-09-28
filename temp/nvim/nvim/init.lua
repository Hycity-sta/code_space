require("basic") 
require("mapping")

local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
vim.opt.rtp:prepend(lazypath)
require("lazy").setup({
    spec = {
        { import = "plugin" },
        { import = "lsp" }
    }
})


