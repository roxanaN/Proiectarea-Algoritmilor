#include <algorithm>
#include <fstream>
// #include <queue>
// #include <utility>
#include <vector>

using namespace std;

class Task {
 public:
	void solve() {
		// read_input();
		print_output(get_result());
	}

 private:
	int n;
    bool ok;
    vector<int> dists;

	void read_input() {
		ifstream fin("in");
        dists.push_back(-1);

		fin >> n;

        int first;
        fin >> first;
        dists.push_back(first);
        
		for (int i = 2, d; i <= n; i++) {
			fin >> d;
            if (d == 0) {
                ok = false;
                fin.close();

                return;
            }

			dists.push_back(d);
		}
		
        ok = true;
		fin.close();
	}

	vector<int> get_result() {
		vector<int> sol;

        sol.push_back(-1);

		return sol;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");

		fout << result.size() << '\n';
		for (const auto& v : result) {
			fout << v << '\n';
		}

		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;

	return 0;
}
