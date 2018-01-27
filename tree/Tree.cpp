#include "Tree.h"


TreeNode::TreeNode()
{
}

TreeNode::~TreeNode()
{
}

void TreeNode::add_parent(TreeNode * Pa1) 
{
	Parent = Pa1;
}

void TreeNode::add_children(TreeNode * Pa1)
{
	Children.push_back(Pa1);
}

TreeNode * TreeNode::get_perent()
{
	return this->Parent;
}

TreeNode * TreeNode::get_perent(TreeNode * Pa1)
{
	return Pa1->Parent;
}

vector< TreeNode * > TreeNode::get_children()
{
	return this->Children;
}


Tree::Tree()
{
	Root = nullptr;
}

Tree::Tree(string InputFileName)
{
	Root = nullptr;
	input(InputFileName);
}

Tree::~Tree()
{
}

bool isInteger(string str)
{
	size_t pos = 0;
	if (str[pos] == '-')
		++pos;
	return str.find_first_not_of("0123456789", pos) == std::string::npos;
}

bool isFloat(string str)
{
	size_t pos = 0, count = 0;
	
	if (str[pos] == '-')
		++pos;
	bool flag = str.find_first_not_of(".0123456789", pos) == std::string::npos;
	for (; flag && pos < str.size(); pos++) {
		pos = str.find('.', pos);
		if (pos != string::npos)count++;
		else break;
		if (count > 1) return false;
	}
	
	return flag;
}

bool isString(string str)
{
	return str[0] == '\"' && str.back() == '\"';
}



void Tree::input(string & InputFileName)
{
	ifstream InputFile(InputFileName);
	TreeNode *Pa1;
	if (!InputFile.is_open())throw "Error open input file";
	else
	{
		string str;
		Pa1 = Root;
		while (InputFile >> str)
		{
			if (str == ")") {
				if (Pa1 == nullptr) throw "Error in input file";
				Pa1 = Pa1->get_perent();
				continue; 
			}
			if (isString(str)) {
				str.erase(str.begin());
				str.erase(str.end() - 1);
				Pa1 = add_node(str, Pa1);
				continue;
			}
			if (isInteger(str)) {
				Pa1 = add_node(stoi(str), Pa1);
				continue;
			}
			if (isFloat(str)) {
				Pa1 = add_node(stod(str), Pa1);
				continue;
			}
			throw "Error input data";
		}
	}
	if (Pa1 != nullptr) throw "Error input data check )";
	InputFile.close();
}

TreeNode * Tree::get_root()
{
	return Root;
}


void Tree::out_tree_on_console(TreeNode * Pa1, size_t indent, vector<size_t> prev)
{
	if (Pa1 == nullptr) return;
	for (size_t i = 0; i < indent; i++)
		if (i == indent - 1)
			cout << "|---" << '>';
		else {
			bool flag = true;
			for (size_t j = 0; j < prev.size(); j++)
				if (i == prev[j]) { cout << "|  "; flag = false; break; }
			if(flag)cout << "   ";
		}
	cout << Pa1 << endl;
	for (size_t i = 0; i < Pa1->get_children().size(); i++)
	{
		if(Pa1->get_children().size() > 1&& i+1 != Pa1->get_children().size())
			prev.push_back( indent);
		out_tree_on_console(Pa1->get_children()[i], indent + 1, prev);
		if(Pa1->get_children().size() > 1&&prev.size()!=0)
			prev.erase(prev.begin() + prev.size() - 1);
	}
}

void Tree::output(string OutputFileName)
{
	ofstream OutputFile(OutputFileName);
	if (!OutputFile.is_open()) throw "Error open output file";
	vector< size_t > previous;
	size_t num = 0;
	TreeNode * Pa1;
	Pa1 = get_root();
	previous.push_back(0);

	while (Pa1 != nullptr) {
		OutputFile << Pa1 << " ";

		if (Pa1->get_children().size() > 0) {
				Pa1 = Pa1->get_children()[previous[num]];
				previous[num]++;
				num++;
				previous.push_back(0);
		}
		else {
			while (true && Pa1 != nullptr) {
				if (Pa1->get_children().size() <= previous[num]) {
					Pa1 = Pa1->get_perent();
					previous.erase(previous.begin() + previous.size() - 1);
					num--;
					OutputFile << ") ";
				}
				else {
					Pa1 = Pa1->get_children()[previous[num]];
					previous[num]++;
					num++;
					previous.push_back(0);
					break;
				}
			}
		}
	}
	OutputFile.close();
}

ostream & operator<<(ostream & os,  TreeNode * Pa1)
{
	if (Pa1->get_type() == integer)
		os << Pa1->get_ivalue();
	else if (Pa1->get_type() == floating)
		os << Pa1->get_dvalue();
	else if (Pa1->get_type() == character)
		os << '\"' << Pa1->get_svalue() << '\"';
	else
		throw "Error << type";

	return os;
}
