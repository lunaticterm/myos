call plug#begin('~/.vim/plugged')
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'jiangmiao/auto-pairs'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'sheerun/vim-polyglot'
Plug 'Mofiqul/dracula.nvim'
Plug 'pangloss/vim-javascript'
Plug 'leafgarland/typescript-vim'
Plug 'peitalin/vim-jsx-typescript'
Plug 'styled-components/vim-styled-components', { 'branch': 'main' }
Plug 'jparise/vim-graphql'
Plug 'ms-jpq/chadtree', {'branch': 'chad', 'do': 'python3 -m chadtree deps'}
Plug 'mhinz/vim-startify'
Plug 'shirk/vim-gas'
call plug#end()
let g:airline_theme='base16_dracula'
colorscheme dracula
set nu
let g:airline_powerline_fonts = 1
set pumheight=15
set pumwidth=10
let g:airline#extensions#tabline#enabled = 1  
inoremap <expr> <Tab> pumvisible() ? "\<C-n>" : "\<Tab>"
inoremap <expr> <S-Tab> pumvisible() ? "\<C-p>" : "\<S-Tab>"
nnoremap <C-b> :CHADopen<CR>
nnoremap tn :tabnew <CR>
nnoremap ZA ZQ
" nnoremap <C-t> :NERDTreeToggle<CR>
