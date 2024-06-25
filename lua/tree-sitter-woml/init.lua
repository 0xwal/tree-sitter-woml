local parser_config = require("nvim-treesitter.parsers").get_parser_configs()

vim.cmd([[
    augroup WomlFiletype
        autocmd!
        autocmd BufRead,BufNewFile *.woml set filetype=woml
    augroup END
]])

parser_config.woml = {
	install_info = {
		url = "https://github.com/0xWaleed/tree-sitter-woml.git", -- local path or git repo
		files = { "src/parser.c" }, -- note that some parsers also require src/scanner.c or src/scanner.cc
		branch = "main",
		-- optional entries:
	},
	highlights = true,
}
