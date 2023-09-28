vim.cmd([[
function! MyQuickfix()  
  setlocal buftype=nofile bufhidden=delete nobuflisted  
  setlocal modifiable  
  setlocal nowrap  
  setlocal number  
  setlocal relativenumber  
  setlocal foldenable  
  setlocal foldmethod=marker  
  setlocal foldcolumn=0  
  setlocal foldlevel=0  
  normal! 0vG$  
  put! =system('ls ' . expand('~/myfile'))  
  normal! G0  
  normal! ggVGs/^\n//d  
  normal! gg  
endfunction  
  
command! MyQuickfix call MyQuickfix()
]])
