#include"stdafx.h"
#include"UnionFind.h"

UnionFind::UnionFind(int size) :m_size(size), m_components(size), m_sizeVector(size, 1)
{
	m_id.reserve(size);
	for (int i = 0; i < size; i++)
		m_id.emplace_back(i);
}

int UnionFind::find(int element)
{
	int root = m_id[element];
	while (root != m_id[root]) //find the root
		root = m_id[root];
	while (element != root) //path compression, what gives amortized time complexity
	{
		int next = m_id[element];
		m_id[element] = root;
		element = next;
	}
	return root;
}

/*
*if they have the same root
*does path compression along the way
*/
bool  UnionFind::isConnected(int element1, int element2) { return (find(element1) == find(element1)); }

int UnionFind::size() const { return m_size; }

int UnionFind::components() const { return m_components; }

void UnionFind::unify(int element1, int element2)
{
	int root1 = find(element1), root2 = find(element2);
	if (root1 == root2) return;
	if (m_sizeVector[root1] < m_sizeVector[root2])
	{
		m_id[root1] = m_id[root2];
		m_sizeVector[root2] += m_sizeVector[root1];
	}
	else
	{
		m_id[root2] = m_id[root1];
		m_sizeVector[root1] += m_sizeVector[root2];
	}
	m_components--;
}