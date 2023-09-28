return {
    --高亮所在缩进的缩进线
    chunk = {
        enable = false,
        notify = true, -- 在某些情况下弹出提示（比如连续两次使用 disableHLChunk 命令）
        --support_filetypes = ft.support_filetypes,
        --exclude_filetypes = ft.exclude_filetypes,
        use_treesitter = false,
        chars = {
            horizontal_line ="|",
            vertical_line = "│",
            left_top = "|",
            left_bottom = "|",
            right_arrow = "|",
        },
        style = {
            { fg = "#806d9c" },
            { fg = "#c21f30" }, -- 这个高亮是用来标志错误的代码块
        },
        textobject = "",
        max_file_size = 1024 * 1024,
        error_sign = false,
    },

    --缩进线
    indent = {
        enable = true,
        use_treesitter = false,
        chars = {
            "│",
        },
        style = {
            { fg = vim.fn.synIDattr(vim.fn.synIDtrans(vim.fn.hlID("Whitespace")), "fg", "gui") }
        },
    },

    --所在缩进的数字都高亮
    line_num = {
        enable = false,
        use_treesitter = false,
        style = "#806d9c",
    },

    --空白显示
    blank = {
        enable = false,
        chars = {
            "․",
        },
        style = {
            vim.fn.synIDattr(vim.fn.synIDtrans(vim.fn.hlID("Whitespace")), "fg", "gui"),
        },
    }
}
