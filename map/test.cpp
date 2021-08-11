/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:13:04 by nelisabe          #+#    #+#             */
/*   Updated: 2021/08/11 14:32:22 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tree.hpp"
# include <functional>

using namespace ft;

template<typename Pair>
struct SelectFirst
{
	typename Pair::first_type &operator()(Pair &pair) const
	{
		return pair.first;
	}
	const typename Pair::first_type &operator()(const Pair &pair) const
	{
		return pair.first;
	}
};

template<typename T>
struct Select
{
	T &operator()(T &x) const
	{
		return x;
	}
	const T &operator()(const T &x) const
	{
		return x;
	}
};

int		main()
{
	Tree<int, Select<int>, std::less<int> >	tree;
	int		array[] = { 10, 7, 3, 8, 1, 5, 4, 6, 20, 15, 25, 13, 17, 16, 30, 29, 35 };

	std::cout << "Size: " << tree.Size() << std::endl;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		tree.Add(array[i]);
	tree.PrintWidth();
	std::cout << "----------\n";
	tree.Print();
	std::cout << "Size: " << tree.Size() << std::endl;
	std::cout << "----------\n";
	tree.Delete(10);
	tree.Print();
	std::cout << "Size: " << tree.Size() << std::endl;
	std::cout << "----------\n";
	tree.PrintWidth();
	std::cout << "Data found: " << tree.Find(6)->data << std::endl;
	std::cout << "Data found: ";
	if (tree.Find(99) == NULL)
		std::cout << "no\n";
	

	Tree<int, Select<int>, std::less<int> >	tree2;
	tree2.Add(4);
	tree2.Delete(4);
	tree2.Delete(5);
	std::cout << "Size: " << tree2.Size() << std::endl;
	// tree.Delete(20);
	// tree.Print();
	// // std::cout << "----------\n";
	// // tree.Delete(7);
	// // tree.Print();
	// std::cout << "----------\n";
	// tree.PrintWidth();

	return 0;
}