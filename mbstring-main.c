void draw_sep(char const start[static 1],
		char const end[static 1]) {
	fputs(start, stdout);
	size_t slen = mbstrlen(start, 0);
	size_t elen = 90 - mbstrlen(end, 0);
	for (size_t i = slen; i < elen; ++i) fputs(HBAR,stdout);
	fputs(end, stdout);
	fputc('\n',stdout);
}
