#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include "streamcorr.h"

using namespace std;

int n;
vector<int> a;
vector<int> b;

struct equation {
	int a;
	char op;
	int b;
	long long ans;
};

struct solution {
	equation *eqs; // NULL means impossible, otherwise length == n
};

solution read_sol(istream& in, void (*error)(const char *err, ...)) {
	solution ret;

	while (isspace(in.peek())) in.get();

	if(in.peek() == 'i' || in.peek() == 'I') { // must be impossible
		string line;
		in >> line;

		if(strcasecmp(line.c_str(), "impossible") != 0)
			error("Invalid first line: %s", line.c_str());

		ret.eqs = NULL;
	} else {
		// Must contain exactly n equations
		ret.eqs = new equation[n];
		for(int i = 0; i < n; i++) {
			char eqsign;
			if(!(in >> ret.eqs[i].a >> ret.eqs[i].op >> ret.eqs[i].b >> eqsign >> ret.eqs[i].ans) || eqsign != '=')
				error("Equation %d is invalid", i + 1);
		}
	}

	return ret;
}

void check_valid(solution sol, void (*error)(const char *err, ...)) {
	if(sol.eqs == NULL) return;

	map<long long, int> used;
	for(int i = 0; i < n; i++) {
		if(sol.eqs[i].a != a[i]) error("First number in equation %d is %d but must be %d", i+1, sol.eqs[i].a, a[i]);
		if(sol.eqs[i].b != b[i]) error("Second number in equation %d is %d but must be %d", i+1, sol.eqs[i].b, b[i]);

		if(sol.eqs[i].op != '+' && sol.eqs[i].op != '-' && sol.eqs[i].op != '*')
			error("Invalid operator '%c' in equation %d", sol.eqs[i].op, i+1);

		long long ans;
		if(sol.eqs[i].op == '+') ans = (long long)a[i] + (long long)b[i];
		if(sol.eqs[i].op == '-') ans = (long long)a[i] - (long long)b[i];
		if(sol.eqs[i].op == '*') ans = (long long)a[i] * (long long)b[i];
		if(sol.eqs[i].ans != ans) error("Answer in equation %d is %lld but must be %lld", i+1, sol.eqs[i].ans, ans);

		if(used.find(ans) != used.end()) error("Duplicate answer %lld in equations %d and %d", ans, used[ans], i+1);
		used[ans] = i + 1;
	}
}

int main(int argc, char **argv) {
	init_io(argc, argv);

	// reading input
	judge_in >> n;
	for(int i = 0; i < n; i++) {
		int na, nb;
		judge_in >> na >> nb;
		a.push_back(na);
		b.push_back(nb);
	}

	// Read judge and contestant output
	solution judge = read_sol(judge_ans, judge_error);
	solution team = read_sol(author_out, report_error);
	
	// do the real checking
	check_valid(judge, judge_error);
	check_valid(team, report_error);

	if(judge.eqs == NULL && team.eqs != NULL) {
		judge_error("Team found a valid solution but jury said 'impossible'");
	} else if(judge.eqs != NULL && team.eqs == NULL) {
		report_error("Team said 'impossible' but jury has a valid solution");
	}

	/* Check for trailing output in author file. */
	string trash;
	if (judge_ans  >> trash) judge_error("Trailing output in judge data");
	if (author_out >> trash) report_error("Trailing output in team output");

	/* Yay! */
	accept();
	return 0;
}
