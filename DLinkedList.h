#include"Node.h"
template<class T>
class DLinkedList{ 
public:
	DLinkedList();
	DLinkedList(const DLinkedList<T>& L);
	~DLinkedList();
	int size() const;
	bool empty();//判断是否为空链表
	Node<T> remove();//删除结点
	Node<T> first();//返回首结点
	Node<T> last();//返回尾结点
	void insertAsFirst(const T& item);//在前面插入结点
	void insertAsLast(const T& item);//在后面插入结点
	Node<T> find(int);//查找结点
	void sort();//按大小顺序排序
	void reverse();//将链表逆序输出
	void merge(DLinkedList<T>list);//合并另一有序链表
	void show();//输出链表
private:
	Node<T>* front, * rear;//表头和表尾指针
	Node<T>* predptr, * succptr;
	int length;//链表长度
	int position;
};
//构造函数，构造一个空链表
template<class T>
DLinkedList<T>::DLinkedList() {
	front->succ = rear;
	front->pred = nullptr;
	rear->succ = nullptr;
	rear->pred = front;
	length = 0;
}
template<class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& L) {
	Node<T>* temp = L.front;
	while (temp->succ != L.rear)
	{
		temp = temp->succ;
		rear->data = temp->data;
		Node<T>* p = rear;
		rear = rear->succ;
		rear->pred = p;
		rear->succ = nullptr;
		length++;
	}
}
template<class T>
int DLinkedList<T>::size() const
{
	return length;
}
template<class T>
bool DLinkedList<T>::empty()
{
	if (length == 0) {
		return true;
	}
	else {
		return false;
	}
}
template<class T>
Node<T> DLinkedList<T>::remove() 
{
	if (length == 0)
	{
		std::cout << "DLinkedList is empty";
		return 0;
	}
	Node<T>* p = front;
	while (p->succ != nullptr)
	{
		    p = p->succ;
			Node<T>* temp = p->pred;
			temp->succ = p->succ;
			p->succ->pred = temp;
			delete p;
			length--;
			return 0;
	}
}
template<class T>
Node<T> DLinkedList<T>::first() 
{
	return front;
}
template<class T>
Node<T> DLinkedList<T>::last() 
{
	return rear;
}
template<class T>
void DLinkedList<T>::insertAsFirst(const T &item) 
{
	Node<T>* p = new Node<T>;
	p.insertpred(item);
}
template<class T>
void DLinkedList<T>::insertAsLast(const T& item)
{
	Node<T>* p = new Node<T>;
	p.insertsucc(item);
}
template<class T>
Node<T> DLinkedList<T>::find(int index)
{
	if (length == 0)
	{
		std::cout << "DLinkedList is empty";
		return 0;
	}
	if (index >= length)
	{
		std::cout << "Out of bounds";
		return 0;
	}
	int x = 0;
	T data;
	Node<T> *p;
	if (index < length / 2)
	{
		p = front->next;
		while (p->pred != nullptr && x++ != index)
		{
			p = p->pred;
		}
	}
	else {
		p = rear->pred;
		while (p->pred != nullptr && x++ != index)
		{
			p = p->pred;
		}
	}
	return p->data;
}
template<class T>
void DLinkedList
<T>::sort()
{
	if (length <= 1) return 0;
	Node<T>* p = front->succ;
	for (int i = 0;i < length - 1;i++)
	{
		Node<T>* q = p->succ;
		for(int j=i+1;j<length;j++)
		{
			if (p->data > q->data)
			{
				T temp = q->data;
				q->data = p->data;
				p->data = temp;
			}
			q = q->succ;
		}
		p = p->succ;
	}
}
template<class T>
void DLinkedList<T>::reverse()
{
	if (length <= 1) return 0;
	Node<T>* p = front->succ;
	Node<T>* q = rear->pred;
	T temp;
	temp = front->data;
	front->data = rear->data;
	rear->data = temp;
	for (int i = 1;i < length / 2;i++)
	{
		temp = p->data;
		p->data = q->data;
		q->data = temp;
		p = p->succ;
		q = q->pred;
	}
}
template<class T>
void DLinkedList<T>::merge(DLinkedList<T>list)
{
	rear->succ = list.front;
	list.front->pred = rear;
	rear = list.rear;
}
template<class T>
void DLinkedList<T>::show()
{
	if (length == 0)
	{
		std::cout << "DLinkedList is empty";
	}
	Node<T>* p = front;
	for (int i = 0; i < length - 1;i++)
	{
		std::cout << "data" << i << ":";
		std::cout << p->data;
		p = p->succ;
	}
}
template<class T>
DLinkedList<T>::~DLinkedList()
{
	remove();
}