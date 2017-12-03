size(1500);
defaultpen(3);
bbox(white, Fill);

int wells = stdin;
int pipes = stdin;

pair[] wellPts = new pair[wells];
for (int i = 0; i < wells; ++i) {
	int x = stdin;
	int y = stdin;
	wellPts[i] = (x, y);
}
for (int i = 0; i < pipes; ++i) {
	int well = stdin;
	--well;
	int x2 = stdin;
	int y2 = stdin;
	
	draw(wellPts[well] -- (x2,y2), linewidth(5));
}
for (int i = 0; i < wells; ++i) {
	dot(wellPts[i], red+linewidth(35));
}

shipout(bbox(xmargin=10, white, Fill));
