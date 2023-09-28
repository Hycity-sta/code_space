local function my()
    return [[o(TヘTo)]]
end

return {
    options = {
        icons_enabled = true,
        theme = 'everforest',
        section_separators = { left = '', right = '' },
        component_separators = { left = '|', right = '|' },
        disabled_filetypes = {
            statusline = {},
            winbar = {},
        },

        ignore_focus = {},
        always_divide_middle = true,
        globalstatus = false,

        refresh = {
            statusline = 1000,
            tabline = 1000,
            winbar = 1000,
        },
    },

    --活动的窗口下的lualine
    sections = {
        lualine_a = {'mode'},
        lualine_b = {'diff', 'diagnostics'},
        lualine_c = {'filename',{my}},
        lualine_x = {'encoding','filetype','filesize'},
        lualine_y = {'progress'},
        lualine_z = {'fileformat'}
    },

    --不活动的窗口下的lualine
    inactive_sections = {
        lualine_a = {},
        lualine_b = {},
        lualine_c = {'filename'},
        lualine_x = {'filesize'},
        lualine_y = {},
        lualine_z = {}
    },

}
