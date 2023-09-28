-- lsp本身的快捷键, 这个是用来诊断的.
local opts = { noremap = true, silent = true }

vim.keymap.set('n', '<space>ll', vim.diagnostic.open_float, opts) -- 打开一个显示信息的浮窗,类似于补全窗口那样
vim.keymap.set('n', '<space>lr', vim.diagnostic.goto_prev, opts)  -- 跳转到上一个出错的地方
vim.keymap.set('n', '<space>ln', vim.diagnostic.goto_next, opts)  -- 跳转到下一个出错的地方
vim.keymap.set('n', '<space>lq', vim.diagnostic.setloclist, opts) -- 直接打开一个窗口, 里面记录了哪里出错了
vim.keymap.set('n', '<space>lf', vim.lsp.buf.format, opts) -- 直接打开一个窗口, 里面记录了哪里出错了

vim.cmd('command! LspForHover lua vim.lsp.buf.hover()<CR>')
vim.cmd('command! LspForDecla lua vim.lsp.buf.declaration()<CR>')
vim.cmd('command! LspForDefin lua vim.lsp.buf.definition()<CR>')
vim.cmd('command! LspForImplement lua vim.lsp.buf.implementation()<CR>')
vim.cmd('command! LspForRename lua vim.lsp.buf.rename()<CR>')
vim.cmd('command! LspForSignatureHelp lua vim.lsp.buf.signature_help()<CR>')
vim.cmd('command! LspForAdd lua vim.lsp.buf.add_workspace_folder()<CR>')
vim.cmd('command! LspForRemove lua vim.lsp.buf.remove_workspace_folder()<CR>')
vim.cmd('command! LspForType lua vim.lsp.buf.type_definition()<CR>')
vim.cmd('command! LspForCodeAct lua vim.lsp.buf.code_action()<CR>')
vim.cmd('command! LspForRefer lua vim.lsp.buf.references()<CR>')

local function myopts(desc)
    return { desc = 'LSP: ' .. desc,noremap = true, silent = true }
end

vim.keymap.set("n","<leader>ph",":LspForHover<cr>",myopts("显示说明"))
vim.keymap.set("n","<leader>pr",":LspForRename<cr>",myopts("重命名"))
vim.keymap.set("n","gd",":LspForDecla<cr>",myopts("显示定义"))
vim.keymap.set("n","<leader>pi",":LspForImplement<cr>",myopts("显示实现"))

local on_attach = function(_, _)
end

-- 以下是各种语言服务器的启动代码
-- java不适合用vim写,因为本身太过于繁杂了,这种东西还是交给ide吧
-- c的语言服务器还有c++
require("lspconfig").clangd.setup {
    on_attach = on_attach,
    cmd = { "clangd" },
    filetypes = { "c", "cpp", "objc", "objcpp" },
    --root_dir = function() return vim.loop.cwd() end,
    single_file_support = true
}
