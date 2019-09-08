#include <iostream>
using namespace std;

namespace cyx{
	typedef struct NODE {
		NODE* left;
		NODE* right;
		NODE* parent;
		int key;

		NODE(const int& value) {
			key = value;
			left = NULL;
			right = NULL;
			parent = NULL;
		}
	}bst_node;

	class bst{
		public:
			bst();
			~bst();
			void Insert(const int& value);
			void Insert(bst_node* node);
			bst_node* Find(const int& value);
			void Delete(const int& value);
			void Clear(bst_node* root);
			void InorderTraversal(bst_node* node);
			void PostorderTraversal(bst_node* node);
			void PreorderTraversal(bst_node* node);
			void SequenceTraversal();
		protected:
			void Translate(bst_node* src, bst_node* swapnode);
			bst_node* TreeMin(bst_node* node);
		public:
			bst_node* m_root;
	};
}

