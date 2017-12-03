size(1500);
defaultpen(3);
bbox(white, Fill);

int workers = stdin;
int prodlines = stdin;
int maxx = 0;

pair[] intervals = new pair[workers];
for (int i = 0; i < workers; ++i) {
	int x1 = stdin;
	int x2 = stdin;
	intervals[i] = (x1, x2);
	maxx = max(maxx, x2);
}
bool[] outside = new bool[workers];
for (int i = 0; i < workers; ++i) {
	outside[i] = false;
	for (int j = 0; j < workers; ++j) {
		if (i != j && xpart(intervals[i]) < xpart(intervals[j]) && ypart(intervals[j]) < ypart(intervals[i])) {
			outside[i] = true;
		}
	}
}
int stepY = (int) (maxx/(workers+1));
int startY = (int) (stepY/2);
for (int i = 0; i < workers; ++i) {
	pen p = linewidth(5);
	if (outside[i]) {
		p = red+linewidth(5);
	}
	draw((xpart(intervals[i]), startY+stepY*i) -- (ypart(intervals[i]), startY+stepY*i), p);
}

shipout(bbox(xmargin=50, white, Fill));
