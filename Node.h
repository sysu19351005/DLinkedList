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
	const Node<T>* predNode() const;//����ǰ�����
	Node<T>* succNode();
	const Node<T>* succNode() const;//���غ������
};
//���캯������һ���ս�㣬����ʼ�����ݳ�Ա������������
template<class T>
Node<T>::Node(void) {
	pred = succ = this;
}
//���캯��������һ���ս�㲢��ʼ�����ݳ�Ա
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
