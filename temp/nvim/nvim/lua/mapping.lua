local map = vim.keymap.set -- 下面是键盘映射的部分

local n_t = {noremap = true} --指定noremap和silent键值对
local n_f = {noremap = false}
local s_t = {silent = true}
local s_f = {silent = false}

local function opt(n_mine, s_mine, str) --传入相应的变量,然后赋值给传参
    return { noremap = n_mine.noremap, silent = s_mine.silent, desc = str}
end


map({"n","x"},"r","k",opt(n_t,s_t,"up"))
map({"n","x"},"n","j",opt(n_t,s_t,"down"))
map({"n","x"},"t","h",opt(n_t,s_t,"left"))
map({"n","x"},"s","l",opt(n_t,s_t,"right"))

-- 加速jk
map('n', 'n', '<Plug>(accelerated_jk_j)', opt(n_t,s_t))
map('n', 'r', '<Plug>(accelerated_jk_k)', opt(n_t,s_t))

-- 插入
map("n","i","a",opt(n_t,s_t))
map("n","I","A",opt(n_t,s_t))
map("n","u","i",opt(n_t,s_t))
map("n","U","I",opt(n_t,s_t))

-- 回退与恢复
map("n","<backspace>","u",opt(n_t,s_t))

-- 大跳转跳转
map("n","<s-r>","{zz",opt(n_t,s_t))
map("n","<s-n>","}zz",opt(n_t,s_t))
-- 改变一下行首行尾的快捷键
map("n","<s-s>","$",opt(n_t,s_t))
map("n","<s-t>","^",opt(n_t,s_t))
-- 正常模式下将分号替换冒号,方便进入命令模式
map("n",";",":",opt(n_t,s_f))

-- Terminal相关
vim.cmd("command! Pwsh :vsp | terminal pwsh<CR>")
map("t", "<Esc>", "<C-\\><C-n>", opt(n_t,s_t))

map("n","[[",'?{<cr>',opt(n_t,s_t))
map("n","]]",'/{<cr>',opt(n_t,s_t))

map("n",":",';',opt(n_t,s_t))







-----以下需要辅助键-----




map("n","<A-n>","n",opt(n_t,s_t))
map("n","<A-N>","N",opt(n_t,s_t))


--在窗口之间跳转
map("n", "<leader>wt", "<C-w>h", opt(n_t,s_t))
map("n", "<leader>wn", "<C-w>j", opt(n_t,s_t))
map("n", "<leader>wr","<C-w>k", opt(n_t,s_t))
map("n", "<leader>ws", "<C-w>l", opt(n_t,s_t))


-- 统一设计原则:上与右是加, 左与下是减,调整垂直窗口是上下,调整水平窗口是左右
--垂直显示区域 -是减少+是增加, 是针对当前窗口而言的
map("n", "<s-up>", ":vertical resize +2<CR>", opt(n_t,s_t))
map("n", "<s-down>", ":vertical resize -2<CR>", opt(n_t,s_t))
-- 水平显示区域, 是针对当前窗口而言的
map("n", "<s-right>", ":resize +2<CR>", opt(n_t,s_t))
map("n", "<s-left>", ":resize -2<CR>", opt(n_t,s_t))

-- 等比例
map("n", "<leader>=", "<C-w>=", opt(n_t,s_t))


-- 退出与关闭
map("n", "<leader>qq", ":q!<CR>", opt(n_t,s_t))
map("n", "<leader>ww", ":w<cr>", opt(n_t,s_t))
map("n", "<leader>wq", ":wq<cr>", opt(n_t,s_t))
map("n", "<leader>cc", ":close<cr>", opt(n_t,s_t))

-- 按下f6之后自动加载source命令
map("n","<leader>ss",":source %",opt(n_t,s_t))


--关于buffer的操作
map("n","<leader>bn",":bn<cr>",opt(n_t,s_t))
map("n","<leader>br",":bp<cr>",opt(n_t,s_t))
map("n",")",":bn<cr>",opt(n_t,s_t))
map("n","(",":bp<cr>",opt(n_t,s_t))

map("n","<leader>bd",":bd!<cr>",opt(n_t,s_t))
map("n","<leader>bls",":ls<cr>",opt(n_t,s_t))

--关于tab的操作
map("n","<leader>tn",":tabn<cr>",opt(n_t,s_t))
map("n","<leader>tr",":tabp<cr>",opt(n_t,s_t))
map("n","<leader>tt",":tabfirst<cr>",opt(n_t,s_t))
map("n","<leader>ts",":tablast<cr>",opt(n_t,s_t))
map("n","<leader>tls",":tabs<cr>",opt(n_t,s_t))
map("n","<leader>td",":tabclose<cr>",opt(n_t,s_t))
map("n","<leader>ty",":tabnew ",opt(n_t,s_f))
map("n",'<leader>tf',":tabfind ",opt(n_t,s_f))
map("n","<leader>to",":tabonly<cr>",opt(n_t,s_f))

map("v","<leader>y",'"*y',opt(n_t,s_t)) --粘贴到系统剪切板中
map("n","<leader>Y",'G^Vgg"*y',opt(n_t,s_t)) --选中全文粘贴到系统剪切板中

--开启与关闭折行
map("n","<F7>",":set wrap<cr>",opt(n_t,s_f))
map("n","<S-F7>",":set nowrap<cr>",opt(n_t,s_f))

map("i","<C-z><C-z>","<C-o>zz",opt(n_t,s_t))

-- 执行当前目录下的build脚本
map("n","<leader>wb",":w<cr>:!pwsh -f build.ps1<cr><cr>",opt(n_t,s_t))

-- 执行当前目录下的build脚本,带上当前文件名
map("n","<leader>wB",":w<cr>:!pwsh -f build.ps1 %<cr><cr>",opt(n_t,s_t))

-- 原来的键位兼容
map({"n","x"},"hr","r",opt(n_t,s_t))
map({"n","x"},"hR","R",opt(n_t,s_t))
map({"n","x"},"hs","s",opt(n_t,s_t))
map({"n","x"},"hS","S",opt(n_t,s_t))
map({"n","x"},"ht","t",opt(n_t,s_t))
map({"n","x"},"hT","T",opt(n_t,s_t))
map({"n","x"},"hn","n",opt(n_t,s_t))
map({"n","x"},"hN","N",opt(n_t,s_t))

map({"n","x"},"h;",";",opt(n_t,s_t))
map({"n","x"},"h:",":",opt(n_t,s_t))
map({"n","x"},"hO","O",opt(n_t,s_t))
map({"n","x"},"ho","o",opt(n_t,s_t))
map({"n","x"},"hi","i",opt(n_t,s_t))
map({"n","x"},"hI","I",opt(n_t,s_t))
map({"n","x"},"ha","a",opt(n_t,s_t))
map({"n","x"},"hA","A",opt(n_t,s_t))

-- 将宏录制换掉, 太容易误触了
map({"n"},"q","<Nop>",opt(n_t,s_t))
map({"n"},"hq","q",opt(n_t,s_t))

-- luasnip 的选择节点的映射
map({"i","s"}, "<C-n>", "<Plug>luasnip-next-choice",opt(n_t,s_t))
map({"i","s"}, "<C-r>", "<Plug>luasnip-prev-choice",opt(n_t,s_t))

map({"n"}, "<F3>", ":NvimTreeToggle<cr>",opt(n_t,s_t))

