#include <iostream>
#include <vector>
#include <algorithm>
struct EDGE {
	int u, v, w;
	EDGE(int u, int v, int w) : u(u), v(v), w(w) {}
	bool operator<(const EDGE& comp) const {
		return w < comp.w;
	}
};
// union-find structure
class union_find final
{
public:
	union_find(const int N) : number_of_V(N) {
		parents.resize(N, 0);
	}
	void makeset(int u) {
		parents[u] = u;
	}
	int find(int u) {
		if (u != parents[u])
			parents[u] = find(parents[u]);
		return parents[u];
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		parents[v] = u;
	}
private:
	int number_of_V{ 0 };
	std::vector<int> parents{};
};
std::vector<EDGE> kruskal(std::vector<EDGE>& edges, const int N)
{
	union_find uf(N);
	for (int i = 0; i < N; i++) {
		uf.makeset(i);
	}
	std::vector<EDGE> ret;
	sort(edges.begin(), edges.end());
	for (auto& edge : edges) {
		if (uf.find(edge.u) != uf.find(edge.v)) {
			ret.push_back(edge);
			uf.merge(edge.u, edge.v);
		}
	}
	return ret;
}
int main(void)
{
	std::vector<EDGE> edges;
	int N = 6;
	edges.push_back({ 0, 1, 2 }); // A-B, 2
	edges.push_back({ 0, 2, 1 }); // A-C, 1
	edges.push_back({ 1, 2, 2 }); // B-C, 2
	edges.push_back({ 1, 3, 1 }); // B-D, 1
	edges.push_back({ 2, 3, 2 }); // C-D, 2
	edges.push_back({ 2, 4, 3 }); // C-E, 3
	edges.push_back({ 3, 4, 3 }); // D-E, 3
	edges.push_back({ 3, 5, 4 }); // D-F, 4
	edges.push_back({ 4, 5, 1 }); // E-F, 1
	auto result = kruskal(edges, N);
	std::cout << "-- °á°ú --\n";
	int total_weights = 0;
	for (auto& edge : result) {
		std::cout << static_cast<char>(edge.u + 'A') << "-" << static_cast<char>(edge.v + 'A') << ", weight=" << edge.w << std::endl;
		total_weights += edge.w;
	}
	std::cout << "MST's total weight = " << total_weights << std::endl;
}
