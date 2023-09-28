vim.g.loaded_netrw = 1
vim.g.loaded_netrwPlugin = 1
vim.opt.termguicolors = true

local function on_attach(bufnr)
    local api = require('nvim-tree.api')
    local function opts(desc)
        return { desc = 'nvim-tree: ' .. desc, buffer = bufnr, noremap = true, silent = true, nowait = true }
    end

    -- BEGIN_DEFAULT_ON_ATTACH
    vim.keymap.set('n', '<leader>bo', api.node.open.replace_tree_buffer,       opts('在tree的窗口打开'))
    vim.keymap.set('n', 'k', api.node.show_info_popup,                    opts('详情'))
    vim.keymap.set('n', '<C-o>', api.node.open.tab,                           opts('在新的tab打开'))
    vim.keymap.set('n', '<C-v>', api.node.open.vertical,                      opts('垂直打开'))
    vim.keymap.set('n', '<C-x>', api.node.open.horizontal,                    opts('水平打开'))
    vim.keymap.set('n', '<tab>',  api.node.open.edit,                          opts('打开'))
    vim.keymap.set('n', '<leader>p', api.node.open.preview,                       opts('预览'))
    vim.keymap.set('n', '<C-a>', api.fs.rename_sub,                           opts('Rename: Omit Filename'))
    vim.keymap.set('n', '<BS>',  api.node.navigate.parent_close,              opts('关闭展开的目录'))
    vim.keymap.set('n', '>',     api.node.navigate.sibling.next,              opts('Next Sibling'))
    vim.keymap.set('n', '<',     api.node.navigate.sibling.prev,              opts('Previous Sibling'))
    vim.keymap.set('n', '.',     api.node.run.cmd,                            opts('Run Command'))
    vim.keymap.set('n', '-',     api.tree.change_root_to_parent,              opts('显示父级文件夹的内容'))
    vim.keymap.set('n', 'a',     api.fs.create,                               opts('新建'))
    vim.keymap.set('n', 'bmv',   api.marks.bulk.move,                         opts('Move Bookmarked'))
    vim.keymap.set('n', 'B',     api.tree.toggle_no_buffer_filter,            opts('Toggle No Buffer'))
    vim.keymap.set('n', 'C',     api.tree.toggle_git_clean_filter,            opts('Toggle Git Clean'))
    vim.keymap.set('n', '[c',    api.node.navigate.git.prev,                  opts('Prev Git'))
    vim.keymap.set('n', ']c',    api.node.navigate.git.next,                  opts('Next Git'))
    vim.keymap.set('n', 'c',     api.fs.copy.node,                            opts('复制'))
    vim.keymap.set('n', 'd',     api.fs.remove,                               opts('删除'))
    vim.keymap.set('n', 'D',     api.fs.trash,                                opts('Trash'))
    vim.keymap.set('n', 'E',     api.tree.expand_all,                         opts('展开所有'))
    vim.keymap.set('n', 'e',     api.fs.rename_basename,                      opts('Rename: Basename'))
    vim.keymap.set('n', ']e',    api.node.navigate.diagnostics.next,          opts('Next Diagnostic'))
    vim.keymap.set('n', '[e',    api.node.navigate.diagnostics.prev,          opts('Prev Diagnostic'))
    vim.keymap.set('n', 'F',     api.live_filter.clear,                       opts('Clean Filter'))
    vim.keymap.set('n', 'f',     api.live_filter.start,                       opts('Filter'))
    vim.keymap.set('n', '?',    api.tree.toggle_help,                         opts('快捷键提示'))
    vim.keymap.set('n', 'gy',    api.fs.copy.absolute_path,                   opts('Copy Absolute Path'))
    vim.keymap.set('n', 'H',     api.tree.toggle_hidden_filter,               opts('Toggle Dotfiles'))
    vim.keymap.set('n', 'I',     api.tree.toggle_gitignore_filter,            opts('Toggle Git Ignore'))
    vim.keymap.set('n', 'J',     api.node.navigate.sibling.last,              opts('Last Sibling'))
    vim.keymap.set('n', 'K',     api.node.navigate.sibling.first,             opts('First Sibling'))
    vim.keymap.set('n', 'm',     api.marks.toggle,                            opts('Toggle Bookmark'))
    vim.keymap.set('n', 'O',     api.node.open.no_window_picker,              opts('Open: No Window Picker'))
    vim.keymap.set('n', 'p',     api.fs.paste,                                opts('粘贴'))
    vim.keymap.set('n', '<leader>P',     api.node.navigate.parent,            opts('光标跳转到所属父级目录上'))
    vim.keymap.set('n', 'q',     api.tree.close,                              opts('关闭Tree'))
    vim.keymap.set('n', '<leader>r',     api.fs.rename,                       opts('重命名'))
    vim.keymap.set('n', '<leader>R',     api.tree.reload,                     opts('刷新'))
    vim.keymap.set('n', '<leader>S',     api.tree.search_node,                opts('搜索'))
    vim.keymap.set('n', '<leader>s',     api.node.run.system,                 opts('Run System'))
    vim.keymap.set('n', '<leader>U',     api.tree.toggle_custom_filter,       opts('Toggle Hidden'))
    vim.keymap.set('n', 'W',     api.tree.collapse_all,                       opts('Collapse'))
    vim.keymap.set('n', 'Y',     api.fs.copy.relative_path,                   opts('Copy Relative Path'))
    vim.keymap.set('n', 'x',     api.fs.cut,                                  opts('剪切'))
    vim.keymap.set('n', 'c', api.tree.change_root_to_node,                    opts('进入文件夹'))
    vim.keymap.set('n', 'yy',     api.fs.copy.filename,                       opts('复制名字'))
    vim.keymap.set('n', '<2-LeftMouse>',  api.node.open.edit,                 opts('打开'))
    vim.keymap.set('n', '<2-RightMouse>', api.tree.change_root_to_node,       opts('进入文件夹'))
    --如果不映射键的话,就会被普通的快捷键给代替,这个插件是没有默认映射的,可以随便改

    -- You might tidy things by removing these along with their default mapping.
    vim.keymap.set('n', '<2-RightMouse>', '', { buffer = bufnr })
    vim.keymap.del('n', '<2-RightMouse>', { buffer = bufnr })

    -- You will need to insert "your code goes here" for any mappings with a custom action_cb
    vim.keymap.set('n', 'A', api.tree.expand_all, opts('Expand All'))

    vim.keymap.set('n', '<cr>', function()
        api.node.open.edit()
        --api.tree.close()
    end, opts('打开文件并关闭tree'))

end

local old = {
    sort_by = "case_sensitive",
    renderer = {
        group_empty = true,
    },
    filters = {
        dotfiles = true,
    }
}

local opt = {
    on_attach = on_attach,
    hijack_cursor = false,
    auto_reload_on_write = true,
    disable_netrw = true,
    hijack_netrw = true,
    hijack_unnamed_buffer_when_opening = false,
    root_dirs = {},
    prefer_startup_root = false,
    sync_root_with_cwd = false,
    reload_on_bufenter = false,
    respect_buf_cwd = false,
    select_prompts = false,
    sort = {
        sorter = "name",
        folders_first = true,
        files_first = false,
    },

    view = {
        centralize_selection = false,
        cursorline = true,
        debounce_delay = 15,
        hide_root_folder = false,
        side = "left",
        preserve_window_proportions = false,
        number = false,
        relativenumber = false,
        signcolumn = "yes",
        width = 40,

        float = {
            enable = true,
            quit_on_focus_loss = true,
            open_win_config = { --这里调用的是nvim自己的api
                relative = "editor",
                border = "rounded",
                width = 60,
                height = 20,
                row = 0,
                col = 1,
                title = "file-tree",
                title_pos = "center"
            },
        },

    },

    renderer = {
        add_trailing = false,
        group_empty = false,
        full_name = false,
        root_folder_label = ":~:s?$?/..?",
        indent_width = 4,
        special_files = { "Cargo.toml", "Makefile", "README.md", "readme.md","readme.adoc" },
        symlink_destination = true,
        highlight_git = false,
        highlight_diagnostics = false,
        highlight_opened_files = "none",
        highlight_modified = "none",

        indent_markers = {
            enable = true,
            inline_arrows = false,
            icons = {
                corner = "└",
                edge = "│",
                item = "│",
                bottom = "─",
                none = " ",
            },
        },

        icons = {
            web_devicons = {
                file = {
                    enable = true,
                    color = true,
                },

                folder = {
                    enable = false,
                    color = true,
                },
            },
            git_placement = "before",
            diagnostics_placement = "signcolumn",
            modified_placement = "after",
            padding = " ",
            symlink_arrow = " ➛ ",
            show = {
                file = true,
                folder = true,
                folder_arrow = true,
                git = true,
                diagnostics = true,
                modified = true,
            },
            glyphs = {
                default = "",
                symlink = "",
                bookmark = "󰆤",
                modified = "●",
                folder = {
                    arrow_closed = "",
                    arrow_open = "",
                    default = "",
                    open = "",
                    empty = "",
                    empty_open = "",
                    symlink = "",
                    symlink_open = "",
                },
                git = {
                    unstaged = "✗",
                    staged = "✓",
                    unmerged = "",
                    renamed = "➜",
                    untracked = "★",
                    deleted = "",
                    ignored = "◌",
                },
            },
        },
    },

    hijack_directories = {
        enable = true,
        auto_open = true,
    },

    update_focused_file = {
        enable = false,
        update_root = false,
        ignore_list = {},
    },

    system_open = {
        cmd = "",
        args = {},
    },

    git = {
        enable = true,
        show_on_dirs = true,
        show_on_open_dirs = true,
        disable_for_dirs = {},
        timeout = 400,
    },

    diagnostics = {
        enable = false,
        show_on_dirs = false,
        show_on_open_dirs = true,
        debounce_delay = 50,
        severity = {
            min = vim.diagnostic.severity.HINT,
            max = vim.diagnostic.severity.ERROR,
        },

        icons = {
            hint = "",
            info = "",
            warning = "",
            error = "",
        },
    },

    modified = {
        enable = false,
        show_on_dirs = true,
        show_on_open_dirs = true,
    },

    filters = {
        git_ignored = true,
        dotfiles = false,
        git_clean = false,
        no_buffer = false,
        custom = {},
        exclude = {},
    },

    live_filter = {
        prefix = "[FILTER]: ",
        always_show_folders = true,
    },

    filesystem_watchers = {
        enable = true,
        debounce_delay = 50,
        ignore_dirs = {},
    },

    actions = {
        use_system_clipboard = true,

        change_dir = {
            enable = false,
            global = true,
            restrict_above_cwd = false,
        },

        expand_all = {
            max_folder_discovery = 10,
            exclude = {".xmake"},
        },

        file_popup = {
            open_win_config = {
                col = 1,
                row = 1,
                relative = "cursor",
                border = "shadow",
                style = "minimal",
            },
        },

        open_file = {
            quit_on_open = true,
            eject = true,
            resize_window = true,
            window_picker = {
                enable = true,
                picker = "default",
                chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890",
                exclude = {
                    filetype = { "notify", "packer", "qf", "diff", "fugitive", "fugitiveblame" },
                    buftype = { "nofile", "terminal", "help" },
                },
            },
        },

        remove_file = {
            close_window = true,
        },
    },


    tab = {
        sync = {
            open = false,
            close = false,
            ignore = {},
        },
    },


    ui = {
        confirm = {
            remove = true,
            trash = true,
        },
    },


}

return opt
