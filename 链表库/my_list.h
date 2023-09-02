//my_list.h
//2023.9.2��ɸÿ�,Ŀ��ȡ��vector

//��Ҫ������:

//sun_x_chuan123
//haodedoge

//�ر��л:


//bilibili __�ִ�__
//bilibili __�ﴨ__�����Ĺ�__

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
		List(const List<T>& list);//��һ������������
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
			//std::cout << "��ɾ����ǰ�ڵ�\n";
		}
	}


	template <class T>
	List<T>::List(const List<T>& list)//��һ������������
	{
		//std::cout << "���뿽��������\n";
		// ����һ��������
		this->clear();
		head = NULL;

		// ����ԭ�������ƽڵ�
		Node<T>* current = list.head;
		while (current != NULL)
		{
			// ���ƽڵ�����
			T data = current->data;

			// ���½ڵ���뵽�������ĩβ
			push_back(data);

			current = current->next;
		}
		//std::cout << "�뿪����������\n";

	}


	template<class T>
	void List<T>::push_back()
	{
		Node<T>* new_node = new Node<T>;
		new_node->next = NULL;
		//�ǿ�����
		if (head == NULL)
		{
			head = new_node;
			//std::cout << "�½ڵ���ӳɹ�\n";
		}
		else
		{
			//���ǿ�����
			Node<T>* temp = head;
			//�ƶ���β��
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			//std::cout << "�½ڵ���ӳɹ�\n";
		}
	}


	template <class T>
	void List<T>::push_back(const T& val)
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = val;
		new_node->next = NULL;
		//�ǿ�����
		if (head == NULL)
		{
			head = new_node;
			//std::cout << "�½ڵ���ӳɹ�\n";
		}
		else
		{
			//���ǿ�����
			Node<T>* temp = head;
			//�ƶ���β��
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			//std::cout << "�½ڵ���ӳɹ�\n";
		}
	}


	template <class T>
	void List<T>::push_back(T&& val)
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = val;
		new_node->next = NULL;
		//�ǿ�����
		if (head == NULL)
		{
			head = new_node;
			//std::cout << "�½ڵ���ӳɹ�\n";
		}
		else
		{
			//���ǿ�����
			Node<T>* temp = head;
			//�ƶ���β��
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			//std::cout << "�½ڵ���ӳɹ�\n";
		}
	}


	template <class T>
	void List<T>::push_head()
	{
		Node<T>* new_node = new Node<T>;
		new_node->next = NULL;
		//�ǿ�����
		if (head == NULL)
		{
			head = new_node;
			std::cout << "�½ڵ���ӳɹ�\n";

		}
		else
		{
			Node<T>** p_head = &head;
			new_node->next = head;
			*p_head = new_node;
			std::cout << "�½ڵ���ӳɹ�\n";

		}
	}

	template <class T>
	void List<T>::push_head(T&& val)
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = val;
		new_node->next = NULL;
		//�ǿ�����
		if (head == NULL)
		{
			head = new_node;
			//std::cout << "�½ڵ���ӳɹ�\n";

		}
		else
		{
			Node<T>** p_head = &head;
			new_node->next = head;
			*p_head = new_node;
			//std::cout << "�½ڵ���ӳɹ�\n";

		}
	}


	template <class T>
	void List<T>::push_head(const T& val)
	{
		Node<T>* new_node = new Node<T>;
		new_node->data = val;
		new_node->next = NULL;
		//�ǿ�����
		if (head == NULL)
		{
			head = new_node;
			//std::cout << "�½ڵ���ӳɹ�\n";

		}
		else
		{
			Node<T>** p_head = &head;
			new_node->next = head;
			*p_head = new_node;
			//std::cout << "�½ڵ���ӳɹ�\n";

		}
	}

	template <class T>
	void List<T>::clear()
	{
		//������ֱ�ӷ���
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
			std::cout << "��ɾ����ǰ�ڵ�\n";
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
		//�Ȼ�ȡ������,�����˷��ش���
		size_t list_size = this->size();
		if (node >= list_size)
		{
			Error = "Ҫ���ʼ�ɾ���Ľڵ㳬��������\n";
			return 1;
		}
		Node<T>* temp = head;
		//before_del���ڼ�¼Ҫɾ������һ��֮ǰ���Ǹ��ڵ�,����ɾ������������
		Node<T>* before_del = head;
		//after_del���ڼ�¼Ҫɾ������һ��֮����Ǹ��ڵ�,����ɾ������������
		Node<T>* after_del = NULL;
		//���ڸ���ͷָ��
		Node<T>** p_head = &head;
		//��λ��ָ���ڵ�,�����ͷ��ʼɾ��,before_del��ͷָ�빲ָͬ���һ���ڵ�,��ִ�м�¼
		for (size_t i = 0; i < node; i++)
		{
			//��¼��Ҫɾ������һ��֮ǰ���Ǹ��ڵ�
			if (i == node - 1)
			{
				before_del = temp;
				//std::cout << "before_del�ɹ���¼�˵�" << i << "�ڵ�" << before_del << '\n';
			}
			temp = temp->next;
			//std::cout << "tempƫ�Ƶ�����һλ" << temp << '\n';
		}
		//tempָ��Ҫɾ���Ľڵ�
		//ɾ���Լ�ƴ������
		if (head == temp)
		{
			//ɾ������ͷ�ڵ�
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
		//���Ҫɾ���ĳ��ȹ�����������Χ,��ɾ��node��������ȫ���ڵ�
		//�Ȼ�ȡ������,�����˷��ش���
		//���ֻ��ɾ��temp���ڵ�
		bool resault = 0;
		size_t list_size = this->size();
		size_t temp = del_size;
		if (node >= list_size)
		{
			Error = "Ҫ���ʼ�ɾ���Ľڵ㳬��������\n";
			return 1;
		}
		//std::cout << list_size - node << '\n';
		//std::cout << del_size << '\n';
		if (list_size - node < del_size)
		{
			//std::cout << "list_size - node < del_size\n";
			temp = list_size - node;
			resault = 1;
			Error = "Ҫ���ʼ�ɾ���Ľڵ㳬��������\n";
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
			std::cout << "��ǰ�ڵ�����:" << temp->data << '\n';
			temp = temp->next;
		}
	}

	template <class T>
	void List<T>::reserve(size_t size)
	{
		size_t list_size = this->size();
		size_t push_count = size - list_size;
		//���ҪԤ����Ŀռ�С�ڵ��ڵ�ǰ�ڵ�������򲻽��в���
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
		//Խ�����
		if (i >= list_size)
		{
			throw std::string("error:Խ�����\n");
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
		this->clear();//����������
		//�Ѵ�����ϢҲ���ƹ�ȥ
		Error = list.Error;
		//std::cout << "������Ϣ���Ƴɹ�\n";
		if (this == &list)
		{
			//�������Լ����Լ���ֵ
			return list;
		}

		//�����ֵ������Ϊ������
		if (list_size == 0)
		{
			return list;
		}

		for (size_t i = 0; i < list_size; i++)
		{
			this->push_back(list[i]);
			std::cout << "��" << i << "���ڵ㸴�Ƴɹ�\n";

		}
		return *this;
	}

}

#endif