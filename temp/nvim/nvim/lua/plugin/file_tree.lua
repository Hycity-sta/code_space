--文件树
return {
    "nvim-tree/nvim-tree.lua",
    version = "*",
    config = function()
        require("nvim-tree").setup(require("config.file_tree"))
    end
}

