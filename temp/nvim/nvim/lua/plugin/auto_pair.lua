-- 自动括号补全
return {
    "windwp/nvim-autopairs",
    config = function()
        require('nvim-autopairs').setup( require("config.auto_pair"))
        --require("config.auto_pair_rule")
    end
}


