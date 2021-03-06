// UnionFindPathCompression.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"UnionFind.h"
#include<iostream>

int findCircleNum(std::vector<std::vector<int>>& M) {	
	if (M.size() == 0) return 0;
	UnionFind mySet(M.size());
	for (size_t i = 0; i < M.size(); i++)	
		for (size_t j = 0; j < M[i].size(); j++)		
			if (i != j && M[i][j])
				mySet.unify(i, j);
	return mySet.components();
}

int main()
{
	//testing the UnionFind class on the friends circle problem	
	/*
	*There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C.
	*And we defined a friend circle is a group of students who are direct or indirect friends.
	*Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
	*And you have to output the total number of friend circles among all the students.
	*/
	std::vector<std::vector<int>> friends = { {1,1,0},{1,1,0},{0,1,1} };
	std::cout << findCircleNum(friends)<<std::endl;
	std::vector<std::vector<int>> friends2 = { { 1,1,0 },{ 1,1,0 },{ 0,0,1 } };
	std::cout << findCircleNum(friends2) << std::endl;
	std::cin.get();
    return 0;
}

