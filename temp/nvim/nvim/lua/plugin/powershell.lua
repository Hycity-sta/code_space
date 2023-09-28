--powershell的插件
return {
    "pprovost/vim-ps1",
    version = "*",
    config = function()
        vim.cmd([[let g:ps1_nofold_blocks = 1]])
        vim.cmd([[let g:ps1_nofold_sig = 1]])
    end
}

