-- 状态栏
return {
    "nvim-lualine/lualine.nvim",
    config = function()
        require('lualine').setup(require('config.lualine'))
    end
}

