#pragma once
#include"tree.h"
#include<filesystem>

namespace fs = std::filesystem;
class database
{
	std::string file_path;
	std::ios_base::openmode _openmode;


public:
	database(const std::string& path, std::ios_base::openmode _openmode = 0) :file_path(path), _openmode(_openmode) {}

	template<class K, class T>
	void	load_data(tree<K, T>& tree_collection);
	template<class K, class T>
	void	save_data(tree<K, T>& tree_collection);
	template<class K, class T>
	void print(tree<K, T>& tree_collection);

};


template<class K, class T>
inline void database::load_data(tree<K, T>& tree_collection)
{
	T current_object;

	std::ifstream fin(file_path, std::ios_base::in | _openmode);

	if (!fin.is_open())
	{
		std::ofstream fout(file_path, std::ios_base::out | _openmode);
		fout.close();
		return;
	}
	if (!_openmode)
	{
		while (fin >> current_object)
			tree_collection.add(current_object.key(), current_object);
	}
	else
	{
		std::uintmax_t f_size = fs::file_size(fs::path(file_path));
		while (fin.tellg() != f_size)
		{
			current_object.from_binary(fin);
			tree_collection.add(current_object.key(), current_object);
		}
	}
	fin.close();
}

template<class K, class T>
inline void database::save_data(tree<K, T>& tree_collection)
{
	std::ofstream fout(file_path, std::ios_base::out | std::ios_base::trunc | _openmode);

	if (!fout.is_open())
	{
		std::cerr << "error" << std::endl;
	}
	if (!_openmode)
		for (int key : tree_collection.keys())
		{

			fout << *tree_collection[key] << std::endl;
		}
	else
		for (int key : tree_collection.keys())
		{

			tree_collection[key]->to_binary(fout);
		}
	fout.close();
}

template<class K, class T>
inline void database::print(tree<K, T>& tree_collection)
{
	for (int key : tree_collection.keys())
	{
		std::cout << *tree_collection[key] << std::endl;
	}
}

