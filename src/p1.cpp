#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>
#include <iostream>

#define NON_EXISTENCE -1

using namespace std;


class Task {
 public:
	void solve() {
		read_input();
		print_output();
	}

 private:
	int n;
    bool ok = true;
    map<int, vector<int>> dists;

	void read_input() {
		ifstream fin("p1.in");

		fin >> n;

		for (int i = 1, d; i <= n; i++) {
            /* Citim distanta de la radacina la nodul i.
               Consideram distanta ca fiind nivelul pe care se gaseste nodul i. */
			fin >> d;

            /* Daca exista alt nod fara parinte,
               in afara de primul nod citit (radacina),
               input-ul nu este valid.
               Nu vom continua. */ 
            if (d == 0 && i != 1) {
                ok = false;
                break;
            }

            //  In caz contrar, adaugam nodul i la nivelul citit
			dists[d].push_back(i);
		}
		
		fin.close();
	}

	void print_output() {
		ofstream fout("p1.out");

        /* Daca nu exista solutie,
           iar aceasta problema poate fi detectata la citire */
        if (!ok) {
            fout << NON_EXISTENCE << '\n';
            fout.close();

            return;
        }

        stringstream output;
        int lvl = dists.size();
        int m = n - 1;
        int dist;
        int newParent = 1;
        int parent = newParent;

        // Construiesc output-ul. Adaug numarul de muchii
		output << m << '\n';

		for (dist = 1; dist < lvl; ++dist) {
            /* Verificam daca exista nod, pe nivelul curent.
               Ar trebui sa se gaseasca noduri pe fiecare dintre cele lvl nivele */
            if (dists[dist].empty()) {
                output.str(string());
                output << NON_EXISTENCE << '\n';
                break;
            }

            /* Daca inputul este valid, retin ultimul nod adaugat
               pe nivelul curent, pentru a fi parinte pentru
               nodurile de pe nivelul urmator. */
            for (auto node : dists[dist]) {
                output << parent << " " << node << '\n';
                newParent = node;
            }
            
            // Actualizez parintele, pentru nivelul urmator
            parent = newParent;
		}

        fout << output.str();
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;

	return 0;
}
