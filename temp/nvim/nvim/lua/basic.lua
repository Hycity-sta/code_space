--vim.cmd([[set complete]])
vim.cmd([[command! SnipC :NvimTreeOpen C:\Users\10068\AppData\Local\nvim\lua\lsp\snippet_lua\common_snippet]])
vim.cmd([[command! SnipP :NvimTreeOpen C:\Users\10068\AppData\Local\nvim\lua\lsp\snippet_lua\postfix_snippet]])

vim.cmd("command! SetLocation :silent :cd %:p:h") --设置目录为当前文件所在的目录
--设置目录后在当前目录下打开tree
vim.cmd[[
command! Tree :silent :cd %:p:h | :NvimTreeToggle .
]]
-- 编码
vim.g.encoding = "UTF-8"
vim.o.fileencoding = 'UTF-8'

-- jkhl 移动时光标周围保留8行
vim.cmd([[
set scrolloff =8
set sidescrolloff =8
]])

-- 因为有了觉得文件树在编辑器里面不重要,所以可以把vim自带的文件树netrw给禁用了
vim.g.loaded_netrw = 1
vim.g.loaded_netrwPlugin = 1

-- 行号和相对行号
vim.wo.number = true
vim.wo.relativenumber = false
vim.wo.cursorline = true -- 高亮所在行
vim.wo.cursorcolumn= false-- 高亮所在列
vim.wo.signcolumn = "yes" -- 显示左侧图标指示列

-- 右侧参考线，超过表示代码太长了，考虑换行
vim.wo.colorcolumn = "99999"

-- 缩进2个空格等于一个Tab
vim.o.tabstop = 4
vim.bo.tabstop = 4
vim.o.softtabstop = 4
vim.o.shiftround = true
-- >> << 时移动长度
vim.o.shiftwidth = 4
vim.bo.shiftwidth = 4

-- 如果为true, 那么按下tab就等于按下shfttabstop个空格
vim.o.expandtab = true
vim.bo.expandtab = true

-- 新行对齐当前行
vim.o.autoindent = true
vim.bo.autoindent = true
vim.o.smartindent = false 

-- 搜索大小写不敏感，除非包含大写
vim.o.ignorecase = true
vim.o.smartcase = true
vim.o.hlsearch = false -- 搜索高亮
vim.o.incsearch = true -- 边输入边搜索

-- 当文件被外部程序修改时，自动加载
vim.o.autoread = true
vim.bo.autoread = true

vim.wo.wrap = false -- 折行,一行如果超过显示范围就会自动折行
vim.o.hidden = true -- 允许隐藏被修改过的buffer
vim.o.mouse = "a" -- 鼠标支持

-- 禁止创建备份文件
vim.o.backup = false
vim.o.writebackup = false
vim.o.swapfile = false

-- smaller updatetime
vim.o.updatetime = 400

-- 等待键盘快捷键连击时间500毫秒 可根据需要设置
vim.o.timeoutlen = 3000

-- split window 从下边和右边出现
vim.o.splitbelow = true
vim.o.splitright = true

-- 自动补全不自动选中
vim.g.completeopt = "menu,menuone,noselect,noinsert"

-- 样式
vim.o.background = "dark"
vim.o.termguicolors = true
vim.opt.termguicolors = true

-- 不可见字符的显示
vim.o.list = false

vim.o.shortmess = vim.o.shortmess .. 'c' -- Dont' pass messages to |ins-completin menu|

vim.o.wildmenu = true -- 补全增强
vim.o.pumheight = 5 -- 补全最多显示5行
vim.o.showtabline = 1 -- 永远显示 tabline
vim.o.showmode = false -- 使用增强状态栏插件后不再需要 vim 的模式提示
vim.o.cmdheight = 1 -- 命令行高,就是:模式下输入玩意的地方
vim.o.showmatch = false -- 这个是自动高亮匹配符号, 但是插件的功能好像会覆盖掉, 所以关掉了

vim.g.mapleader = " " -- 指定leader键
vim.g.maplocalleader = " " -- 指定leader键


--这个是调整c/cpp的缩进,在输入的时候自动进行调整
--有需要再去查文档来修改, 在cindent里面
vim.o.cinoptions = "N-s,g0,j1,{0,J1"

