#ifndef TREE_CPP
#define TREE_CPP
#include"Tree.h"
template<class K, class T>
typename tree<K, T>::node_ptr tree<K, T>::create_node(const K& key, const T& info)
{
	node_ptr new_node = new node();
	new_node->key = key;
	new_node->info = info;
	return new_node;
}

template<class K, class T>
void tree<K, T>::add(node_ptr root, const K& key, const T& info)
{
	if (key < root->key)
	{
		if (root->left != nullptr)
			add(root->left, key, info);
		else
		{
			root->left = create_node(key, info);
			length++;
			root->left->parent = root;
		}
	}
	if (key > root->key)
	{
		if (root->right != nullptr)
			add(root->right, key, info);
		else
		{
			root->right = create_node(key, info);
			length++;
			root->right->parent = root;
		}
	}
	if (key == root->key)
	{
		root->info = info;
	}
}

template<class K, class T>
void tree<K, T>::output(node_ptr root, std::ostream& out)  const
{
	if (!root)
		return;
	output(root->right, out);
	out << root->key << '\t' << root->info << std::endl;
	output(root->left, out);
}

template<class K, class T>
T* tree<K, T>::find(node_ptr root, const K& key)
{
	if (!root)
		return nullptr;
	if (root->key == key)
		return &(root->info);
	if (key < root->key)
		return find(root->left, key);
	if (key > root->key)
		return find(root->right, key);
}

template<class K, class T>
void tree<K, T>::clear(node_ptr& root)
{
	if (!root)
		return;
	clear(root->left);
	node_ptr right_node = root->right;
	delete root;
	root = nullptr;
	length--;
	clear(right_node);
}

template<class K, class T>
void tree<K, T>::fill(node_ptr root)
{
	if (!root)
		return;
	this->add(root->key, root->info);
	fill(root->left);
	fill(root->right);
}

template<class K, class T>
void tree<K, T>::keys(node_ptr root, std::vector<K>& key_collection)
{
	if (!root)
		return;
	keys(root->left, key_collection);
	key_collection.push_back(root->key);
	keys(root->right, key_collection);
}

template<class K, class T>
bool tree<K, T>::empty()
{
	return !root;
}

template<class K, class T>
std::vector<K> tree<K, T>::keys()
{
	std::vector<K> key_collection;
	keys(root, key_collection);
	return key_collection;
}

template<class K, class T>
tree<K, T>::tree(const tree<K, T>& tree_object)
{
	*this = tree_object;
}

template<class K, class T>
tree<K, T>& tree<K, T>::operator=(const tree<K, T>& tree_object)
{
	if (this == &tree_object)
		return *this;
	clear();
	fill(tree_object.root);
}

template<class K, class T>
T* tree<K, T>::operator[](const K& key)
{
	return find(key);
}

template<class K, class T>
tree<K, T>::~tree()
{
	clear();
}

template<class K, class T>
size_t tree<K, T>::size() const
{
	return length;
}

template<class K, class T>
void tree<K, T>::add(const K& key, const T& info)
{

	if (!root)
	{
		root = create_node(key, info);
		length++;
	}
	else
		add(root, key, info);


}

template<class K, class T>
T* tree<K, T>::find(const K& key)
{
	return find(root, key);
}


template<class K, class T>
void tree<K, T>::clear()
{
	clear(root);
}

template<class K, class T>
std::ostream& operator<<(std::ostream& out, const tree<K, T>& tree_object)
{
	tree_object.output(tree_object.root, out);
	return out;
}

#endif
