#pragma once

#include <unordered_map>

struct DLinkedNode {
	int key, value;
	DLinkedNode *prev;
	DLinkedNode *next;
	DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
	DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
	std::unordered_map<int, DLinkedNode*> cache;
	DLinkedNode *head;
	DLinkedNode *tail;
	int size;
	int capacity;

public:
	LRUCache(int _capacity) : capacity(_capacity), size(0) {
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}
	int get(int key) {
		if (cache.count(key) == 0)
			return -1;
		DLinkedNode *node = cache[key];
		//最新使用，要移到头部
		moveToHead(node);
		return node->value;
	}
	void put(int key, int value) {
		if (cache.count(key) == 0) {//插入
			DLinkedNode *node = new DLinkedNode(key, value);
			cache[key] = node;
			addToHead(node);
			++size;

			if (size > capacity) {//移出最后一个
				DLinkedNode *removed = removeTail();
				cache.erase(removed->key);
				delete removed;
				--size;
			}
		}
		else {//更新值
			DLinkedNode *node = cache[key];
			node->value = value;
			moveToHead(node);
		}
	}

	void addToHead(DLinkedNode *node) {
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}
	void removeNode(DLinkedNode *node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void moveToHead(DLinkedNode *node) {
		//移除node
		removeNode(node);
		//再添加到head
		addToHead(node);
	}
	DLinkedNode *removeTail() {
		DLinkedNode *node = tail->prev;
		removeNode(node);
		return node;
	}
};

