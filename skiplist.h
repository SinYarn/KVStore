#pragma once
#include<iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <mutex>
#include <fstream>

// KV节点
template <typename K, typename V>
class Node {
public:
	Node() {};
	Node(K k, V v, int);
	~Node();
	K get_key() const;
	V get_value() const;
	void set_value(V value);
	Node<K, V>** forward;
	int node_level;
private:
	K key;
	V value;
};

template <typename K, typename V>
Node<K, V>::Node(const K k, const V v, int level) {
	this->key = k;
	this->value = v;
	this->node_level = level;
	this->forward = new Node<K, V>* [level + 1]; // level 从0开始分配
	memset(this->forward, 0, sizeof(Node<K, V> *) * (static_cast<unsigned long long>(level) + 1)); //forward数组初始化为nullptr
}

template<typename K, typename V>
Node<K, V>::~Node() {
	delete[] forward;
}

template<typename K, typename V>
inline K Node<K, V>::get_key() const {
	return key;
};

template<typename K, typename V>
inline V Node<K, V>::get_value() const {
	return value;
}
template<typename K, typename V>
inline void Node<K, V>::set_value(V value) {
	this->value = value;

};


// 情况一： 不同节点的单层跳转：在相同层级、不同键值节点之间的跳转
class LinkList {
public:
	int data;
	LinkList* next;
};

// 单链表实现节点跳转的简单实现
void travasal(LinkList* listHeader)
{
	// 单链表实现节点跳转的简单实现
	LinkList* current = listHeader;
	while (current->next != nullptr) {
		current = current->next;
	}
}

template <typename K, typename V>
class SkipList {
public:
	SkipList(int);                      // 构造函数
	~SkipList();                        // 析构函数
	int get_random_level();             // 获取节点的随机层级
	Node<K, V>* create_node(K, V, int); // 节点创建
	int insert_element(K, V);           // 插入节点
	void display_list();                // 展示节点
	bool search_element(K);             // 搜索节点
	void delete_element(K);             // 删除节点
	void dump_file();                   // 持久化数据到文件
	void load_file();                   // 从文件加载数据
	void clear(Node<K, V>*);           // 递归删除节点
	int size();                         // 跳表中的节点个数
private:
	// ...
};