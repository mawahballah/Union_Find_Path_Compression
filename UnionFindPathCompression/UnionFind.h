#pragma once
#include<vector>
#include<algorithm>
class UnionFind {
private:
	std::vector<int> m_id,m_sizeVector;	
	int m_size,m_components;
public:
	UnionFind(int size);
	int find(int element);
	bool isConnected(int element1, int element2);
	int size() const;
	int components() const;
	void unify(int element1, int element2);
};
