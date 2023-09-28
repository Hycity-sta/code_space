local cmp = require("cmp")
local luasnip = require("luasnip")


-- 用字符串或者nerd字符来当作提示文字或者图标
local kind_icons = {
    Text = "文本",
    Method = "方法",
    Function = "函数",
    Constructor = "构造",
    Field = "所属",
    Variable = "变量",
    Class = "类",
    Interface = "接口",
    Module = "模块",
    Property = "属性",
    Unit = "联合",
    Value = "值",
    Enum = "枚举",
    Keyword = "关键词",
    Snippet = "片段",
    Color = "颜色",
    File = "文件",
    Reference = "引用",
    Folder = "文件夹",
    EnumMember = "枚举成员",
    Constant = "Constant",
    Struct = "结构",
    Event = "事件",
    Operator = "操作符",
    TypeParameter = "类型参数",
}

-- 在补全函数和方法的时候补上()
local cmp_autopairs = require('nvim-autopairs.completion.cmp')
cmp.event:on( 'confirm_done', cmp_autopairs.on_confirm_done())

cmp.setup {
	snippet = {
		expand = function(args)
			luasnip.lsp_expand(args.body) -- For `luasnip` users.
		end,
	},
    
	mapping = {
		["}"] = cmp.mapping.select_prev_item(),
		["]"] = cmp.mapping.select_next_item(),
		["<C-R>"] = cmp.mapping(cmp.mapping.scroll_docs(-1), { "i", "c" }),
		["<C-N>"] = cmp.mapping(cmp.mapping.scroll_docs(1), { "i", "c" }),
		["<a-Space>"] = cmp.mapping(cmp.mapping.complete(), { "i", "c" }),

		["\\"] = cmp.mapping {
			i = cmp.mapping.abort(),
			c = cmp.mapping.close(),
		},
        ["<cr>"] = cmp.mapping.confirm { select = true },
		-- Accept currently selected item. If none selected, `select` first item.
		-- Set `select` to `false` to only confirm explicitly selected items.

		["<C-n>"] = cmp.config.disable, -- Specify `cmp.config.disable` if you want to remove the default mapping.
		["<C-r>"] = cmp.config.disable, -- Specify `cmp.config.disable` if you want to remove the default mapping.

        ["<tab>"] = cmp.mapping(function(fallback)
            if require("luasnip").jumpable() then
                vim.fn.feedkeys(vim.api.nvim_replace_termcodes("<Plug>luasnip-jump-next", true, true, true), "")
            else
                fallback()
            end
        end, {"i","s",}),
        ["<S-tab>"] = cmp.mapping(function(fallback)
            if require("luasnip").jumpable(-1) then
                vim.fn.feedkeys(vim.api.nvim_replace_termcodes("<Plug>luasnip-jump-prev", true, true, true), "")
            else
                fallback()
            end
        end, {"i","s",}),
    },

	formatting = {
        fields = { "kind", "abbr", "menu" },

        format = function(entry, vim_item)
            vim_item.kind = string.format("%s", kind_icons[vim_item.kind])
            vim_item.menu = ({
                nvim_lsp = "[LSP]",
                buffer = "[Buf]",
                luasnip = "[片段]",
            })
            [entry.source.name]
            return vim_item
        end,
	},

	sources = {
		{ name = "nvim_lsp" ,keyword_length = 2},
		{ name = "buffer" ,keyword_length = 2 },
		{ name = "luasnip" ,keyword_length = 1},
	},

	confirm_opts = {
		behavior = cmp.ConfirmBehavior.Replace,
		select = true,
	},

	window = {
		documentation = {
			border = { "╭", "─", "╮", "│", "╯", "─", "╰", "│" },
		},
		completion = {
			border = { "╭", "─", "╮", "│", "╯", "─", "╰", "│" },
		},--设置补全的窗口边框
        scrollbar_shape = "thumb",
	},

    view = {
        entries = {name = 'custom', selection_order = 'near_cursor'}
    },

	experimental = {
		ghost_text = false,
		native_menu = false,
	},
}

-- `/` cmdline setup.
cmp.setup.cmdline('/', {
    mapping = cmp.mapping.preset.cmdline(),
    sources = {
        { name = 'buffer' }
    }
})

-- `:` cmdline setup.
cmp.setup.cmdline(':', {
    mapping = cmp.mapping.preset.cmdline(),
    sources = cmp.config.sources (
        {
            { 
                name='cmdline', 
                option={ignore_cmds={'Man','!' }} 
            }
        }
    )
})

--vim.cmd([[hi CmpItemAbbrMatch guifg=#58a6ff "补全菜单里面匹配的文字颜色"]])
--vim.cmd([[ hi Pmenu guibg=#282c34"补全菜单的背景颜色" ]])
