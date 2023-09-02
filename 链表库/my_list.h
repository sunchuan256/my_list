//my_list.h
//2023.9.2完成该库,目标取代vector

//主要开发者:

//sun_x_chuan123
//haodedoge

//特别感谢:


//bilibili __乐达__
//bilibili __孙川__曾经的狗__

#ifndef MY_LIST_H
#define MY_LIST_H

#include <iostream>
template<class T>
class Node
{
public:
	T data;
	Node* next;
};
namespace my_List
{
	template<class T>
	class List
	{
	public:
		List();
		List(const List<T>& list);//搞一个拷贝构造器
		~List();
		void push_back(T&& val);
		void push_back(const T& val);
		void push_back();
		void push_head(T&& val);
		void push_head(const T& val);
		void push_head();
		void clear();
		bool erase(size_t node);
		bool erase(size_t node, size_t del_size);
		void print_list();
		size_t size();
		void reserve(size_t size);
		std::string error();
		bool operator==(List<T>& list);
		bool operator!=(List<T>& list);
		bool operator>(List<T>& list);
		bool operator<(List<T>& list);
		bool operator>=(List<T>& list);
		bool operator<=(List<T>& list);
		T& operator[](size_t i) throw(std::string);
		List<T>& operator=(const List<T>& list);
	private:
		Node<T>* head;
		bool del_node(size_t node);
		std::string Error;
	};

	template <class T>
	List<T>::List()
	{
		head = NULL;
		Error = "NULL\n";
	}


	template <class T>
	List<T>::~List()
	{
		Node<T>* temp1 = head;
		Node<T>* temp2 = head;
		while (temp1 != NULL)
		{
			temp2 = temp2->next;
			delete temp1;
			temp1 = temp2;
			//std::cout << "已删除当前节点\n";
		}
	}


	template <class T>
	List<T>::List(const List<T>& list)//搞一个拷贝构造器
	{
		//std::cout << "进入拷贝构造器\n";
		// 创建一个空链表
		this->clear();
		head = NULL;

		// 遍历原链表，复制节点
		Node<T>* current = list.head;
		while (current != NULL)
		{
			// 复制节点数据
			T data = current->data;

			// 将新节点插入到新链表的末尾
			push_back(data);

			current = current->next;
		}
		//std::cout << "离开拷贝构造器\n";

	}


	template<class T>
	void List<T>::push_back()
	{
		Node<T>* new_node = new Node<T>;
		new_node->next = NULL;
		//是空链表
		if (head == NULL)
		{
			head = new_node;
			//std::cout << "新节点添加成功\n";
		}
		else
		{
			//不是空链表
			Node<T>* temp = head;
			//移动到尾部
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			//std::cout << "新节点添加成功\n";
		}
	}


	template <class T>
	void List<T>::push_back(const T& val)
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = val;
		new_node->next = NULL;
		//是空链表
		if (head == NULL)
		{
			head = new_node;
			//std::cout << "新节点添加成功\n";
		}
		else
		{
			//不是空链表
			Node<T>* temp = head;
			//移动到尾部
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			//std::cout << "新节点添加成功\n";
		}
	}


	template <class T>
	void List<T>::push_back(T&& val)
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = val;
		new_node->next = NULL;
		//是空链表
		if (head == NULL)
		{
			head = new_node;
			//std::cout << "新节点添加成功\n";
		}
		else
		{
			//不是空链表
			Node<T>* temp = head;
			//移动到尾部
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			//std::cout << "新节点添加成功\n";
		}
	}


	template <class T>
	void List<T>::push_head()
	{
		Node<T>* new_node = new Node<T>;
		new_node->next = NULL;
		//是空链表
		if (head == NULL)
		{
			head = new_node;
			std::cout << "新节点添加成功\n";

		}
		else
		{
			Node<T>** p_head = &head;
			new_node->next = head;
			*p_head = new_node;
			std::cout << "新节点添加成功\n";

		}
	}

	template <class T>
	void List<T>::push_head(T&& val)
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = val;
		new_node->next = NULL;
		//是空链表
		if (head == NULL)
		{
			head = new_node;
			//std::cout << "新节点添加成功\n";

		}
		else
		{
			Node<T>** p_head = &head;
			new_node->next = head;
			*p_head = new_node;
			//std::cout << "新节点添加成功\n";

		}
	}


	template <class T>
	void List<T>::push_head(const T& val)
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = val;
		new_node->next = NULL;
		//是空链表
		if (head == NULL)
		{
			head = new_node;
			//std::cout << "新节点添加成功\n";

		}
		else
		{
			Node<T>** p_head = &head;
			new_node->next = head;
			*p_head = new_node;
			//std::cout << "新节点添加成功\n";

		}
	}

	template <class T>
	void List<T>::clear()
	{
		//空链表直接返回
		if (head == NULL)
		{
			return;
		}
		Node<T>* temp1 = head;
		Node<T>* temp2 = head;
		while (temp1 != NULL)
		{
			temp2 = temp2->next;
			delete temp1;
			temp1 = temp2;
			std::cout << "已删除当前节点\n";
		}
		head = NULL;
	}


	template <class T>
	size_t List<T>::size()
	{
		size_t count = 0;
		Node<T>* temp = head;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}


	template <class T>
	bool List<T>::del_node(size_t node)
	{
		//先获取链表长度,超过了返回错误
		size_t list_size = this->size();
		if (node >= list_size)
		{
			Error = "要访问及删除的节点超过链表长度\n";
			return 1;
		}
		Node<T>* temp = head;
		//before_del用于记录要删除的那一段之前的那个节点,便于删除后连接链表
		Node<T>* before_del = head;
		//after_del用于记录要删除的那一段之后的那个节点,便于删除后连接链表
		Node<T>* after_del = NULL;
		//用于更改头指针
		Node<T>** p_head = &head;
		//定位到指定节点,如果从头开始删除,before_del和头指针共同指向第一个节点,不执行记录
		for (size_t i = 0; i < node; i++)
		{
			//记录下要删除的那一段之前的那个节点
			if (i == node - 1)
			{
				before_del = temp;
				//std::cout << "before_del成功记录了第" << i << "节点" << before_del << '\n';
			}
			temp = temp->next;
			//std::cout << "temp偏移到了下一位" << temp << '\n';
		}
		//temp指向要删除的节点
		//删除以及拼接链表
		if (head == temp)
		{
			//删除的是头节点
			head = before_del->next;
			delete before_del;
			before_del = NULL;
		}
		else
		{
			after_del = temp->next;
			delete temp;
			temp = NULL;
			before_del->next = after_del;
		}
		return 0;
	}


	template <class T>
	bool List<T>::erase(size_t node)
	{
		bool result = del_node(node);
		return result;
	}


	template <class T>
	bool List<T>::erase(size_t node, size_t del_size)
	{
		//如果要删除的长度过长超出链表范围,则删除node及其后面的全部节点
		//先获取链表长度,超过了返回错误
		//最后只会删除temp个节点
		bool resault = 0;
		size_t list_size = this->size();
		size_t temp = del_size;
		if (node >= list_size)
		{
			Error = "要访问及删除的节点超过链表长度\n";
			return 1;
		}
		//std::cout << list_size - node << '\n';
		//std::cout << del_size << '\n';
		if (list_size - node < del_size)
		{
			//std::cout << "list_size - node < del_size\n";
			temp = list_size - node;
			resault = 1;
			Error = "要访问及删除的节点超过链表长度\n";
			//std::cout << temp << '\n';
		}
		for (size_t i = 0; i < temp; i++)
		{
			del_node(node);
		}
		return resault;
	}


	template <class T>
	void List<T>::print_list()
	{
		Node<T>* temp = head;
		while (temp != NULL)
		{
			std::cout << "当前节点数据:" << temp->data << '\n';
			temp = temp->next;
		}
	}

	template <class T>
	void List<T>::reserve(size_t size)
	{
		size_t list_size = this->size();
		size_t push_count = size - list_size;
		//如果要预分配的空间小于等于当前节点个数，则不进行操作
		if (size <= list_size)
		{
			return;
		}
		for (size_t i = 0; i < push_count; i++)
		{
			push_back();
		}
	}

	template <class T>
	std::string List<T>::error()
	{
		return Error;
	}


	template <class T>
	bool List<T>::operator==(List<T>& list)
	{
		return size() == list.size();
	}


	template <class T>
	bool List<T>::operator!=(List<T>& list)
	{
		return size() != list.size();
	}


	template <class T>
	bool List<T>::operator>(List<T>& list)
	{
		return size() > list.size();
	}


	template <class T>
	bool List<T>::operator<(List<T>& list)
	{
		return size() < list.size();
	}


	template <class T>
	bool List<T>::operator<=(List<T>& list)
	{
		return size() <= list.size();
	}


	template <class T>
	bool List<T>::operator>=(List<T>& list)
	{
		return size() >= list.size();
	}



	template<class T>
	T& List<T>::operator[](size_t i) throw(std::string)
	{
		size_t list_size = this->size();
		Node<T>* temp = this->head;
		//越界访问
		if (i >= list_size)
		{
			throw std::string("error:越界访问\n");
		}

		for (size_t i_ = 0; i_ < i; i_++)
		{
			temp = temp->next;
		}

		return temp->data;

	}


	template <class T>
	List<T>& List<T>::operator=(const List<T>& list)
	{
		size_t list_size = list.size();
		this->clear();//清空这个链表
		//把错误信息也复制过去
		Error = list.Error;
		//std::cout << "错误信息复制成功\n";
		if (this == &list)
		{
			//不可以自己给自己赋值
			return list;
		}

		//如果赋值的链表为空链表
		if (list_size == 0)
		{
			return list;
		}

		for (size_t i = 0; i < list_size; i++)
		{
			this->push_back(list[i]);
			std::cout << "第" << i << "个节点复制成功\n";

		}
		return *this;
	}

}

#endif