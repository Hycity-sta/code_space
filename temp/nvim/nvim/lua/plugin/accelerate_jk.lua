return {
    "rainbowhxch/accelerated-jk.nvim",
    lazy = false,
    priority = 1000,
    config = function()
        require('accelerated-jk').setup(require("config/accelerate_jk"))
    end
}
