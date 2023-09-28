local npairs = require'nvim-autopairs'
local Rule = require'nvim-autopairs.rule'
local cond = require 'nvim-autopairs.conds'

local brackets = { { '(', ')' }, { '[', ']' }, { '{', '}' } }

npairs.add_rules {
    -- Rule for a pair with left-side ' ' and right side ' '
    Rule(' ', ' ')
    -- Pair will only occur if the conditional function returns true
    :with_pair(function(opts)
        -- We are checking if we are inserting a space in (), [], or {}
        local pair = opts.line:sub(opts.col - 1, opts.col)
        return vim.tbl_contains({
            brackets[1][1] .. brackets[1][2],
            brackets[2][1] .. brackets[2][2],
            brackets[3][1] .. brackets[3][2]
        }, pair)
    end)

    :with_move(cond.none())

    :with_cr(cond.none())

    -- We only want to delete the pair of spaces when the cursor is as such: ( | )
    :with_del(function(opts)
        local col = vim.api.nvim_win_get_cursor(0)[2]
        local context = opts.line:sub(col - 1, col + 2)
        return vim.tbl_contains({
            brackets[1][1] .. '  ' .. brackets[1][2],
            brackets[2][1] .. '  ' .. brackets[2][2],
            brackets[3][1] .. '  ' .. brackets[3][2]
        }, context)
    end)
}

-- 对于(  )执行下面的规则
for _, bracket in pairs(brackets) do
    npairs.add_rules {
        -- 匹配(  )注意里面是有两个空格的, 光标位置在( | )
        Rule(bracket[1] .. ' ', ' ' .. bracket[2])

        :with_pair(cond.none())

        :with_move(function(opts) 
            return (opts.char == bracket[2])
        end)

        :with_del(cond.none())
        :use_key(bracket[2])

        -- 在(  )中按下回车的话, 会自动换行的同时把空格清除
        :replace_map_cr(function(_) 
            return '<C-c>2xi<CR><C-c>O'
        end)
    }
end
