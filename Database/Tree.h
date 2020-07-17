#ifndef TREE_H
#define TREE_H

#include<iostream>
#include<vector>
template<class K, class T>
class tree
{
	struct node;
	typedef node* node_ptr;
	struct node
	{
		K key;
		T info;
		node_ptr parent = nullptr, left = nullptr, right = nullptr;
	};

	node_ptr root = nullptr;
	size_t length = 0;

	node_ptr create_node(const K& key, const T& info);
	void add(node_ptr root, const K& key, const T& info);
	void output(node_ptr root, std::ostream& out) const;
	T* find(node_ptr root, const K& key);
	void clear(node_ptr& root);
	void fill(node_ptr root);
	void keys(node_ptr root, std::vector<K>& key_collection);

public:
	tree() = default;
	tree(const tree<K, T>& tree_object);
	tree<K, T>& operator=(const tree<K, T>& tree_object);
	T* operator[](const K& key);
	~tree();

	size_t size() const;
	void add(const K& key, const T& info);
	T* find(const K& key);
	void clear();
	bool empty();
	std::vector<K> keys();

	template<class K, class T>
	friend std::ostream& operator<<(std::ostream& out, const tree<K, T>& tree_object);

};

#include"Tree.cpp"
#endif
