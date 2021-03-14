#include <iostream>
#include <stdint.h>

namespace nxstl {

	template<typename T>
	class SingleLinkedList
	{
		template<typename TT>
		class SingleLinkedListNode {
			public:
			TT data;
			SingleLinkedListNode<TT> *next;
			SingleLinkedListNode(TT d) : data(d), next(nullptr) {}

			// stream operator overriding
			friend std::istream& operator>>(std::istream &is, SingleLinkedListNode<TT> &node)
			{
				is >> node.data;
				return is;
			}
			friend std::ostream& operator<<(std::ostream &os, const SingleLinkedListNode<TT> &node)
			{
				os << node.data;
				return os;
			}
		};

		protected:
		SingleLinkedListNode<T> *root;
		uint32_t element_no;

		public:
		SingleLinkedList() : root(nullptr), element_no(0) {}
		SingleLinkedList(T& d) {
			root = new SingleLinkedListNode<T>(d);
			element_no = 0;
		}

		void append(T data) {
			if(nullptr == root) {
				root = new SingleLinkedListNode<T>(data);
			}
			else
			{
				// find the last item
				auto p = root;
				for(; p->next != nullptr; p = p->next);

				// insert new item at the end
				p->next = new SingleLinkedListNode<T>(data);
			}
			element_no++;
		}

		uint32_t size() const
		{
			return element_no;
		}


		// stream operator overriding
		friend std::istream& operator>>(std::istream &is, SingleLinkedList<T> &lst)
		{
			if (nullptr == lst.root) return is;

			for(auto p = lst.root; p != nullptr; p = p->next)
			{
				is >> *p;
			}

			return is;
		}

		friend std::ostream& operator<<(std::ostream &os, const SingleLinkedList<T> &lst)
		{
			if (nullptr == lst.root) return os;

			for(auto p = lst.root; p != nullptr; p = p->next)
			{
				os << *p;
			}

			return os;
		}

		~SingleLinkedList()
		{
			auto p = root;
			while(nullptr != p)
			{
				auto t = p;
				p = p->next;
				delete t;
			}
		}

	};

}