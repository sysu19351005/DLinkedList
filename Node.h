template<class T>
class Node{
public:
	Node<T>* pred;
	Node<T>* succ;
	T data;
	Node(void);
	Node(const T& item);
	void insertpred(const T& item);
	void insertsucc(const T& item);
	Node<T>* predNode();
	const Node<T>* predNode() const;//返回前趋结点
	Node<T>* succNode();
	const Node<T>* succNode() const;//返回后驱结点
};
//构造函数创建一个空结点，不初始化数据成员，用于链表结点
template<class T>
Node<T>::Node(void) {
	pred = succ = this;
}
//构造函数，创建一个空结点并初始化数据成员
template<class T>
Node<T>::Node(const T& item) {
	pred = succ = this;
	data = item;
}
template<class T>
void Node<T>::insertpred(const T &item) {
	Node<T>* p;
	p->pred = pred;
	pred->succ = p;
	p->succ = this;
	pred = p;
	p->data = item;
}
template<class T>
void Node<T>::insertsucc(const T& item) {
	Node<T>* p;
	p->succ = succ;
	succ->pred = p;
	p->pred = this;
	succ = p;
	p->data = item;
}
template<class T>
Node<T>* Node<T>::predNode() {
	return pred;
}
template<class T>
const Node<T>* Node<T>::predNode() const {
	return pred;
}
template<class T>
Node<T>* Node<T>::succNode() {
	return succ;
}
template<class T>
const Node<T>* Node<T>::succNode() const {
	return succ;
}
