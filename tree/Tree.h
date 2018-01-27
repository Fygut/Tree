#pragma once
#include "Element.h"

class TreeNode: public Element
{
public:
	TreeNode();
	~TreeNode();
	void add_parent(TreeNode * Pa1);
	void add_children(TreeNode * Pa1);
	TreeNode * get_perent();
	vector< TreeNode * > get_children();
	TreeNode * get_perent(TreeNode *Pa1);
	friend ostream& operator << (ostream& os, TreeNode * Pa1);
private:
	TreeNode * Parent;
	vector< TreeNode * > Children;
};


class Tree
{
public:
	Tree();
	Tree(string InputFileName);
	~Tree();
	void input(string & InputFileName);
	TreeNode * get_root();
	void out_tree_on_console(TreeNode * Pa1, size_t indent, vector<size_t> prev);
	void output(string OutputFileName);
	template< typename Ty1 >
	TreeNode * add_node(Ty1 elem, TreeNode * parent);
private:
	TreeNode * Root;
};

template< typename Ty1 >
TreeNode * Tree::add_node(Ty1 elem, TreeNode * parent)
{
	if(parent==nullptr)	{
		Root = new TreeNode;
		Root->add_parent(nullptr);
		Root->add_elem(elem);
		return Root;
	}
	else {
		TreeNode *child;
		child = new TreeNode;
		child->add_parent(parent);
		child->add_elem(elem);
		parent->add_children(child);
		return child;
	}
}