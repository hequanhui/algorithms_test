#include <queue>
#include <unordered_set>
#include <vector>
#include <unordered_map>

const int width = 10;
const int height = 10;


struct Vertex
{
	int x;
	int y;
	bool block = false;
	Vertex(int x1, int y1) : x(x1), y(y1) {}
};
std::unordered_map<std::pair<int, int>, Vertex*> vertexMap;

Vertex* empty = new Vertex(-1, -1);

Vertex* getVertex(int x, int y) {
	auto key = std::pair<int, int>{ x, y };
	auto it = vertexMap.find(key);
	if (it == vertexMap.end()) {
		return empty;
	}
	return vertexMap[{x, y}];
}

void neighbors(Vertex* vert, std::vector<Vertex*>& neigh) {
	auto x = vert->x;
	auto y = vert->y;
	if (x > 0) {
		neigh.push_back(getVertex(x - 1, y));
	}

	if (y > 0) {
		neigh.push_back(getVertex(x, y - 1));
	}

	if (x < width -1) {
		neigh.push_back(getVertex(x + 1, y));
	}

	if (y < height - 1) {
		neigh.push_back(getVertex(x, y + 1));
	}
}


void bfs() {
	auto start = new Vertex(1, 1);
	vertexMap[{1, 1}] = start;

	auto frontier = std::queue<Vertex*>();
	frontier.push(start);

	auto visited = std::unordered_set<Vertex*>();
	visited.insert(start);

	while (!frontier.empty())
	{
		auto vertex = frontier.front();
		frontier.pop();
		auto neighb = std::vector<Vertex*>();
		neighbors(vertex, neighb);
		for (auto tmp : neighb) {
			if (visited.count(tmp)) {
				continue;
			}
			frontier.push(tmp);
			visited.insert(tmp);
		}
	}
}


int main() {
	bfs();
	return 0;
}