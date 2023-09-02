# my_list
#这是一个自制的链表库，我平时没事的时候闲的蛋疼写的
#我希望用于取代之前使用的vector库

my_list.h
2023.9.2完成该库,目标取代vector

主要开发者:

sun_x_chuan123
haodedoge

特别感谢:


bilibili __乐达__
bilibili __孙川__曾经的狗__

类模板List有以下方法：

向链表尾部添加节点：

void push_back(T&& val);      加入一个右值
void push_back(const T& val); 加入一个左值
void push_back();             加入一个节点

向链表头部添加节点：

void push_head(T&& val);      （和上面一样）
void push_head(const T& val); （和上面一样）
void push_head();             （和上面一样）

清空链表：
void clear();

删除节点：
bool erase(size_t node);       删除第node个节点
bool erase(size_t node, size_t del_size);从第node个节点向后删除del_size个节点

这个方法仅仅用于测试，现在已经无法使用：

void print_list();

返回链表长度：
size_t size();

提前预设空间，如果已经预设空间了，再次调用该方法，则如果size大于之前预设的空间，则在尾部增加 size - 之前预设的空间 个节点：
void reserve(size_t size);

返回错误信息（例如越界访问，删除范围大于链表长度）：
std::string error();

重载各个运算符比较链表长度：
bool operator==(List<T>& list);
bool operator!=(List<T>& list);
bool operator>(List<T>& list);
bool operator<(List<T>& list);
bool operator>=(List<T>& list);
bool operator<=(List<T>& list);
T& operator[](size_t i) throw(std::string);

重载=运算符避免逐位复制，会把左边的链表复制到右边去，而不是复制头指针：
List<T>& operator=(const List<T>& list);
