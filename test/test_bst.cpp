//标准库
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

//自定义头文件
#include "bst.h"
using namespace cyx;

int main(int argc, char* argv[]) {
	int num = 0;
	bst* tree = new bst();
	srand(time(0));
	cout << "origin:" << endl;
	for (int i = 0; i < 10; ++i) {
		int value = rand() % 100;
		num = value;
		tree->Insert(value);
		cout << value << " ";
	}
	cout << endl;
	cout << "InorderTraversal:" << endl;
	tree->InorderTraversal(tree->m_root);
	cout << endl;
	cout << "PreorderTraversal:" << endl;
	tree->PostorderTraversal(tree->m_root);
	cout << endl;
	cout << "PostorderTraversal:" << endl;
	tree->PostorderTraversal(tree->m_root);
	cout << endl;
	cout << "SequenceTraversal:" << endl;
	tree->SequenceTraversal();
	cout << endl;
	for (int i = 0; i < 10; ++i) {
		int value = rand() % 100;
		cout << "Find " << value << " ";
		cout << tree->Find(value) << endl;
	}
	cout << endl;
	cout << "delete " << num << ":" << endl;
	tree->Delete(num);
	cout << "now tree InorderTraversal:" << endl;
	tree->InorderTraversal(tree->m_root);
	cout << endl;

	delete tree;
	tree = NULL;
	return 0;
}
